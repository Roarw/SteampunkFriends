#include "DrawHandler.h"
#include "GameWorld.h"

GameWorld * DrawHandler::gameWorld;

void DrawHandler::InitOpenGL()
{
	//Enable smooth shading
	glShadeModel(GL_SMOOTH); 
	//Set clear color
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f); 
	// Set clearing depth for depth buffer
	glClearDepth(1.0f); 
	//Enable depth testing
	glEnable(GL_DEPTH_TEST); 
	//Set depth buffer testing to less then or equal
	glDepthFunc(GL_LEQUAL); 
	//Specifies how colors/textures are interpolized on surfaces
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); 
}

void DrawHandler::Reshape(int width, int height)
{
	//Make sure no divide by zero can happen 
	if (height == 0) { height = 1; } 
	//Reset the current viewport
	glViewport(0, 0, width, height);
	//Specify projection matrix stack
	glMatrixMode(GL_PROJECTION); 
	//Reset projection matrix stack - top matrix
	glLoadIdentity(); 
	//Set perspective to match current display size
	gluPerspective(45.0f, (float)width / height, 0.0f, 100.0f); 
	//Specify model view matrix
	glMatrixMode(GL_MODELVIEW);
	//reset model view matrix - top matrix
	glLoadIdentity(); 
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


void DrawHandler::DrawLine(GLuint texture, float x, float y, float z)
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

	//Fetching screensize (in theory)
	GLint m_viewport[4];
	glGetIntegerv(GL_VIEWPORT, m_viewport);
	//Initialize glut display mode with rgb and alpha colors and Depth
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	//Set window size
	glutInitWindowSize(m_viewport[2], m_viewport[3]); 
	//Set window position
	glutInitWindowPosition(0, 0); 
	//Create GLUT OpenGL Window
	glutCreateWindow("SteamPunk'd"); 
	//Going fullscreen!
	//glutFullScreen();

	InitOpenGL();
	glutReshapeFunc(this->Reshape);
	glutDisplayFunc(this->GameLoop);
	glutKeyboardFunc(this->Keyboard);

	//Enable texture mapping
	glEnable(GL_TEXTURE_2D); 
	//Specify how textures should be interpolized over surfaces 
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}


DrawHandler::~DrawHandler()
{
}
