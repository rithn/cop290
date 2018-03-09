#include<stdio.h>
#include<Point.h>

float dot(Point p , Line l){
	return (p.x_coord * l.dir_rat1) + (p.y_coord * l.dir_rat2) + (p.z_coord * l.dir_rat3);
}

Point:: Point project(Line normal, Point origin, Line axis1, Line axis2){
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