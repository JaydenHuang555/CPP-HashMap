#pragma once
#include <stdexcept>
template<typename K, typename V>
class Map {
#define MAX 1024
#define HASH(x) ((__hash(x) % MAX))

    std::hash<K> __hash;
    struct Node {
        K key;
        V val;
        struct Node *next;
        
        Node(K key, V val) : key(key), val(val), next(0) {}

    }; 
    Node *table[MAX];
public:
    Map(){
        for(int i = 0; i < MAX; i++) table[i] = 0;
    }

    Map(Map<K,V> &other){
        for(int i = 0; i < MAX; i++) table[i] = other.table[i];
    }

    void put(K key, V val){
        unsigned long index = HASH(key);
        if(!table[index]) table[index] = new Node(key, val);
        else {
            struct Node *next = table[index];
            while(next->next) next = next->next;
            next->next = new Node(key, val);
        }
    }

    V get(K key){
        unsigned long index = HASH(key);
        if(!table[index]) throw std::invalid_argument("hashmap: key is not in map");
        struct Node *next = table[index];
        while(next)
            if(next && next->key == key) return next->val;
            else next = next->next;
        throw std::invalid_argument("hashmap: key is not in map");
    }

    bool contains(K key){
        unsigned long index = HASH(key);
        struct Node *next = table[index];
        while(next)
             if(next && next->key == key) return true;
             else next = next->next;
        return false;
    }

#undef MAX
#undef HASH
};