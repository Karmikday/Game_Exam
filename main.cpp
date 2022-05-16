#include <iostream>
#include "Game.h"
using namespace std;
using namespace sf;

int main()
{
	//���� ����
	RenderWindow window(VideoMode(1280, 800), "FIRST GAME", Style::Titlebar | Style::Close);
	Event proc;
	// ����
	while (window.isOpen())
	{
		//��������
		while (window.pollEvent(proc))
		{
			switch (proc.type)
			{
			case Event::Closed:
			{
				window.close();
			}break;
			case Event::KeyPressed:
			{
				if (proc.key.code == Keyboard::Escape)
				{
					window.close();
				}
			}break;
			}
		}
		//���������
		window.clear(Color::Black);
		window.display();
	}
	//����� ����
	return 0;
}