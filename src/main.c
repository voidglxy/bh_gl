#include "all.h"
#define WIDTH 800
#define HEIGHT 800


void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}; 


int main(){
    // window stuff
    if(!glfwInit()){
        printf("GLFW LOAD FAILED\n");
    };
    GLFWwindow* window;  
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(WIDTH, HEIGHT, "title", NULL, NULL);
    if(!window){
        printf("no window for u\n");
    }
    glfwMakeContextCurrent(window);                                                                          
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        printf("GLAD LOAD FAILED\n");                                                               
    }                 
                 
    float prev = 0;
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);                                                        
    mat4 transform = GLM_MAT4_IDENTITY_INIT;
    glm_rotate(transform, glm_rad(90), (vec3){0.0,0.0,1.0});
    glm_scale(transform, (vec3){0.5,0.5,0.5});

    glEnable(GL_DEPTH_TEST);
    printf("this is just for testing\n");

    // create shader object
    struct Shader sh;
    initShader(&sh, "src/shaders/testShader/test.vs", "src/shaders/testShader/test.fs");

    struct Object test = initObject("assets/obj/Cube/Cube.png", "assets/obj/Cube/Cube.obj");

    printf("%i\n", test.vSize);
    struct Camera cam;
    initCamera(&cam);
    while(!glfwWindowShouldClose(window)){
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);


        //glUseProgram(shaderProgram);
       
        useShader(sh.ID); 
        mat4 model = GLM_MAT4_IDENTITY_INIT;
        //glm_scale(model, (vec3){0.1f,0.1f,0.1f});        
        //glm_rotate(model, prev, (vec3){0.0,1.0,1.0f});
        prev += 0.01;
        mat4 view = GLM_MAT4_IDENTITY_INIT;
        float radius = 10.0f;
        glm_translate(view, (vec3){0.0f, 0.0f, -3.0f});
        vec3 temp;
        glm_vec3_add(cam.pos, cam.front, temp);
        glm_lookat(cam.pos, temp, cam.up, view);
        mat4 projection;
        glm_perspective(glm_rad(45.0f), 1920.0f/1080.0f, 0.1f, 100.0f, projection);



        
        unsigned int modelLoc = glGetUniformLocation(sh.ID, "model");
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, model[0]);
        unsigned int viewLoc = glGetUniformLocation(sh.ID, "view");
        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, view[0]);
        unsigned int projLoc = glGetUniformLocation(sh.ID, "projection");
        glUniformMatrix4fv(projLoc, 1, GL_FALSE, projection[0]);

        
        drawObject(&test);
        glfwPollEvents();
        glfwSwapBuffers(window);
    }
    glfwTerminate();
    return 0;
}
