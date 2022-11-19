#include <SFML/Graphics.hpp>
#include <time.h>
#include <string>
#include <fstream>
#include <iostream>
#include <math.h>

using namespace sf;

int main()
{
   
    //zobrazení okne ve velikosti tolika a tolik pixelů plus název okna
    RenderWindow window(VideoMode(266, 420), "ACB screan");
    //Načtení textur pozadí a tlačítka
    Texture t1,t2,t3,t4;
        t1.loadFromFile("image/basic3.png");
        t2.loadFromFile("image/up.png");
        t3.loadFromFile("image/down.png");
        t4.loadFromFile("image/entr.png");
    //nadefeninování textur ajejich umístění 
    Sprite s(t1), sUp(t2),sDown(t3), sEntr(t4);
    sUp.setPosition(26,347);
    sDown.setPosition(102,347);
    sEntr.setPosition(174,347);
    // nadefinování čáry oddělující nadpis od zbytku seznamu
    RectangleShape rectangle(sf::Vector2f(120.f, 50.f));
    rectangle.setSize(Vector2f(215.f,2.f));
    rectangle.setPosition(29,130);
    rectangle.setFillColor(Color :: Black);
    // odelník na vyznačení položky v menu na které je kurzor
    RectangleShape rectangle2(sf::Vector2f(120.f, 50.f));
    rectangle2.setSize(Vector2f(215.f,23.f));
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

    //načtení fontu pro text využívám zatím arial
    Font font;
    if (!font.loadFromFile("arial.ttf"))
    {
        std::cout << "Error 1"<< std::endl;
        return 100;
    }
    
    // vektor naplněný vším co má být zaznamenané na obrazovce 
    String h [6];
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
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::Black);
    text.setPosition(85,103);
    Text menu;
    menu.setFont(font);
    menu.setCharacterSize(14);
    menu.setFillColor(sf::Color::Black);
    Text menu2;
    menu2.setFillColor(sf::Color::White);
    menu2.setFont(font);
    menu2.setCharacterSize(14);
    
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
        if (pozice [1]>347 && pozice [1]<428)
            {
                if (pozice [0] > 25 && pozice [0] < 75 )
                {
                    if (k != start)
                    {
                    k--;
                    std :: cout << k << std ::endl;
                    pozice [0] = 0;
                    pozice [1] = 0;
                    } 
                }
                else if (pozice [0] > 102 && pozice [0] < 162 )
                {
                    if (k != stop)
                    {
                    k++;
                    std :: cout << k << std ::endl; // pro kontolu že mačkám na správné tlačítko 
                    pozice [0] = 0;
                    pozice [1] = 0;
                    }
                }
                else if (pozice [0] > 174 && pozice [0] < 240 )
                
                {
                    std :: cout << k << std ::endl; // pro kontolu že mačkám na správné tlačítko 
                    pozice [0] = 0;
                    pozice [1] = 0;
                }
            }
    
    //vypsaní jednotlivých textur důležité je začít pozadím a pka až ostatní textury pokud se v prubehu programu nemění
    window.draw(s);
    window.draw(text);
    window.draw(sUp);
    window.draw(sDown);
    window.draw(sEntr);
    window.draw(rectangle);
    //proměná pro označení kurzoru a místa kde se přestane ukazovat šipka dolu

    //vypsání částí menu 
    for (int i = 0; i < 6; i++)
    {   
        if (k==start)
        {
            window.draw(triangle2);
        }
        else if (k== stop)
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
            rectangle2.setPosition(29,148+i*25);
            window.draw(rectangle2);
            menu2.setPosition(32,150 +i*25);
            menu2.setString(h[i]);
            window.draw(menu2);
            
        }else
        {
            menu.setPosition(32,150 +i*25);
            menu.setString(h[i]);
            window.draw(menu);
        }
        
    }

    window.display();

    }
    return 0;
}