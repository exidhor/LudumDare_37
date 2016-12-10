#include "Game.hpp"

Game::Game()
	: m_window(sf::VideoMode(1280, 768), "LD 37"),
	m_shape(100.f)
{
	m_shape.setFillColor(sf::Color::Green);
}

void Game::gameLoop()
{
	handleInput();

	draw();
}

void Game::handleInput()
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			m_window.close();
	}
}

void Game::draw()
{
	m_window.clear();
	m_window.draw(m_shape);
	m_window.display();
}

bool Game::windowIsOpen() const
{
	return m_window.isOpen();
}