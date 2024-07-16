#ifndef ORGE_ALIEN_H
#define ORGE_ALIEN_H

#include <iostream>
#include "Alien.h"

class OrgeAlien : public Alien {
    private:
    public:
        OrgeAlien(int health, string name) : Alien(health, name, 3) {};
};

#endif