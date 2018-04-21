
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
	Point* end;
	const Vector* vecs;
} VectorList;


// Variables
const Vector* Vectoren ;
Point* I;

void DrawVecListWithMove(const VectorList* vecList)
{
	Vectoren = vecList->vecs;

	Moveto_dd(Vectoren->d);

	Point* end = vecList->end;
	I = (Point*)(Vectoren + 1);

	while(I != end)
	{
	 	Draw_Line_d(I->y,I->x);
	  	I++;
	}
}

void DrawVecList(const VectorList* vecList)
{
	Vectoren = vecList->vecs;

	Point* end = vecList->end;
	I = (Point*)(Vectoren);

	while(I != end)
	{
	 	Draw_Line_d(I->y,I->x);
	  	I++;
	}
}