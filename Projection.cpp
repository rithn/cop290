#include "Projection.h"

void Projection::dispdata()
{
	std::cout << "origin: ";
	origin.disppt();
	std::cout << "axes: \n";
	axis1.displn();
	axis2.displn();
	std::cout << "normal: \n";
	normal.displn();
	for(std::pair<std::string, Point> pt : point_arr){
		std::cout << "PT: " << pt.first << " ";
		pt.second.disppt();
	}
	for(std::pair<std::pair<std::string, std::string>, bool> lseg : lineseg_arr){
		std::cout << "LS: " << lseg.first.first << " " << lseg.first.second << "\n" ;
	}
	for(std::pair<std::string, std::set<std::string>> p2l : point2labels){
		printf("PT: ");
		point_arr[p2l.first].disppt();
		for (std::string s : p2l.second){
			std::cout << s << " ";
		}
		std::cout << "\n";
	}
}