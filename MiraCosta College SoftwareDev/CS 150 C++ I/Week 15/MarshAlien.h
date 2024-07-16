#ifndef MARSH_ALIEN_H
#define MARSH_ALIEN_H

#include <iostream>
#include "Alien.h"

class MarshAlien : public Alien {
    private:
    public:
        MarshAlien(int health, string name) : Alien(health, name, 1) {};
};

#endif