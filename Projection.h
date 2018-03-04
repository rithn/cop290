#include <string>
#include <unordered_map>

class Projection 
{
	public: 
		Point origin;
		Line axis1, axis2, normal;
		LineSegment lineseg_arr[];
		std::unordered_map<std::string, Point> point_arr;
		
		void render();
		void getData();
};