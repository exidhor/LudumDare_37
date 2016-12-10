#ifndef __PAUSE_VIEW_HPP
#define __PAUSE_VIEW_HPP

#include "Interface/BasicInterface.hpp"

class PauseView : public BasicInterface
{
public:

    /// \brief Constructor
    /// \param debug Debug value
    /// \param inputHandler The controller
    explicit PauseView(bool debug, InputHandler * inputHandler);

    /// \brief Destructor
    virtual ~PauseView();

    /// \brief Update the menu
    /// \param elapsed The elapsed time
    virtual void update(double elapsed);

    /// \param e The event
    /// \param frameTime
    virtual void processInput(sf::Event & e);

    /// \param w The window
    virtual void draw(sf::RenderWindow * w);

private:

    NButton m_resume;
    NButton m_len1;
    NButton m_len2;
    NButton m_len3;
};

#endif // __PAUSE_VIEW_HPP

