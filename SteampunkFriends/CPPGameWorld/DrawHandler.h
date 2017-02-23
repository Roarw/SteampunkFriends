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

	static float * red;
	static float * green;
	static float * blue;
	static float * counter;
public:
	static void Reshape(int width, int height);
	static void KeyboardPress(unsigned char key, int x, int y);
	static void KeyboardRelease(unsigned char key, int x, int y);
	static void KeyPress(int key, int x, int y);
	static void KeyRelease(int key, int x, int y);
	static void GameLoop();
	
	void StartLoop();
	void DrawTexture(GLuint texture, float x, float y, float z, float sizeW, float sizeH, bool mirrorX = false, bool flipX = false, bool flipY = false, float angle = 0, float rX = 0, float rY = 0, float rZ = 1);
	void DrawBox(RectangleF aRect, float R, float G, float B);
	void BeginDraw();
	void EndDraw();

	DrawHandler(GameWorld * gameWorld, int argc, char** argv);
	~DrawHandler();
};
#endif // !DRAWHANDLER_H
