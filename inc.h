
#include "Line.h"
#include "Point.h"
#include "LineSegment.h"
#include "Face.h"
#include "Projection.h"
#include "Solid.h"

float* solve(float a1, float b1, float c1, float a2, float b2, float c2);
Solid reconstruct(Projection proj[], int size);
bool handlePoints(Projection proj[], int size);
bool handleLines(Projection projs[], int size);
void handleFaces(Solid solid);
Face generateFace(LineSegment l1, LineSegment l2, Solid solid);
