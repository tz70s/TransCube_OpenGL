#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>
#include <cmath>
#include "shader_load.h"
#include "Utils.h"
#include <pthread.h>
using namespace std;

#define width 1024
#define high 768

//global 

GLuint VBO, IBO;
GLuint ProMatloc,ViewMatloc,ModMatloc,extMatloc;
Matrix ProjectionMatrix , ViewMatrix, ModelMatrix , ExtentMatrix;
GLuint program;

int CurrentWidth , CurrentHeight;
float move_x =0;
float move_y =0;
float flag=0;

float ext_x=0.0001;


void animate();
void set_matrix();
void RenderSceneCB();
void ResizeFunction();
void InitializeGlutCallbacks();
void CreateVertexBuffer();
void CreateIndexBuffer();
void init_matrix();
void init_window(int argc, char **argv);
void junk();
void mouse(int button,int state,int x,int y);

int main(int argc, char** argv)
{
    //initialized glut and glew
    init_window(argc,argv);
    init_matrix();
    InitializeGlutCallbacks();
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}

void init_window(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA);
    glutInitWindowSize(1024, 768);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Experiment : 01");
    
    // Must be done after glut is initialized!
    GLenum res = glewInit();
    if (res != GLEW_OK)
    {
        std::cout<<glewGetErrorString(res);
    }
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    

    glDepthFunc(GL_LESS);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glFrontFace(GL_CCW);

    std:cout<<"\n"<<glGetString(GL_VERSION)<<"\n"<<endl;

}

void mouse(int button,int state,int x,int y)
{
	switch(button)
	{
	case GLUT_LEFT_BUTTON:
		if(GLUT_DOWN==state)
		{
			glutIdleFunc(RenderSceneCB);
		}
		else
		{
			//glutIdleFunc(0);
		}
	}
}

void init_matrix()
{
    //VOA
    //call the shader_load class 
    //make the linker between vertext shader, fragment shader and program
    shader_load load_shader;
    load_shader.initShader("vertext.vs","fragment.fs");
    program = load_shader.program;
    //uniform location init
    ModMatloc = glGetUniformLocation(load_shader.program, "ModelMatrix");
    ProMatloc = glGetUniformLocation(load_shader.program, "ProjectionMatrix");
    ViewMatloc = glGetUniformLocation(load_shader.program, "ViewMatrix");
    //VOB
    
    ProjectionMatrix = IDENTITY_MATRIX;
    ViewMatrix = IDENTITY_MATRIX;
    ModelMatrix = IDENTITY_MATRIX;
    gluPerspective(30.f, 1 ,0.01f ,1000.0f);
    RotateAboutX(&ModelMatrix,10);
    RotateAboutY(&ModelMatrix,10);
    ExtensionX(&ModelMatrix,0);
    //ProjectionMatrix =CreateProjectionMatrix(45.f, 0.75,0.01f,1000.0f);
    TranslateMatrix(&ViewMatrix, 0 , 0, 0);
}

void CreateVertexBuffer()
{
    const GLfloat vertices[][3] =
{
     {-.5f, -.5f,  -.5f }, 
     { .5f,  -.5f, -.5f },
     {  .5f, .5f, -.5f},
     {  -.5f, .5f,  -.5f }, 
     { -.5f, -.5f, .5f }, 
     { .5f,  -.5f, .5f }, 
     {  .5f,  .5f, .5f }, 
     {  -.5f, .5f, .5f }
                      };
    
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
}

void CreateIndexBuffer()
{
    const unsigned int indicies[] = { 
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
    glGenBuffers(1, &IBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indicies),indicies, GL_STATIC_DRAW);
}


void ResizeFunction(int Width, int Height)
{
    CurrentWidth = Width;
    CurrentHeight = Height;
    glViewport(0, 0, CurrentWidth, CurrentHeight);
    ProjectionMatrix =
    CreateProjectionMatrix(
      60,
      (float)CurrentWidth / CurrentHeight,
      1.0f,
      100.0f
    );
}

void InitializeGlutCallbacks()
{
    CreateVertexBuffer();
    CreateIndexBuffer();
    //glutReshapeFunc(ResizeFunction);
    glUniformMatrix4fv(ProMatloc, 1, GL_TRUE, &ProjectionMatrix.m[0]);
    glutDisplayFunc(RenderSceneCB);
    glutIdleFunc(RenderSceneCB);
}

void animate()
{
    move_x=0.0005;
    move_y=0.0005;
    flag=flag+ext_x;
    if(flag>0.1)
    ext_x=-1 * ext_x;
    else if(flag<-0.1)
    ext_x=-1 * ext_x;
    cout<<ext_x<<endl;
    
}

void set_matrix()
{
    glUniformMatrix4fv(ModMatloc, 1, GL_TRUE, &ModelMatrix.m[0]);
    glUniformMatrix4fv(ViewMatloc, 1, GL_TRUE, &ViewMatrix.m[0]);
    animate();
    //Extent in Y
    //ExtensionX(&ModelMatrix,ext_x);
    
    RotateAboutX(&ModelMatrix,move_x);
    RotateAboutY(&ModelMatrix,move_y);
    glutPostRedisplay();
}

void RenderSceneCB()
{
    glClear(GL_COLOR_BUFFER_BIT);
    set_matrix();
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER,VBO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE,0,0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
    glDrawElements(GL_TRIANGLES,36,GL_UNSIGNED_INT,0);
    glDisableVertexAttribArray(0);
    glutSwapBuffers();
}
void junk() {
    int i;
    i=pthread_getconcurrency();
};