#include "Model.h"
#include "Views/View.h"
#include "EventQueue.h"

namespace Tetris
{

Model::Model(View& v, EventQueue& eq)
    : view_(v)
    , queue_(eq)
{
}

void Model::process_event(EventQueue::EventInfo)
{
}

} // namespace Tetris
