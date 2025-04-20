#include <SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <cmath>

void drawCube(float angle) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -5.0f);
    glRotatef(angle, 1.0f, 1.0f, 1.0f);

    glBegin(GL_QUADS);
    glColor3f(1, 0, 0); glVertex3f(1, 1, -1); glVertex3f(-1, 1, -1); glVertex3f(-1, 1, 1); glVertex3f(1, 1, 1);     // Top
    glColor3f(0, 1, 0); glVertex3f(1, -1, 1); glVertex3f(-1, -1, 1); glVertex3f(-1, -1, -1); glVertex3f(1, -1, -1); // Bottom
    glColor3f(0, 0, 1); glVertex3f(1, 1, 1); glVertex3f(-1, 1, 1); glVertex3f(-1, -1, 1); glVertex3f(1, -1, 1);     // Front
    glColor3f(1, 1, 0); glVertex3f(1, -1, -1); glVertex3f(-1, -1, -1); glVertex3f(-1, 1, -1); glVertex3f(1, 1, -1); // Back
    glColor3f(1, 0, 1); glVertex3f(-1, 1, 1); glVertex3f(-1, 1, -1); glVertex3f(-1, -1, -1); glVertex3f(-1, -1, 1); // Left
    glColor3f(0, 1, 1); glVertex3f(1, 1, -1); glVertex3f(1, 1, 1); glVertex3f(1, -1, 1); glVertex3f(1, -1, -1);     // Right
    glEnd();
}

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("Spinning Cube",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600,
        SDL_WINDOW_OPENGL);
    SDL_GLContext context = SDL_GL_CreateContext(window);

    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);
    gluPerspective(70.0, 800.0 / 600.0, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);

    bool running = true;
    SDL_Event event;
    float angle = 0.0f;

    while (running) {
        while (SDL_PollEvent(&event))
            if (event.type == SDL_QUIT)
                running = false;

        drawCube(angle);
        SDL_GL_SwapWindow(window);
        angle += 1.0f;
    }

    SDL_GL_DeleteContext(context);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
