
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

inline static void Move(const Vector* vec)
{
	Moveto_dd(vec->d);
}

inline static void Draw(const Vector* vec)
{
	Draw_Line_d(vec->point.y,vec->point.x);
}

// First member in array is for positioning the start point 
// of the sprite
void DrawVecList(const VectorList* vecList)
{
	Moveto_dd(vecList->vecs->d);
	unsigned int i = 1;
	
	while(i < vecList->size)
	{
		Draw(&vecList->vecs[i]);
		i++;
	}
}


