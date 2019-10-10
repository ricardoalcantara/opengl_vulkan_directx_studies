#version 330 core
layout (location = 0) in vec3 aPos;   // the position variable has attribute position 0
layout (location = 1) in vec3 aColor;   // the position variable has attribute position 0
layout (location = 2) in vec2 aTexCoord;   // the position variable has attribute position 0

out vec3 ourColor;
out vec2 texCoord;

void main()
{
    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
    ourColor = aColor;
    texCoord = aTexCoord;
}