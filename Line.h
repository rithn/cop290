#ifndef LINE_H
#define LINE_H

#include <stdio.h>
#include <math.h>

class Line 
{
	public: 
		float dir_rat1, dir_rat2, dir_rat3;
		void displn(); 
		
		Line(float x, float y, float z);
		Line();
};

Line choose_firstax(Line norm);
Line choose_secondax(Line norm, Line ax1);
Line normalise(Line ln);

#endif