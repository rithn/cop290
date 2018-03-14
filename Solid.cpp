#include "Solid.h"

void Solid::getData(FILE* file){
	
	// read points from file ( points: (f,f,f,s),(....), )
	Point point;
	std::string label;
	fscanf(file,"%*s(%f,%f,%f,%s)", &point.x_coord,&point.y_coord,&point.z_coord,&label);
	point.label = label;
	point_arr.insert( {label,point} ); // WARNING!! if error, then try doubling the curly brackets
	
	while(getc(file) != '\n'){
		fscanf(file,"(%f,%f,%f,%s)", &point.x_coord,&point.y_coord,&point.z_coord,&label);
		point.label = label;
		point_arr.insert( {label,point} ); // WARNING!! if error, then try doubling the curly brackets
	}
	
	// read lines from file ( lines: (s1,s2),(..), )
	std::string l1,l2;
	// std::set<std::string> s1, s2;
	
	fscanf(file,"%*s(%s,%s)", &l1,&l2);
	// s1.insert(l1);s2.insert(l2);
	// std::pair<std::set<std::string>, std::set<std::string>> ls = std::make_pair(s1, s2);
	lineseg_arr.insert( {l1,l2} );
	
	while(getc(file) != '\n'){
		// set<std::string> s1, s2;
	
		fscanf(file,"%*s(%s,%s)", &l1,&l2);
		// s1.insert(l1);s2.insert(l2);
		// std::pair<std::set<std::string>, std::set<std::string>> ls = std::make_pair(s1, s2);
		lineseg_arr.insert( {l1, l2} );
	}
	
	// read the projection planes (planes: size (...),(...), )
	Line normal;
	int n,i=0;
	fscanf(file,"%*s %d (%f,%f,%f)", &n,&normal.dir_rat1,&normal.dir_rat2,&normal.dir_rat3);
	
	std::vector<Line> planes;
	planes.push_back(normal);
	
	while(getc(file) != EOF){
		fscanf(file,"(%f,%f,%f)", &normal.dir_rat1,&normal.dir_rat2,&normal.dir_rat3);
		planes.push_back(normal);
	}
	
	proj_planes = planes;
	fclose(file);
	return;
}

Projection Solid::project(Line planenorm)
{
	Point ori(5.0, 5.0, 5.0, "planeorigin");
	Line ax1 = choose_firstax(planenorm);
	Line ax2 = choose_secondax(planenorm, ax1);
	Projection proj;
	proj.origin = ori;
	proj.axis1 = ax1;
	proj.axis2 = ax2;
	proj.lineseg_arr = lineseg_arr;
	for (std::pair<std::string, Point> elem : point_arr)
	{
		proj.point_arr[elem.first] = elem.second.project(planenorm, ori, ax1, ax2);
	}
	return proj;
}