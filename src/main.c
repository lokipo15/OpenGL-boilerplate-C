#include <SDL.h>
#include <SDL_events.h>
#define GLEW_STATIC
#include <GL/glew.h>
#include <SDL_opengl.h>
#include <SDL_video.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  SDL_Init(SDL_INIT_VIDEO);

  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
  SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

  /* Create a Window */
  SDL_Window *window =
      SDL_CreateWindow("OpenGL", 100, 100, 800, 600, SDL_WINDOW_OPENGL);

  // Create the context
  SDL_GLContext glContext = SDL_GL_CreateContext(window);

  // Initialize GLEW
  glewExperimental = GL_TRUE;
  glewInit();

  // GLEW Test
  GLuint vertexBuffer;
  glGenBuffers(1, &vertexBuffer);

  printf("%u\n", vertexBuffer);

  // Program event loop
  SDL_Event windowEvent;
  while (1) {
    if (SDL_PollEvent(&windowEvent)) {
      if (windowEvent.type == SDL_QUIT)
        break;
    }

    SDL_GL_SwapWindow(window);
  }

  SDL_GL_DeleteContext(glContext);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
