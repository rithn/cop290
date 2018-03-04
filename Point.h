#include <string>

class Point 
{
	public: 
		float x_coord, y_coord, z_coord;
		std::string label;
		Point project(Line plane, Point origin, Line axis1, Line axis2);
};