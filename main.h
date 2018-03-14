#include <iostream>
#include <limits>
#include <set>
#include <string>
#include <utility>

#include "Projection.h"
#include "Solid.h"
#include "draw.h"

std::pair<float, float> solve(float a1, float b1, float c1, float a2, float b2, float c2);
Solid *reconstruct(Projection proj[], int size);

bool handlePoints(Solid* solid, Projection proj[], int size);
bool handleLines(Solid* solid, Projection proj[], int size);

void handleFaces(Solid solid);
Face generateFace(LineSegment l1, LineSegment l2, Solid solid);

