#ifndef mother_HPP
#define mother_HPP

#include <string>
#include <fstream>
#include <iostream>
#include "setingAsets.hpp"
#include <SFML/Graphics.hpp>
#include "secund/sorceDt/sorceDt.hpp"
#include "secund/mainmanu.hpp"
#include "secund/summary.hpp"
#include "secund/editSetings.hpp"

namespace mo /** mo as mother data **/
{
    /** this function makes decision what wil be displaid aftr entr is presed **/
    void DMAEntr (mo:: Data * data, mo::Texts * text, mo:: Shapes *shapes)
    {
        int a=0;
        a = ((data->page*6)+data->cursor);
        
        switch (data -> layer)
        {
        case 0:
                /***Seting of headline,*/
                mo :: hedlainMain (data,text,shapes);
                mo :: ArawsMain (data , shapes);
                mo :: workMeinMenu (data, text, shapes);
                break;
        case 1:
            switch (a)
              { 
                  //tetování zda se mohu dostat do nějakého podmeníčka 
                case 0:
                data -> memori [1] [0]= data ->cursor;
                data -> memori [1] [1]= data->page;
                mo :: LoadDataSummary(data);
                data->page =0;
                data ->cursor =0;
                mo :: SumaryHedlain (data, text,shapes);
                mo :: workSummary (data, text);
                data -> preweusl = data ->layer;
                break;
                case 7:
                data -> memori [1] [0]= data ->cursor;
                data -> memori [1] [1]= data->page;
                data->page =0;
                data ->cursor =0;
                std :: cout << data ->cursor << " kuzor "<< data->page << " list "<< std :: endl ;
                 data ->preweusl= data ->layer;
                break;
                default:
                data ->layer = data ->preweusl;
                break;
              } 
            break;
        case 2:
        // tohle mi zatím když nemám žádné další podmenu tak mi to pomáhá ABYCH SE DOSTAL Z TOHO NOVÉHO POD MENU KTERÉ vytvořím a nemám pro něj zatím žádný cod 
            data ->cursor = data -> memori [1] [0];
            data->page = data -> memori [1] [1];
            mo :: LoadDataMain (data);
            data ->layer=data ->layer -2;
            data ->preweusl=data -> layer;
            break;
        default:
            break;
        }

    }
    void drawLayer (mo:: Data * data, mo::Texts * text, mo:: Shapes *shapes)
    {
        int a=0;
        a = ((data -> memori [1] [1]*6)+data -> memori [1] [0]);
         switch (data -> layer)
        {
            case 0:
                    /***Seting of headline,*/
                    mo :: hedlainMain (data,text,shapes);
                    mo :: ArawsMain (data , shapes);
                    mo :: workMeinMenu (data, text, shapes);
                    break;
            case 1:
                switch (a)
                { 
                    
                    //tetování zda se mohu dostat do nějakého podmeníčka 
                    case 0:
                        mo :: SumaryHedlain (data, text,shapes);
                        mo :: workSummary (data, text);
                    
                    break;
                    default:
                    
                    break;
                } 
                break;
            case 2:
                break;
            default:
                break;
        }


    }
}




#endif