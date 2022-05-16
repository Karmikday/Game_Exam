#include "Game.h"
//���������� ��������
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
//�����������
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
//����������(������ ����� ����)

void Game::pollEvents()
{
	//��������� ��������
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

	//���������� ����
	this->window->display();

}

