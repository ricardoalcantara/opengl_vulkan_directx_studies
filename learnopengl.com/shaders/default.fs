#version 330 core
out vec4 FragColor;  

in vec2 texCoord;

uniform float time;
uniform sampler2D texture1;
uniform sampler2D texture2;

void main()
{
    // FragColor = texture(texture2, texCoord);
    FragColor = mix(texture(texture1, texCoord), texture(texture2, texCoord), 0.2);
}