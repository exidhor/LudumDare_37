#include "Game.hpp"
#include "GameState/MenuState.hpp"

Game::Game()
: m_window(sf::VideoMode(1280, 768), "LD 37")
, m_shape(100.f)
{
	m_shape.setFillColor(sf::Color::Green);
}

void Game::Init()
{
    // Singleton, bitch please
    MenuState::Instance()->init();

    // Push the first state ! An awesome menu \o/
    StateMachine::Instance()->pushState(MenuState::Instance());

    // Set the framerate limit
    m_window.setFramerateLimit(60);
}

void Game::gameLoop(double time)
{
    // Processing inputs
	handleInput(time);

    // Updating the top state
    StateMachine::Instance()->update(time);

    // Render the top state
	draw();
}

void Game::handleInput(double elapsed)
{
	sf::Event event;
	while (m_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			m_window.close();

        // Process input of the top state
        StateMachine::Instance()->onPollEvent(event, elapsed);
	}
}

void Game::draw()
{
    // Clearing buffer
	m_window.clear();

    // Draw in the buffer the state at the top
    // of the state machine
	StateMachine::Instance()->render(m_window);

    // Swap buffer
	m_window.display();
}

bool Game::windowIsOpen() const
{
	return m_window.isOpen();
}
