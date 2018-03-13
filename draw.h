#include <windows.h>
#include <iostream>
#include <set>
#include "Point.h"
#include "LineSegment.h"
#include "glut.h"

void DrawPoints();
void DrawSegments();

void Draw();

void Initialize();

void render(Solid *sptr, int iArgc, char** cppArgv);
void render(Projection *pptr, int iArgc, char** cppArgv);