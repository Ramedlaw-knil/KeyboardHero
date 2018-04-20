
#include "game.h"
#include "vectrex.h"
#include "Playground.h"

#include "../../utils/utils.h"

inline int Game()
{
	GameInit();
	GameLoop();
	
	return 0;
}

inline void GameInit()
{
	SelectedSong = &FirstSong;
	
	duration  = SelectedSong->Rhythm1->noteDurations[0];
	duration2 = SelectedSong->Rhythm2->noteDurations[0];
	duration3 = SelectedSong->Lead->noteDurations[0];
}

inline void GameLoop()
{
	int SongEnd = 0; 

	// While song 
	while(!SongEnd)
	{
		// Synchronize loop
		Wait_Recal();
		Reset0Ref();
		
		Read_Btns();
		
		
		// Get Pressed Buttons
		DrawPlayground();
		
		DrawNotes();
		
		Sound();
	}
}

