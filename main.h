#include <iostream>
#include <limits>
#include <set>
#include <string>
#include <utility>
#include <fstream>
#include <vector>
//using namespace std;

#include "Projection.h"
#include "Solid.h"
#include "draw.h"

std::pair<float, float> solve(float a1, float b1, float c1, float a2, float b2, float c2);
Solid reconstruct(std::vector<Projection> proj, int size);

bool handlePoints(Solid* solid, std::vector<Projection> proj, int size);
void handleLines(Solid* solid, std::vector<Projection> proj, int size);

void handleFaces(Solid solid);
Face generateFace(LineSegment l1, LineSegment l2, Solid solid);

