
#include "../include/Point.h"

float dot(Point p , Line l){
	return (p.x_coord * l.dir_rat1) + (p.y_coord * l.dir_rat2) + (p.z_coord * l.dir_rat3);
}

Point Point::project(Line normal, Point origin, Line axis1, Line axis2){
	float t1,t2,s;
	Point Rpo,ans;
	
	Rpo.x_coord = (x_coord) - (origin.x_coord) ;
	Rpo.y_coord = (y_coord) - (origin.y_coord) ;
	Rpo.z_coord = (z_coord) - (origin.z_coord) ;
	t1 = dot(Rpo,axis1);
	t2 = dot(Rpo,axis2);
	s = dot(Rpo,normal);
	
	ans.x_coord=t1; ans.y_coord=t2; ans.z_coord=0;
	return ans;
}

Point::Point(float x, float y, float z, std::string l)
{
	x_coord = x;
	y_coord = y;
	z_coord = z;
	label = l;
}

Point::Point()
{
};

void Point::disppt()
{
	printf("%f %f %f\n", x_coord, y_coord, z_coord);
};

// int main(){
	// Line norm = {1.0, 1.0, 1.0};
	// Line ax1 = choose_firstax(norm);
	// Line ax2 = choose_secondax(norm, ax1);
	// Point ori = {3.0, 4.4 , 5.6, "ori"};
	// Point chk = {1.0, 2.0, 3.0, "chk"};
	// Point ans = chk.project(norm, ori, ax1, ax2);
	// printf("%f %f %f\n", ans.x_coord, ans.y_coord, ans.z_coord);
	// printf("%f %f %f\n", ax1.dir_rat1, ax1.dir_rat2, ax1.dir_rat3);
	// printf("%f %f %f\n", ax2.dir_rat1, ax2.dir_rat2, ax2.dir_rat3);
// }
