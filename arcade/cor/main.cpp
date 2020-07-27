//
// EPITECH PROJECT, 2020
// arcade
// File description:
// main function
//

#include "../include/IGames.hpp"
#include "../include/IGraphics.hpp"
#include <string.h>
#include <dlfcn.h>
using namespace interface;

IGames *my_open_libGame(const char *str)
{
    void *func;
    maker_Game pm;
    void *hndl = dlopen(str, RTLD_LAZY);

    func = dlsym(hndl, "create");
    if (func == NULL || hndl == NULL)
    {
        printf("erreur dlsym : %s\n", dlerror());
        exit (84);
    }
    pm = (maker_Game)func;
    IGames *mine = pm();
    return (mine);
}

IGraphics *my_open_libGraph(const char *str)
{
    void *func;
    maker_Graph pm;
    void *hndl = dlopen(str, RTLD_LAZY);

    func = dlsym(hndl, "create");
    if (func == NULL || hndl == NULL)
    {
        printf("erreur dlsym : %s\n", dlerror()); 
        exit(84);
    }
    pm = (maker_Graph)func;
    IGraphics *mine = pm();
    return (mine);
}

void wrongParth(char **av)
{
    if (strcmp(av[1], "./lib/lib_arcade_sfml.so") != 0) {
        fprintf(stderr, "wrong path to the library\n");
        exit(84);
    }
}

int main(int ac, char **av)
{
    IGraphics *Graph;
    IGames *Game;

    if (ac != 2)
        exit(84);
    wrongParth(av);
    Graph = my_open_libGraph(av[1]);
    Game = my_open_libGame("./game/lib_arcade_nibbler.so");
    Game->start(Graph);
    free(Game);
    free(Graph);
    dlclose(Game);
    dlclose(Graph);
    return (0);
}
