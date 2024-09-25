#ifndef CAMERA_H
#define CAMERA_H
#include <cglm/vec3.h>
#include <GLFW/glfw3.h>
struct Camera {
    vec3 pos;
    vec3 front;
    vec3 up;
};
void initCamera(struct Camera *cam);
#endif
