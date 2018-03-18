#include "main.h"

float MAX_FLOAT = std::numeric_limits<float>::max();
//std::numeric_limits<float>::min();
//std::numeric_limits<float>::infinity();

// Eq. format : a*x + b*y = c 
std::pair<float, float> solve(float a1, float b1, float c1, float a2, float b2, float c2){
	std::pair<float, float> ans;
	ans.first = -(b1*c2-b2*c1)/a1*b2-a2*b1;
	ans.second = (a1*c2-a2*c1)/a1*b2-a2*b1;
	return ans;
}

bool handlePoints(Solid* solid, Projection proj[], int size){
	
	if(size<2)
		return false;  // Reconstruction isn't possible with less than 2 projs
	
	int i;
	for( std::pair<std::string, Point> elem : proj[0].point_arr ){
		
		std::string label = elem.first;
		Point point = elem.second;
		
		Point c[2];
		for(i=0;i<2;i++){
			Point Ro = proj[i].origin;
			Line e1 = proj[i].axis1, e2 = proj[i].axis2;
			c[i].x_coord = Ro.x_coord + e1.dir_rat1*point.x_coord + e2.dir_rat1*point.y_coord;
			c[i].y_coord = Ro.y_coord + e1.dir_rat2*point.x_coord + e2.dir_rat2*point.y_coord;
			c[i].z_coord = Ro.z_coord + e1.dir_rat3*point.x_coord + e2.dir_rat3*point.y_coord;
		}
		std::pair<float, float> solution;
		// if eq is solvable i.e. a1*b2 != a2*b1
		if(proj[0].normal.dir_rat1*proj[1].normal.dir_rat2 != proj[0].normal.dir_rat2*proj[1].normal.dir_rat1 )
			solution = solve(proj[0].normal.dir_rat1, -proj[1].normal.dir_rat1, -c[0].x_coord+c[1].x_coord, 
									proj[0].normal.dir_rat2, -proj[1].normal.dir_rat2, -c[0].y_coord+c[1].y_coord);
		else return false;
		
		float s1 = solution.first;
		float s2 = solution.second;
		Point Rp;
		// check for consistency in z-coordinate
		if( proj[0].normal.dir_rat3*s1 - proj[1].normal.dir_rat3*s2 == -c[0].z_coord+c[1].z_coord ){
			Rp.x_coord = c[0].x_coord + s1*proj[0].normal.dir_rat1;
			Rp.y_coord = c[0].y_coord + s1*proj[0].normal.dir_rat2;
			Rp.z_coord = c[0].z_coord + s1*proj[0].normal.dir_rat3;
			
			for(i=2; i<size; i++){
				Point Ro = proj[i].origin;
				Line e1 = proj[i].axis1, e2 = proj[i].axis2, n = proj[i].normal;
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
					solid->point_arr.insert( {label,point} ); // WARNING!! if error, then try doubling the curly brackets
				}
			}			
		}
		else return false;
	}
	// AT THIS STAGE ALL POINTS HAVE BEEN RECONSTRUCTED!
	return true;
}

// bool handleLines(Solid* solid, Projection projs[], int size)
// {	int flag;
	// for (Projection proj: projs){
		// for (std::pair<std::string, std::string> lseg : proj.lineseg_arr){
			// std::string pt1 = lseg.first;
			// std::string pt2 = lseg.second;
			// flag = 0;
			// for(Projection proj2:projs){
				// set<std::string> set_pt1 = proj2.point2labels[proj2.point_arr[pt1]];
				// set<std::string> set_pt2 = proj2.point2labels[proj2.point_arr[pt2]];
				// if (set_pt1 != set_pt2 && 
					// proj2.lineseg_arr.find("hello") == proj2.lineseg_arr.end() &&
					// proj2.lineseg_arr.find("hello") == proj2.lineseg_arr.end()){
					// flag = 1;
					// break;
				// }
			// }
			// if (flag == 0){
				// set<std::string> s1, s2;
				// s1.insert(pt1);
				// s2.insert(pt2);
				// (solid -> lineseg_arr).insert({{pt1, pt2}});
			// }
				
			
		// }
	// }
// }

Solid *reconstruct(Projection proj[], int size){
	
	Solid* solid;
	if( !handlePoints(solid,proj,size) )
		return solid; // empty(or with some pts) solid due to inconsistent points
	else{
		return solid; /////////////////////////////////////
	}
}

int main(int argc, char** argv)
{
	std::ifstream file("input.txt");
	
	Solid solid;
	if(!file){
		printf("ERROR: can't open input file");
		return 1;
	}
	else{
		solid.getData(file);
	}
	solid.datadisp();
	Solid *solidptr;
	solidptr = &solid;
	//render(solidptr, argc, argv);
	Line n1 = {1.0, 0.0, 0.0};
	Projection p1 = solid.project(n1);
	// p1.normal.displn();
	p1.datadisp();
	render(&p1, argc, argv);
	return 0;
}