#ifndef SOLID_H
#define SOLID_H

#include <iostream>
#include <stdio.h>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
#include <fstream>

#include "Point.h"
#include "LineSegment.h"
#include "Face.h"
#include "Line.h"
#include "Projection.h"

class Solid 
{
	public: 
		std::unordered_map<std::pair<std::string, std::string>, bool, pairhash> lineseg_arr;
		std::unordered_map<std::string, Point> point_arr;
		//Face face_arr[];
		std::vector<Line> proj_planes;
		void getData(std::ifstream& file);
        projection project(Line plane);
		void datadisp();
		//void render();
};

#endif
