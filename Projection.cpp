#include "Projection.h"

void Projection::getData(std::ifstream& file){
	
	// read origin from file (x y z label) !!CAUTION TERMINATOR IS NOT REQD, SO PLS DON'T ADD IT IN INPUT FILE
	float x_coord, y_coord, z_coord;
	std::string label;
	std::string terminator = "terminate";
	
	
	file>>x_coord>>y_coord>>z_coord>>label;
	origin = Point(x_coord,y_coord,z_coord,label);
	
	// read axes and normal from file (x y z ... ...) !!CAUTION TERMINATOR IS NOT REQD., SO PLS DON'T ADD IT IN INPUT FILE
	file>>x_coord>>y_coord>>z_coord;
	axis1 = Line(x_coord,y_coord,z_coord);
	
	file>>x_coord>>y_coord>>z_coord;
	axis2 = Line(x_coord,y_coord,z_coord);
	
	file>>x_coord>>y_coord>>z_coord;
	normal = Line(x_coord,y_coord,z_coord);
	
	// read points from file (f f f s ...)
	while(file>>x_coord>>y_coord>>z_coord>>label){
		if( !label.compare(terminator) )
			break;
		Point point(x_coord,y_coord,z_coord,label);
		point_arr[point.label] = point;
	}
	
	// read lines from file (s1 s2 ...)
	std::string l1,l2;
	std::pair<std::string, std::string> ls;
	
	while(file>>l1>>l2){
		if( !l1.compare(terminator) )
			break;
		ls = make_pair(l1, l2);
		lineseg_arr[ls] = true;
	}
	// read the projection planes (planes: size (...),(...), )
	Line normal;
	float dir_rat1, dir_rat2, dir_rat3;
	while(file>>dir_rat1>>dir_rat2>>dir_rat3){
		normal = {dir_rat1, dir_rat2, dir_rat3};
		proj_planes.push_back(normal);
	}
	return;
}