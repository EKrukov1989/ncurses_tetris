#pragma once

namespace Tetris
{

enum class Screen
{
    START_SCREEN,
	CUSTOM_SCREEN,
	GAME_SCREEN,
	HELP_SCREEN,
	PAUSE_SCREEN,
	GAME_OVER,	
    SMALL_SCREEN
};

enum class Event
{
	INVALID = 0,
    START,
	STOP,
	LEFT,
	RIGHT,
	UP,
	DOWN,
	LEAVE,
	ROTATE,
	CONFIRM,
	HELP,
	LAST
};


}  // namespace Tetris