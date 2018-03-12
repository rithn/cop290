#include "Solid.h"

void Solid::getData(FILE* file){
	
	// read points from file ( points: (f,f,f,s),(....), )
	Point point;
	String label;
	fscanf(file,"%*s (%f,%f,%f,%s)", &point.x_coord,&point.y_coord,&point.z_coord,&label);
	point.label = label;
	point_arr.insert( {label,point} ); // WARNING!! if error, then try doubling the curly brackets
	
	while(getc(file) != '\n'){
		fscanf(file,"(%f,%f,%f,%s)", &point.x_coord,&point.y_coord,&point.z_coord,&label);
		point.label = label;
		point_arr.insert( {label,point} ); // WARNING!! if error, then try doubling the curly brackets
	}
	
	// read lines from file ( lines: (s1,s2),(..), )
	String l1,l2;
	set<std::string> s1, s2;
	
	fscanf(file,"%*s (%s,%s)", &l1,&l2);
	s1.insert(l1);s2.insert(l2);
	
	LineSegment ls ( s1,s2 );
	lineseg_arr.insert( {ls,true} );
	
	while(getc(file) != '\n'){
		set<std::string> s1, s2;
	
		fscanf(file,"%*s (%s,%s)", &l1,&l2);
		s1.insert(l1);s2.insert(l2);
		
		LineSegment ls ( s1,s2 );
		lineseg_arr.insert( {ls,true} );
	}
	
	// read the projection planes (planes: size (...),(...), )
	Line normal;
	int n,i=0;
	fscanf(file,"%*s %d (%f,%f,%f)", &n,&normal.dir_rat1,&normal.dir_rat2,&normal.dir_rat3);
	
	Line proj_plane[n];
	proj_plane[i] = normal;
	i++;
	
	while(getc(file) != EOF){
		fscanf(file,"(%f,%f,%f)", &normal.dir_rat1,&normal.dir_rat2,&normal.dir_rat3);
		proj_plane[i] = normal;
		i++;
	}
	proj_plane_arr = proj_plane;
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