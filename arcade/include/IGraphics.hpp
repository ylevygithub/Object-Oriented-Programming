/*
** EPITECH PROJECT, 2020
** IGraphics.hpp
** File description:
** graphics interface
*/

#ifndef GRAPHIC_INTERFACE
#define GRAPHIC_INTERFACE

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Config.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <string>
#include <cstdlib>

using namespace sf;

const char *sfml_lib = "./lib_arcade_sfml.so";
const char *snake_game = "./lib_arcade_nibbler.so";

namespace interface
{
    class IGraphics
    {
        public:
            virtual ~IGraphics() = default;
            virtual int Move(int direction) = 0;
            virtual void SetScore(int score) = 0;
            virtual int MyEvent() = 0;
            virtual void initWindow(int height, int width, int Size, const char *gameName) = 0;
            virtual bool CheckWindow() = 0;
            virtual int ActionDuringTime() = 0;
            virtual void ClearWindow() = 0;
            virtual void SetPositionPlayerAndDrawIt(int Size, int x, int y) = 0;
            virtual void SetFruitPosAndDrawIt(int Size, int x, int y) = 0;
            virtual void DisplayWindow(void) = 0;
            virtual void HeadTouchBorder(int Size, int x, int y) = 0;
            virtual void HeadTouchBody(int x, int y, int posBodyX, int posBodyY) = 0;
            virtual void InitScreenGameOver(int height, int width, const char *gameName, int score) = 0;
            virtual void DisplayScreenGameOver() = 0;
            virtual int CheckScreenGameOver(void) = 0;
            virtual int MyEventGameOver() = 0;
            virtual void CloseWindow() = 0;
            virtual void InitText() = 0;
    };
}

typedef interface::IGraphics *(*maker_Graph)();

#endif
