#ifndef DRAWHANDLER_H
#define DRAWHANDLER_H

#include "GL\glut.h"
#include "soil.h"
#include <vector>
#include "Vector2.h"
#include "RectangleF.h"

class GameWorld;

class DrawHandler
{
private:
	static GameWorld * gameWorld;
	void InitOpenGL();
public:
	static void Reshape(int width, int height);
	static void Keyboard(unsigned char key, int x, int y);
	static void GameLoop();
	
	void StartLoop();
	void DrawTexture(GLuint texture, float x, float y, float z);
	void DrawBox(RectangleF aRect, float R, float G, float B);
	void BeginDraw();
	void EndDraw();

	DrawHandler(GameWorld * gameWorld, int argc, char** argv);
	~DrawHandler();
};
#endif // !DRAWHANDLER_H
