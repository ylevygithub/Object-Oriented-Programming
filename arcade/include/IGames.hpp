/*
** EPITECH PROJECT, 2020
** IGames.hpp
** File description:
** games interface
*/

#ifndef GAME_INTERFACE
#define GAME_INTERFACE

#include <iostream>
#include <string>
#include "IGraphics.hpp"

namespace interface
{
    class IGames
    {
        public :
            virtual void FirstDisplay() = 0;
            virtual void start(IGraphics *Graph) = 0;
            virtual void RandomFruit(void) = 0;
            virtual void Action() = 0;
            virtual void MoveAction() = 0;
            virtual void BodyIncrease() = 0;
            virtual void SetSnakePosAndDrawIt(IGraphics *graph) = 0;
            virtual void GameLoop(IGraphics *graph) = 0;
            virtual void GameOver(IGraphics *graph) = 0;
        public:
            virtual ~IGames() = default;
    };
}
typedef interface::IGames *(*maker_Game)();

#endif
