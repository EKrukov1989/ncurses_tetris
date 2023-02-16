#pragma once
#include "IScreenModel.h"
#include "Enums.h"

namespace Tetris
{

class StartScreenModel : public IScreenModel
{
public:
    StartScreenOption get_state() const;
    virtual Tetris::Screen process_event(const EventInfo&);
};

}  // namespace Tetris