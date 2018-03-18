#ifndef POINT_H
#define POINT_H

#include <string>
#include <stdio.h>
#include "Line.h"

class Point 
{
	public: 
		float x_coord, y_coord, z_coord;
		std::string label;
		Point project(Line normal, Point origin, Line axis1, Line axis2);
		
		Point(float x, float y, float z, std::string label);
		Point();
		void disppt();
		
		bool operator !=(Point& pt2){
			if (this->x_coord == pt2.x_coord && this->y_coord == pt2.y_coord && this->z_coord == pt2.z_coord)
				return true;
			return false;
		}
};

#endif