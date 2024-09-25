#ifndef OBJECT_H
#define OBJECT_H
#include <cglm/mat4.h>
// TODO: whatever this is
struct Object{
    unsigned int VBO, VAO, texture;
    int vSize;
    mat4 model;
    mat4 view;
    mat4 projection;
    float vertices[]; 
};

struct Object initObject(char *tPath, char *mPath);
void drawObject(struct Object *obj);
#endif
