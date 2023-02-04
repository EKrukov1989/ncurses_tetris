#include "CustomScreenView.h"
#include <ncurses.h>

namespace
{

// Content and order of strings in next array must correspond with enum in the header!
// This strings don't contain numeral values, because numeral vaoues will be added later.
// Values added insead of dots in the end of the line. For example: speed.... -> speed..10
const std::vector<std::string> opts = { " start custom game ",
                                        " speed............ ",
                                        " height........... ",
                                        " width............ ",
                                        "       back        " };

}  // nameless namespace

void s_insert_settings_in_template(std::vector<std::string>& opts,
                                   Tetris::CustomScreenView::Settings settings)
{
    auto add_in_the_end = [](std::string& line, unsigned num)
    {
        auto nstr = std::to_string(num);
        auto start = line.size() - nstr.size() - 1;
        for (int i = 0; i < nstr.size(); ++i)
            line[start + i] = nstr[i];
    };

    add_in_the_end(opts[int(Tetris::CustomScreenView::Option::SPEED)], settings.speed);
    add_in_the_end(opts[int(Tetris::CustomScreenView::Option::HEIGHT)], settings.height);
    add_in_the_end(opts[int(Tetris::CustomScreenView::Option::WIDTH)], settings.width);
}

namespace Tetris
{

void CustomScreenView::show(Option option, Settings settings)
{
    std::vector<std::string> opts_copy = opts;
    s_insert_settings_in_template(opts_copy, settings);
    OptionScreenView::show(opts_copy, int(option));
}

}  // namespace Tetris
