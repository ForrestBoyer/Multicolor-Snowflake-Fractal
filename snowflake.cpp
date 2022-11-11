// Copyright 2022 Forrest Boyer

#include <math.h>
#include <iostream>
#include <random>
#include <chrono>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

sf::RenderWindow window(sf::VideoMode(1, 1), "Triangle Stuff");
unsigned int seed = std::chrono::system_clock::now().time_since_epoch().count();
std::minstd_rand0 g1(seed);

class Triangle: public sf::CircleShape{
 public:
    explicit Triangle(int sidelength = 0, int sides = 3):
        sf::CircleShape((sidelength * sqrt(3) / 3), sides),
        length(sidelength),
        r(sidelength * (sqrt(3) / 3)),
        height((sqrt(3) / 2) * sidelength) {}

    int getLength() {
        return length;
    }

    int getHeight() {
        return height;
    }

    int getr() {
        return r;
    }

 private:
    int length;
    int r;
    int height;
};

void flakes(int num, int length, int x, int y, int rotation) {
    if (num == 0) {
        return;
    } else {
        Triangle t(length, 3);
        t.setOrigin(t.getr(), t.getr());
        t.setPosition(x, y);
        // Changing color based on random number generator g1
        sf::Color color(static_cast<int>(g1()) % 255, static_cast<int>(g1()) % 255, static_cast<int>(g1()) % 255);
        t.setFillColor(color);
        t.rotate(rotation);
        window.draw(t);

        // Right triangle
        if (rotation == 90) {
            // Right side
            flakes(num - 1,
             length / 2,
             x + (t.getr() * (5.0/4.0)),
             y,
             rotation);
            // Bottom
            flakes(num - 1,
             length / 2,
             x - (5.0/4.0 * t.getr() * cos(M_PI / 3)),
             y + (5.0/4.0 * t.getr() * sin(M_PI / 3)),
             rotation);
             // Top
            flakes(num - 1,
             length / 2,
             x - (5.0/4.0 * t.getr() * cos(M_PI / 3)),
             y - (5.0/4.0 * t.getr() * sin(M_PI / 3)),
             rotation);
        // Left Triangle
        } else if (rotation == 270) {
            // Left side
            flakes(num - 1,
            length / 2,
            x - (t.getr() * (5.0/4.0)),
            y,
            rotation);
            // Bottom
            flakes(num - 1,
            length / 2,
            x + (5.0/4.0 * t.getr() * cos(M_PI / 3)),
            y + (5.0/4.0 * t.getr() * sin(M_PI / 3)),
            rotation);
            // Top
            flakes(num - 1,
            length / 2,
            x + (5.0/4.0 * t.getr() * cos(M_PI / 3)),
            y - (5.0/4.0 * t.getr() * sin(M_PI / 3)),
            rotation);
        // Top right triangle
        } else if (rotation == 30) {
            // Top right
            flakes(num - 1,
            length / 2,
            x + (5.0/4.0 * t.getr() * cos(M_PI / 3)),
            y - (5.0/4.0 * t.getr() * sin(M_PI / 3)),
            rotation);
            // Bottom
            flakes(num - 1,
            length / 2,
            x + (5.0/4.0 * t.getr() * cos(M_PI / 3)),
            y + (5.0/4.0 * t.getr() * sin(M_PI / 3)),
            rotation);
            // Bottom
            flakes(num - 1,
            length / 2,
            x - (5.0/4.0 * t.getr()),
            y,
            rotation);
        // Top left triangle
        } else if (rotation == 330) {
            // Right
            flakes(num - 1,
            length / 2,
            x + (5.0/4.0 * t.getr()),
            y,
            rotation);
            // Bottom
            flakes(num - 1,
            length / 2,
            x - (5.0/4.0 * t.getr() * cos(M_PI / 3)),
            y + (5.0/4.0 * t.getr() * sin(M_PI / 3)),
            rotation);
            // Top
            flakes(num - 1,
            length / 2,
            x - (5.0/4.0 * t.getr() * cos(M_PI / 3)),
            y - (5.0/4.0 * t.getr() * sin(M_PI / 3)),
            rotation);
        // Bottom right triangle
        } else if (rotation == 150) {
            // Left
            flakes(num - 1,
            length / 2,
            x - (5.0/4.0 * t.getr()),
            y,
            rotation);
            // Bottom
            flakes(num - 1,
            length / 2,
            x + (5.0/4.0 * t.getr() * cos(M_PI / 3)),
            y + (5.0/4.0 * t.getr() * sin(M_PI / 3)),
            rotation);
            // Top
            flakes(num - 1,
            length / 2,
            x + (5.0/4.0 * t.getr() * cos(M_PI / 3)),
            y - (5.0/4.0 * t.getr() * sin(M_PI / 3)),
            rotation);
        // Bottom left triangle
        } else if (rotation == 210) {
            // Right
            flakes(num - 1,
            length / 2,
            x + (5.0/4.0 * t.getr()),
            y,
            rotation);
            // Bottom
            flakes(num - 1,
            length / 2,
            x - (5.0/4.0 * t.getr() * cos(M_PI / 3)),
            y + (5.0/4.0 * t.getr() * sin(M_PI / 3)),
            rotation);
            // Top
            flakes(num - 1,
            length / 2,
            x - (5.0/4.0 * t.getr() * cos(M_PI / 3)),
            y - (5.0/4.0 * t.getr() * sin(M_PI / 3)),
            rotation);
        }
    }
}

void snowflake(int num, int length, int centerX, int centerY) {
    // Right side triangle
    Triangle t1(length, 3);
    t1.setOrigin(t1.getr(), t1.getr());
    t1.setPosition(centerX + (2 * t1.getr()), centerY);
    t1.rotate(90);
    t1.setFillColor(sf::Color::Cyan);
    window.draw(t1);

    // Recursion call
    flakes(num, length / 2,
     t1.getPosition().x + (t1.getr() * (5.0/4.0)),
     t1.getPosition().y,
     90);

    // Left side triangle
    Triangle t2(length, 3);
    t2.setOrigin(t2.getr(), t2.getr());
    t2.setPosition(centerX - (2 * t2.getr()), centerY);
    t2.rotate(270);
    t2.setFillColor(sf::Color::Cyan);
    window.draw(t2);

    // Recursion call
    flakes(num, length / 2,
     t2.getPosition().x - (t1.getr() * (5.0/4.0)),
     t2.getPosition().y,
     270);

    // Top right triangle
    Triangle t3(length, 3);
    t3.setOrigin(t3.getr(), t3.getr());
    t3.setPosition(centerX + (2 * t3.getr() * cos(M_PI / 3)), centerY - (2 * t3.getr() * sin(M_PI / 3)));
    t3.rotate(30);
    t3.setFillColor(sf::Color::Cyan);
    window.draw(t3);

    // Recursion call
    flakes(num, length / 2,
     t3.getPosition().x + ((5.0/4.0 * t3.getr()) * cos(M_PI / 3)),
     t3.getPosition().y - ((5.0/4.0 * t3.getr()) * sin(M_PI / 3)),
     30);

    // Top left triangle
    Triangle t4(length, 3);
    t4.setOrigin(t4.getr(), t4.getr());
    t4.setPosition(centerX - (2 * t4.getr() * cos(M_PI / 3)), centerY - (2 * t4.getr() * sin(M_PI / 3)));
    t4.rotate(330);
    t4.setFillColor(sf::Color::Cyan);
    window.draw(t4);

    // Recursion call
    flakes(num, length / 2,
     t4.getPosition().x - ((5.0/4.0 * t4.getr()) * cos(M_PI / 3)),
     t4.getPosition().y - ((5.0/4.0 * t4.getr()) * sin(M_PI / 3)),
     330);

    // Bottom right triangle
    Triangle t5(length, 3);
    t5.setOrigin(t5.getr(), t5.getr());
    t5.setPosition(centerX + (2 * t5.getr() * cos(M_PI / 3)), centerY + (2 * t5.getr() * sin(M_PI / 3)));
    t5.rotate(150);
    t5.setFillColor(sf::Color::Cyan);
    window.draw(t5);

    // Recursion call
    flakes(num, length / 2,
     t5.getPosition().x + ((5.0/4.0 * t5.getr()) * cos(M_PI / 3)),
     t5.getPosition().y + ((5.0/4.0 * t5.getr()) * sin(M_PI / 3)),
     150);

    // Bottom left triangle
    Triangle t6(length, 3);
    t6.setOrigin(t6.getr(), t6.getr());
    t6.setPosition(centerX - (2 * t6.getr() * cos(M_PI / 3)), centerY + (2 * t6.getr() * sin(M_PI / 3)));
    t6.rotate(210);
    t6.setFillColor(sf::Color::Cyan);
    window.draw(t6);

    // Recursion call
    flakes(num, length / 2,
     t6.getPosition().x - ((5.0/4.0 * t6.getr()) * cos(M_PI / 3)),
     t6.getPosition().y + ((5.0/4.0 * t6.getr()) * sin(M_PI / 3)),
     210);
}


int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cout << "Incorrect number of command line arguments" << std::endl;
        return -1;
    }

    window.create(sf::VideoMode(atoi(argv[1]) * 6, atoi(argv[1]) * 6), "Triangle stuff");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        snowflake(atoi(argv[2]), atoi(argv[1]), atoi(argv[1]) * 3, atoi(argv[1]) * 3);
        window.display();
    }

    return 0;
}
