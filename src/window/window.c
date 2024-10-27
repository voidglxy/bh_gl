#include <GLFW/glfw3.h>
#include <stdio.h>
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}; 


void initWindow(GLFWwindow **window, int width, int height){
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    *window = glfwCreateWindow(width, height, "title", NULL, NULL);
    if(!window){
        printf("Window creation failed\n");
    }
    glfwMakeContextCurrent(*window);                                                                          
    glfwSetFramebufferSizeCallback(*window, framebuffer_size_callback);

}