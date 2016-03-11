#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <string>


#ifdef APPLE_COMPILE
#include <OpenGL/gl3.h>
#define GLFW_INCLUDE_NONE
#endif

#ifdef WIN_COMPILE
#include "glew.h"
#endif

#include "glfw3.h"

#ifndef NULL
    #define NULL 0
#endif

#include "png.h"

GLuint compile_shaders(const char * vshader, const char * fshader);
GLFWwindow * InitializeGLFWWindow(unsigned int _width,
                          unsigned int _height,
                          const char * title);

struct openglTexture2DRGBA_UBYTE{
	GLsizei width, height;
	GLsizei bufferlen;
	void * dataptr;
	openglTexture2DRGBA_UBYTE() 
	{	
		width = height = bufferlen = 0;
		dataptr = NULL;
	}
};

typedef openglTexture2DRGBA_UBYTE Texture;

Texture LoadPNGTexture(const char * filename);