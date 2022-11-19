#ifndef editSetings_hpp
#define editSetings_hpp
#include "sorceDt/sorceDt.hpp"
#include <string>
#include <fstream>
#include <iostream>

namespace mo
{
    /*** function for loaading data freom text document **/ 

    void LoadDataEditSetings (mo:: Data * data)
    {   
        int special = 0;
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
        else if (h != "" && data -> stop !=2)
        {
            std :: ifstream vysledek;
            vysledek.open("test.txt");
            std :: string line;
            std :: getline(vysledek, line, '\n');
            data -> h[0]=line;
            if (h== data ->h[0])
            {
                
            }
            else
            {
            std :: getline(vysledek, line, '\n');
            data -> h[1]=line;
            data -> stop = 1;
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
     /*** clasic Menu is menu whitch has only draweble articles no special functions **/
    void workEditSetings (mo:: Data* data, mo:: Texts *text, mo :: Shapes * shapes)
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
    /*** This function draw arews when thei are visible **/
    void ArawsEditSetings (mo:: Data * data, mo:: Shapes * shapes)
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
    /*** seting of all paramitrs of headline mainly position wher it schould be located. Finaly draw them on screan **/
    void hedlainEditSetings (mo:: Data *data, mo:: Texts * text , mo :: Shapes * shapes)
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


    
}





#endif