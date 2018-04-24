
#pragma once 
#include "Notes.h"

const unsigned long int frequencys1[] =
{
	A2, C3, E3, C3, 
	A2, C3, E3, C3, 
	A2, C3, E3, C3, 
	A2, C3, E3, C3
};

const unsigned int durations1[] =
{
	quarter,quarter,quarter,quarter,
	quarter,quarter,quarter,quarter,
	quarter,quarter,quarter,quarter,
	quarter,quarter,quarter,quarter
};

const unsigned long int frequencys2[] =
{
	C3, E3, A3, E3, 
	C3, E3, A3, E3, 
	C3, E3, A3, E3, 
	C3, E3, A3, E3
};

const unsigned int durations2[] =
{
	quarter,quarter,quarter,quarter,
	quarter,quarter,quarter,quarter,
	quarter,quarter,quarter,quarter,
	quarter,quarter,quarter,quarter
};

const unsigned long int frequencys3[] = 
{
	pause,pause,pause,pause,
	pause,pause,pause,pause,

	C5, A4, E5, A4, 
	E5, F5, A4, D5, 
	C4, D5, E5, D5,
	H5, F5, E5, g4,
	C5, A4, E5, A4, 
	E5, F5, A4, D5, 
	C4, D5, E5, D5,
	H5, F5, E5, g4,
	
	
	
	pause,pause,pause,pause,
	pause,pause,pause,pause,
	pause,pause,pause,pause,
	pause,pause,pause,pause
};

const unsigned int durations3[] =
{
	eight,eight,eight,eight,

	eight,eight,eight,eight,
	eight,eight,eight,eight,
	eight,eight,eight,eight,
	eight,eight,eight,eight,
	eight,eight,eight,eight,
	eight,eight,eight,eight,
	eight,eight,eight,eight,
	eight,eight,eight,eight,
	
	eight,eight,eight,eight,
	eight,eight,eight,eight,
	eight,eight,eight,eight,
	eight,eight,eight,eight
};

NoteSheet _Rhythm1 = 
{
	.notes = frequencys1,
	.noteDurations = durations1
};

NoteSheet _Rhythm2 = 
{
	.notes = frequencys2,
	.noteDurations = durations2
};

NoteSheet _Lead = 
{
	.notes = frequencys3,
	.noteDurations = durations3
};

const Arrangement FirstSong = 
{
	.songLength = 0,
	
	//Rhythm channel 1
	.Rhythm1 = &_Rhythm1,
	
	//Rhythm channel 2
	.Rhythm2 = &_Rhythm2,
	
	// Lead channel
	.Lead = &_Lead
	
};


