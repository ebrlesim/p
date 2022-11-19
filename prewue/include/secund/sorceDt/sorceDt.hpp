#ifndef sorceDt_HPP
#define sorceDt_HPP

#include <SFML/Graphics.hpp>

namespace mo
{
    /*** structu whitch holde all necesery data */
    struct Data 
    {
        sf :: RenderWindow window;
        int start = 0;
        int stop = 1;
        int cursor = 0;
        int page = 0;
        int layer = 0;
        int preweusl = 0;
        int memori [3] [2];
         // this hold preveus layer 
        sf:: String h [20];
    };
    /*** Structurs of all shapes whitch we use **/
    struct Shapes
    {
        sf:: RectangleShape rectangle;
        sf:: RectangleShape rectangle2;
        sf::CircleShape triangle;
        sf:: CircleShape triangle2;
        sf::CircleShape Araw12;
        sf:: RectangleShape Araw22;
    };
    
    /*** structur whirtch holde all paramitrs of text and it wersins **/
    struct Texts
    {
        sf:: Text headline;
        sf:: Text menu;
        sf:: Text menu2;
        sf:: Font font;

    };
}

#endif