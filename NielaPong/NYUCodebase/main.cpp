
#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>
#include <math.h>

using namespace std;

SDL_Window* displayWindow;


struct LeftBumper {
	LeftBumper(GLint texture, float x, float y, float rotation):texture(texture), x(x), y(y), rotation(rotation){};

	GLint texture;
	float x;
	float y;
	float rotation;
	float leftx = -1.3f;
	float rightx = -1.25f;
	float upy = 0.0f;
	float downy = -0.3f;
	void setup() {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		glTranslatef(x, y, 0.0);
		glRotatef(rotation, 0.0, 0.0, 1.0);

		GLfloat quad[] = { -1.3f, upy, -1.3f, downy, -1.25f, downy, -1.25f, upy };
		rightx = quad[4];
		glVertexPointer(2, GL_FLOAT, 0, quad);
		glEnableClientState(GL_VERTEX_ARRAY);

		GLfloat quadUVs[] = { 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 0.0 };
		glTexCoordPointer(2, GL_FLOAT, 0, quadUVs);
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glDrawArrays(GL_QUADS, 0, 4);

		glDisable(GL_TEXTURE_2D);
	}
};

struct RightBumper {

	RightBumper(GLint texture, float x, float y, float rotation) :texture(texture), x(x), y(y), rotation(rotation){};
	GLint texture;
	float x;
	float y;
	float rotation;

	void setup() {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		glTranslatef(x, y, 0.0);
		glRotatef(rotation, 0.0, 0.0, 1.0);

		GLfloat quad[] = { 1.3f, 0.0f, 1.3f, -0.3f, 1.25f, -0.3f, 1.25f, 0.0f };
		glVertexPointer(2, GL_FLOAT, 0, quad);
		glEnableClientState(GL_VERTEX_ARRAY);

		GLfloat quadUVs[] = { 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 0.0 };
		glTexCoordPointer(2, GL_FLOAT, 0, quadUVs);
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glDrawArrays(GL_QUADS, 0, 4);
		glDisable(GL_TEXTURE_2D);
	}
};

struct BallSprite {
	BallSprite(GLint texture, float x, float y, float rotation) :texture(texture), x(x), y(y), rotation(rotation){};
	GLint texture;
	float x;
	float y;
	float rotation;
	float leftx = 0.0f;
	float rightx = 0.03f;
	float upy = 0.03f;
	float downy = 0.0f;
	void setup() {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		glTranslatef(x, y, 0.0);
		glRotatef(rotation, 0.0, 0.0, 1.0);

		GLfloat quad[] = { 0.0f, upy, 0.0f, downy, rightx, downy, rightx, upy };
		leftx = quad[2];
		glVertexPointer(2, GL_FLOAT, 0, quad);
		glEnableClientState(GL_VERTEX_ARRAY);

		GLfloat quadUVs[] = { 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 0.0 };
		glTexCoordPointer(2, GL_FLOAT, 0, quadUVs);
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glDrawArrays(GL_QUADS, 0, 4);

		glDisable(GL_TEXTURE_2D);
	}
};

void Bandup(GLint texture, float x, float y, float rotation) {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(x, y, 0.0);
	glRotatef(rotation, 0.0, 0.0, 1.0);

	GLfloat top[] = { -1.33f, 0.8f, -1.33f, 0.78f, 1.33f, 0.78f, 1.33f, 0.8f };
	glVertexPointer(2, GL_FLOAT, 0, top);
	glEnableClientState(GL_VERTEX_ARRAY);

	GLfloat quadUVs[] = { 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 0.0 };
	glTexCoordPointer(2, GL_FLOAT, 0, quadUVs);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glDrawArrays(GL_QUADS, 0, 4);

	glDisable(GL_TEXTURE_2D);
}

void Banddown(GLint texture, float x, float y, float rotation) {
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, texture);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(x, y, 0.0);
	glRotatef(rotation, 0.0, 0.0, 1.0);
	GLfloat quad[] = { -1.33f, -0.78f, -1.33f, -0.8f, 1.33f, -0.8f, 1.33f, -0.78f };
	glVertexPointer(2, GL_FLOAT, 0, quad);
	glEnableClientState(GL_VERTEX_ARRAY);

	GLfloat quadUVs[] = { 0.0, 0.0, 0.0, 1.0, 1.0, 1.0, 1.0, 0.0 };
	glTexCoordPointer(2, GL_FLOAT, 0, quadUVs);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glDrawArrays(GL_QUADS, 0, 4);

	glDisable(GL_TEXTURE_2D);
}

int main(int argc, char *argv[])
{
	SDL_Init(SDL_INIT_VIDEO);
	displayWindow = SDL_CreateWindow("My Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_OPENGL);
	SDL_GLContext context = SDL_GL_CreateContext(displayWindow);
	SDL_GL_MakeCurrent(displayWindow, context);

	glViewport(0, 0, 800, 600);

	glMatrixMode(GL_PROJECTION);

	glOrtho(-1.33, 1.33, -1.0, 1.0, -1.0, 1.0);


	bool done = false;

	SDL_Event event;

	float lastFrameTicks = 0.0f;
	float leftShiftY = 0.0;
	float rightShiftY = 0.0;

	float ballPositionX = 0.0;
	float ballPositionY = 0.0;


	while (!done) {


		glClear(GL_COLOR_BUFFER_BIT);

		float ticks = (float)SDL_GetTicks() / 1000.0f;
		float elapsed = ticks - lastFrameTicks;
		lastFrameTicks = ticks;

		ballPositionX += elapsed*cos(3.14159265)*0.5;
		ballPositionY += elapsed*sin(3.14159265)*0.2;

		const Uint8 *keys = SDL_GetKeyboardState(NULL);
		if (keys[SDL_SCANCODE_W]) {

			leftShiftY += elapsed*0.5;
		}
		else if (keys[SDL_SCANCODE_S]) {
			leftShiftY += elapsed*(-0.5);
		}

		if (keys[SDL_SCANCODE_O]) {
			rightShiftY += elapsed*0.5;
		}
		else if (keys[SDL_SCANCODE_L]) {
			rightShiftY += elapsed*(-0.5);
		}
		Bandup(0, 0, 0, 0);
		Banddown(0, 0, 0, 0);

		LeftBumper L(0, 0, leftShiftY, 0);
		L.setup();
		RightBumper R(0, 0, rightShiftY, 0);
		R.setup();
		BallSprite B(0, ballPositionX, ballPositionY, 0);
		B.setup();
		if (B.upy > 0.78f){
			ballPositionY += elapsed*sin(270/3.14159265)*0.2;
		}
		if (B.leftx < L.rightx){
			ballPositionX += elapsed*cos(180/3.14159265)*(0.5);
		}

		//glDrawArrays(GL_QUADS, 0, 4);
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT || event.type == SDL_WINDOWEVENT_CLOSE) {
				done = true;
			}
			//else if (event.type == SDL_KEYDOWN) {
			//	if (event.key.keysym.scancode == SDL_SCANCODE_DOWN){
			//	}
			//}
		}
		SDL_GL_SwapWindow(displayWindow);
	}

	SDL_Quit();
	return 0;
}