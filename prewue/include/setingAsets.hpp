#ifndef setingAsets_HPP
#define setingAsets_HPP

#include <string>
#include <fstream>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "secund/sorceDt/sorceDt.hpp"

namespace mo /** mo as mother data **/
{
    
    /*** this finction set the paramistrs of al shapes whitch are youse for ewrething **/   
    void defineShapes (Shapes *shapes)
    {
        /*** arouy up **/
        shapes -> triangle.setPointCount(3);
        shapes -> triangle.setRadius(8.f);
        shapes -> triangle.setFillColor(sf::Color :: Black);
        shapes -> triangle.setOrigin(-120,-133);
       /*** arouy down **/
        shapes -> triangle2.setPointCount(3);
        shapes -> triangle2.setRadius(8.f);
        shapes ->triangle2.setFillColor(sf::Color :: Black);
        shapes -> triangle2.setOrigin(137,311);
        shapes -> triangle2.setRotation(180);
       
        shapes -> Araw12.setPointCount(3);
        shapes -> Araw12.setRadius(8.f);
        shapes ->Araw12.setFillColor(sf::Color :: White);
        shapes -> Araw12.setOrigin(168,-33);
        shapes -> Araw12.setRotation(270);
        shapes -> Araw22.setSize(sf::Vector2f(15.f,10.f));
        shapes -> Araw22.setFillColor(sf:: Color :: White);
        shapes -> Araw22.setPosition(45,155);
        /*** ractangle witche  seperate headline from the rest of text **/
        shapes -> rectangle.setSize(sf::Vector2f(205.f,2.f));
        shapes -> rectangle.setPosition(29,130);
        shapes -> rectangle.setFillColor(sf::Color :: Black);
        /*** ractangle witche  hedline positio of cursor **/
        shapes -> rectangle2.setSize(sf::Vector2f(205.f,23.f));
        shapes -> rectangle2.setFillColor(sf:: Color :: Black);
    }
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





}


#endif