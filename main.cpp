#include "Map.h"

typedef char byte;

int main(int argc, byte **argv){
    Map<const byte*, const byte*> *map = new Map<const byte*, const byte*>();
    const byte *key = "this is";
    map->put(key, "a test");
    if(map->contains(key)) printf("%s\n", map->get(key));
    else printf("map doesn't contain %s\n", key);
    delete map;
    return 0;
}