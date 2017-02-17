#include "DrawHandler.h"
#include "GameWorld.h"

GameWorld * DrawHandler::gameWorld;

void DrawHandler::InitOpenGL()
{
	glShadeModel(GL_SMOOTH); //Enable smooth shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f); //Set clear color
	glClearDepth(1.0f); // Set clearing depth for depth buffer
	glEnable(GL_DEPTH_TEST); //Enable depth testing
	glDepthFunc(GL_LEQUAL); //Set depth buffer testing to less then or equal

	//Specifies how colors/textures are interpolized on surfaces
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); 
}

void DrawHandler::Reshape(int width, int height)
{
	if (height == 0) { height = 1; } //Make sure no divide by zero can happen 
	glViewport(0, 0, width, height);//Reset the current viewport

	glMatrixMode(GL_PROJECTION); //Specify projection matrix stack
	glLoadIdentity(); //Reset projection matrix stack - top matrix

	//Set perspective to match current display size
	gluPerspective(45.0f, width / height, 0.0f, 100.0f); 

	glMatrixMode(GL_MODELVIEW); //Specify model view matrix
	glLoadIdentity(); //reset model view matrix - top matrix
}

void DrawHandler::Keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27: //ESC
		exit(0);
		break;
	default:
		break;
	}

}

void DrawHandler::GameLoop()
{
	gameWorld->Update();
	gameWorld->Draw();
}

void DrawHandler::StartLoop()
{
	glutMainLoop();
}

void DrawHandler::DrawTexture(GLuint texture, float x, float y, float z)
{
	glPushMatrix(); //Makes sure only this objects uses the current matrix
	glTranslatef(x, y, z);

	glBindTexture(GL_TEXTURE_2D, texture); //Bind texture for usage
	glBegin(GL_TRIANGLE_FAN);
	// Front Face
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	glEnd();

	glPopMatrix();
}

void DrawHandler::BeginDraw()
{
	//Clear color and depth buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
	//loads the identity matrix on the matrix stack - essentially resetting any other matrixes
	glLoadIdentity(); 
	//World starting matrix. (Will draw things smaller because we're 'zooming' out on z)
	glTranslatef(0.0f, 0.0f, -12.0f);
}

void DrawHandler::EndDraw()
{
	glutSwapBuffers();
	glutPostRedisplay();
}

DrawHandler::DrawHandler(GameWorld * gameWorld, int argc, char** argv)
{
	this->gameWorld = gameWorld;

	glutInit(&argc, argv);//Init GLUT

	//Initialize glut display mode with rgb and alpha colors and Depth
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH); 
	glutInitWindowSize(600, 600); //Set window size
	glutInitWindowPosition(0, 0); //Set window position

	glutCreateWindow("Game Name"); //Create GLUT OpenGL Window

	InitOpenGL();
	glutReshapeFunc(this->Reshape);
	glutDisplayFunc(this->GameLoop);
	glutKeyboardFunc(this->Keyboard);

	//Enable texture mapping
	glEnable(GL_TEXTURE_2D); 
	//Specify how textures should be interpolized over surfaces 
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); 
	//Specify how textures should be interpolized over surfaces
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); 
}


DrawHandler::~DrawHandler()
{
}
