#include "Line.h"

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
	dummy.dir_rat1 = (-1.0*norm.dir_rat1)+1.0;
	dummy.dir_rat2 = norm.dir_rat2;
	dummy.dir_rat3 = norm.dir_rat3;
	return cross_product(norm, dummy);	
}

Line choose_secondax(Line norm, Line ax1)
{
	return cross_product(norm, ax1);
}