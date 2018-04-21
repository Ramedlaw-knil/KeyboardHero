
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
	{{ -20, -30}}, // Move
	{{  40,   0}}, // Draw
	{{   0,  60}},
	{{ -40,   0}},
	{{   0, -60}}
};

const Vector vectorsNote[] = 
{
	{{  40,   0}}, // Draw
	{{   0,  40}},
	{{ -40,   0}},
	{{   0, -40}}
}; 

const VectorList keyVecList =  
{	
	.end  = (Point*)(vectorsKey + 5),
	.vecs = vectorsKey
};

const VectorList noteVecList =  
{	
	.end  = (Point*)(vectorsNote + 4),
	.vecs = vectorsNote
};

//Variables
const Vector* Vectoren ;
Point* I;
static inline __attribute__((always_inline)) 
void DrawKey()
{
	Vectoren = keyVecList.vecs;

	Moveto_dd(Vectoren->d);

	Point* end = keyVecList.end;
	I = (Point*)(Vectoren + 1);

	while(I != end)
	{
	 	Draw_Line_d(I->y,I->x);
	  	I++;
	}
}
static inline __attribute__((always_inline)) 
void DrawNote()
{
	Vectoren = noteVecList.vecs;

	Point* end = noteVecList.end;
	I = (Point*)(Vectoren);

	while(I != end)
	{
	 	Draw_Line_d(I->y,I->x);
	  	I++;
	}
}


// First Key Point
const int yKeyPos = -118; 
const int xKeyPos = 100; 

unsigned int keyScales[] =  {50, 45};// 45 when pressed

// Draw Keys and Lines for the Notes
static inline __attribute__((always_inline)) 
void DrawPlayground()
{	
	VIA_t1_cnt_lo = 100;
	Moveto_d(yKeyPos, xKeyPos);

	for(int i = 8; i > 0; i = i >> 1)
	{

		VIA_t1_cnt_lo  = keyScales[Vec_Btn_State & i];

		// Draw Key
		DrawKey();
		// Center in Key
		Moveto_dd(0x141E);
		
		
		if(i & 0b00001010)
		{
			VIA_t1_cnt_lo = 200;
			Draw_Line_d(125, 0);

			VIA_t1_cnt_lo = 50;
			Moveto_dd((long)0x009C);	

			VIA_t1_cnt_lo = 200;
			Draw_Line_d(-125, 0);
		}
		else
		{
			VIA_t1_cnt_lo = 50;
			Moveto_dd((long)0x009C);
		}
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

static inline __attribute__((always_inline)) 
void DrawNotes()
{
	channelCounter = channel3Counter + 1;
	durationSum = duration3;
	
	reset_beam();
	
	// Draw First Note
	VIA_t1_cnt_lo = 100;
	Moveto_d((int)durationSum + firstNotePos, FourthRow);
	
	VIA_t1_cnt_lo = 50;
	DrawVecList(&noteVecList);


	while(durationSum < 125U)
	{
		note = leadNotes[channelCounter];
		
		// extra variable für letzte gespielte note?
		// letzte reihe merken?
		// reihe nach höhe der note auswählen?
		
		VIA_t1_cnt_lo = 100;
		durationBuffer = leadDurations[channelCounter];
		Moveto_d((int)durationBuffer << 1, 0);

		if(note != 0) // 0 = Pause
		{	
			// Hier wird festgetellt ob die Note getroffen wurde,
			// wenn getroffen, variable auf true setzen
			// und in SoundPlayer Variable abfragen und abspielen
			VIA_t1_cnt_lo = 50;
			DrawNote();
		}
		
		
		++channelCounter;
		durationSum += durationBuffer;
	}
}




