
#include "Line.h"
#include "Point.h"
#include "LineSegment.h"
#include "Face.h"
#include "Projection.h"
#include "Solid.h"

Solid reconstruct(Projection projs[]);
bool handlePoints(Projection projs[]);
bool handleLines(Projection projs[]);
void handleFaces(Solid solid);
Face generateFace(LineSegment l1, LineSegment l2, Solid solid);
