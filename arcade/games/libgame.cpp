//
// EPITECH PROJECT, 2020
// arcade
// File description:
// libgame
//

#include "../include/IGraphics.hpp"
#include "../include/IGames.hpp"
using namespace interface;

class Nibbler : public IGames
{
    private :
        const char *gameName = "Nibbler Game";
        struct snake {
            int x = 30/2;
            int y = 30/2;
        }s[100];

        struct fruit {
            int x;
            int y;
        }f;
    private :
        static const int Size = 30;
        int width = Size*Size;
        int height = Size*Size;
        int body = 4;
        int direction = -1;
        int score = 0;
    public :
        virtual void start(IGraphics* Graph);
        virtual void RandomFruit(void);
        virtual void Action();
        virtual void MoveAction();
        virtual void BodyIncrease();
        virtual void SetSnakePosAndDrawIt(IGraphics *graph);
        virtual void GameLoop(IGraphics *graph);
        virtual void GameOver(IGraphics *graph);
    public :
        virtual void FirstDisplay();
};

extern "C"
{
    IGames *create()
    {
        return new Nibbler();
    }
}

void Nibbler::start(IGraphics* Graph)
{
    FirstDisplay();
    GameLoop(Graph);
}

void Nibbler::RandomFruit(void)
{
    f.x = rand() % Size;
    f.y = rand() % Size;
}

void Nibbler::GameLoop(IGraphics *graph)
{
    graph->initWindow(height, width, Size, gameName);
    RandomFruit();
    score = 0;
    while (graph->CheckWindow()) {
        score++;
        graph->SetScore(score);
        graph->MyEvent();
        if (graph->ActionDuringTime() == 1)
            Action();
        direction = graph->Move(direction);
        graph->ClearWindow();
        SetSnakePosAndDrawIt(graph);
        graph->SetFruitPosAndDrawIt(Size, f.x, f.y);
        graph->DisplayWindow();
        graph->HeadTouchBorder(Size, s[0].x, s[0].y);
        for (int i = 4; i < body; i++) {
            graph->HeadTouchBody(s[0].x, s[0].y, s[i].x, s[i].y);
        }
    }
    GameOver(graph);
}

void Nibbler::GameOver(IGraphics *graph)
{
    graph->InitScreenGameOver(height, width, gameName, score);
    while (graph->CheckScreenGameOver() == 1) {
        graph->DisplayScreenGameOver();
        if (graph->MyEventGameOver() == 1) {
            direction = -1;
            body = 4;
            s[0].x = Size/2;
            s[0].y = Size/2;
            graph->CloseWindow();
            GameLoop(graph);
        }
    }
}

void Nibbler::MoveAction()
{
    if (direction == 0)
        s[0].y -= 1;
    if (direction == 1)
        s[0].x += 1;
    if (direction == 2)
        s[0].y += 1;
    if (direction == 3)
        s[0].x -= 1;
}

void Nibbler::Action()
{
    for (int i = body; i > 0; i--) {
        s[i].x = s[i-1].x;
        s[i].y = s[i-1].y;
    }
    MoveAction();
    BodyIncrease();
}

void Nibbler::BodyIncrease()
{
    if (s[0].x == f.x && s[0].y == f.y) {
        body++;
        f.x = rand()%Size;
        f.y = rand()%Size;
    }
}

void Nibbler::SetSnakePosAndDrawIt(IGraphics *graph)
{
    for (int i = 0; i < body; i++) {
        graph->SetPositionPlayerAndDrawIt(Size, s[i].x, s[i].y);
    }
}

void Nibbler::FirstDisplay(void)
{
    std::string name;

    std::cout << "Games :\n\tNibbler\nLibraries :\n\tSFML\nScore = 0\nEntrez votre nom : ";
    std::cin >> name;
    std::cout << "Welcome " << name << " !" << std::endl;
}
