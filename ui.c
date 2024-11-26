#include "filehandler.h"
#include <stdio.h>
#include "structs.h"
#include <ctype.h>
#include <stdlib.h>
#include "printout.h"
#include <string.h>
#include "tree.h"



int uiAskCommand(struct node* root, struct node* current, char curentPath[], int* saved){                                                         //Asks user for command to do
    printf("\n-> ");
    char command[15] = "";          //main command to the program, like print, or add
    char switch1[15] = "";           //switch no 1 of given command
    char switch2[2048] = "";        //switch no 2 of given command
    char str[2078];
    fgets(str, 2078, stdin);
    int commandsNum = 0;         //stores, how many switches were given
    int i = 0;
    int j = 0;
    if (str[0] == '\n'){
        return 1;
    }
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
            printf("Not enought arguments. Print needs at least 1, 0 was given.");
            break;
        
        case 2:
            if (strcmp(switch1, "a") == 0){
                printTree(root);
            }
            else if (strcmp(switch1, "c") == 0){
                printNode(*current);
            }
            break;
        
        case 3:
            if (strcmp(switch1, "a") == 0){
                filePrintTree(root, switch2);
            }
            else if (strcmp(switch1, "c") == 0){
                filePrintNode(current, switch2);
            }
            break;
        
        default:
            printf("To many arguments. Print takes 2 arguments max, %d was given.", commandsNum - 1);
            break;
        }
        return 1;
    }
    else if (strcmp(command, "del") == 0){                                //command for deleting nodes
        switch (commandsNum)
        {
        case 1:
            printf("Not enought arguments. Del needs at least 1, 0 was given.");
            break;
        
        case 2:
            if (strcmp(switch1, "i") == 0){
                printf("ok");
            }
            else if (strcmp(switch1, "c") == 0){
                filePrintNode(current, switch2);
            }
            break;
        
        case 3:
            if (strcmp(switch1, "i") == 0){
                int id = atoi(switch2);
                struct node* idStruct = findNodeById(root, id);
                int children = treeHasChildren(idStruct);
                if (idStruct == root){
                    printf ("Cannot delete node with id %d, because it is root.", id);
                }
                else if (children != 0){
                    char ansver = 'n';
                    printf("Selected node has %d children. Are you sure you want to delete it (y/n): ", children);
                    scanf("%c", &ansver);
                    if (ansver == 'y' || ansver == 'Y'){
                        treeDelNodes(idStruct);
                    }
                }
            }
            else if (strcmp(switch1, "c") == 0){
                filePrintNode(current, switch2);
            }
            break;
        
        default:
            printf(" ");
            break;
        }
        return 1;
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
        return 1;
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
        return 1;
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
        return 1;
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
        return 1;
    }
    else if (strcmp(command, "clear") == 0){                            //command for clearing the console
        switch (commandsNum)
        {
        case 1:
            system("clear");
            break;
        default:
            printf("To many arguments. Clear takes no arguments, %d was given.", commandsNum - 1);
            break;
        }
        return 1;
    }
    else if (strcmp(command, "help") == 0){                            //command for help to the user
        switch (commandsNum)
        {
        case 1:
            help();
            break;
        default:
            printf("To many arguments. Help takes no arguments, %d was given.", commandsNum - 1);
            break;
        }
        return 1;
    }


    return 0;
}
