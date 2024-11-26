#include "filehandler.h"
#include <stdio.h>
#include "structs.h"
#include <ctype.h>
#include <stdlib.h>
#include "printout.h"
#include <string.h>



int uiAskCommand(struct node* root){                                                         //Asks user for command to do
    printf("\n-> ");
    char command[15] = "";          //main command to the program, like print, or add
    char switch1[15] = "";           //switch no 1 of given command
    char switch2[2048] = "";        //switch no 2 of given command
    char str[2078];
    fgets(str, 2078, stdin);
    int commandsNum = 0;         //stores, how many switches were given
    int i = 0;
    int j = 0;
    while (!(str[i] == ' ' || str[i] == '\n') && j < 14){
        command[j] = str[i];
        i++;
        j++;
    }
    command[j] = '\0';
    commandsNum++;
    if (str[i] == ' ' ){
        j = 0;
        i++;
        while (!(str[i] == ' ' || str[i] == '\n') && j < 14){
            switch1[j] = str[i];
            i++;
            j++;
        }
        switch1[j] = '\0';
        commandsNum++;
    }
    if (str[i] == ' '){
        j = 0;
        i++;
        while (!(str[i] == ' ' || str[i] == '\n') && j < 2047){
            switch2[j] = str[i];
            i++;
            j++;
        }
        switch2[j] = '\0';
        commandsNum++;
    }
    if (!(str[i] == '\n' || str[i] == '\0')){
        commandsNum++;
    }

    if (strcmp(command, "print") == 0){                                     //command for printing
        switch (commandsNum)
        {
        case 1:
            printf("print1");
            break;
        
        case 2:
            printf("print2");
            break;
        
        case 3:
            printf("print3");
            break;
        
        default:
            printf(" ");
            break;
        }
    }
    else if (strcmp(command, "del") == 0){                                //command for deleting nodes
        switch (commandsNum)
        {
        case 1:
            printf("del1");
            break;
        
        case 2:
            printf("del2");
            break;
        
        case 3:
            printf("del3");
            break;
        
        default:
            printf(" ");
            break;
        }
    }
    else if (strcmp(command, "checkout") == 0){                            //command for changing working node
        switch (commandsNum)
        {
        case 1:
            printf("checkout1");
            break;
        
        case 2:
            printf("checkout2");
            break;
        
        case 3:
            printf("checkout3");
            break;
        
        default:
            printf(" ");
            break;
        }
    }
    else if (strcmp(command, "add") == 0){                                //command for adding nodes
        switch (commandsNum)
        {
        case 1:
            printf("add1");
            break;
        
        case 2:
            printf("add2");
            break;
        
        case 3:
            printf("add3");
            break;
        
        default:
            printf("To many commands");
            break;
        }
    }
    else if (strcmp(command, "load") == 0){                            //command for loading from file
        switch (commandsNum)
        {
        case 1:
            printf("load1");
            break;
        
        case 2:
            printf("load2");
            break;
        
        case 3:
            printf("load3");
            break;
        
        default:
            printf(" ");
            break;
        }
    }
    else if (strcmp(command, "save") == 0){                            //command for saving into file
        switch (commandsNum)
        {
        case 1:
            printf(" ");
            break;
        
        case 2:
            printf(" ");
            break;
        
        case 3:
            printf(" ");
            break;
        
        default:
            printf(" ");
            break;
        }
    }
    else if (strcmp(command, "clear") == 0){                            //command for clearing the console
        switch (commandsNum)
        {
        case 1:
            printf(" ");
            break;
        
        case 2:
            printf(" ");
            break;
        
        case 3:
            printf(" ");
            break;
        
        default:
            printf(" ");
            break;
        }
    }
    else if (strcmp(command, "help") == 0){                            //command for help to the user
        switch (commandsNum)
        {
        case 1:
            printf(" ");
            break;
        
        case 2:
            printf(" ");
            break;
        
        case 3:
            printf(" ");
            break;
        
        default:
            printf(" ");
            break;
        }
    }


    return 0;
}
