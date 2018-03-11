#include <string>
#include <unordered_map>
#include <set>

class Projection 
{
	public: 
		Point origin;
		Line axis1, axis2, normal;
		LineSegment lineseg_arr[];
		std::unordered_map<std::string, Point> point_arr;
		std::unordered_map<Point, set<std::string>> point2labels;
		
		void render();
		void getData();
};