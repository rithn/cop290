#include "../include/Solid.h"

void Solid::getData(std::ifstream& file){
	
	// read points from file ( points: (f,f,f,s),(....), )
    // std::cout << "reading\n";
    Point point;
	float x_coord, y_coord, z_coord;
	std::string label;
	std::string terminator = ";";
	file>>label; // this is to skip the "points" tag in the input file
	
	while(file>>x_coord>>y_coord>>z_coord>>label){
		
		point.x_coord = x_coord;
		point.y_coord = y_coord;
		point.z_coord = z_coord;
		//printf("Hey\n");
		point.label = label;
		point_arr[point.label] = point;
		// check for terminator
		file>>label;
		if( !label.compare(terminator) )
			break;
	}
	
	// read lines from file ( lines: (s1,s2),(..), )
	std::string l1,l2;
	// std::set<std::string> s1, s2;
	std::pair<std::string, std::string> ls;
	
	file>>label; // to skip the "lines" tag in the input file
	while(file>>l1>>l2){
		ls = make_pair(l1, l2);
		lineseg_arr[ls] = true;
		// check for terminator
		file>>label;
		if( !label.compare(terminator) )
			break;
	}
	// read the Projection planes (planes: size (...),(...), )
	Line normal;
	float dir_rat1, dir_rat2, dir_rat3;
	file>>label; // to skip the tag in the input file
	while(file>>dir_rat1>>dir_rat2>>dir_rat3){
		normal = {dir_rat1, dir_rat2, dir_rat3};
		proj_planes.push_back(normal);
		// check for terminator
		file>>label;
		if( !label.compare(terminator) )
			break;
	}
	return;
}

void Solid::datadisp()
{
	for(std::pair<std::string, Point> pt : point_arr){
		std::cout << "PT: " << pt.first << " ";
		pt.second.disppt();
	}
	for(std::pair<std::pair<std::string, std::string>, bool> lseg : lineseg_arr){
		std::cout << "LS: " << lseg.first.first << " " << lseg.first.second << "\n" ;
	}
	for(Line norm : proj_planes){
		printf("LN: ");
		norm.displn();
	}
}

Projection Solid::project(Line planenorm)
{
	Point ori(0.0, 0.0, 0.0, "planeorigin");
	Line ax1 = choose_firstax(planenorm);
	Line ax2 = choose_secondax(planenorm, ax1);
    Projection proj;
	proj.origin = ori;
	proj.axis1 = ax1;
	proj.axis2 = ax2;
	proj.normal = normalise(planenorm);
	proj.lineseg_arr = lineseg_arr;
	for (std::pair<std::string, Point> elem : point_arr)
	{
		proj.point_arr[elem.first] = elem.second.project(planenorm, ori, ax1, ax2);
	}
	return proj;
}

// int main()
// {
	// Solid tst;
	// std::ifstream file("input.txt");
	// tst.getData(file);
	// tst.datadisp();
	// return 0;
// }
