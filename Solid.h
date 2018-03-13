#include <string>
#include <unordered_map>
#include "Face.h"
#include "Line.h"
#include "Projection.h"

class Solid 
{
	public: 
		std::unordered_map<LineSegments, bool> lineseg_arr;
		std::unordered_map<std::string, Point> point_arr;
		Face face_arr[];
		Line proj_plane_arr[];
		
		void getData(FILE* file);
		Projection project(Line plane);
		//void render();
};