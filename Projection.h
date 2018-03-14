#ifndef PROJ_H
#define PROJ_H

#include <string>
#include <unordered_map>
#include <set>

#include "Point.h"
#include "Line.h"
#include "LineSegment.h"

class Projection 
{
	public: 
		Point origin;
		Line axis1, axis2, normal;
		std::unordered_map<std::string, std::string> lineseg_arr;
		std::unordered_map<std::string, Point> point_arr;
		// std::unordered_map<Point, std::set<std::string>> point2labels;
		
		// void render();
		void getData();
};

#endif