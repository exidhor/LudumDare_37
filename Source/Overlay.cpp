//
// Created by Kraghan on 11/12/2016.
//

#include <cstdlib>
#include <iostream>
#include <time.h>
#include "Overlay.hpp"

/* Explicit */ Overlay::Overlay()
{
    m_randomMessage.push_back("Wow, such spam");
    m_randomMessage.push_back(".:H4CK3D_BY_FOX_M4C_T4G:.");
    m_randomMessage.push_back("Ping... Pong");
    m_randomMessage.push_back("Mama mia !");
    m_randomMessage.push_back("Let's build a wall... A firewall !");
}

/* Virtual */ Overlay::~Overlay()
{

}

bool Overlay::isOverlayPhase()
{
    return m_nextOverlayPhaseIn == 0 && m_overlayPhase;
}

void Overlay::prepareNextOverlayEvent()
{
    m_nextOverlayPhaseIn = rand() % (m_NEXT_OVERLAY_PHASE_MAX-m_NEXT_OVERLAY_PHASE_MIN+1) + m_NEXT_OVERLAY_PHASE_MIN;
    m_overlayKey = rand() % 36;
    m_overlayPhase = true;
    m_randomMessageId = rand() % m_randomMessage.size();
}

char Overlay::getCharFromKeyCode()
{
    if(m_overlayKey < 26)
        return (char) ('A' + m_overlayKey);

    return (char) ('0' + (m_overlayKey - 26));
}

void Overlay::updateOverlayCounter()
{
    --m_nextOverlayPhaseIn;
}

int Overlay::getKeycode()
{
    return m_overlayKey;
}

std::string Overlay::getRandomMessage()
{
    return m_randomMessage[m_randomMessageId];
}

void Overlay::endPhase()
{
    m_overlayPhase = false;
}
