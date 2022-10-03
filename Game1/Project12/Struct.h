#pragma once
#include "Enum.h"
struct Info
{
	bool act;
	int x;
	int y;
	const char* shape[4];
	int boolshape[3][7];
	Color color;
	SMALL_RECT rect;
	DIR dir;


	Info()
	{
		act = false;
		x = 0;
		y = 0;
		
		color = Èò»ö;
	}
};

struct MenuIcon
{
	int x;
	int y;
	const char* shpae;
	Color color;
};
