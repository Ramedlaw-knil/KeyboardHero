
#include "game.h"
#include "vectrex.h"

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

	rhythm1Durations = SelectedSong->Rhythm1->noteDurations;
	rhythm2Durations = SelectedSong->Rhythm2->noteDurations;
	leadDurations = SelectedSong->Lead->noteDurations;
	
	rhythm1Notes = SelectedSong->Rhythm1->notes;
	rhythm2Notes = SelectedSong->Rhythm2->notes;
	leadNotes = SelectedSong->Lead->notes;
}

inline void GameLoop()
{
	int SongEnd = 0; 

	// While song 
	while(!SongEnd)
	{
		// Synchronize loop
		Wait_Recal();
		reset_beam();
		
		Read_Btns();
		
		// Get Pressed Buttons
		DrawPlayground();
		
		DrawNotes();
		
		//Sound();
	}
}

