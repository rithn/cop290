
#ifndef DRAW_H
#define DRAW_H

#include <windows.h>
#include <iostream>
#include <set>
#include <string>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

#include "Solid.h"
#include "freeglut.h"


void DrawSegments();

void Draw();

void Initialize();

void render(Solid *sptr, int iArgc, char** cppArgv);
// void render(Projection *pptr, int iArgc, char** cppArgv);
void render_result(Solid *sptr, std::vector<Projection> projs, int argc, char** argv);

void printv(va_list args, const char* format);

void print(const char* format, ...);

void printAt(int x, int y, const char* format, ...);

#endif
