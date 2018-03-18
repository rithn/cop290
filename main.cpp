#include "main.h"

float MAX_FLOAT = std::numeric_limits<float>::max();
//std::numeric_limits<float>::min();
//std::numeric_limits<float>::infinity();

// Eq. format : a*x + b*y = c 
std::pair<float, float> solve(float a1, float b1, float c1, float a2, float b2, float c2){
	printf("slv\n");
	std::pair<float, float> ans;
	ans.first = -(b1*c2-b2*c1)/a1*b2-a2*b1;
	ans.second = (a1*c2-a2*c1)/a1*b2-a2*b1;
	return ans;
}

bool handlePoints(Solid* solid, std::vector<Projection> proj, int size){
	
	printf("hp\n");
	if(size<2)
		return false;  // Reconstruction isn't possible with less than 2 projs
	int i;
	printf("hpuy\n");
	for( std::pair<std::string, Point> elem : proj[0].point_arr ){
		
		std::string label = elem.first;
		Point point = elem.second;
		
		Point c[2];
		printf("hpins\n");
		for(i=0;i<2;i++){
			Point Ro = proj[i].origin;
			Line e1 = proj[i].axis1, e2 = proj[i].axis2;
			c[i].x_coord = Ro.x_coord + e1.dir_rat1*point.x_coord + e2.dir_rat1*point.y_coord;
			c[i].y_coord = Ro.y_coord + e1.dir_rat2*point.x_coord + e2.dir_rat2*point.y_coord;
			c[i].z_coord = Ro.z_coord + e1.dir_rat3*point.x_coord + e2.dir_rat3*point.y_coord;
		}
		std::pair<float, float> solution;
		// if eq is solvable i.e. a1*b2 != a2*b1
		printf("hpstillin\n");
		proj[0].normal.displn();
		proj[1].normal.displn();
		if(((proj[0].normal.dir_rat1)*(proj[1].normal.dir_rat2)) != ((proj[0].normal.dir_rat2)*(proj[1].normal.dir_rat1)) ){
			//solution = solve(proj[0].normal.dir_rat1, -proj[1].normal.dir_rat1, -c[0].x_coord+c[1].x_coord, 
									//proj[0].normal.dir_rat2, -proj[1].normal.dir_rat2, -c[0].y_coord+c[1].y_coord);
			printf("hpifori\n");								
		}
		else{ 
			printf("hpelse\n");
			return false;
		}
		
		float s1 = solution.first;
		float s2 = solution.second;
		Point Rp;
		printf("hpgoingon\n");
		// check for consistency in z-coordinate
		if( proj[0].normal.dir_rat3*s1 - proj[1].normal.dir_rat3*s2 == -c[0].z_coord+c[1].z_coord ){
			Rp.x_coord = c[0].x_coord + s1*proj[0].normal.dir_rat1;
			Rp.y_coord = c[0].y_coord + s1*proj[0].normal.dir_rat2;
			Rp.z_coord = c[0].z_coord + s1*proj[0].normal.dir_rat3;
			printf("hpinif\n");
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

void handleLines(Solid* solid, std::vector<Projection> projs, int size)
{	int flag;
	for (Projection proj: projs){
		for (std::pair<std::pair<std::string, std::string>,bool> lseg : proj.lineseg_arr){
			flag = 0;
			for(Projection proj2:projs){
				if (proj2.point_arr[lseg.first.first] != proj2.point_arr[lseg.first.second] && 
					(proj2.lineseg_arr.find(lseg.first) == proj2.lineseg_arr.end() ||
					proj2.lineseg_arr.find(lseg.first)->second == false)){
					flag = 1;
					break;
				}
			}
			if (flag == 0){
				(solid -> lineseg_arr)[lseg.first] = true;
			}			
		}
	}
}

Solid reconstruct(std::vector<Projection> proj, int nproj){
	
	Solid solid;
	printf("re\n");
	if( !handlePoints(&solid,proj, nproj) ){
		printf("kucchna\n");
		return solid; // empty(or with some pts) solid due to inconsistent points
	}
	printf("ren\n");
	handleLines(&solid, proj, nproj);
	printf("reza\n");
	return solid;
}

int main(int argc, char** argv)
{
	
	// Solid solid;
	// if(!file){
		// printf("ERROR: can't open input file");
		// return 1;
	// }
	// else{
		// solid.getData(file);
	// }
	// solid.datadisp();
	// Solid *solidptr;
	// solidptr = &solid;
	//render(solidptr, argc, argv);
	// Line n1 = {0.5, 0.6, 0.5};
	// Projection p1 = solid.project(n1);
	// p1.normal.displn();
	// p1.datadisp();
	// render(&p1, argc, argv);
	
	printf("hi\n");
	Projection tst1;
	std::ifstream file1("inproj1.txt");
	tst1.getData(file1);
	Projection tst2;
	std::ifstream file2("inproj2.txt");
	tst2.getData(file2);
	Projection tst3;
	std::ifstream file3("inproj3.txt");
	tst3.getData(file3);
	printf("hiya\n");
	Projection projlist[] = {tst1, tst2, tst3};
	std::vector<Projection> projs(projlist, projlist+ sizeof(projlist)/sizeof(Projection)); 
	printf("hing\n");
	Solid tstsolid = reconstruct(projs, 3);
	tstsolid.datadisp();
	printf("hight\n");
	return 0;
}