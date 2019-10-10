#ifndef TEXTURE_H
#define TEXTURE_H

#include <glad/glad.h>
#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

class Texture2D
{
public:
    GLuint ID;
public:
    Texture2D(const GLchar* texPath)
    {
        stbi_set_flip_vertically_on_load(true);
        int width, height, nrChannels;
        unsigned char *data = stbi_load(texPath, &width, &height, &nrChannels, 0); 

        if (data)
        {
            glGenTextures(1, &ID);
            glBindTexture(GL_TEXTURE_2D, ID);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_LINEAR);
            std::cout << nrChannels << std::endl;
            glTexImage2D(GL_TEXTURE_2D, 0, (nrChannels == 3 ? GL_RGB : GL_RGBA), width, height, 0, (nrChannels == 3 ? GL_RGB : GL_RGBA) , GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(GL_TEXTURE_2D);

            glBindTexture(GL_TEXTURE_2D, 0);
        }
        else
        {
            std::cout << "Failed to load texture: " << std::string(texPath) << std::endl;
        }
        

        stbi_image_free(data);
    }
};
#endif