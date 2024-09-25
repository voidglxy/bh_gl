#ifndef SHADER_H
#define SHADER_H
// NOTE: ...
struct Shader {
    unsigned int ID;
};

void initShader(struct Shader *shader, char *vPath, char *fPath);
char *loadShader(char path[]);
void useShader(unsigned int ID);
#endif
