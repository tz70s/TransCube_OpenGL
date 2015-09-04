#ifndef _data_
#define _data_
#include <GL/glew.h>
#include <GL/freeglut.h>

class data
{
    static const GLfloat dataver1[][3] ={
		{-.5f, -.5f,  -.5f }, 
     { .5f,  -.5f, -.5f },
     {  .5f, .5f, -.5f},
     {  -.5f, .5f,  -.5f }, 
     { -.5f, -.5f, .5f }, 
     { .5f,  -.5f, .5f }, 
     {  .5f,  .5f, .5f }, 
     {  -.5f, .5f, .5f }
	};
	static const unsigned int dataind1[] = { 
        0,4,5,
        0,5,1,
        1,5,6,
        1,6,2,
        2,6,7,
        2,7,3,
        3,7,4,
        3,4,0,
        4,7,6,
        4,6,5,
        3,0,1,
        3,1,2
    };
};

#endif