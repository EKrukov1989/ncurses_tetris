#pragma once

namespace Tetris
{

enum class Screen
{
	INVALID = 0,
    START_SCREEN,
	CUSTOM_SCREEN,
	GAME_SCREEN,
	HELP_SCREEN,
	PAUSE_SCREEN,
	GAME_OVER,	
    SMALL_SCREEN,
	LAST
};

enum class StartScreenOption
{
	START,
	CUSTOM,
	HELP,
	QUIT
};

enum class Event
{
	INVALID = 0,
	STOP,
	LEFT,
	RIGHT,
	UP,
	DOWN,
	LEAVE,
	ROTATE,
	CONFIRM,
	PAUSE,
	HELP,
	RESIZE,
	LAST
};

enum class ApplicationError
{
	FINISHED_SUCCESSFULLY = 0,
	NOCOLORS
};


}  // namespace Tetris