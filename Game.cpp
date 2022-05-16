#include "Game.h"
//ôóíêöèîíàë çàêğûòûé
void Game::initVariables()
{
	this->window = nullptr;
}

void Game::initWindow()
{
	this->videomode.height = 800;
	this->videomode.width = 1280;
	this->window = new RenderWindow(this->videomode, "FIRST GAME", Style::Titlebar | Style::Close);
}
//ÊÎÍÑÒĞÓÊÒÎĞ
Game::Game()
{

	this->initVariables(); 
	this->initWindow();
}

Game::~Game()
{
	delete this->window;
}

const bool Game::running() const
{
	return this->window->isOpen();
}
//ôóíêöèîíàë(Ëîãèêà ñàìîé èãğû)

void Game::pollEvents()
{
	//Îáğàáîòêà äåéñòâèé
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

void Game::update()
{
	this->pollEvents();

}
void Game::render()
{
	this->window->clear(Color::Red);

	//ÏĞÎĞÈÑÎÂÊÀ ÎÊÍÀ
	this->window->display();

}

