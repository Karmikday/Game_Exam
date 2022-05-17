#include "Game.h"
//функционал закрытый
void Game::initVariables()
{
	this->window = nullptr;


	//ЛОГИКА ИГРЫ
	this->endGame = false;
	this->points = 0;
	this->health = 10;
	this->enemySpawnTimerMax = 15.f;
	this->enemySpawnTimer = this->enemySpawnTimerMax;
	this->maxEnemies = 5;
	this->mouseHeld = false;
}

void Game::initWindow()
{
	this->videomode.getFullscreenModes;
	this->window = new RenderWindow(this->videomode, "AIM LAB", Style::Titlebar | Style::Fullscreen);
	this->window->setFramerateLimit(60);
	this->imAge.loadFromFile("Photos/555.jpg");
	this->texTure.loadFromImage(imAge);
	this->spRite.setTexture(texTure);
	this->spRite.setPosition(450.f,200.f);
	this->spRite.getPosition();
}
void Game::initFonts()
{
	if(this->font.loadFromFile("Fonts/CactiDisplay.otf"));
	{
		cout << "Failed to load font!" << "\n";
	}
}
void Game::initText()
{
	this->uiText.setFont(this->font);
	this->uiText.setCharacterSize(24);
	this->uiText.setFillColor(Color::White);
	this->uiText.setString("NONE");
}
void Game::initEnemies()
{
	this->enemy.setPosition(10.f,10.f);
	this->enemy.setSize(Vector2f(100.f, 100.f));
	this->enemy.setFillColor(Color::Cyan);
	/*this->enemy.setOutlineColor(Color::Green);
	this->enemy.setOutlineThickness(1.f);*/

}
//КОНСТРУКТОР
Game::Game()
{


	this->initVariables(); 
	this->initWindow();
	this->initFonts();
	this->initText();
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
const bool Game::getEndGame() const
{
	return this->endGame;
}
//функционал(Логика самой игры)

void Game::spawnEnemy()
{
	//Генерация врагов и определение цвета и позиции для них
	this->enemy.setPosition(
		static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->enemy.getSize().x)),
		0.f
	);
	//Рандом врагов
	int type = rand() % 5;
	switch (type)
	{
	case 0:
		this->enemy.setSize(Vector2f(20.f, 20.f));
		this->enemy.setFillColor(Color::Magenta);
		break;
	case 1:
		this->enemy.setSize(Vector2f(30.f, 30.f));
		this->enemy.setFillColor(Color::Blue);
		break;
	case 2:
		this->enemy.setSize(Vector2f(50.f, 50.f));
		this->enemy.setFillColor(Color::Cyan);
		break;
	case 3:
		this->enemy.setSize(Vector2f(70.f, 70.f));
		this->enemy.setFillColor(Color::Red);
		break;
	case 4:
		this->enemy.setSize(Vector2f(100.f, 100.f));
		this->enemy.setFillColor(Color::Green);
		break;
	default:
		this->enemy.setSize(Vector2f(100.f, 100.f));
		this->enemy.setFillColor(Color::Yellow);
		break;
	}
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

void Game::updateText()
{
	stringstream ss;
	ss << "Points: " << this->points << "\n"
		<< "Health: " << this->health << "\n";
	this->uiText.setString(ss.str());
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
	//Движение и обновление врагов
	
	for (int i = 0; i < this->enemies.size(); i++)
	{
		bool deleted = false;

		this->enemies[i].move(0.f, 3.f);

		if (this->enemies[i].getPosition().y > this->window->getSize().y)
		{
			this->enemies.erase(this->enemies.begin() + i);
			this->health -= 1;
			cout << "Health: " << this->health << "\n";
		}
	}
	//Проверка на нажатие по врагу
	
	if (Mouse::isButtonPressed(Mouse::Left))
	{
		if (this->mouseHeld == false)
		{
			this->mouseHeld = true;
			bool deleted = false;
			for (size_t i = 0; i < this->enemies.size() && deleted == false; i++)
			{
				if (this->enemies[i].getGlobalBounds().contains(this->mousePostView))
				{
					//Наши очки
					if (this->enemies[i].getFillColor() == Color::Magenta)
						this->points += 10;
					else if (this->enemies[i].getFillColor() == Color::Blue)
						this->points += 7;
					else if (this->enemies[i].getFillColor() == Color::Cyan)
						this->points += 5;
					else if (this->enemies[i].getFillColor() == Color::Red)
						this->points += 3;
					else if (this->enemies[i].getFillColor() == Color::Green)
						this->points += 1;
					cout << "Points: " << this->points << "\n";
					//Удаляем врага
					deleted = true;
					this->enemies.erase(this->enemies.begin() + i);
				}
			}
		}
	}
	else
	{
		this->mouseHeld = false;
	}
}

void Game::update()
{
	this->pollEvents();
	if (this->endGame == false)
	{
		this->updateMousePositions();
		this->updateText();
		this->updateEnemies();
	}
	//КОНЕЦ ИГРЫ
	if (this->health <= 0)
		this->endGame = true;
}

void Game::renderSpite(RenderTarget& target)
{
	target.draw(this->spRite);
}

void Game::renderText(RenderTarget& target)
{
	target.draw(this->uiText);
}

void Game::renderEnemies(RenderTarget& target)
{
	for (auto& e : this->enemies)
	{
		target.draw(e);
	}
}


void Game::render()
{
	this->window->clear();
	//ПРОРИСОВКА ОКНА
	this->renderSpite(*this->window);
	this->renderEnemies(*this->window);
	this->renderText(*this->window);
	this->window->display();
	

}


