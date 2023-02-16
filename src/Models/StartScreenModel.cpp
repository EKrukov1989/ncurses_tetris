#include "StartScreenModel.h"

namespace Tetris
{

StartScreenOption StartScreenModel::get_state() const
{
    return StartScreenOption::START;
}

Tetris::Screen StartScreenModel::process_event(const EventInfo&)
{
    return Screen::INVALID;
}

}  // namespace Tetris
