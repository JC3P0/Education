#include "AlienPack.h"
using namespace std;

//default construct
AlienPack::AlienPack() {
    count = 0;
}

//adds an alien to the pack
void AlienPack::addAlien(Alien alien, int index) {
    aliens[index] = alien;
    count++;
}

//returns the alien pack array
Alien* AlienPack::getAliens() {
    return aliens;
}

int AlienPack::getAlienCount() {
    return count;
}

int AlienPack::calculateDamage(Alien* alienArray, int count) {
    int damage = 0;
    
    for(int i = 0; i < count; i++) {
        damage += (*(alienArray + i)).getDamage();
    }
    
    return damage;
}