
#pragma once

#include "vectrex.h"
#include "SoundStructs.h"

const Arrangement* SelectedSong;

int Pressed;


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
	Sound_Byte(channel + 8U, frequency ? volume : 0U);
	Sound_Byte(7, 0b00111000);
}

//Globals
//Globals
const unsigned int* rhythm1Durations;
const unsigned int* rhythm2Durations;
const unsigned int* leadDurations;

const unsigned long int* rhythm1Notes;
const unsigned long int* rhythm2Notes;
const unsigned long int* leadNotes;

unsigned int channel1Counter = 0;
unsigned int channel2Counter = 0;
unsigned int channel3Counter = 0;
unsigned int duration;
unsigned int duration2;
unsigned int duration3;

static inline __attribute__((always_inline)) 
void Sound()
{

	play_tune(0, rhythm1Notes[channel1Counter], 200);
	play_tune(1, rhythm2Notes[channel2Counter], 200);
	// Do check if the right Note was played

	play_tune(2, Pressed ? leadNotes[channel3Counter] : 0UL, 200);
	
	if(duration == 0)
	{
		++channel1Counter;
		duration = rhythm1Durations[channel1Counter]; // optimization: noteDuration in extra variable -> every differentiation does an ldx
	}
		
	if(duration2 == 0)
	{
		++channel2Counter;
		duration2 = rhythm2Durations[channel2Counter];
	}
	
	if(duration3 == 0)
	{
		++channel3Counter;
		duration3 = leadDurations[channel3Counter];
		// Prüfen ob das Lied zuende ist
	}
	
	--duration;
	--duration2;
	--duration3;
}


