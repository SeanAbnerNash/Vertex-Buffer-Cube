#include <Game.h>
//@Author Sean Nash De Andrade
//@Login C00217019
//Cube Buffer Assignment
//Known Issues: The Scaling has a distorting effect on the cube. Translation breaks apart the cube. Unsure as to the cause.
int main(void)
{
	Game& game = Game();
	game.run();
}