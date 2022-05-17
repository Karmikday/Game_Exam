#pragma once
#include <iostream>
#include <vector>
#include <ctime>
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
	//ОТвечают за окна(интерфейс)
	RenderWindow* window;
	VideoMode videomode;
	Event proc;

	//Позиция мышки
	Vector2i mousePosWindow;
	Vector2f mousePostView;



	//Игровая логика
	int points;
	float enemySpawnTimer;
	float enemySpawnTimerMax;
	int maxEnemies;


	//ИГРОВЫЕ ОБЪЕКТЫ
	vector<RectangleShape> enemies;
	RectangleShape enemy;


	//Приват функционал
	void initVariables();
	void initWindow();
	void initEnemies();

public:
	//Конструктор
	Game();
	virtual ~Game();
	const bool running() const;
	//функционал
	void spawnEnemy();
	void pollEvents();
	void updateMousePositions();
	void updateEnemies();
	void update();
	void renderEnemies();
	void render();

};

