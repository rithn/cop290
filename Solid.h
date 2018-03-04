#include <string>
#include <unordered_map>

class Solid 
{
	public: 
		LineSegment lineseg_arr[];
		std::unordered_map<std::string, Point> point_arr;
		Face face_arr[];
		Line proj_plane_arr[];
		
		void getData();
		Projection project(Line plane);
		void render();
};