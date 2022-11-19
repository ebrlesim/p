#include <SFML/Graphics.hpp>
#include <time.h>
#include <string>
#include <fstream>
#include <iostream>
#include <math.h> 

using namespace sf;
void sorce (int i)
{       // funkkce pro vybrání spravných dat z csv souboru a vložení do textaku který bude dále použit jako jazykové podklady pro hlavní program.
                            int k=0;
                            std :: ifstream myFile;
                            std:: ofstream vysledek;
                            myFile.open("PXR20.csv");
                            vysledek.open("test.txt");
                            while (myFile.good())
                            {
                            std:: string line;
                            std:: getline(myFile, line, ';');
                            if (k>40)
                            {   
                            if(k%10==(i+1))
                            {
                            vysledek << line << std:: endl;
                            }
                            }
                            k++;
                            }
                            myFile.close();
                            vysledek.close();
}
int main () 
{
    RenderWindow window(VideoMode(266, 420), "ACB screan");
    window.clear(Color::White);

    Texture t1;
    t1.loadFromFile("prewue/image/basic.png");
    Sprite s(t1);
    RectangleShape rectangle(sf::Vector2f(120.f, 50.f));
    rectangle.setSize(Vector2f(204.f,2.f));
    rectangle.setPosition(29,130);
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

    Font font;
    if (!font.loadFromFile("prewue/arial.ttf"))
    {
        std::cout << "Error 1"<< std::endl;
        return 100;
    }
    String nadpis [2];
    nadpis [0] = "Select type of ACB";
    nadpis [1] = "Select language";

    Text  hedline;
    hedline.setFont(font);
    hedline.setCharacterSize(20);
    hedline.setFillColor(sf::Color::Black);
    

    String h [6];
    h[0]="Big";
    h[1]="Small";
    h[2]="Englisch";
    h[3]="Deutch";
    h[4]="Spanisch";
    h[5]="Portugie";
    Text menu;
    menu.setFont(font);
    menu.setCharacterSize(14);
    menu.setFillColor(sf::Color::Black);
    Text menu2;
    menu2.setFillColor(sf::Color::White);
    menu2.setFont(font);
    menu2.setCharacterSize(14);
    int pozice [2];
    int vrstva=0, k=0, stranka=0 ,stop=1, start = 0, verze=2;
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
            if (pozice [1]>428 || pozice [1]<347 )
            {
                continue;
            }
        }
        // nalezní jaké tlačítko jsem zmáčknul pokud vůbec 
        window.draw(s);
        if (pozice [1]>347 && pozice [1]<428)
            {
                if (pozice [0] > 25 && pozice [0] < 75 )
                {
                    if (k != start)
                    {
                    k--;
                    pozice [0] = 0;
                    pozice [1] = 0;
                    } 
                }
                else if (pozice [0] > 102 && pozice [0] < 162 )
                {
                    if (k != stop)
                    {
                    k++;
                    pozice [0] = 0;
                    pozice [1] = 0;
                    }
                }
                else if (pozice [0] > 174 && pozice [0] < 240 )
                
                {
                    if ( vrstva==1)
                    {
                        if (k==0)
                        {
                            sorce (k);
                        }else if (k==1)
                        {
                            sorce (k);
                        }else if (k==2)
                        {
                            sorce (k);
                        }else if (k==3)
                        {
                            sorce (k+1);
                        }
                        
                        
                        if (verze == 0)
                        {
                            system ("start prewue2/ACB.exe"); // volání programu ve složce prewue2 s názvem ACB.exe
                            return 0;
                        }
                        if (verze == 1)
                        {
                            system ("start prewue/ACB.exe");
                            return 0;
                            
                        }
                    pozice [0] = 0;
                    pozice [1] = 0;
                    }
                    else
                     {
                    verze=k;     
                    k=0;
                    vrstva ++;
                    pozice [0] = 0;
                    pozice [1] = 0;
                    }
                }
            }
        if (vrstva==1)
        {
            stop= 3;
        }
        if (vrstva==0 )
        {
            hedline.setString(nadpis[vrstva]);
            hedline.setPosition(45,100);
            window.draw(hedline);
            for (int i=0; i<2; i++)
            {
                if (k==0)
                {
                window.draw(triangle2);
                }
                else if (k== 1)
                {
                window.draw(triangle);
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
        }
        else if (vrstva==1 )
        {
            hedline.setString(nadpis[vrstva]);
            hedline.setPosition(60,100);
            window.draw(hedline);
            for (int i=2; i<6; i++)
            {
                if (k==0)
                {
                window.draw(triangle2);
                }
                else if (k== 3)
                {
                window.draw(triangle);
                }else
                {
                    window.draw(triangle2);
                    window.draw(triangle);
                }
                if (k==(i-2))
                {
                rectangle2.setPosition(29,148+(i-2)*25);
                window.draw(rectangle2);
                menu2.setPosition(32,150 +(i-2)*25);
                menu2.setString(h[i]);
                window.draw(menu2);
                }
                else 
                {
                menu.setPosition(32,150 +(i-2)*25);
                menu.setString(h[i]);
                window.draw(menu);
                }
            }
        }
        window.draw(rectangle);

        window.display();
        
        
    }

   




    return 0;
}
