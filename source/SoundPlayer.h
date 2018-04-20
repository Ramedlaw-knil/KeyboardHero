
#pragma once

#include "vectrex.h"
#include "SoundStructs.h"

const Arrangement* SelectedSong;

int Pressed;


//--------------------------- Alter Code -------------------------------------------
// counter für:
// derzeitige Note              = wird nach ablauf der Dauer inkrementiert
unsigned int channel1Counter = 0;
unsigned int channel2Counter = 0;
unsigned int channel3Counter = 0;
// für dauer der Note           = wird jede Runde dekrementiert, bei aublauf neu gesetzt
unsigned int duration;
unsigned int duration2;
unsigned int duration3;
// für stelle im Timbre         = wird jede runde dekrementiert
// für die Stelle der Amplitude = wird jede runde dekrementiert, bei aublauf bleibts auf 0



void play_tune(unsigned int channel, long unsigned int frequency, unsigned int volume)
{
	unsigned int cha = channel << 1;
	unsigned int x = (unsigned int) (frequency & 255LU);
	Sound_Byte(cha++, x);
	//~ unsigned int y =  (unsigned int)*((&frequency) + 1);
	unsigned int y =  (unsigned int) (frequency >> 8);
	Sound_Byte(cha, y);
	// When Frequency equals 0, the channel will be muted
	Sound_Byte(channel + 8U, (unsigned int)(frequency != 0UL) * volume);
	Sound_Byte(7, 0b00111000);
}

unsigned long int note;
static inline void Sound()
{

	play_tune(0, SelectedSong->Rhythm1->notes[channel1Counter], 200);
	play_tune(1, SelectedSong->Rhythm2->notes[channel2Counter], 200);
	// Do check if the right Note was played
	note = Pressed ? SelectedSong->Lead->notes[channel3Counter] : 0UL;
	play_tune(2, note, 200);
	
	if(duration == 0)
	{
		++channel1Counter;
		duration = SelectedSong->Rhythm1->noteDurations[channel1Counter]; // optimization: noteDuration in extra variable -> every differentiation does an ldx
	}
		
	if(duration2 == 0)
	{
		++channel2Counter;
		duration2 = SelectedSong->Rhythm2->noteDurations[channel2Counter];
	}
	
	if(duration3 == 0)
	{
		++channel3Counter;
		duration3 = SelectedSong->Lead->noteDurations[channel3Counter];
		// Prüfen ob das Lied zuende ist
	}
	
	--duration;
	--duration2;
	--duration3;
}


