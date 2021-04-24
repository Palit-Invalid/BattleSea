#ifndef BATTLEFIELD_H
#define BATTLEFIELD_H

#include <SFML/Graphics.hpp>

using namespace sf;

enum rotate {vertical = 0, horizontal = 1};

enum status {miss = 0, hit = 1};

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
    battlefield(int size, RenderWindow& window, int width, int height);
    ~battlefield();
    void print_battlefield();
    void print_shot(Color color, int x, int y);
    void print_x(Color color, int x, int y);
    status toShot(int x, int y);
    void setup_ships(ship ships[]);


private:
    int** gridView;
    int size;
    int width, height; //size of window
    RenderWindow* window;
    ship ships[];



};


#endif // BATTLEFIELD_H
