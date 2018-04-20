// ***************************************************************************
// main
// ***************************************************************************
#include "game.h"

// ---------------------------------------------------------------------------
// at system startup, a cold reset is performed
// cold reset: the vectrex logo is shown, all ram data is cleared
// if the reset button is pressed, then a warm reset is performed
// warm reset: skip vectrex logo and keep ram data
// after each reset, the game title screen is shown and then main() is called

// start of program code
int main(void)
{
	return Game();
}

// ***************************************************************************
// end of file
// ***************************************************************************
