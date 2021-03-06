#include "DrawHandler.h"
#include "GameWorld.h"
#include "MyMath.h"

GameWorld * DrawHandler::gameWorld;

float * DrawHandler::discoTime;
float * DrawHandler::red;
float * DrawHandler::green;
float * DrawHandler::blue;
bool * DrawHandler::redUp;
bool * DrawHandler::greenUp;
bool * DrawHandler::blueUp;

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

void DrawHandler::Disco()
{
	if (*discoTime < 0.0f)
	{
		//Disco speed:
		float multiplier = 200.0f;
		//Min value:
		float minValue = 155.0f;
		//More:
		float valueChange = gameWorld->GetDeltaTime() * multiplier;

		if (*redUp)
			*red += valueChange;
		else
			*red -= valueChange;

		if (*greenUp)
			*green += valueChange;
		else
			*green -= valueChange;

		if (*blueUp)
			*blue += valueChange;
		else
			*blue -= valueChange;

		if (*red > 255.0f)
			*redUp = false;
		if (*green > 255.0f)
			*greenUp = false;
		if (*blue > 255.0f)
			*blueUp = false;

		if (*red < minValue)
			*redUp = true;
		if (*green < minValue)
			*greenUp = true;
		if (*blue < minValue)
			*blueUp = true;
	}
	else if (*discoTime < 1000.0f) 
	{
		*discoTime += gameWorld->GetDeltaTime();
	}
	else if (*discoTime >= 1000.0f)
	{
		red = new float(255.0f);
		green = new float(155.0f);
		blue = new float(205.0f);
		*discoTime = -1.0f;
	}
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
	//gluPerspective(45.0f, (float)width / height, 0.0f, 100.0f); //TELL ME WHYYYYYYYYY!!
	glOrtho(0, width, 0, height, -100, 100);
	//Specify model view matrix
	glMatrixMode(GL_MODELVIEW);
	//reset model view matrix - top matrix
	glLoadIdentity(); 
}

void DrawHandler::KeyboardPress(unsigned char key, int x, int y)
{
	//Esc:
	if (key == 27)
		exit(0);
	//Keyboard keys:
	gameWorld->AddKey(key);
}

void DrawHandler::KeyboardRelease(unsigned char key, int x, int y)
{
	//Keyboard keys:
	gameWorld->DeleteKey(key);
}

void DrawHandler::KeyPress(int key, int x, int y)
{
	//Arrow keys:
	gameWorld->AddKey(key);
}

void DrawHandler::KeyRelease(int key, int x, int y)
{
	//Arrow keys:
	gameWorld->DeleteKey(key);
}

void DrawHandler::GameLoop()
{
	gameWorld->Update();
	gameWorld->Draw();

	Disco();
}

void DrawHandler::StartLoop()
{
	glutMainLoop();
}

void DrawHandler::DrawTexture(GLuint texture, float x, float y, float z, float sizeW, float sizeH, bool mirrorX, bool flipX, bool flipY, float angle, float rX, float rY, float rZ)
{
	glPushMatrix(); //Makes sure only this objects uses the current matrix
	glTranslatef(x, y, z);
	glRotatef(angle, rX, rY, rZ);

	glEnable(GL_TEXTURE_2D);

	glColor3f(*red / 256.0f, *green / 256.0f, *blue / 256.0f);

	glBindTexture(GL_TEXTURE_2D, texture); //Bind texture for usage

	glBegin(GL_TRIANGLE_FAN);

	if (mirrorX)
	{
		glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, 0.0f, 0.0f); 
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-sizeW, 0.0f, 0.0f); 
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-sizeW, sizeH, 0.0f); 
		glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0f, sizeH, 0.0f);
	}
	else if (flipX && flipY)
	{
		glTexCoord2f(0.0f, 0.0f); glVertex3f(sizeW, sizeH, 0.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(0.0f, sizeH, 0.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(0.0f, sizeH, 0.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(sizeW, 0.0f, 0.0f);
	}
	else if (flipX)
	{
		glTexCoord2f(0.0f, 0.0f); glVertex3f(sizeW, 0.0f, 0.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(0.0f, 0.0f, 0.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(0.0f, sizeH, 0.0f); 
		glTexCoord2f(0.0f, 1.0f); glVertex3f(sizeW, sizeH, 0.0f);
	}
	else if (flipY)
	{
		glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, sizeH, 0.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(sizeW, sizeH, 0.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(sizeW, 0.0f, 0.0f); 
		glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0f, 0.0f, 0.0f); 
	}
	else
	{
		// Front Face
		glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, 0.0f, 0.0f); //glVertex3f(-1.0f, -1.0f, 10.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(sizeW, 0.0f, 0.0f); //glVertex3f(1.0f, -1.0f, 10.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(sizeW, sizeH, 0.0f); //glVertex3f(1.0f, 1.0f, 10.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0f, sizeH, 0.0f); //glVertex3f(-1.0f, 1.0f, 10.0f);		
	}

	glEnd();

	glDisable(GL_TEXTURE_2D);	

	glPopMatrix();
}

void DrawHandler::DrawBox(RectangleF aRect, float R, float G, float B)
{
	glPushMatrix(); //Makes sure only this objects uses the current matrix
	glTranslatef(aRect.X, aRect.Y, 1.0f);

	glLineWidth(4);
	glColor3f(R, G, B);
	glBegin(GL_LINE_LOOP);

	glVertex2f(0, 0);
	glVertex2f(aRect.Width, 0);
	glVertex2f(aRect.Width, aRect.Height);
	glVertex2f(0, aRect.Height);

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
	glutInitWindowSize(1280, 900); 
	//Set window position
	glutInitWindowPosition(0, 0); 
	//Create GLUT OpenGL Window
	glutCreateWindow("SteamPunk'd"); 
	//Going fullscreen!
	//glutFullScreen();

	discoTime = new float(1.0f);
	red = new float(256.0f);
	green = new float(256.0f);
	blue = new float(256.0f);
	redUp = new bool(true);
	greenUp = new bool(true);
	blueUp = new bool(true);

	InitOpenGL();
	glutReshapeFunc(this->Reshape);
	glutDisplayFunc(this->GameLoop);
	glutKeyboardFunc(this->KeyboardPress);
	glutKeyboardUpFunc(this->KeyboardRelease);
	glutSpecialFunc(this->KeyPress);
	glutSpecialUpFunc(this->KeyRelease);

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glClearColor(0.0, 0.0, 0.0, 0.0);

	//Enable texture mapping
	glEnable(GL_TEXTURE_2D); 
	//Specify how textures should be interpolized over surfaces 
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}


DrawHandler::~DrawHandler()
{
	delete discoTime;
	delete red;
	delete green;
	delete blue;
	delete redUp;
	delete greenUp;
	delete blueUp;
}
