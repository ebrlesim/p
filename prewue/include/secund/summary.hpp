
#define summary_HPP

#include <string>
#include <fstream>
#include <iostream>
#include <math.h>
#include "sorceDt/sorceDt.hpp"

namespace mo
    {
            /*** clasic Menu is menu whitch has only draweble articles no special functions **/
        void workSummary (mo:: Data* data, mo:: Texts *text)
        {
            for (int i =1; i<6; i++)
            {
                text ->menu.setPosition(32,150 +i*25);
                text -> menu.setString(data -> h[i*2]);
                data -> window.draw(text ->menu);
            }
            for (int i =1; i<6; i++)
            {
                text ->menu.setPosition(180,150 +i*25);
                text -> menu.setString(data -> h[i*2+1]);
                data -> window.draw(text ->menu);
            }
            for (int i =1; i<6; i++)
            {
                std:: string h= "0";
                text ->menu.setPosition(160,150 +i*25);
                text -> menu.setString(h);
                data -> window.draw(text ->menu);
            }   
        
        }
        
        /*** function for loaading data freom text document **/ 

        void LoadDataSummary (mo:: Data * data)
        {   
            int special = 0;
            std :: string h;
            h = data -> h[data ->cursor +1];
            
            std :: ifstream vysledek;
            vysledek.open("test.txt");
            std :: string line;
            while ( special <2)
            {
                std :: getline(vysledek, line, '\n');
                if (line==h)
                {
                    special++;
                }
            }
            data -> h[0]= h;
            std :: getline(vysledek, line, '\n');
            data -> h[1]=line;
            data ->stop =0;
            for (int i = 2; i<12; i++)
            {
                std :: getline(vysledek, line, '\n');
                data -> stop ++;
                data -> h[i]=line;
            }
            h= data->h[2];
            data ->stop = data -> stop/2;
            vysledek.close();

        }
        void SumaryHedlain (mo:: Data* data, mo:: Texts *text, mo :: Shapes * shapes)
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
            shapes->rectangle2.setPosition(29,148);
            data -> window.draw(shapes -> rectangle2);
            text ->menu2.setPosition(70,150);
            text ->menu2.setString(data -> h[1]);
            data -> window.draw(text ->menu2);
            data -> window.draw(shapes->Araw22);
            data -> window.draw(shapes->Araw12);
        }
    }



