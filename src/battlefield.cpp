#include "battlefield.h"

using namespace sf;

ship::ship(int size)
{
    r = static_cast<rotate>(rand() % 2);
    this->size = size;
    arr = new int[size];
    cord_1 = 0;
    cord_2 = 0;
    //setup_ships();
}

rotate ship::getRotate()
{
    return r;
}

int ship::getSize()
{
    return size;
}



battlefield::battlefield(int size, RenderWindow& window, int width, int height)
{
    this->width = width;
    this->height = height;
    this->window = &window;
    this->size = size;
    gridView = new int* [size+2];
    for (int i = 0; i < size+2; i++)
    {
        gridView[i] = new int[size+2];
    }

    for (int i = 0; i < size+2; i++)
    {
        for (int j = 0; j < size+2; j++)
        {
            gridView[i][j] = 0;
        }
    }
}

battlefield::~battlefield()
{
    for (int i = 0; i < size+2; i++)
    {
        delete[] gridView[i];
    }
    delete[] gridView;
}

void battlefield::print_battlefield()
{
    this->window->clear(Color::White);
    ConvexShape vertical;
    vertical.setPointCount(4);
    vertical.setPoint(0, Vector2f(0.f, 0));
    vertical.setPoint(1, Vector2f(2.f, 0));
    vertical.setPoint(2, Vector2f(2.f, height));
    vertical.setPoint(3, Vector2f(0.f, height));
    vertical.setFillColor(Color::Black);
    for (int i = 1; i <= 10; i++)
    {
        vertical.setPosition(i*width/(size+1), 0);
        this->window->draw(vertical);
    }

    ConvexShape horizontal;
    horizontal.setPointCount(4);
    horizontal.setPoint(0, Vector2f(0, 0));
    horizontal.setPoint(1, Vector2f(0, 2));
    horizontal.setPoint(2, Vector2f(width, 2));
    horizontal.setPoint(3, Vector2f(width, 0));
    horizontal.setFillColor(Color::Black);

    for (int i = 1; i <= 10; i++)
    {
        horizontal.setPosition(0, i*height/(size+1));
        this->window->draw(horizontal);
    }

    Font arial;
    arial.loadFromFile("arial.ttf");
    Text words[]
    {
        Text(L"some_text", arial, 20),
        Text(L"А", arial, 20),
        Text(L"Б", arial, 20),
        Text(L"В", arial, 20),
        Text(L"Г", arial, 20),
        Text(L"Д", arial, 20),
        Text(L"Е", arial, 20),
        Text(L"Ж", arial, 20),
        Text(L"З", arial, 20),
        Text(L"И", arial, 20),
        Text(L"К", arial, 20)
    };
    for (int i = 1; i <= 10; i++)
    {
        words[i].setFillColor(Color::Black);
        words[i].setPosition(5, i*height/(size+1));
        this->window->draw(words[i]);
    }

    Text numbers[]
    {
        Text(L"some_text", arial, 20),
        Text("1", arial, 20),
        Text("2", arial, 20),
        Text("3", arial, 20),
        Text("4", arial, 20),
        Text("5", arial, 20),
        Text("6", arial, 20),
        Text("7", arial, 20),
        Text("8", arial, 20),
        Text("9", arial, 20),
        Text("10", arial, 20)
    };
    for (int i = 1; i <= 10; i++)
    {
        numbers[i].setFillColor(Color::Black);
        numbers[i].setPosition(i*width/(size+1), 0);
        this->window->draw(numbers[i]);
    }
}

void battlefield::setup_ships(ship ships[])
{
    for (int i = 0; i < 10;)
    {
        bool isCorrect = true;
        if (ships[i].getRotate() == vertical)
        {
            int cord_1 = (rand() % 10) + 1;
            int cord_2 = (rand() % (11 - ships[i].getSize())) + 1;
            for (int j = 0, k = cord_2 - 1, a = cord_1 - 1, b = cord_1, c = cord_1 + 1; j <= ships[i].getSize()+1; j++, k++)
            {
                if (gridView[a][k] == 1 || gridView[b][k] == 1 || gridView[c][k] == 1)
                {
                    isCorrect = false;
                    break;
                }
            }

            if (isCorrect)
            {
                ships[i].cord_1 = cord_1;
                ships[i].cord_2 = cord_2;
                for (int j = 0; j < ships[i].getSize(); j++, cord_2++)
                {
                    gridView[cord_1][cord_2] = 1;
                }
                i++;
            }
        }
        else
        {
            int cord_1 = (rand() % (11 - ships[i].getSize())) + 1;
            int cord_2 = (rand() % 10) + 1;
            for (int j = 0, k = cord_1 - 1, a = cord_2 - 1, b = cord_2, c = cord_2 + 1; j <= ships[i].getSize()+1; j++, k++)
            {
                if (gridView[k][a] == 1 || gridView[k][b] == 1 || gridView[k][c] == 1)
                {
                    isCorrect = false;
                    break;
                }
            }

            if (isCorrect)
            {
                ships[i].cord_1 = cord_1;
                ships[i].cord_2 = cord_2;
                for (int j = 0; j < ships[i].getSize(); j++, cord_1++)
                {
                    gridView[cord_1][cord_2] = 1;
                }
                i++;
            }
        }
    }
}

void battlefield::print_shot(Color color, int x, int y)
{
    CircleShape circle(10.f);
    circle.setFillColor(color);
    circle.setPosition(x*width/11+width/66, y*height/11+height/66);
    this->window->draw(circle);
}

void battlefield::print_x(Color color, int x, int y)
{
    ConvexShape cross;
    cross.setPointCount(12);
    cross.setPoint(0, Vector2f(0, 2));
    cross.setPoint(1, Vector2f(2, 0));
    cross.setPoint(2, Vector2f(12, 10));
    cross.setPoint(3, Vector2f(22, 0));
    cross.setPoint(4, Vector2f(24, 2));
    cross.setPoint(5, Vector2f(14, 12));
    cross.setPoint(6, Vector2f(24, 22));
    cross.setPoint(7, Vector2f(22, 24));
    cross.setPoint(8, Vector2f(12, 14));
    cross.setPoint(9, Vector2f(2, 24));
    cross.setPoint(10, Vector2f(0, 22));
    cross.setPoint(11, Vector2f(10, 12));

    cross.setFillColor(color);
    cross.setPosition(x*width/11, y*height/11);
    this->window->draw(cross);
}

status battlefield::toShot(int x, int y)
{
    if (gridView[x][y] == 1)
    {
        return hit;
    }
    else
    {
        return miss;
    }
}

void battlefield::printShips()
{
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            std::cout << gridView[j][i] << " ";
            if (gridView[i][j] == 1)
            {
                print_shot(Color::Blue, i, j);
            }
        }
        std::cout << std::endl;
    }
}




