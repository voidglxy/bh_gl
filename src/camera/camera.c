#include "camera.h"
#include <GLFW/glfw3.h>
#include <cglm/vec3.h>
#include <string.h>

void initCamera(struct Camera *cam){
    memcpy(cam->pos, (vec3){0.0f, 0.0f, 3.0f}, sizeof(vec3));
    memcpy(cam->front, (vec3){0.0f, 0.0f, -1.0f}, sizeof(vec3));
    memcpy(cam->up, (vec3){0.0f, 1.0f, 0.0f}, sizeof(vec3));
};
