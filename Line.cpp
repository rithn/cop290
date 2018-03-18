#include "Line.h"

Line normalise(Line ln)
{
	float size = sqrt(ln.dir_rat1*ln.dir_rat1 + ln.dir_rat2*ln.dir_rat2 + ln.dir_rat3*ln.dir_rat3);
	Line ans;
	ans.dir_rat1 = ln.dir_rat1/size;
	ans.dir_rat2 = ln.dir_rat2/size;
	ans.dir_rat3 = ln.dir_rat3/size;
	return ans;
}

Line cross_product(Line line1, Line line2)
{
	Line ans;
	ans.dir_rat1 = (line1.dir_rat2 * line2.dir_rat3) - (line1.dir_rat3 * line2.dir_rat2);
	ans.dir_rat2 = (line1.dir_rat3 * line2.dir_rat1) - (line1.dir_rat1 * line2.dir_rat3);
	ans.dir_rat3 = (line1.dir_rat1 * line2.dir_rat2) - (line1.dir_rat2 * line2.dir_rat1);
	return ans;
}

Line choose_firstax(Line norm)
{
	Line dummy;
	dummy.dir_rat1 = dummy.dir_rat2 = dummy.dir_rat3 = 1.0;
	if (norm.dir_rat1 == norm.dir_rat2 && norm.dir_rat1 == norm.dir_rat3){
		dummy.dir_rat1 = 2.0;
	}
	return normalise(cross_product(norm, dummy));	
}

Line choose_secondax(Line norm, Line ax1)
{
	return normalise(cross_product(norm, ax1));
}

void Line::displn()
{
	printf("%f %f %f\n", dir_rat1, dir_rat2, dir_rat3);
}

Line::Line(float x, float y, float z)
{
	dir_rat1 = x;
	dir_rat2 = y;
	dir_rat3 = z;
}

Line::Line()
{
}
// int main(){
	// Line x, y;
	// x.dir_rat1 = 1.0;
	// x.dir_rat2 = x.dir_rat3 = 0.0;
	// y.dir_rat3 = 1.0;
	// y.dir_rat2 = y.dir_rat1 = 0.0;
	// Line cp = cross_product(x, y);
	// printf("%f %f %f\n", cp.dir_rat1, cp.dir_rat2, cp.dir_rat3);
	// Line ax1 = choose_firstax(x);
	// printf("%f %f %f\n", ax1.dir_rat1, ax1.dir_rat2, ax1.dir_rat3);
	// Line ax2 = choose_secondax(x, ax1);
	// printf("%f %f %f\n", ax2.dir_rat1, ax2.dir_rat2, ax2.dir_rat3);
// }