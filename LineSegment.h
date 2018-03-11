#include <string>
#include <set>

class LineSegment
{
	public: 
		set<std::string> point1_labels, point2_labels;
		
	LineSegment(set<std::string> s1, set<std::string> s2){
		point1_labels = s1;
		point2_labels = s2;
	};
};