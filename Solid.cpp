#include "Solid.h"

void Solid::getData(FILE* file){
	
	// read points from file ( points: (f,f,f,s),(....), )
	Point point;
	float x_coord, y_coord, z_coord;
	char* label;
	fscanf(file,"( %f,%f,%f,%s )", &x_coord,&y_coord,&z_coord,&label);
	point.x_coord = x_coord;
	point.y_coord = y_coord;
	point.z_coord = z_coord;
	printf("Hey\n");
	std::string lbl = std::string(label);
	point.label = lbl;
	point_arr[point.label] = point;
	while(getc(file) != '\n'){
		fscanf(file,"( %f,%f,%f,%s )", &x_coord,&y_coord,&z_coord,&label);
		point.label = label;
		point.x_coord = x_coord;
		point.y_coord = y_coord;
		point.z_coord = z_coord;		
		point_arr[label] = point; // WARNING!! if error, then try doubling the curly brackets
	}
	// read lines from file ( lines: (s1,s2),(..), )
	std::string l1,l2;
	// std::set<std::string> s1, s2;
	
	fscanf(file,"( %s ,%s )", &l1,&l2);
	// s1.insert(l1);s2.insert(l2);
	// std::pair<std::set<std::string>, std::set<std::string>> ls = std::make_pair(s1, s2);
	printf("4 %s %s\n",l1,l2);
	lineseg_arr[l1] = l2;
	printf("4.5\n");
	while(getc(file) != '\n'){
		// set<std::string> s1, s2;
	
		fscanf(file,"( %s ,%s )", &l1,&l2);
		printf("4 %s %s\n",l1,l2);
		// s1.insert(l1);s2.insert(l2);
		// std::pair<std::set<std::string>, std::set<std::string>> ls = std::make_pair(s1, s2);
		lineseg_arr[l1] = l2;
	}
	
	// read the projection planes (planes: size (...),(...), )
	Line normal;
	int n,i=0;
	float dir_rat1, dir_rat2, dir_rat3;
	fscanf(file,"%d ( %f,%f,%f )", &n,&dir_rat1,&dir_rat2,&dir_rat3);
	normal = {dir_rat1, dir_rat2, dir_rat3};
	std::vector<Line> planes;
	planes.push_back(normal);
	while(getc(file) != EOF){
		fscanf(file,"( %f,%f,%f )", &dir_rat1, &dir_rat2, &dir_rat3);
		normal = {dir_rat1, dir_rat2, dir_rat3};
		planes.push_back(normal);
	}
	proj_planes = planes;
	fclose(file);
	return;
}

void Solid::datadisp()
{
	for(std::pair<std::string, Point> pt : point_arr){
		printf("PT: %s ", pt.first);
		printf("%s ",pt.second.label);
		pt.second.disppt();
	}
	for(std::pair<std::string, std::string> lseg : lineseg_arr){
		printf("LS: %s %s\n", lseg.first, lseg.second);
	}
	for(Line norm : proj_planes){
		printf("LN: ");
		norm.displn();
	}
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

int main()
{
	Solid tst;
	FILE *file = fopen("input.txt", "r");
	tst.getData(file);
	tst.datadisp();
	return 0;
}
