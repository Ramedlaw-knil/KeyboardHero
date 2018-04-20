
#pragma once 
#include "Vectors.h"
#include "SoundPlayer.h"

extern const Arrangement* SelectedSong;
extern unsigned int channel3Counter;
extern unsigned int duration3;

#include "../../utils/utils.h"


// Key 
// Width = 30
// Height = 20
const Vector vectorsKey[] =
{
	{{ -10, -15}}, // Move
	{{  20,   0}}, // Draw
	{{   0,  30}},
	{{ -20,   0}},
	{{   0, -30}}
};


// change scaling by distance from Key
// Width = 20
// Height = 20
const Vector vectorsNote[] = 
{
	{{ -10, -10}}, // Move
	{{  20,   0}}, // Draw
	{{   0,  20}},
	{{ -20,   0}},
	{{   0, -20}}
}; 

const VectorList keyVecList =  
{	
	.size = 5,
	.vecs = vectorsKey
};

const VectorList noteVecList =  
{	
	.size = 5,
	.vecs = vectorsNote
};




const int Divider = -50;

// First Key Point
const int yKeyPos = -118; 
const int xKeyPos = 100; 

// Draw Keys and Lines for the Notes
inline static void DrawPlayground()
{	
	VIA_t1_cnt_lo = 110;
	Moveto_d(yKeyPos, xKeyPos);

	for(int i = 8; i > 0; i = i >> 1)
	{
		if(Vec_Btn_State & i)
		{
			VIA_t1_cnt_lo = 95;
		}

		// Draw Key
		DrawVecList(&keyVecList);

		// Center in Key
		Moveto_d(10, 15);
		
		// better to set it everytime 
		// alternative would be to set in the else branch
		// Then 110 is the standard scale and needs to be reset
		// after 100 was set for the Note Lines
		VIA_t1_cnt_lo = 110;
		
		// Draw Line for Notes
		Draw_Line_d(125, 0);
		Draw_Line_d(125, 0);
		
		// TODO: umschreiben
		// Bewegung unnötig beim letzten durchlauf
		Moveto_d(-125, 0);
		Moveto_d(-125, Divider);
	}
}

// Draw all Notes until an specified duration is reached:
// sum duration of drawn notes and when they exceed an specified number, 
// the function is finished
unsigned long int note;
int toggle = -50;
long int durationSum;
unsigned int channelCounter;

const int FirstRow = -50;
const int SecondRow = 0;
const int ThirdRow = 50;
const int FourthRow = 100;
inline static void DrawNotes()
{
	const unsigned long int* notes = SelectedSong->Lead->notes;
	const unsigned int* durations = SelectedSong->Lead->noteDurations; 
	channelCounter = channel3Counter + 1;
	durationSum = duration3;
	
	reset_beam();
	// Move to first position and save last set row
	Moveto_d(yKeyPos,xKeyPos);
	
	Moveto_d((int)duration3, 0);
	DrawVecList(&noteVecList);
	Moveto_d(10, 10);

// FFFF mean that the song ended ---- TODO: note must be initializd
	while(durationSum < 250U || note != 0xFFFF)
	{
		note = notes[channelCounter];
		
		
		// extra variable für letzte gespielte note?
		// letzte reihe merken?
		// reihe nach höhe der note auswählen?
		
		if(note != 0)
		{	
			Moveto_d((int)durations[channel1Counter], 0);
			
			
			DrawVecList(&noteVecList);
			Moveto_d(10, 10);
		}
		
		
		++channelCounter;
		durationSum += durations[channel1Counter];
	}
	// Hier wird festgetellt ob die Note getroffen wurde,
	// wenn getroffen, variable auf true setzen
	// und in SoundPlayer Variable abfragen und abspielen
}




