#include "../../lib/glad/glad/glad.h"
#include "shader.h"
#include "stdio.h"
#include "stdlib.h"
#include "errno.h"
#include <string.h>
void initShader(struct Shader *shader, char *vPath, char *fPath){
    const char *vsSource = loadShader("src/shaders/testShader/test.vs");
    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vsSource, NULL);
    glCompileShader(vertexShader);
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        printf("%s\n", infoLog);
    }
    

    const char *fragSource = loadShader("src/shaders/testShader/test.fs");
    unsigned int fragShader;
    fragShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragShader, 1, &fragSource, NULL);
    glCompileShader(fragShader);

    shader->ID = glCreateProgram();
    glAttachShader(shader->ID, vertexShader);
    glAttachShader(shader->ID, fragShader);
    glLinkProgram(shader->ID);
    glDeleteShader(vertexShader);
    glDeleteShader(fragShader);
};
char *loadShader(char path[]){
    char *result = NULL;
    FILE *fptr;
    int aSize = 0;
    fptr = fopen(path, "r");
    int c, i = 0;
    
    if(fptr == NULL){
        printf("%s\n", strerror(errno));
        printf("File error\n");
    }else{
        printf("it works\n");
    }

    while((c=fgetc(fptr))!=EOF){
        if(i>=aSize){
            aSize +=1000;
            result = realloc(result, aSize);
            if(result == NULL){
                printf("Realloc error");
            }
        }
        result[i]=c;
        i++;
    }
    fclose(fptr);
    result[i]='\0';
    return result;
};

void useShader(unsigned int ID){
    glUseProgram(ID);
}
