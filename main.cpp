#include <iostream>
#include "Game.h"
using namespace std;
using namespace sf;
int main()
{
	//рандом
	srand(static_cast<unsigned>(time(0)));
	//Наше окно
	Game game;
	// Цикл
	while (game.running() && !game.getEndGame())
	{

		//Добовление+
		game.update();
		//Обработка
		game.render();
	
	}
	//Конец игры
	return 0;
}