
#pragma once 
#include "Vectors.h"
#include "SoundPlayer.h"

extern const Arrangement* SelectedSong;
extern unsigned int channel3Counter;
extern unsigned int duration3;
extern int Pressed;

#include "../../utils/utils.h"


const Vector vectorsKey[] =
{
	{{ -10, -15}}, // Move
	{{  20,   0}}, // Draw
	{{   0,  30}},
	{{ -20,   0}},
	{{   0, -30}}
};

const Vector vectorsNote[] = 
{
	{{  20,   0}}, // Draw
	{{   0,  20}},
	{{ -20,   0}},
	{{   0, -20}}
}; 


// const Vector vectorsKey[] =
// {
// 	{{  -4,  -6}}, // Move
// 	{{   8,   0}}, // Draw
// 	{{   0,  12}},
// 	{{  -8,   0}},
// 	{{   0, -12}}
// };

// const Vector vectorsNote[] = 
// {
// 	{{ -4,  -4}}, // Move
// 	{{  8,   0}}, // Draw
// 	{{   0,  8}},
// 	{{ -8,   0}},
// 	{{   0, -8}}
// }; 

const VectorList keyVecList =  
{	
	.size = 5,
	.vecs = vectorsKey
};

const VectorList noteVecList =  
{	
	.size = 4,
	.vecs = vectorsNote
};



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
		DrawVecListWithMove(&keyVecList);
		// Center in Key
		Moveto_dd(0x0A0F);//10, 15);
		
		// better to set it everytime 
		// alternative would be to set in the else branch
		// Then 110 is the standard scale and needs to be reset
		// after 100 was set for the Note Lines
		VIA_t1_cnt_lo = 110;
		
		if(i & 0b00001010)
		{
			Draw_Line_d(125, 0);
			Draw_Line_d(125, 0);

			Moveto_dd((long)0x00CE);	

			Draw_Line_d(-125, 0);
			Draw_Line_d(-125, 0);
		}
		else
		{
			Moveto_dd((long)0x00CE);
		}

		// // Draw Line for Notes
		// Draw_Line_d(125, 0);
		// Draw_Line_d(125, 0);
		
		// // TODO: umschreiben
		// // Bewegung unnötig beim letzten durchlauf
		// Moveto_dd((long)0x8300);//-125, 0);
		// Moveto_dd((long)0x83CE);//-125, -50);
	}
}

// Draw all Notes until an specified duration is reached:
// sum duration of drawn notes and when they exceed an specified number, 
// the function is finished
// Globals
extern const unsigned int* leadDurations;
extern const unsigned long int* leadNotes;
// Variables 
unsigned long int note;
int toggle = -50;
unsigned int durationSum;
unsigned int durationBuffer; 
unsigned int channelCounter;

const int FirstRow = -60;
const int SecondRow = -10;
const int ThirdRow = 40;
const int FourthRow = 90;

const int firstNotePos = -128; 

inline static void DrawNotes()
{
	channelCounter = channel3Counter + 1;
	durationSum = duration3;
	
	reset_beam();
	
	// Draw First Note
	Moveto_d((int)duration3 + firstNotePos, FourthRow);
	DrawVecList(&noteVecList);


	while(durationSum < 125U)
	{
		note = leadNotes[channelCounter];
		
		// extra variable für letzte gespielte note?
		// letzte reihe merken?
		// reihe nach höhe der note auswählen?
		
		durationBuffer = leadDurations[channelCounter];

		if(note != 0)
		{	
			Moveto_d((int)durationBuffer << 1, 0);
			
			DrawVecList(&noteVecList);
		}
		
		
		++channelCounter;
		durationSum += durationBuffer;
	}
	// Hier wird festgetellt ob die Note getroffen wurde,
	// wenn getroffen, variable auf true setzen
	// und in SoundPlayer Variable abfragen und abspielen
}




