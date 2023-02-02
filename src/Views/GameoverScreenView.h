#pragma once
#include "OptionScreenView.h"

namespace Tetris
{

class View;

class GameoverScreenView : private OptionScreenView
{
    friend class View;
public:
    struct Scores
    {
        unsigned final_speed = 0;
        unsigned lines = 0;
        unsigned score = 0;
    };

private:
    static void show(Scores);
};

}  // namespace Tetris
