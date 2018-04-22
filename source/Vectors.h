
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
	int length;
	const Vector vecs[];
} VectorList;
