
#pragma once

#include "Playground.h"
#include "SoundPlayer.h"

#include "FirstSong.h"

extern const Arrangement FirstSong;
extern unsigned int duration;
extern unsigned int duration2;
extern unsigned int duration3;
extern const Arrangement* SelectedSong;

int Game();

void GameInit();

//void ChooseSong();

void GameLoop();


