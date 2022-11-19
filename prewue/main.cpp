#include <SFML/Graphics.hpp>

#include "mother.hpp"
using namespace sf;



/** loading data for rest of  **/



int main ()
{
   mo :: Data *data = new mo::Data();
   mo :: Texts *text = new mo:: Texts();
   mo :: Shapes *shapes = new mo :: Shapes();
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
    mo :: defineShapes ( shapes);
    //error abyout bead sorcing of font
    int error = 0;
    error = mo:: seting_fonts (text);
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
            /*** mais presing findig if and wher is mouse presed **/
            if (e.type == Event :: MouseButtonPressed)
            {
                if (e.key.code == Mouse ::Left)  // ther is a warning eventhou the e event is redifang asd Mouse button
                {
                    position [0] = pos.x;
                    position [1] = pos.y;
                }
            }
            if (special !=0)
            /*** chekíing the validitio of mous position */
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
        /*** Draw all neceseri asets, you nead to draw bag graund befour then you display words, all stact. First you draw baggraound than over thet you displad all text or grafs **/
        data -> window.draw(s);
        data -> window.draw(sUp);
        data -> window.draw(sDown);
        data -> window.draw(sEntr);
        
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
                            ;
                        }
                    }
                }
                else if (position [0] > 174 && position [0] < 240 )
                
                {
                    std:: cout << data->page << " " << data ->cursor << std :: endl;
                    data -> layer ++; 
                    position [0] = 0;
                    position [1] = 0;
                }
            }
        
        if (special == 0)
        {
            mo :: LoadDataMain (data);
            special = 1; 
        }
        if (data -> layer != data->preweusl)
        {
            mo :: DMAEntr (data, text, shapes);
        }
        else 
        {
            mo :: drawLayer (data, text, shapes);
        }
        
        
        
        
    
        

        data -> window.display();

    }
    delete text;
    delete shapes;
    delete data;
    return 0;
}