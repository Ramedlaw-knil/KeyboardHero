
#pragma once 
#include "Vectors.h"
#include "SoundPlayer.h"

extern const Arrangement* SelectedSong;
extern unsigned int channel3Counter;
extern unsigned int duration3;
extern int Pressed;

#include "../../utils/utils.h"

const  VectorList keyVecList =  
{	
	.length  = 4,
	.vecs = 
    {
		{{ -40,  -60}}, // Move
		{{  80,    0}}, // Draw
		{{   0,  120}},
		{{ -80,    0}},
		{{   0, -120}}
	}
};

const VectorList noteVecList =  
{	
	.length  = 3,
	.vecs = 
    {
		{{  80,   0}}, 
		{{   0,  80}},
		{{ -80,   0}},
		{{   0, -80}}
	}
};


// //Variables
// const Vector* Vectoren ;
// Point* I;
// static inline __attribute__((always_inline)) 
// void DrawKey()
// {
// 	Vectoren = keyVecList.vecs;

// 	Moveto_dd(Vectoren->d);

// 	Point* end = keyVecList.end;
// 	I = (Point*)(Vectoren + 1);

// 	while(I != end)
// 	{
// 	 	Draw_Line_d(I->y,I->x);
// 	  	I++;
// 	}
// }
// static inline __attribute__((always_inline)) 
// void DrawNote()
// {
// 	Vectoren = noteVecList.vecs;

// 	Point* end = noteVecList.end;
// 	I = (Point*)(Vectoren);

// 	while(I != end)
// 	{
// 	 	Draw_Line_d(I->y,I->x);
// 	  	I++;
// 	}
// }


// First Key Point
const int yKeyPos = -118; 
const int xKeyPos = 100; 
const long xyKeyPos = (long)0x8A64;

unsigned int keyScales[] =  {22, 25};// 22 when pressed

// Draw Keys and Lines for the Notes
static inline __attribute__((always_inline)) 
void DrawPlayground()
{	
	VIA_t1_cnt_lo = 100;
	Moveto_dd(xyKeyPos);

	for(int i = 8; i > 0; i = i >> 1)
	{

		VIA_t1_cnt_lo  = keyScales[(Vec_Btn_State & i) == 0];

		// Draw Key
		Mov_Draw_VLc_a((void*)&keyVecList);
		// Center in Key
		Moveto_dd(0x283C);
		
		
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
unsigned int durationSum;
unsigned int durationBuffer; 
unsigned int channelCounter;

// const int FirstRow = -60;
// const int SecondRow = -10;
// const int ThirdRow = 40;
// const int FourthRow = 90;

const int FirstRow = -30;
const int SecondRow = -5;
const int ThirdRow = 20;
const int FourthRow = 45;

const int Rows[] = {-30, -5, 20, 45};

unsigned long lastNote;
int passiveRow = 0;
int aktiveRow = 0;

int addsub[] = {1,-1};

static inline __attribute__((always_inline)) 
void DrawNotes()
{
	// Pack that in a function?
	if(duration3 < 3) // smaller then 3 for tolerance
	{
		if(!Pressed && Vec_Btn_State == (aktiveRow & 0b11))
		{
			Pressed = 1;
		}
	}







	channelCounter = channel3Counter + 1;
	durationSum = duration3;


	passiveRow = aktiveRow - 1;
	if(durationSum == 0)
	{
		aktiveRow += addsub[leadNotes[channelCounter] < leadNotes[channelCounter + 1]]; 
	}

	lastNote = 0;

	while(durationSum < 125U)
	{
		note = leadNotes[channelCounter];
		

		if(note != 0) // 0 = Pause
		{	

			// if(note > lastNote) // Test what is faster
			// 	++passiveRow;
			// else
			// 	--passiveRow;
			passiveRow += addsub[note > lastNote];
			lastNote = note;

			reset_beam(); // all notes after the second are displaced = for a start reset everytime 
			VIA_t1_cnt_lo = 200;
			Moveto_d((int)(durationSum  - 64), Rows[passiveRow & 0b11]);


			VIA_t1_cnt_lo = 25;
			Draw_VLc((void*)&noteVecList);
		}
		
		durationSum += leadDurations[channelCounter];
		++channelCounter;
	}
}




