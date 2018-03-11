#include <iostream>

#include "inc.h"
#include <limits>

MAX_FLOAT = std::numeric_limits<float>::max();
//std::numeric_limits<float>::min();
//std::numeric_limits<float>::infinity();

// Eq. format : a*x + b*y = c 
float* solve(float a1, float b1, float c1, float a2, float b2, float c2){
	float ans[];
	ans[0] = -(b1*c2-b2*c1)/a1*b2-a2*b1;
	ans[1] = (a1*c2-a2*c1)/a1*b2-a2*b1;
	return ans;
}

bool handlePoints(Projection proj[], int size){
	
	if(size<2)
		return false;  // Reconstruction isn't possible with less than 2 projs
	
	int i;
	for(each point in point_arr){
		
		Point c [2];
		for(i=0;i<2;i++){
			int Ro = proj[i].origin;
			int e1 = proj[i].axis1, e2 = proj[i].axis2;
			int c[i].x_coord = Ro.x_coord + e1.dir_rat1*point.x_coord + e2.dir_rat1*point.y_coord;
			int c[i].y_coord = Ro.y_coord + e1.dir_rat2*point.x_coord + e2.dir_rat2*point.y_coord;
			int c[i].z_coord = Ro.z_coord + e1.dir_rat3*point.x_coord + e2.dir_rat3*point.y_coord;
		}
		
		// if eq is solvable i.e. a1*b2 != a2*b1
		if(proj[0].normal.dir_rat1*proj[1].normal.dir_rat2 != proj[0].normal.dir_rat2*proj[1].normal.dir_rat1 )
			float* solution = solve(proj[0].normal.dir_rat1, -proj[1].normal.dir_rat1, -c[0].x_coord+c[1].x_coord, 
									proj[0].normal.dir_rat2, -proj[1].normal.dir_rat2, -c[0].y_coord+c[1].y_coord);
		else return false;
		
		float s1 = solution[0];
		float s2 = solution[1];
		Point Rp;
		// check for consistency in z-coordinate
		if( proj[0].normal.dir_rat3*s1 - proj[1].normal.dir_rat3*s2 == -c[0].z_coord+c[1].z_coord ){
			Rp.x_coord = c[0].x_coord + s1*proj[0].normal.dir_rat1;
			Rp.y_coord = c[0].y_coord + s1*proj[0].normal.dir_rat2;
			Rp.z_coord = c[0].z_coord + s1*proj[0].normal.dir_rat3;
			
			for(i=2; i<size; i++){
				int Ro = proj[i].origin;
				int e1 = proj[i].axis1, e2 = proj[i].axis2, n = proj[i].normal;
				float sx=MAX_FLOAT,sy=MAX_FLOAT,sz=MAX_FLOAT;
				if(n.dir_rat1!=0)
					sx = (Rp.x_coord - Ro.x_coord - point.x_coord*e1.dir_rat1 - point.y_coord*e2.dir_rat1)/n.dir_rat1;
				if(n.dir_rat2!=0)
					sy = (Rp.y_coord - Ro.y_coord - point.x_coord*e1.dir_rat2 - point.y_coord*e2.dir_rat2)/n.dir_rat2;
				if(n.dir_rat3!=0)
					sz = (Rp.z_coord - Ro.z_coord - point.x_coord*e1.dir_rat3 - point.y_coord*e2.dir_rat3)/n.dir_rat3;
				if( (sx!=MAX_FLOAT && sy!=MAX_FLOAT && sx!=sy) || (sx!=MAX_FLOAT && sz!=MAX_FLOAT && sx!=sz) || (sz!=MAX_FLOAT && sy!=MAX_FLOAT && sz!=sy))
					return false; // inconsistent
				else{
					// System is consistent for this point
					// final 3D point is Rp , hence you can put it in the hashtable or whatever
				}
			}			
		}
		else return false;
	}
	// AT THIS STAGE ALL POINTS HAVE BEEN RECONSTRUCTED!
	return true;
}

bool handleLines(Projection projs[], int size)
{
	for (Projection proj: projs){
		for (LineSegment lseg: proj.lineseg_arr){
			for (std::string pt1: lseg.point1_labels){
				for (std::string pt2: lseg.point2_labels){
					
				}
			}
		}
	}
}

Solid reconstruct(Projection proj[], int size){
	
	Solid solid;
	if( !handlePoints(proj,size) )
		return solid; // empty solid due to inconsistent points
	else{
		
	}
}

int main()
{
	
	return 0;
}