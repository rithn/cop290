#include "../include/Projection.h"


void Projection::datadisp()
{
	std::cout << "origin: "; origin.disppt();
	std::cout<<"axis1: "; axis1.displn();
	std::cout<<"axis2: "; axis2.displn();
	std::cout<<"normal: "; normal.displn();
	
	for(std::pair<std::string, Point> pt : point_arr){
		std::cout << "PT: " << pt.first << " ";
		pt.second.disppt();
	}
	for(std::pair<std::pair<std::string, std::string>, bool> lseg : lineseg_arr){
		std::cout << "LS: " << lseg.first.first << " " << lseg.first.second << "\n" ;
	}
	/*for(std::pair<std::string, std::set<std::string>> p2l : point2labels){
		printf("PT: ");
		point_arr[p2l.first].disppt();
		for (std::string s : p2l.second){
			std::cout << s << " ";
		}
		std::cout << "\n";
	}*/
}

void Projection::getData(std::ifstream& file){
	
	lineseg_arr.clear();
	point_arr.clear();
	// read origin from file (x y z label) !!CAUTION TERMINATOR IS NOT REQD, SO PLS DON'T ADD IT IN INPUT FILE
	float x_coord, y_coord, z_coord;
	std::string label;
	std::string terminator = ";";
	
	file>>label; // to skip the "origin" tag in the input file
	file>>x_coord>>y_coord>>z_coord>>label;
	origin = Point(x_coord,y_coord,z_coord,label);
	
	// read axes and normal from file (x y z ... ...) !!CAUTION TERMINATOR IS NOT REQD., SO PLS DON'T ADD IT IN INPUT FILE
	file>>label; // to skip tag in input file
	file>>x_coord>>y_coord>>z_coord;
	axis1 = Line(x_coord,y_coord,z_coord);
	
	file>>label; // to skip tag in input file
	file>>x_coord>>y_coord>>z_coord;
	axis2 = Line(x_coord,y_coord,z_coord);
	
	file>>label; // to skip tag in input file
	file>>x_coord>>y_coord>>z_coord;
	normal = Line(x_coord,y_coord,z_coord);
	
	// read points from file (f f f s1 s2 s3 s4 ...)
	file>>label; // to skip tag in input file
	while(file>>x_coord>>y_coord>>z_coord){
		
		std::set<std::string> sop;
		while(file>>label){
			if( !label.compare(terminator) )
				break;
			sop.insert(label);
		}
		for(std::string label : sop){
			Point point(x_coord,y_coord,z_coord,label);
			point_arr[point.label] = point;
		}
		// check for terminator
		file>>label;
		if( !label.compare(terminator) )
			break;
	}
	
	// read lines from file (s1 s2 ...)
	file>>label; // to skip tag in input file
	std::string l;
	while(true){
		std::set<std::string> s1,s2;
		
		while(file>>l){
			if( !l.compare(terminator) )
				break;
			s1.insert(l);
		}
		while(file>>l){
			if( !l.compare(terminator) )
				break;
			s2.insert(l);
		}
		std::string l1,l2;
		//l1 = *s1.begin(); l2 = *s2.begin();
		//point2labels.insert(l1,s1); point2labels.insert(l2,s2);
		for(std::string l1 : s1)	
			for(std::string l2 : s2){
				std::pair<std::string, std::string> ls;
				ls = std::make_pair(l1, l2);
				lineseg_arr[ls] = false;
				ls = std::make_pair(l2, l1);
				lineseg_arr[ls] = false;
			}
		// check for terminator
		file>>label;
		if( !label.compare(terminator) )
			break;
	}
	// return;
}

// inline Projection::Projection(){}

// int main()
// {
	// Projection tst;
	// std::ifstream file("inproj.txt");
	// tst.getData(file);
	// tst.datadisp();
	// return 0;
// }
