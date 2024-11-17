# include "filehandler.h"
#include <stdio.h>
#include "structs.h"
#include <ctype.h>

int loadSaved(struct node node, int id){           //loads single node from saved file
    FILE *filePtr;
    filePtr = fopen("myTree.csv", "r");

    if (filePtr == NULL){                   //stops loading, when the file does not exist
        printf("Nothing is saved for the specified file!");
        return 1;
    }

    char fileLine[20];

    while (fgets(fileLine, 20, filePtr)){   //goes over all the lines of the specified file
        if (atoi(fileLine[0]) == id){      //in the line search for given id
            char numChar[4];                //variable for temporary value storage
            char numCharPos = 0;
            char pos = 0;                   //variable for position of current argument (char is used only for memory saving purpose, value is number)
            for (int i = 0; i <= 20; i++){
                if (isdigit(fileLine[i]) && numCharPos < 3){
                    numChar[numCharPos] = fileLine[i];
                    numCharPos++;
                }
                else {
                    if (fileLine[i] = '\n' && pos > 3){
                        break;
                    }
                    else if (fileLine[i] = ','){
                        numChar[numCharPos] = '\0';
                        numCharPos = 0;
                        switch (pos)
                        {
                        case 0:
                            /* code */   //todo: opravit strukturu, aby obsahovala id krome adresy, vytvořit funkci pro doplnovani struktur a funkci pro ukladani
                            break;
                        case 1:
                            /* code */
                            break;
                        case 2:
                            /* code */
                            break;
                        case 3:
                            /* code */
                            break;
                        
                        default:
                            break;
                        }
                        pos++;
                    }
                }
            }
            break;

        }
    }




    fclose(filePtr);
    return 0;
}
