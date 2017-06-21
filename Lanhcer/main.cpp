// Code 
#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>

using namespace std;
typedef int (*MsgFunctioned) (int);

HINSTANCE hinstDLL;
HWND windowhandle = FindWindow(NULL, "GTA: San Andreas"); 
void changeViewPort(int w, int h)
{
	glViewport(0, 0, w, h);
}

void render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glutSwapBuffers();
}



int main(int argc, char* argv[]) {
	//-----------------
	MsgFunctioned FuncOpenDLL(0);
	hinstDLL = LoadLibrary("Lancher.dll"); // dll loc
	if(hinstDLL != 0)
	{
		FuncOpenDLL = (MsgFunctioned)GetProcAddress(hinstDLL, "FuncOpenDLL"); // All tybe in fund main or h
	}
	
	FuncOpenDLL(5);
	
	FreeLibrary(hinstDLL);
	
	if(windowhandle) // if gta open we can add NULL 
	{
	//---------------
	// Initialize GLUT
	glutInit(&argc, argv);
	// Set up some memory buffers for our display
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	// Set the window size
	glutInitWindowSize(800, 600);
	// Create the window with the title "Hello,GL"
	glutCreateWindow("GTA SA Lancher Beta [in program ]");
	// Bind the two functions (above) to respond when necessary
	glutReshapeFunc(changeViewPort);
	glutDisplayFunc(render);

	// Very important!  This initializes the entry points in the OpenGL driver so we can 
	// call all the functions in the API.
	GLenum err = glewInit();
	
	if (GLEW_OK != err) {
		fprintf(stderr, "GLEW error");
		return 1;
	}
	}


	glutMainLoop();
	return 0;
}
