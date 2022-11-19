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

    RenderWindow window(VideoMode(243, 802), "ACB");
    Texture t;
        t.loadFromFile("prewue2/image/basic2.png");
    Sprite s(t);
    //načtení fontu pro text využívám zatím arial
    Font font;
    if (!font.loadFromFile("prewue2/arial.ttf"))
    {
        std::cout << "Error 1"<< std::endl;
        return 100;
    }
    // nadefinování čáry oddělující nadpis od zbytku seznamu
    RectangleShape rectangle(sf::Vector2f(120.f, 50.f));
    rectangle.setSize(Vector2f(180.f,2.f));
    rectangle.setPosition(28,105);
    rectangle.setFillColor(Color :: Black);
    // odelník na vyznačení položky v menu na které je kurzor
    RectangleShape rectangle2(sf::Vector2f(120.f, 50.f));
    rectangle2.setSize(Vector2f(180.f,23.f));
    rectangle2.setFillColor(Color :: Black);
    //trojuhelníky pro označení šipek dolu nebo nahoru
    sf::CircleShape triangle(6.f, 3);
    triangle.setFillColor(Color :: Black);
    triangle.setOrigin(-110,-110);
    // šipka dole
    sf::CircleShape triangle2(6.f, 3);
    triangle2.setFillColor(Color :: Black);
    triangle2.setOrigin(124,267);
    triangle2.setRotation(180);
    // textové pole s odnotama co se vypíší na dysplej
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
    text.setPosition(70,80);
    Text menu;
    menu.setFont(font);
    menu.setCharacterSize(12);
    menu.setFillColor(sf::Color::Black);
    Text menu2;
    menu2.setFillColor(sf::Color::White);
    menu2.setFont(font);
    menu2.setCharacterSize(12);

      int pozice [2]; // vektor pro zjišťování pozice myši
    int k=0, stranka=0 ,stop=5, start = 0; // proměné k == kolikátý řádek, stop kde je poslední řádek, start prvnířádek ale to tam teoreticky nebude muset býti 
    while (window.isOpen())
    {
        Vector2i pos = Mouse :: getPosition(window);
        Event e;
        while (window.pollEvent(e))
        {
            if (e.type == Event::Closed)
                window.close();
            // zjištění zda je nějaké tlačítko na myši zmáčknuté 
            if (e.type == Event :: MouseButtonPressed)
            {
                // získání pozice myši kdž je zmáčknuté levé
                if (e.key.code == Mouse ::Left)  // tady je warnining nevím proč 
                {
                    pozice [0] = pos.x;
                    pozice [1] = pos.y;
                }
            }
        }
    // nalezní jaké tlačítko jsem zmáčknul pokud vůbec 
        if (pozice [1]>265 && pozice [1]<345)
            {
                if (pozice [0] > 21 && pozice [0] < 70 )
                {
                    if (k != start)
                    {
                    k--;
                    std :: cout << k << std ::endl;
                    pozice [0] = 0;
                    pozice [1] = 0;
                    } 
                }
                else if (pozice [0] > 98 && pozice [0] < 148 )
                {
                    if (k != stop)
                    {
                    k++;
                    std :: cout << k << std ::endl; // pro kontolu že mačkám na správné tlačítko 
                    pozice [0] = 0;
                    pozice [1] = 0;
                    }
                }
                else if (pozice [0] > 154 && pozice [0] < 204 )
                
                {
                    std :: cout << k << std ::endl; // pro kontolu že mačkám na správné tlačítko 
                    pozice [0] = 0;
                    pozice [1] = 0;
                }
            }
    window.clear(Color::Green);
    window.draw(s);
    window.draw(text);
    window.draw(rectangle);
    //vypsání částí menu 
    for (int i = 0; i < 6; i++)
    {   
        if ((k+stranka)==start)
        {
            window.draw(triangle2);
        }
        else if ((k+(stranka*6)+1== stop)
        {
            window.draw(triangle);
        }
        else 
        {
            window.draw(triangle);
            window.draw(triangle2);
        }

        if (k==i)
        {
            rectangle2.setPosition(29,125+i*21);
            window.draw(rectangle2);
            menu2.setPosition(31,127 +i*21);
            menu2.setString(h[i]);
            window.draw(menu2);
            
        }else
        {
            menu.setPosition(29,125+i*21);
            menu.setString(h[i]);
            window.draw(menu);
        }
        
    }


    window.display();
    }
    return 0;
}