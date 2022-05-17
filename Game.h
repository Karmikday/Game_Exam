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
	//�������� �� ����(���������)
	RenderWindow* window;
	VideoMode videomode;
	Event proc;

	//������� �����
	Vector2i mousePosWindow;
	Vector2f mousePostView;



	//������� ������
	int points;
	float enemySpawnTimer;
	float enemySpawnTimerMax;
	int maxEnemies;


	//������� �������
	vector<RectangleShape> enemies;
	RectangleShape enemy;


	//������ ����������
	void initVariables();
	void initWindow();
	void initEnemies();

public:
	//�����������
	Game();
	virtual ~Game();
	const bool running() const;
	//����������
	void spawnEnemy();
	void pollEvents();
	void updateMousePositions();
	void updateEnemies();
	void update();
	void renderEnemies();
	void render();

};

