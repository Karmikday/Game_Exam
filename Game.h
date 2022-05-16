#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
using namespace std;
using namespace sf;
class Game
{
private:
	RenderWindow* window;
	Event proc;
	void initVariables();
	void initWindow();

public:
	//�����������
	Game();
	virtual ~Game();

	//����������
	void update();
	void render();

};

