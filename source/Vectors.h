
#pragma once
#include "vectrex.h"

typedef	struct
{
	int y;
	int x;
} Point;

typedef union
{
	Point point;
	long int d;
} Vector;

typedef struct 
{
	unsigned int size;
	const Vector* vecs;
} VectorList;

// First member in array is for positioning the start point 
// of the sprite
// Variables
const Vector* Vectoren ;
Point point;
void DrawVecListWithMove(const VectorList* vecList)
{
	Vectoren = vecList->vecs;

	Moveto_dd(Vectoren->d);
	unsigned int i = 1;
	
	while(i < vecList->size)
	{
		point = Vectoren[i].point;
		Draw_Line_d(point.y,point.x);
		i++;
	}
}

void DrawVecList(const VectorList* vecList)
{
	Vectoren = vecList->vecs;

	unsigned int i = 0;
	
	while(i < vecList->size)
	{
		point = Vectoren[i].point;
		Draw_Line_d(point.y,point.x);
		i++;
	}
}

