#version 330

layout (location = 0) in vec3 Position;

out vec4 ex_Color;

uniform mat4 ModelMatrix;
uniform mat4 ViewMatrix;
uniform mat4 ProjectionMatrix;

void main()
{
    gl_Position =  ProjectionMatrix*ViewMatrix*ModelMatrix*vec4(Position, 1.5);
    ex_Color = vec4(clamp(Position, 0.0, 1.0), 1.0);
}

