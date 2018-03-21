#ifndef LINESEG_H
#define LINESEG_H

#include <string>
#include <set>

class LineSegment
{
	public: 
		std::set<std::string> point1_labels, point2_labels;
		
	LineSegment(std::set<std::string> s1, std::set<std::string> s2){
		point1_labels = s1;
		point2_labels = s2;
	};
};

#endif