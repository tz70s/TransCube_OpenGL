#ifndef __shader_load__
#define __shader_load__
#include <iostream>
#include <cstring>
#include <GL/glew.h>
#include <GL/freeglut.h>
using namespace std;

class shader_load
{
public:
	void loadFile( const char* filename, string &string ) ;
	GLuint loadShader(string &source, GLenum type) ;
	void initShader(const char* vname, const char* fname);
	GLuint vs,fs,program;
};

#endif