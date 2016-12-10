/*!
 * \file BasicInterface.hpp
 * \brief Super class for Interfaces
 * \author Aredhele
 * \version 0.1
 * \date 2015-12-26
 */

#ifndef DEF_BASIC_INTERFACE_HPP
#define DEF_BASIC_INTERFACE_HPP

#include "Utils/Updatable.hpp"

#include "Interface/NPanel.hpp"
#include "Interface/NLabel.hpp"
#include "Interface/NButton.hpp"
#include "Interface/NTextField.hpp"
#include "Interface/InputHandler.hpp"
#include "Interface/AnimatableObject.hpp"

class BasicInterface : public Updatable
{
public:

    /*!
     * \brief Constructor
     * \param ptr_managerGroup
     */
    BasicInterface(bool debug, InputHandler * inputHandler);

    /*!
     * \brief Destructor
     */
    virtual ~BasicInterface();

    /*!
     * \brief Draw all object on the window
     * \param window The surface to draw
     * \param visualObjectList The list of object to draw
     */
    void basicDraw(sf::RenderWindow * window);

    /*!
     * Update
     * \param elapsed
     */
    void basicUpdate(double elapsed);

    /*!
     * \brief Handle inputs of the basics Interfaces
     * \param e The current event to handle
     * \param frameTime TimeElapsed since last iteration
     */
    void basicInput(sf::Event & event);

    /*!
     * \brief Allow the acces on the main panel
     * \return m_contentPane The reference on the main panel
     */
    NPanel * getContentPane();

    /*!
     * \brief Replace the current main panel
     * \param pane The pointeur on the panel
     * \return None
     */
    void setContentPane(NPanel * pane);

protected:

    bool m_debug;
    bool m_optionActive;
    InputHandler * m_inputHandler;

private:
    NPanel m_contentPane;

    std::vector < VisualObject * > m_Interfaces;

    /*!
     * \brief Update all component
     * \param frameTime Time elapsed since last frame
     */
    void updateInterfaces(double frameTime);
};

#endif // DEF_BASIC_INTERFACE_HPP