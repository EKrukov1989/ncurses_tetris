#pragma once
#include <string>
#include <vector>

namespace Tetris
{
class View;

class HelpScreenView
{
    friend class View;
public:
    HelpScreenView();

private:
    std::vector<std::string> prepared_text_;
    std::size_t prepared_text_width_ = 1;

    // next function shows some help-text that hardcoded inside view.
    // "line_index" - defines the part of the text, that will be shown on the screen.
    // max_pos - maximal possible line index.
    bool show(std::size_t line_index, std::size_t& max_pos);

    void prepare_text_();
};

}  // namespace Tetris
