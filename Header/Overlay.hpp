//
// Created by Kraghan on 11/12/2016.
//

#ifndef LUDUMDARE_OVERLAY_HPP
#define LUDUMDARE_OVERLAY_HPP


#include <string>
#include <vector>

class Overlay
{
    //------------------------------------------------------------------------------------------------------------------
    /// Public members
    //------------------------------------------------------------------------------------------------------------------
public:

    static const long   m_OVERLAY_REWARD = 1000;

    explicit            Overlay                 ();
    virtual             ~Overlay                ();

    bool                isOverlayPhase          ();
    void                prepareNextOverlayEvent ();
    char                getCharFromKeyCode      ();
    void                updateOverlayCounter    ();
    int                 getKeycode              ();
    std::string         getRandomMessage        ();
    void                endPhase                ();
    //------------------------------------------------------------------------------------------------------------------
    /// Protected members
    //------------------------------------------------------------------------------------------------------------------
protected:

    //------------------------------------------------------------------------------------------------------------------
    /// Private members
    //------------------------------------------------------------------------------------------------------------------
private:
    int                     m_nextOverlayPhaseIn;
    int                     m_overlayKey;
    bool                    m_overlayPhase;
    int                     m_randomMessageId;

    const int               m_NEXT_OVERLAY_PHASE_MAX = 7;
    const int               m_NEXT_OVERLAY_PHASE_MIN = 5;

    std::vector<std::string> m_randomMessage;
};


#endif //LUDUMDARE_OVERLAY_HPP
