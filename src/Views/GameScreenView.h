#pragma once
#include <vector>
#include "Colors.h"

namespace Tetris
{

class GameScreenView
{
    friend class View;
public:
    struct State
    {
        std::vector<std::vector<TetrisColor>> game_rect;
        std::vector<std::vector<TetrisColor>> next_tetr;  // tetr stands for tetraminoe
        unsigned speed = 0;
        unsigned lines = 0;
        unsigned score = 0;
        unsigned timer = 0;
    };

private:
    static bool show(State);
};

}  // namespace Tetris
