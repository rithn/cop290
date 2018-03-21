
#ifndef DRAW_H
#define DRAW_H

#include <windows.h>
#include <iostream>
#include <set>
#include <string>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>


// #include "Point.h"
// #include "LineSegment.h"
#include "Solid.h"
// #include "Projection.h"
#include "glew.h"
#include "glut.h"


void DrawSegments();

void Draw();

void Initialize();

void render(Solid *sptr, int iArgc, char** cppArgv);
void render(projection *pptr, int iArgc, char** cppArgv);

void printv(va_list args, const char* format);

void print(const char* format, ...);

void printAt(int x, int y, const char* format, ...);

#endif
