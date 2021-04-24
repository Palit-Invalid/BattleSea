#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include "battlefield.h"

using namespace std;

const int width = 500;
const int height = 500;

int main()
{
    srand(time(NULL)); //Generate rotation of ships
    ship ships[]
    {
        ship(4),
        ship(3),
        ship(3),
        ship(2),
        ship(2),
        ship(2),
        ship(1),
        ship(1),
        ship(1),
        ship(1)
    };

    RenderWindow window(VideoMode(width, height), "Battle sea", Style::Default);
    battlefield btl(10, window, width, height);
    btl.print_battlefield();
    btl.setup_ships(ships);
    btl.printShips();

    for (int i = 0; i < 10; i++)
    {
        if (ships[i].getRotate() == vertical)
        {
            std::cout << "Ships №: " << i << std::endl;
            std::cout << "Rotate: Vertical" << endl;
            std::cout << "Cordinates: " << ships[i].cord_1 << ", " << ships[i].cord_2 << std::endl;
            std::cout << "Size: " << ships[i].getSize() << endl;
            std::cout << std::endl;
        }
        else
        {
            std::cout << "Ships №: " << i << std::endl;
            std::cout << "Rotate: Horizontal" << endl;
            std::cout << "Cordinates: " << ships[i].cord_1 << ", " << ships[i].cord_2 << std::endl;
            std::cout << "Size: " << ships[i].getSize() << endl;
            std::cout << std::endl;
        }
    }

    while (window.isOpen())
    {
        Event event;
        window.display();

        while (window.waitEvent(event))
        {
            Vector2i pos = Mouse::getPosition(window);
            int x = pos.x/(width/11);
            int y = pos.y/(height/11);
            if (Mouse::isButtonPressed(Mouse::Left))
            {
                if (!(x > 10 || y > 10 || x < 1 || y < 1))
                {
                    if (btl.toShot(x, y) == hit)
                    {
                        btl.print_x(Color::Red, x, y);
                    }
                    else if (btl.toShot(x, y) == miss)
                    {
                        btl.print_shot(Color::Black, x, y);
                    }
                }
                window.display();
            }
            if (event.type == Event::Closed)
            {
                window.close();
            }
        }
    }
    return 0;
}
