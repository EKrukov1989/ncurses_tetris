#pragma once

namespace Tetris
{
class View;

class StartScreenView
{
    friend class View;
public:
    enum class Option
    {
        START,
        CUSTOM,
        HELP,
        QUIT
    };
private:
    static void show_with_option(Option option);
};

}  // namespace Tetris
