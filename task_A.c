#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int toLower(char**, size_t, char**);
const int upMin = (int)('A');
const int upMax = (int)('Z');
const int lowMin = (int)('a');
const int lowMax = (int)('z');
const int length = 128;

int main()
{
    size_t size = 1;
    char** input = (char**)malloc(sizeof(char*));
    if(input == NULL) {printf("[error]"); return 0;}

    int maxStrIdx = -1;
    while(!feof(stdin))
    {
        ++maxStrIdx;
        if (maxStrIdx >= size)
        {
            ++size;
            input = realloc(input, size * sizeof(char*));
        }
        input[maxStrIdx] = (char*)malloc(length * sizeof(char));
        if(input[maxStrIdx] == NULL) {printf("[error]"); return 0;}
        fgets(input[maxStrIdx], length, stdin);
        //printf("%s", input[maxStrIdx]);
    }
    //printf("\nmaxStrIdx = %d, size = %d\n", maxStrIdx, size);
    if(maxStrIdx == -1) {printf("[error]"); return 0;}

    char** output = (char**)malloc(size * sizeof(char*));
    if(output == NULL) {printf("[error]"); return 0;}
    for(int i = 0; i < size; ++i)
    {
        output[i] = memset((char*)malloc(length * sizeof(char)), 0, length);
        if(output[i] == NULL) {printf("[error]"); return 0;}
    }

    toLower(input, size, output);

    for(int i = 0; i < size; ++i)
    {
        printf("%s", output[i]);
        free(input[i]);
        free(output[i]);
    }
    free(input);
    free(output);
    return 0;
}

int toLower(char** input, size_t size, char** output)
{
    for(int i = 0; i < size; ++i)
        for(int j = 0; j < length; ++j)
        {
            int code = (int)(input[i][j]);
            if(code == '\0') break;
            if((code >= upMin) && (code <= upMax))
                output[i][j] = (code - upMin) + lowMin;
            else output[i][j] = code;
        }
    return size;
}
