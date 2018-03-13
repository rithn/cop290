#ifndef LINE_H
#define LINE_H

class Line 
{
	public: 
		float dir_rat1, dir_rat2, dir_rat3;
		
		
};

Line choose_firstax(Line norm);
Line choose_secondax(Line norm, Line ax1);

#endif