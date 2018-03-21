#ifndef FACE_H
#define FACE_H

#include <unordered_set>
#include "LineSegment.h"

class Face
{
	public:
		std::unordered_set<std::string> lineseg_arr;
};

#endif