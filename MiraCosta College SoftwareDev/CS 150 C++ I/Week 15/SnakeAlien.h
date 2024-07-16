#ifndef SNAKE_ALIEN_H
#define SNAKE_ALIEN_H

#include <iostream>
#include "Alien.h"

class SnakeAlien : public Alien {
    private:
    public:
        SnakeAlien(int health, string name) : Alien(health, name, 10) {};
};

#endif