##
## EPITECH PROJECT, 2020
## arcade
## File description:
## makefile
##

all:	core games graphicals

core:
	g++ cor/main.cpp -ldl -Wall -Wextra -Werror
	mv a.out arcade

games:
	g++ -fPIC -shared -o lib_arcade_nibbler.so game/libgame.cpp -Wall -Wextra -Werror
	mv lib_arcade_nibbler.so game/

graphicals:
	g++ -fPIC -shared -o lib_arcade_sfml.so lib/libgraph.cpp -lsfml-system -lsfml-audio -lsfml-window -lsfml-graphics
	mv lib_arcade_sfml.so lib/

clean:
	echo clean
fclean:
	rm lib/lib_arcade_sfml.so
	rm game/lib_arcade_nibbler.so
	rm arcade
re: fclean all
