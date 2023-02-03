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

    std::size_t show(std::size_t line_index);

    void prepare_text_();
};

}  // namespace Tetris
