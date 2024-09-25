#include "object.h"
#include "../utils/loadObj/loadObj.h"
#include "../../lib/glad/glad/glad.h"
#include "../stb_image.h"
#include <GL/gl.h>
#include <cglm/mat4.h>
#include <string.h>
struct Object initObject(char *tPath, char *mPath){
    int width, height, nrCh;
    unsigned char *data = stbi_load(tPath, &width, &height, &nrCh, 0);
    int v = meshSize(mPath);
    struct Object *obj = malloc((sizeof(struct Object)+v) * sizeof(float));
    obj->vSize = v;
    glGenTextures(1, &obj->texture);
    glBindTexture(GL_TEXTURE_2D, obj->texture);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    if(!data){
        printf("texture loading failed\n");
    }
    
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);

    stbi_image_free(data);

    loadObj(mPath, obj->vertices);

    glGenVertexArrays(1, &obj->VAO);
    glGenBuffers(1, &obj->VBO);

    glBindVertexArray(obj->VAO);

    glBindBuffer(GL_ARRAY_BUFFER, obj->VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float)*(v+1), obj->vertices, GL_STATIC_DRAW);
    

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);
    
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *)(3*sizeof(float)));
    glEnableVertexAttribArray(1);   

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);

    memcpy(obj->model, GLM_MAT4_IDENTITY, sizeof(mat4));
    memcpy(obj->view, GLM_MAT4_IDENTITY, sizeof(mat4));
    // !!!!!!! 
    return *obj;
}


void drawObject(struct Object *obj){
    glBindTexture(GL_TEXTURE_2D, obj->texture);
    glBindVertexArray(obj->VAO);

    glDrawArrays(GL_TRIANGLES, 0, (int)(obj->vSize-(((obj->vSize)/5)*2)));

    glBindVertexArray(0);
};
