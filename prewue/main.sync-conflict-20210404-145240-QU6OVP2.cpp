#include <SFML/Graphics.hpp>
#include <time.h>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iostream>
#include <math.h>

using namespace sf;
/*** structu whitch holde all necesery data */
struct Data 
    {
        sf :: RenderWindow window;
        int start = 0;
        int stop = 1;
        int cursor = 0;
        int page = 0;
        int layer = 0;
        String h [20];
    };
/*** structur whirtch holde all paramitrs of text and it wersins **/
struct Texts
    {
        Text headline;
        Text menu;
        Text menu2;
        Font font;

    };
/*** Structurs of all shapes whitch we use **/
struct Shapes
    {
        RectangleShape rectangle;
        RectangleShape rectangle2;
        CircleShape triangle;
        CircleShape triangle2;
    };
/** functoion for seting all texts paramitrs **/
int seting_fonts (Texts * text)
    {
        if (!text -> font.loadFromFile("prewue/arial.ttf"))
        {
            std::cout << "Error 1"<< std::endl;
            return 100;
        }
        text -> headline.setFont(text -> font);
        text -> menu.setFont(text -> font);
        text -> menu2.setFont(text -> font);
        text  -> headline.setCharacterSize(20);
        text  -> headline.setFillColor(sf::Color::Black);
        text  -> headline.setPosition(85,103);

        text -> menu.setCharacterSize(14);
        text -> menu.setFillColor(sf::Color::Black);

        text -> menu2.setFillColor(sf::Color::White);
        text -> menu2.setCharacterSize(14);
        return 0;
    }
/*** function for loaading data freom text document **/
void LoadData (Data * data)
    {   
        int special =0;
        std :: string h;
        h = data -> h[0];
        if (h== "")
        {
            std :: ifstream vysledek;
            vysledek.open("test.txt");
            std :: string line;
            std :: getline(vysledek, line, '\n');
            data -> h[0]=line;
            std :: getline(vysledek, line, '\n');
            data -> h[1]=line;
            for (int i=2;i<20;i++)
            {
                getline(vysledek, line, '\n');
                if (line == data -> h[1])
                {
                    
                    break;
                }
                data -> stop ++;
                data -> h[i]=line;
            }
            vysledek.close();
        }
        else 
        {
            h = data -> h[(data->cursor+(data->page*6)+1)];
            std :: ifstream vysledek;
            vysledek.open("test.txt");
            std :: string line;
            std :: getline(vysledek, line, '\n');
            while (special<=2)
            {
                getline(vysledek, line, '\n');
                if (h==line)
                {
                    special ++;
                    break;
                }
            }
            data ->h [0] == h;
            for (int i=1;i<20;i++)
            {
                break;
            }
        
        }
    }
/** loading data for rest of  **/
void hedlain (Data *data, Texts * text , Shapes * shapes)
{   
    std :: string h;
    h=data->h[0];
    float lenght = 0;
    data -> window.draw(shapes -> rectangle);
    text  -> headline.setString(data ->h[0]);
    lenght = h.length();
    lenght = 125-((lenght/2)*9.f); /** 125 is midle position for headlain **/
    text -> headline.setPosition(lenght,103);
    data -> window.draw(text -> headline);

    

}
 /*** this finction set the paramistrs of al shapes whitch are youse for ewrething **/   
void defineShapes (Shapes *shapes)
    {
        /*** arouy up **/
        shapes -> triangle.setPointCount(3);
        shapes -> triangle.setRadius(8.f);
        shapes -> triangle.setFillColor(Color :: Black);
        shapes -> triangle.setOrigin(-120,-133);
       /*** arouy down **/
        shapes -> triangle2.setPointCount(3);
        shapes -> triangle2.setRadius(8.f);
        shapes ->triangle2.setFillColor(Color :: Black);
        shapes -> triangle2.setOrigin(137,311);
        shapes -> triangle2.setRotation(180);
        /*** ractangle witche  seperate headline from the rest of text **/
        shapes -> rectangle.setSize(Vector2f(205.f,2.f));
        shapes -> rectangle.setPosition(29,130);
        shapes -> rectangle.setFillColor(Color :: Black);
        /*** ractangle witche  hedline positio of cursor **/
        shapes -> rectangle2.setSize(Vector2f(205.f,23.f));
        shapes -> rectangle2.setFillColor(Color :: Black);
    }
 /*** This function draw arews when thei are visible **/
void Araws (Data * data, Shapes * shapes)
    {
       
        
        if ((data -> cursor + data ->page)== data -> start)
            {
                data -> window.draw( shapes -> triangle2);
            }
            else if ((data -> cursor + (data ->page *6)+1)== data -> stop)
            {
                data -> window.draw( shapes -> triangle);
            }
            else 
            {
                data -> window.draw(shapes ->triangle);
                data -> window.draw( shapes -> triangle2);
            }
    }
/*** clasic Menu is menu whitch has only draweble articles no special functions **/
void clasicMenu (Data* data, Texts *text, Shapes * shapes)
{
    for (int i = 0; i < 6; i++)
    {   
        if (data -> cursor ==i)
        {
            if ((i+(data ->page *6))== data -> stop)
            {
                break;
            }
            else
            {
            shapes->rectangle2.setPosition(29,148+i*25);
            data -> window.draw(shapes -> rectangle2);
            text ->menu2.setPosition(32,150 +i*25);
            text ->menu2.setString(data -> h[i+1+(data ->page*6)]);
            data -> window.draw(text ->menu2);
            }
        }else
        {
            if ((i+(data ->page*6))== data -> stop)
            {
                break;
            }
            else
            {
            text ->menu.setPosition(32,150 +i*25);
            text -> menu.setString(data -> h[i+1+(data->page*6)]);
            data -> window.draw(text ->menu);
            }
        }
    }
}
int main()
{
   Data *data = new Data();
   Texts *text = new Texts();
   Shapes *shapes = new Shapes();
    //creating window in a shape we nead 
    data -> window.create(VideoMode(266, 420), "ACB screan");
    //Texturs of ower circits braker 
    Texture t1,t2,t3,t4;
        t1.loadFromFile("prewue/image/basic3.png");
        t2.loadFromFile("prewue/image/up.png");
        t3.loadFromFile("prewue/image/down.png");
        t4.loadFromFile("prewue/image/entr.png");
    //Textur positioning
    Sprite s(t1), sUp(t2),sDown(t3), sEntr(t4);
    sUp.setPosition(26,347);
    sDown.setPosition(102,347);
    sEntr.setPosition(174,347);
    defineShapes ( shapes);
    //error abyout bead sorcing of font
    int error = 0;
    error = seting_fonts (text);
    if (error != 0)
    {
        return error;
    }
    int position [2]; // vektor pro zjišťování pozice myši
    int special =0; // first iteratin of draw window
    while (data -> window.isOpen())
    {
        Vector2i pos = Mouse :: getPosition(data -> window);
        Event e;
        while (data -> window.pollEvent(e))
        {
            if (e.type == Event::Closed)
                
                data -> window.close();
             // zjištění zda je nějaké tlačítko na myši zmáčknuté 
            if (e.type == Event :: MouseButtonPressed)
            {
                // získání pozice myši kdž je zmáčknuté levé
                if (e.key.code == Mouse ::Left)  // tady je warnining nevím proč 
                {
                    position [0] = pos.x;
                    position [1] = pos.y;
                }
            }
            if (special !=0)
            { 
                
                if (position [1]<347 || position [1]>428)
                {
                    if (position [0]<25 || position [0]>240)
                    {
                        continue;
                    }
                }
            }
            
        }
        
        /*** findig whitch buton we presed **/
        if (position [1]>347 && position [1]<428)
            {
                if (position [0] > 25 && position [0] < 75 )
                {
                    if ((data -> cursor + data-> page)!= data -> start)
                    {
                        if (data -> cursor == 0)
                        {
                            data -> cursor =5;
                            data -> page --;
                            position [0] = 0;
                            position [1] = 0;
                        }
                        else
                        {
                            data -> cursor --;
                            position [0] = 0;
                            position [1] = 0;
                        }
                    } 
                }
                else if (position [0] > 102 && position [0] < 162 )
                {
                    if ((data -> cursor + (data-> page * 6)+1) != data -> stop)
                    {
                        if ( data -> cursor == 5)
                        {
                            data -> cursor =0;
                            data -> page ++;
                            position [0] = 0;
                            position [1] = 0;
                        }
                        else
                        {
                            data -> cursor ++;
                            position [0] = 0;
                            position [1] = 0;
                        }
                    }
                }
                else if (position [0] > 174 && position [0] < 240 )
                
                {
                    
                    std :: cout << data -> page << std ::endl;
                    std :: cout << data -> cursor << std ::endl;
                     std :: cout << data -> stop << std ::endl;// pro kontolu že mačkám na správné tlačítko 
                    position [0] = 0;
                    position [1] = 0;
                }
            }
    if (special == 0)
    {
        LoadData(data);
        special = 1; 
    }
    /*** Draw all neceseri asets**/
    data -> window.draw(s);
    data -> window.draw(sUp);
    data -> window.draw(sDown);
    data -> window.draw(sEntr);
     /***Seting of headline,*/
    hedlain (data,text,shapes);

    Araws (data , shapes);
    //proměná pro označení kurzoru a místa kde se přestane ukazovat šipka dolu
    
    //vypsání částí menu 
    clasicMenu (data, text, shapes);

    data -> window.display();

    }
    return 0;
}