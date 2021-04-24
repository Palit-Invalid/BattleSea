#ifndef BATTLEFIELD_H
#define BATTLEFIELD_H

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

enum rotate {vertical = 0, horizontal = 1};

enum status {miss = 0, alreadyShot = 1, hit = 2};

class ship
{
private:
    int *arr;
    int size;
    rotate r;

public:
    int cord_1;
    int cord_2;
    ship(int size);
    rotate getRotate();
    int getSize();
};


class battlefield
{
public:
    battlefield(int size, RenderWindow& window, int width, int height, int offset);
    ~battlefield();
    void print_battlefield();
    void print_shot(Color color, int x, int y);
    void print_x(Color color, int x, int y);
    status toShot(int x, int y);
    void setup_ships(ship ships[]);
    void printShips();
    void botShot(battlefield& enemy);
    status getXY(int x, int y);
    void setXY(int x, int y);


private:
    int** gridView;
    int size;
    int width, height; //size of window
    int offset;
    RenderWindow* window;
    ship ships[];



};


#endif // BATTLEFIELD_H
