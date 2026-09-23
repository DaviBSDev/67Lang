#include <stdio.h>
#include <string.h>
#include "interpreter.h"

int interpret(char *path){
    FILE *fptr;
    fptr = fopen(path, "r");
    if (fptr == NULL){
	puts("error 67: file not found");
        return 1;
    }
    size_t path_size = strlen(path);
    int is_a_67_program = 0;
    for (int a = 0; a < path_size; a++){
        if (path[a] == '.'){
            if (a + 2 <= path_size){
		if (path[a + 1] == '6' && path[a + 2] == '7'){
		    is_a_67_program = 1;
                }
            }
            break;
        }
    }
    if (!(is_a_67_program)){
	puts("error 67: not a valid program");
        return 2;
    }
    char buffer[40000];
    int cursor = 0;
    float registers[10];
    int debug_mode = 1;
    memset(registers, 0, sizeof(registers));
    while (fgets(buffer, 40000, fptr) != NULL) {
        buffer[strcspn(buffer, "\n")] = '\0';
    }
    fseek(fptr, 0, SEEK_END);
    long size = ftell(fptr);
    fclose(fptr);
    int navigation_mode = 1;
    int loop_mode = 0;
    int loop_start = 0;
    int loop_register = 0;
    int wait = 0;
    for (int a = 0; a <= size; a++){
        if (navigation_mode ){

	    if (buffer[a] == '7' && !(wait)){
                if (cursor + 1 <= 9){
		    cursor++;
                }
                else{
		    cursor = 0;
                }
            }
            else if(buffer[a] == '6' && !(wait)){
	        if (cursor - 1 >= 0){
		    cursor--;
                }
                else{
		    cursor = 9;
                }
            }
        }
        else{
            if (buffer[a] == '7' && !(wait)){
                registers[cursor] += 0.5;
            }
            else if(buffer[a] == '6' && !(wait)){
                registers[cursor] -= 0.5;
            }
        }
        if (buffer[a] == ' '){
            if ((a + 1) <= size){
		if (buffer[a + 1] == ' '){
                    if (!(loop_mode)){
		        if (registers[cursor] >= 1){
			    loop_mode = 1;
                            loop_register = cursor;
                            loop_start = a;
                            a++;
                        }
                        else{
                            wait = !(wait);
                            a++;
                        }
                    }
                    else{
			if (registers[loop_register] >= 1){
			    a = loop_start;
                            a++;
                        }
                        else{
			    loop_mode = 0;
                            a++;
                        }
                    }
                }
                else{
		    navigation_mode = !(navigation_mode);
                }
            }
            else{
    		navigation_mode = !(navigation_mode);
            }
        }
        if ((int)registers[9] != 0){
	    if ((int)registers[9] == 1){
		printf("%c%c%c%c%c%c%c%c%c", (int)registers[0], (int)registers[1], (int)registers[2], (int)registers[3], (int)registers[4], (int)registers[5], (int)registers[6], (int)registers[7], (int)registers[8]);
            }
            registers[9] = 0;
        }
    }
    if (debug_mode){
        printf("#DEBUG MODE - TO DISABLE \nCHANGE debug_mode VARIABLE TO 0 \nAND RUN MAKE#\n\ncursor final position: %d\n", cursor);
        for (int a = 0; a < 10; a++){
           printf("register %d value:%.2f\n", a, registers[a]);
        }
        printf("loop_mode: %d\nnavigation_mode:%d\n", loop_mode, navigation_mode);
    }
    return 0;
}
