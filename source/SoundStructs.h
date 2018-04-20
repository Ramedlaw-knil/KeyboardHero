
#pragma once

typedef struct
{
	// constant length for both arrays? 
	// or additional variables
	const int* AmplitudeCurve;
	
	// sound Texture
	const int* Timbre;
} Instrument;



typedef struct
{
	const long unsigned int* notes;
	const unsigned int* noteDurations;
	Instrument instrument;
	
} NoteSheet;

// from Leadnote duration calculate the position of the note on the display
// forecast with defined length of summed durations
// e.g foreacast of 50 = sum up durations until they reach 50 and display them
// maybe forecast length calculate with bpm,sixteenth note or eight note  
typedef struct 
{
	const long int songLength;
	
	//Rhythm channel 1
	NoteSheet* Rhythm1;
	
	//Rhythm channel 2
	NoteSheet* Rhythm2;
	
	// Lead channel
	NoteSheet* Lead;
	
} Arrangement;

