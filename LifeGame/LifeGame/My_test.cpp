#include "Game.h"

int main(int argc, char** argv)
{
	Game<Parser, Field, Strategy, Executor> life;
	life.run_game();
}