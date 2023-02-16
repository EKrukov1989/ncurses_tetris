#include "GameoverScreenView.h"
#include <ncurses.h>
#include <string>
#include <sstream>

namespace Tetris
{

bool GameoverScreenView::show(Scores scores)
{
    std::vector<std::string> text = { "GAME OVER" };
    text.push_back( "" );
    text.push_back( std::string("speed: ") + std::to_string(scores.final_speed) );
    text.push_back( std::string("lines: ") + std::to_string(scores.lines) );
    text.push_back( std::string("score: ") + std::to_string(scores.score) );
    return OptionScreenView::show(text);
}

}  // namespace Tetris
