#include <iostream>
#include "Game.h"
using namespace std;
using namespace sf;
int main()
{
	//������
	srand(static_cast<unsigned>(time(0)));
	//���� ����
	Game game;
	// ����
	while (game.running() && !game.getEndGame())
	{

		//����������+
		game.update();
		//���������
		game.render();
	
	}
	//����� ����
	return 0;
}