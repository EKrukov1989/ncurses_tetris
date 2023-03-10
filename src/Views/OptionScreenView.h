#pragma once
#include <vector>
#include <string>

namespace Tetris
{

class OptionScreenView
{
    ~OptionScreenView();
protected:
    static bool show(const std::vector<std::string>& options, int chosen_option = -1);
};

}  // namespace Tetris
