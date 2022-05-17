#include "Game.h"
//функционал закрытый
void Game::initVariables()
{
	this->window = nullptr;


	//ЛОГИКА ИГРЫ
	this->points = 0;
	this->enemySpawnTimerMax = 10.f;
	this->enemySpawnTimer = this->enemySpawnTimerMax;
	this->maxEnemies = 5;
}

void Game::initWindow()
{
	this->videomode.height = 800;
	this->videomode.width = 1280;
	this->window = new RenderWindow(this->videomode, "AIM LAB", Style::Titlebar | Style::Close);
	this->window->setFramerateLimit(60);
}
void Game::initEnemies()
{
	this->enemy.setPosition(10.f,10.f);
	this->enemy.setSize(Vector2f(100.f, 100.f));
	this->enemy.setScale(Vector2f(0.5f, 0.5f));
	this->enemy.setFillColor(Color::Cyan);
	/*this->enemy.setOutlineColor(Color::Green);
	this->enemy.setOutlineThickness(1.f);*/

}
//КОНСТРУКТОР
Game::Game()
{

	this->initVariables(); 
	this->initWindow();
	this->initEnemies();
}

Game::~Game()
{
	delete this->window;
}

const bool Game::running() const
{
	return this->window->isOpen();
}
//функционал(Логика самой игры)

void Game::spawnEnemy()
{
	//Генерация врагов и определение цвета и позиции для них
	this->enemy.setPosition(
		static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->enemy.getSize().x)),
		0.f
	);
	this->enemy.setFillColor(Color::Green);
	//Генерация врагов
	this->enemies.push_back(this->enemy);
}

void Game::pollEvents()
{
	//Обработка действий
	while (this->window->pollEvent(this->proc))
	{
		switch (this->proc.type)
		{
		case Event::Closed:
			this->window->close();
			break;
		case Event::KeyPressed:
			if (this->proc.key.code == Keyboard::Escape)
				this->window->close();
			break;
		}
	}
}

void Game::updateMousePositions()
{
	this->mousePosWindow = Mouse::getPosition(*this->window);
	this->mousePostView = this->window->mapPixelToCoords(this->mousePosWindow);
}

void Game::updateEnemies()
{
	//Обновление таймера для генерации врагов
	if (this->enemies.size() < this->maxEnemies)
	{
		if (this->enemySpawnTimer >= this->enemySpawnTimerMax)
		{
			//Генерация врагов и сброс таймера
			this->spawnEnemy();
			this->enemySpawnTimer = 0.f;
		}
		else
			this->enemySpawnTimer += 1.f;
	}
	//Движение врагов
	for (int i = 0; i < this->enemies.size(); i++)
	{
		this->enemies[i].move(0.f, 1.f);

		//Проверка на нажатие по врагу
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (this->enemies[i].getGlobalBounds().contains(this->mousePostView))
			{
				this->enemies.erase(this->enemies.begin() + i);
			}
		}
	}
}

void Game::update()
{
	this->pollEvents();

	this->updateMousePositions();

	this->updateEnemies();

}

void Game::renderEnemies()
{
	for (auto& e : this->enemies)
	{
		this->window->draw(e);
	}
}


void Game::render()
{
	this->window->clear();
	//ПРОРИСОВКА ОКНА
	this->renderEnemies();
	this->window->display();

}

