#include "filehandler.h"
#include <stdio.h>
#include "structs.h"
#include <ctype.h>
#include <stdlib.h>
#include "printout.h"



int uiAskCommand(struct node* root){                                                         //Asks user for command to do
    printf("\n-> ");
    char command[10] = "";          //main command to the program, like plot, or addnode
    char switch1[5] = "";           //switch no 1 of given command
    char switch2[2048] = "";        //switch no 2 of given command
    int commandsNum = scanf("%s %s %s", command, switch1, switch2);         //stores, how many switches were given

    switch (command)                                                        //nelze užitím switche, musím použít if
    {
    case "plot":
        /* code */
        break;
    
    default:
        printf("\nUnknown command: \"%s\"", command);
        void help();
        break;
    }


    return 0;
}