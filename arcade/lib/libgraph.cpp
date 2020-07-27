/*
** EPITECH PROJECT, 2020
** arcade
** File description:
** lib graphic
*/

#include "../include/IGames.hpp"
#include "../include/IGraphics.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Config.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <cstdlib>

using namespace interface;
using namespace sf;

class SFML : public IGraphics
{
    private :
        RenderWindow *win;
        RenderWindow *winGameOver;
        RectangleShape box;
        RectangleShape apple;
        Clock timer;
        std::string scorestr;
        Text text;
        Text text2;
        Text text3;
        Font font;
        Font font2;
        Font font3;
    public :
        virtual int Move(int direction);
        virtual void SetScore(int score);
        virtual int MyEvent();
        virtual void initWindow(int height, int width, int Size, const char *gameName);
        virtual bool CheckWindow();
        virtual int ActionDuringTime();
        virtual void ClearWindow();
        virtual void SetPositionPlayerAndDrawIt(int Size, int x, int y);
        virtual void SetFruitPosAndDrawIt(int Size, int x, int y);
        virtual void DisplayWindow(void);
        virtual void HeadTouchBorder(int Size, int x, int y);
        virtual void HeadTouchBody(int x, int y, int posBodyX, int posBodyY);
        virtual void InitScreenGameOver(int height, int width, const char *gameName, int score);
        virtual void DisplayScreenGameOver();
        virtual int CheckScreenGameOver(void);
        virtual int MyEventGameOver();
        virtual void CloseWindow(void);
        virtual void InitText();
};

extern "C"
{
    IGraphics *create()
    {
        return new SFML();
    }
}

void SFML::initWindow(int height, int width, int Size, const char *gameName)
{
    win = new RenderWindow(VideoMode(width, height), gameName, Style::Default);
    win->setFramerateLimit(60);

    box = RectangleShape(Vector2f(Size, Size));
    box.setFillColor(Color::Red);

    apple = RectangleShape(Vector2f(Size, Size));
    apple.setFillColor(Color::Green);
}

bool SFML::CheckWindow(void)
{
    return (win->isOpen());
}

void SFML::SetScore(int score)
{
    Text text;
    Font font;
    font.loadFromFile("font/mikado.OTF");
    Vector2f pos_over = {50, 20};
    std::string scorestr = std::to_string(score);

    text.setPosition(pos_over);
    text.setString("SCORE : " + scorestr);
    text.setFont(font);
    text.setCharacterSize(30);
    text.setFillColor(Color::Magenta);
    win->draw(text);
    win->display();
}

int SFML::MyEvent()
{
    Event event;

    while (win->pollEvent(event)) {
        switch (event.type)
        {
        case Event::KeyReleased:
            if (event.key.code == Keyboard::Escape)
                win->close();
            if (event.key.code == Keyboard::R)
                return (1);
            if (event.key.code == Keyboard::P)
                win->waitEvent(event);
/*          if (event.key.code == Keyboard::A)
                changer l intance en 2 eme parametre de dlsym qui
                pour l instant est affilié a create qui est dans le extern C
                de SFML en par exemple libcacaCreate qui serait dans le extern C de libcaca.cpp
                qui génèrerait le .so de libcaca et le dlsym serait donc relier a libcaca.cpp et
                plus a libgraph.cpp (SFML)*/
            break;
        }
    }
    return (0);
}

int SFML::ActionDuringTime(void)
{
    if (timer.getElapsedTime().asMilliseconds() > 100) {
        timer.restart();
        return (1);
    }
    return (0);
}

void SFML::ClearWindow(void)
{
    win->clear();
}

int SFML::Move(int direction)
{
    if (Keyboard::isKeyPressed(Keyboard::Up)) return 0;
    if (Keyboard::isKeyPressed(Keyboard::Right)) return 1;
    if (Keyboard::isKeyPressed(Keyboard::Down)) return 2;
    if (Keyboard::isKeyPressed(Keyboard::Left)) return 3;
    return (direction);
}

void SFML::SetPositionPlayerAndDrawIt(int Size, int x, int y)
{
    box.setPosition(x * Size, y * Size);
    win->draw(box);
}

void SFML::SetFruitPosAndDrawIt(int Size, int x, int y)
{
    apple.setPosition(x * Size, y * Size);
    win->draw(apple);
}

void SFML::DisplayWindow(void)
{
    win->display();
}

void SFML::HeadTouchBorder(int Size, int x, int y)
{
    if (x < 0 || x > Size-1 || y < 0 || y > Size-1)
        win->close();
}

void SFML::HeadTouchBody(int x, int y, int posBodyX, int posBodyY)
{
    if (x == posBodyX && y == posBodyY)
        win->close();
}

void SFML::InitScreenGameOver(int height, int width, const char *gameName, int score)
{
    delete win;
    winGameOver = new RenderWindow(VideoMode(width, height), gameName, Style::Default);
    winGameOver->setFramerateLimit(60);
    scorestr = std::to_string(score);
    InitText();
}

void SFML::InitText()
{
    Vector2f pos_over = {150, 100};
    const char *str = "\n\nClick R to restart the Game \n\nOr Esc to End it";
    const char *str2 = "\n\nClick P during the game to pause the game";

    font.loadFromFile("font/arial.ttf");
    text.setPosition(pos_over);
    text.setString("Game Over\n\t Score : " + scorestr + str + str2);
    text.setFont(font);
    text.setCharacterSize(30);
    text.setFillColor(Color::Magenta);
}

void SFML::DisplayScreenGameOver()
{
    winGameOver->draw(text);
    winGameOver->draw(text2);
    winGameOver->draw(text3);
    winGameOver->display();
}

int SFML::CheckScreenGameOver(void)
{
    if (winGameOver->isOpen())
        return (1);
    return (0);
}

int SFML::MyEventGameOver()
{
    Event event;

    while (winGameOver->pollEvent(event)) {
        switch (event.type)
        {
        case Event::KeyReleased:
            if (event.key.code == Keyboard::Escape)
                winGameOver->close();
            if (event.key.code == Keyboard::R)
                return (1);
            if (event.key.code == Keyboard::P)
                winGameOver->waitEvent(event);
/*          if (event.key.code == Keyboard::A)
                changer l intance en 2 eme parametre de dlsym qui
                pour l instant est affilié a create qui est dans le extern C
                de SFML en par exemple libcacaCreate qui serait dans le extern C de libcaca.cpp
                qui génèrerait le .so de libcaca et le dlsym serait donc relier a libcaca.cpp et
                plus a libgraph.cpp (SFML)*/
            break;
        }
    }
    return (0);
}

void SFML::CloseWindow(void)
{    
    winGameOver->close();
    delete winGameOver;
}
