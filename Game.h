#include <iostream>
#include <vector>
#include <ctime>
#include <sstream>
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

	Image imAge;
	Texture texTure;
	Sprite spRite;
	//Ресурсы
	Font font;

	//Текст
	Text uiText;

	//Игровая логика
	bool endGame;
	unsigned points;
	int health;
	float enemySpawnTimer;
	float enemySpawnTimerMax;
	int maxEnemies;
	bool mouseHeld;


	//ИГРОВЫЕ ОБЪЕКТЫ
	vector<RectangleShape> enemies;
	RectangleShape enemy;


	//Приват функционал
	void initVariables();
	void initWindow();
	void initFonts();
	void initText();
	void initEnemies();
	

public:
	//Конструктор
	Game();
	virtual ~Game();
	const bool running() const;
	const bool getEndGame() const;
	//функционал
	void spawnEnemy();
	void pollEvents();
	void updateMousePositions();
	void updateText();
	void updateEnemies();
	void update();
	void renderSpite(RenderTarget& target);
	void renderText(RenderTarget& target);
	void renderEnemies(RenderTarget& target);
	void render();

};

