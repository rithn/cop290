
#include "../include/draw.h"

static std::unordered_map<std::pair<std::string, std::string>, bool, pairhash> lineseg_arr;
static std::unordered_map<std::string, Point> point_arr;

const char* windowname = "render";

bool swAxes = true;
bool swValues = true;
bool drawproj = true;

Line pax1, pax2;
Point origin;

int theta = 0;
int phi = 0;

void printv(va_list args, const char* format){
	char buf[8192];
	char* ch = buf;
	vsnprintf(buf, 8192, format, args);
	while (*ch){
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, *ch++);
	}	
}

void print(const char* format, ...)
{
	va_list args;
	va_start(args, format);
	printv(args, format);
	va_end(args);
}

void DrawAxes()
{
	if (swAxes){
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_LINES);
		glVertex3f(0.0,0.0,0.0);
		glVertex3f(2.0,0.0,0.0);
		glVertex3f(0.0,0.0,0.0);
		glVertex3f(0.0,2.0,0.0);
		glVertex3f(0.0,0.0,0.0);
		glVertex3f(0.0,0.0,2.0);
		glEnd();
		
		glRasterPos3d(2.0, 0.0, 0.0);
		print("X");
		glRasterPos3d(0.0, 2.0, 0.0);
		print("Y");
		glRasterPos3d(0.0, 0.0, 2.0);
		print("Z");
	}
};

/* void DrawValues(){
	if (swValues){
		glColor3f(1.0, 1.0, 1.0);
		printf("in drawvals\n");
		printAt(5, 5, "Angle: (%d %d)", theta, phi);
		printf("in drawvals end\n");
	}
} */

void DrawSegments()
{
	for (std::pair<std::pair<std::string, std::string>, bool> lseg : lineseg_arr){
		std::string pt_1 = lseg.first.first;
		std::string pt_2 = lseg.first.second;
		glBegin(GL_LINES);
			glVertex3f(point_arr[pt_1].x_coord, point_arr[pt_1].y_coord, point_arr[pt_1].z_coord);
			glVertex3f(point_arr[pt_2].x_coord, point_arr[pt_2].y_coord, point_arr[pt_2].z_coord);
		glEnd();
	}
}

void windowKey(unsigned char key, int x, int y ){
	if (key == 27)
		glutLeaveMainLoop();
	else if (key == 'a' | key == 'A')
		swAxes = not swAxes;
	else if (key == 'v' | key == 'V')
		swValues = not swValues;
	else if (key == 't' | key == 'T')
		phi += 5;
	else if (key == 'g' | key == 'G')
		phi -= 5;
	else if (key == 'f' | key == 'F')
		theta += 5;
	else if (key == 'h' | key == 'H')
		theta -= 5;
	glutPostRedisplay();
	
}

void windowSpecial(int key, int x, int y){
	if (key = GLUT_KEY_RIGHT) theta += 5;
	else if (key = GLUT_KEY_LEFT) theta -= 5;
	else if (key = GLUT_KEY_UP) phi += 5;
	else if (key = GLUT_KEY_DOWN) phi -= 5;
	printf("theta: %d phi: %d\n", theta, phi);
	glutPostRedisplay();
}

void Draw() {
	
	// printf("in draw draw\n");
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	
	glScalef(0.5, 0.5, 0.5);
	glRotated(phi, 1, 0, 0);
	glRotated(theta, 0, 1, 0);
	glTranslated(-0.5, -0.5, -0.5);
	
	DrawAxes();
	//printf("in draw ax\n");
	//DrawValues();
	//printf("in draw val\n");
	DrawSegments();
	//printf("in draw segs\n");
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
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION);
	lineseg_arr = sptr -> lineseg_arr;
	point_arr = sptr -> point_arr;
	glutDisplayFunc(Draw);
	glutKeyboardFunc(windowKey);
	glutSpecialFunc(windowSpecial);
	glutMainLoop();
}

void render(Projection *pptr, int iArgc, char** cppArgv) {
    glutInit(&iArgc, cppArgv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(250, 250);
	glutInitWindowPosition(200, 200);
	glutCreateWindow(windowname);
	// printf("in render p\n");
	Initialize();
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION);
	lineseg_arr = pptr->lineseg_arr;
	// printf("in render pr\n");
	point_arr = pptr->point_arr;
	pax1 = pptr -> axis1;
	pax2 = pptr -> axis2;
	origin = pptr -> origin;
	Point dummy;
	for (std::pair<std::string, Point> pt: point_arr){
		dummy.x_coord = pt.second.x_coord * pax1.dir_rat1 + pt.second.y_coord * pax2.dir_rat1 + origin.x_coord;
		dummy.y_coord = pt.second.x_coord * pax1.dir_rat2 + pt.second.y_coord * pax2.dir_rat2 + origin.y_coord;
		dummy.z_coord = pt.second.x_coord * pax1.dir_rat3 + pt.second.y_coord * pax2.dir_rat3 + origin.z_coord;
		point_arr[pt.first] = dummy;
		printf("---------------------------------------------\n");
		dummy.disppt();
	}
	glutDisplayFunc(Draw);
	glutKeyboardFunc(windowKey);
	//glutSpecialFunc(windowSpecial);
	glutMainLoop();
	std::cout << "###########################" << std::endl;
}
