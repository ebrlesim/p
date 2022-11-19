#include <SFML/Graphics.hpp>
#include <time.h>
#include <string>
#include <fstream>
#include <iostream>
#include <math.h>

using namespace sf;

int main()
{
    srand(time(0));     

    RenderWindow window(VideoMode(243, 802), "The Game!");
    Texture t;
        t.loadFromFile("image/basic2.png");
    Sprite s(t);
    //načtení fontu pro text využívám zatím arial
    Font font;
    if (!font.loadFromFile("arial.ttf"))
    {
        std::cout << "Error 1"<< std::endl;
        return 100;
    }
    // nadefinování čáry oddělující nadpis od zbytku seznamu
    RectangleShape rectangle(sf::Vector2f(120.f, 50.f));
    rectangle.setSize(Vector2f(180.f,2.f));
    rectangle.setPosition(28,100);
    rectangle.setFillColor(Color :: Black);
    // odelník na vyznačení položky v menu na které je kurzor
    RectangleShape rectangle2(sf::Vector2f(120.f, 50.f));
    rectangle2.setSize(Vector2f(204.f,23.f));
    rectangle2.setFillColor(Color :: Black);
    //trojuhelníky pro označení šipek dolu nebo nahoru
    sf::CircleShape triangle(8.f, 3);
    triangle.setFillColor(Color :: Black);
    triangle.setOrigin(-120,-133);
    // šipka dole
    sf::CircleShape triangle2(8.f, 3);
    triangle2.setFillColor(Color :: Black);
    triangle2.setOrigin(137,311);
    triangle2.setRotation(180);

    std::string h [6];
    h[0]="Summary";
    h[1]="Current";
    h[2]="Courent Graph";
    h[3]="Voltage";
    h[4]="Power";
    h[5]="Energy";
    // nadefinování textu vypsaného jako nadpis 
    String a;
    a="Main menu";

    Text text; 
    text.setFont(font);
    text.setString(a);
    text.setCharacterSize(18);
    text.setFillColor(sf::Color::Black);
    text.setPosition(84,80);
    Text menu;
    menu.setFont(font);
    menu.setCharacterSize(14);
    menu.setFillColor(sf::Color::Black);
    Text menu2;
    menu2.setFillColor(sf::Color::White);
    menu2.setFont(font);
    menu2.setCharacterSize(14);

    while (window.isOpen())
    {
        Event e;
        while (window.pollEvent(e))
        {
            if (e.type == Event::Closed)
                window.close();
        }
    window.clear(Color::Green);
    window.draw(s);
    window.draw(text);
    window.draw(triangle);
    window.draw(rectangle);
    window.display();
    }
    return 0;
}