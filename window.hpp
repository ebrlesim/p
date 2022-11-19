#ifndef WINDOW_HPP
#define WINDOW_HPP
#include <SFML/Graphics.hpp>

struct Data
    {
        sf:: RenderWindow window;
        sf:: Clock clock;
        unsigned int width;
         unsigned int height;

    };
    inline void CreateWindow(Data *data, unsigned int width, unsigned int height, const char *title)
    {
        data ->width = width;
        data ->height = height;
        data ->window.create(sf:: VideoMode (width, height), title);

    }


#endif