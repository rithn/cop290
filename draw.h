
#ifndef DRAW_H
#define DRAW_H

#include <windows.h>
#include <iostream>
#include <set>

// #include "Point.h"
// #include "LineSegment.h"
// #include "Solid.h"
// #include "Projection.h"
#include "GL/glut.h"

void DrawSegments();

void Draw();

void Initialize();

void render(Solid *sptr, int iArgc, char** cppArgv);
void render(Projection *pptr, int iArgc, char** cppArgv);

#endif