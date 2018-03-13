// A Simple OpenGL Project
// Author: Michael Hall
//
// This C++ code and project are provided "as is" without warranty of any kind.
//
// Copyright 2010 XoaX - For personal use only, not for distribution

#include "draw.h"

static std::unordered_map<LineSegments, bool> lineseg_arr;
static std::unordered_map<std::string, Point> point_arr;

void DrawSegments()
{
	for (std::pair<LineSegment, bool> lseg : lineseg_arr){
		String pt_1 = *(lseg.first.point1_labels.begin());
		String pt_2 = *(lseg.first.point2_labels.begin());
		glBegin(GL_LINES);
			glVertex3f(point_arr[pt_1].x_coord, point_arr[pt_1].y_coord, point_arr[pt_1].z_coord);
			glVertex3f(point_arr[pt_2].x_coord, point_arr[pt_2].y_coord, point_arr[pt_2].z_coord);
		glEnd();
	}
}

void Draw() {
	glClear(GL_COLOR_BUFFER_BIT);
	DrawSegments();
	glFlush();
}

void Initialize() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

void render(Solid *sptr, int iArgc, char** cppArgv) {
	glutInit(&iArgc, cppArgv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(250, 250);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("render");
	Initialize();
	lineseg_arr = sptr -> lineseg_arr;
	point_arr = sptr -> point_arr;
	glutDisplayFunc(Draw);
	glutMainLoop();
}

void render(Projection *pptr, int iArgc, char** cppArgv) {
	glutInit(&iArgc, cppArgv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(250, 250);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("XoaX.net");
	Initialize();
	lineseg_arr = sptr -> lineseg_arr;
	point_arr = sptr -> point_arr;
	glutDisplayFunc(Draw);
	glutMainLoop();
}