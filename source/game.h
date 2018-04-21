
#pragma once

#include "Playground.h"
#include "SoundPlayer.h"

#include "FirstSong.h"

extern const Arrangement FirstSong;

// SoundPlayer.h
extern unsigned int duration;
extern unsigned int duration2;
extern unsigned int duration3;
extern const Arrangement* SelectedSong;

// PLayground.h
extern const unsigned int* rhythm1Durations;
extern const unsigned int* rhythm2Durations;
extern const unsigned int* leadDurations;

extern const unsigned long int* rhythm1Notes;
extern const unsigned long int* rhythm2Notes;
extern const unsigned long int* leadNotes;

int Game();

void GameInit();

//void ChooseSong();

void GameLoop();


