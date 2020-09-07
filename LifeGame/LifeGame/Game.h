#pragma once
#include "Parser.h"

template <class Parser, class Field, class Strategy, class Executor> class Game
{
	Parser p;
	Executor e;
	Field f;
	Strategy s;

public:

	Game();
	~Game();

	void run_game();
};

template<class Parser, class Field, class Strategy, class Executor> Game<Parser, Field, Strategy, Executor>::Game() 
	:s(f), e(f)
{
}

template<class Parser, class Field, class Strategy, class Executor> Game<Parser, Field, Strategy, Executor>::~Game()
{
}

template<class Parser, class Field, class Strategy, class Executor> void Game<Parser, Field, Strategy, Executor>::run_game()
{
	View::print_help();
	View::print_field(f, s.get_step());
	while (e.call_command(p.parser_command(), s))
	{
		View::print_field(f, s.get_step());
	}

	return;
}