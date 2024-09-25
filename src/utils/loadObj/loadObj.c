#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <errno.h>
#include <stdbool.h>
int meshSize(char *path){
    FILE *fptr;

    fptr = fopen(path, "r");

    int c = 0;
    if(fptr == NULL){
        printf("%s\n", strerror(errno));
        printf("File error\n");
    }
   
    char LH[128]; 
    int res = fscanf(fptr, "%s", LH);
    while(res!=EOF){
         
        res = fscanf(fptr, "%s", LH);
        if(strcmp(LH, "f")==0){
            c+=15;
        }
    }
    printf("it works #2\n");
    fclose(fptr); 
    return c;
}
void loadObj(char *path, float *vertices){    
    FILE *fptr;
    fptr = fopen(path, "r");
    int iV = 0;
    int iVT = 0;
    int iF = 0;
    float verticesI[10000][3];
    float vt[10000][2];
    int c = 0;
    if(fptr == NULL){
        printf("%s\n", strerror(errno));
        printf("File error\n");
        exit(0);
    }else{
        printf("it works #3\n");
        while(1){
            char LH[128];
            int res = fscanf(fptr, "%s", LH);


            if(res == EOF){
                fclose(fptr); 
                break;
            }

            if(strcmp(LH, "v") == 0){
                float x, y, z;
                fscanf(fptr, "%f %f %f\n", &x, &y, &z);
                verticesI[iV][0] = x;
                verticesI[iV][1] = y;
                verticesI[iV][2] = z;
                iV++;
            }else if(strcmp(LH, "vt") == 0){
                float x, y;
                fscanf(fptr, "%f %f\n", &x, &y);
                vt[iVT][0] = x;
                vt[iVT][1] = y;
                iVT++;
            }else if(strcmp(LH, "f") == 0){
                int vI[3];
                int nI[3];
                fscanf(fptr, "%d/%d %d/%d %d/%d\n", &vI[0], &nI[0], &vI[1], &nI[1], &vI[2], &nI[2]);
                // TODO: Optimize this part with a loop
                vertices[iF] = verticesI[vI[0]-1][0];
                iF++;
                vertices[iF] = verticesI[vI[0]-1][1];
                iF++;
                vertices[iF] = verticesI[vI[0]-1][2];
                iF++;

                vertices[iF] = vt[nI[0]-1][0];
                iF++;
                vertices[iF] = vt[nI[0]-1][1];
                iF++;

                vertices[iF] = verticesI[vI[1]-1][0];
                iF++;
                vertices[iF] = verticesI[vI[1]-1][1];
                iF++;
                vertices[iF] = verticesI[vI[1]-1][2];
                iF++;

                vertices[iF] = vt[nI[1]-1][0];
                iF++;
                vertices[iF] = vt[nI[1]-1][1];
                iF++;

                vertices[iF] = verticesI[vI[2]-1][0];
                iF++;
                vertices[iF] = verticesI[vI[2]-1][1];
                iF++;
                vertices[iF] = verticesI[vI[2]-1][2];
                iF++;

                vertices[iF] = vt[nI[2]-1][0];
                iF++;
                vertices[iF] = vt[nI[2]-1][1];
                iF++;
            }
            }
    }
}
