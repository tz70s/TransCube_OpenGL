#include <iostream>
#include <fstream>
#include <cstring>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include "shader_load.h"
using namespace std;

void shader_load::loadFile(const char* filename, string &string )
{
	fstream fp;
          fp.open(filename,ios::in);
	if( !fp.is_open() )
	{
      cout << "Open <" << filename << "> error." << endl;
    	}
   	char temp[300];
   	while( !fp.eof() )
   	{
      fp.getline( temp, 300 );
      string += temp;
      string += '\n';
   	}
   	fp.close(); 
}

GLuint shader_load::loadShader(string &source, GLenum type)
{
      GLuint ShaderID;
      ShaderID = glCreateShader( type );     

      const char* csource = source.c_str();   
   
      glShaderSource( ShaderID, 1, &csource, NULL );   
      glCompileShader( ShaderID );                    
      char error[1000] = "";
      glGetShaderInfoLog( ShaderID, 1000, NULL, error );  
      cout << "Complie status: \n" << error << std::endl;  
      return ShaderID;
}

void shader_load::initShader(const char* vname, const char* fname)
{
   string source;
   loadFile( vname, source );    
   vs = loadShader( source, GL_VERTEX_SHADER ); 
   source = "";
   loadFile( fname, source );
   fs = loadShader( source, GL_FRAGMENT_SHADER );

   program = glCreateProgram();  
   glAttachShader( program, vs );  
   glAttachShader( program, fs ); 

   glLinkProgram( program );   
   glUseProgram( program );   
}

