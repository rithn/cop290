#ifndef PROJ_H
#define PROJ_H

#include <iostream>
#include <stdio.h>
#include <string>
#include <unordered_map>
#include <set>
#include <iostream>
#include <fstream>

#include "Point.h"
#include "Line.h"
#include "LineSegment.h"

struct pairhash {
public:
  template <typename T, typename U>
  std::size_t operator()(const std::pair<T, U> &x) const
  {
    return std::hash<T>()(x.first) ^ std::hash<U>()(x.second);
  }
};

class Projection 
{
	public: 
		Point origin;
		Line axis1, axis2, normal;
		std::unordered_map<std::pair<std::string, std::string>, bool, pairhash> lineseg_arr;
		std::unordered_map<std::string, Point> point_arr;
		//std::unordered_map<std::string, std::set<std::string>> point2labels;
		//void dispdata();
		// void render();
		void getData(std::ifstream& file);
		void datadisp();
		Projection();
};

#endif