#include "filehandler.h"
#include <stdio.h>
#include "structs.h"
#include <ctype.h>
#include <stdlib.h>
#include "printout.h"
#include <string.h>
#include "tree.h"



int uiAskCommand(struct node** root1, struct node** current1, char curentPath[], int* saved){                                                         //Asks user for command to do
    struct node* current = *current1;
    struct node* root = *root1;
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
                printTree(root, current);
            }
            else if (strcmp(switch1, "c") == 0){
                printNode(*current);
            }
            else {
                printf("Unknown argument for \"print\": %s", switch1);
            }
            break;
        case 3:
            if (strcmp(switch1, "a") == 0){
                filePrintTree(root, switch2);
            }
            else if (strcmp(switch1, "c") == 0){
                filePrintNode(current, switch2);
            }
            else {
                printf("Unknown argument for \"print\": %s", switch1);
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
            if (strcmp(switch1, "c") == 0){
                int children = treeHasChildren(current);
                if (children != 0){
                    printf("Unable to delete node: Node has %d child(ren).\nTo remove it, try using \"del c r\" command.", children);
                }
                else{
                    struct node* newCurrent = current->parent;
                    treeDelNodes(current);
                    printf("Node successfuly deleted");
                    current = newCurrent;
                    *current1 = current;
                }
            }
            else {
                printf("Unknown argument for \"del\": %s", switch1);
            }
            break;
        case 3:
            if (strcmp(switch1, "i") == 0){
                int id = atoi(switch2);
                struct node* idStruct = findNodeById(root, id);
                if (idStruct == NULL){
                    printf("unable to delete node with id %d: Does not exist!", id);
                    return 1;
                }
                int children = treeHasChildren(idStruct);
                if (idStruct == root){
                    printf ("Cannot delete node with id %d, because it is root.", id);
                    return 1;
                }
                if (children != 0){
                    char answer = 'n';
                    printf("Selected node has %d children. Are you sure you want to delete it (Y/N): ", children);
                    scanf("%c", &answer);
                    if (answer == 'y' || answer == 'Y'){
                        treeDelNodes(idStruct);
                        *root1 = root;
                        *saved += 1;
                    }
                }
                else if (id == current->ID){
                    printf("Could not remove working node ith this command.\nTry \"del c\" instead.");
                    return 1;
                }
                else {
                    treeDelNodes(idStruct);
                    printf("Node %d successfuly deleted", id);
                    *root1 = root;
                    *saved += 1;
                }
            }
            else if (strcmp(switch1, "c") == 0){
                if (strcmp(switch2, "r") == 0){
                    if (current == root){
                        printf ("Cannot delete this node, because it is root.");
                        return 1;
                    }
                    struct node* newCurrent = current->parent;
                    treeDelNodes(current);
                    printf("Nodes successfuly deleted");
                    current = newCurrent;
                    *current1 = current;
                    *saved += 1;
                }
                else{
                    printf("Unknown argument for \"del c\": %s", switch2);
                }
            }
            else {
                printf("Unknown argument for \"del\": %s", switch1);
            }
            break;
        default:
            printf("To many arguments. Del takes 2 arguments max, %d was given.", commandsNum - 1);
            break;
        }
        return 1;
    }
    else if (strcmp(command, "checkout") == 0){                            //command for changing working node
        switch (commandsNum)
        {
        case 1:
            printf("Not enought arguments. Checkout needs 1, 0 was given.");
            break;
        case 2:
            if (0 == 0){
                int id = atoi(switch1);
                struct node* idStruct = findNodeById(root, id);
                if (idStruct == NULL){
                    printf("unable to switch to node with id %d: Does not exist!", id);
                    return 1;
                }
                current = idStruct;
                *current1 = current;
                printf("Switching to node %d", id);
            }
            break;
        default:
            printf("To many arguments. Checkout takes 1 argument, %d was given.", commandsNum - 1);
            break;
        }
        return 1;
    }
    else if (strcmp(command, "add") == 0){                                //command for adding nodes
        switch (commandsNum)
        {
        case 1:
            printf("Not enought arguments. Add needs 2, 0 was given.");
            break;
        case 2:
            printf("Not enought arguments. Add needs 2, 1 was given.");
            break;
        case 3:
            if (0 == 0){
                int passed = treeAddNode(root, atoi(switch1), atoi(switch2));
                if (passed == 0){
                    printf("Successfully created node with parent %s and ID %s", switch1, switch2);
                    *saved += 1;
                    return 1;
                }else if(passed == 1){
                    printf("Failed to create node: ID %s is occupied", switch2);
                    return 1;
                }
                else if(passed == 2){
                    printf("Failed to create node: Parent with ID %s does not exist.", switch1);
                    return 1;
                }
                else if(passed == 3){
                    printf("Failed to create node: Parent with ID %s already has two children", switch1);
                    return 1;
                }
            }
            break;
        default:
            printf("To many arguments. Add takes 2 arguments, %d was given.", commandsNum - 1);
            break;
        }
        return 1;
    }
    else if (strcmp(command, "load") == 0){                            //command for loading from file
        switch (commandsNum)
        {
        case 1:
            printf("Not enought arguments. Load needs 1, 0 was given.");
            break;
        case 2:
            if (strcmp(switch1, "s") == 0){
            printf("Not enought arguments for \"load s\". expected 1, 0 was given");
            }
            else{
                printf("Unknown argument for \"load\": %s", switch1);
            }
            break;
        case 3:
            if (strcmp(switch1, "s") == 0){
                if (*saved != 0){
                    printf("You have some unsaved work. Save it before loading a new tree!");
                    return 1;
                }
                int nodesLoaded = loadSaved(root, switch2);
                switch (nodesLoaded)
                {
                case -1:
                    printf("Unable to load: No such file \"%s\"", switch2);
                    break;
                case -2:
                    printf("Unable to load: File cursed.");
                    break;
                case -3:
                    printf("Unable to load: No such file \"%s\"", switch2);
                    break;
                default:
                    printf("Successfully loaded %d nodes.", nodesLoaded);
                    strcpy(curentPath, switch2);
                    break;
                }
                return 1;
            }else{
                printf("Unknown argument for \"load\": %s", switch1);
            }
            break;
        default:
            printf("To many arguments. Load takes 1 argument, %d was given.", commandsNum - 1);
            break;
        }
        return 1;
    }
    else if (strcmp(command, "save") == 0){                            //command for saving into file
        switch (commandsNum)
        {
        case 1:
            if (*saved == 0){
                printf("Nothing to save");
                return 1;
            }
            int savedNum = saveLoaded(root, curentPath);
            if (savedNum == -1){
                printf("Nothing to save, NULL was given as root");                  //should not happen
            }
            else if (savedNum == -2){
                printf("Failed to save working tree.");
            }
            else{
                printf("Successfully saved %d nodes.", savedNum);
                *saved = 0;
            }
            break;
        case 2:
            if (strcmp(switch1, "e") == 0){
            printf("Not enought arguments for \"save e\". expected 1, 0 was given");
            }
            else{
                printf("Unknown argument for \"save\": %s", switch1);
            }
            break;
        case 3:
            if (strcmp(switch1, "e") == 0){
                int savedNum2 = saveLoaded(root, switch2);
                if (savedNum2 == -1){
                    printf("Nothing to save, NULL was given as root");                  //should not happen
                }
                else if (savedNum2 == -2){
                    printf("Failed to save working tree.");
                }
                else{
                    printf("Successfully saved %d nodes.", savedNum2);
                    *saved = 0;
                }
            }
            else{
                printf("Unknown argument for \"save\": %s", switch1);
            }
            break;
        default:
            printf("To many arguments. Save takes 1 argument max, %d was given.", commandsNum - 1);
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
    else if (strcmp(command, "quit") == 0 || strcmp(command, "q") == 0){
        switch (commandsNum)
        {
        case 1:
            if (*saved != 0){
                char ansver = ' ';
                printf("You have some unsaved work. Do you want to save it? (Y/N): ");
                scanf("%c", &ansver);
                if (ansver == 'y' || ansver == 'Y'){
                    int savedNum2 = saveLoaded(root, curentPath);
                    if (savedNum2 == -1){
                        printf("Nothing to save, NULL was given as root\n");                  //should not happen
                    }
                    else if (savedNum2 == -2){
                        printf("Failed to save working tree.\n");
                    }
                    else{
                        printf("Successfully saved %d nodes.\n", savedNum2);
                        *saved = 0;
                    }
                }
            }
            return 0;
            break;
        default:
            printf("To many arguments. Quit takes no arguments, %d was given.", commandsNum - 1);
            break;
        }
        return 1;
    }
    else {
        printf("unknown command: \"%s\"", command);
        return 1;
    }
}
