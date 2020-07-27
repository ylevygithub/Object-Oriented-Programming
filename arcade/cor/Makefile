##
## EPITECH PROJECT, 2020
## arcade
## File description:
## Makefile
##

all:
	g++ -fPIC -shared -o lib_arcade_sfml.so ../lib/libgraph.cpp -lsfml-system -lsfml-audio -lsfml-window -lsfml-graphics
	g++ -fPIC -shared -o lib_arcade_nibbler.so ../game/libgame.cpp
	g++ main.cpp -ldl
	mv a.out arcade
	mv arcade ..
	mv lib_arcade_nibbler.so ../game/
	mv lib_arcade_sfml.so ../lib/
