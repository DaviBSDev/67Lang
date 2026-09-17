#include <stdio.h>
#include "interpreter.h"

char *path;
int main(int argc, char *argv[]){
    path = argv[1];
    int return_code = interpret(path);
    if (return_code){
        return 1;
    }
    return 0;
}
