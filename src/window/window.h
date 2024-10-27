#ifndef WINDOW_H
#define WINDOW_H
#include <GLFW/glfw3.h>

typedef struct {
    GLFWwindow* window;


} Window;

void initWindow(GLFWwindow **w, int width, int height);
#endif