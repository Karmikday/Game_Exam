#include <iostream>
#include "Game.h"
using namespace std;
using namespace sf;

int main()
{
	//Наше окно
	Game game;
	// Цикл
	while (game.running())
	{
		//Добовление+
		game.update();
		//Обработка
		game.render();
	
	}
	//Конец игры
	return 0;
}