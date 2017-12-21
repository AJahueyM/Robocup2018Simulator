//
// Created by alber on 11/1/2017.
//
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

using namespace std;

#ifndef MYPROJECT_SKETCH_H
#define MYPROJECT_SKETCH_H
unsigned int WIDTH = 800;
unsigned int HEIGHT = 800;

class Sketch {
public:

    void setup() {


    }

    void update() {


    }

    void draw(sf::RenderWindow &window) {
        WIDTH = window.getSize().x;
        HEIGHT = window.getSize().y;
    }
};

#endif //MYPROJECT_SKETCH_H
