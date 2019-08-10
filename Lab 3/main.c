#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

    char* addstr(char* str1, char * str2);
    int fileReader();
    int getNodes(int i);
    #define limit 30
    char data[limit][50];
    char nodes[limit][50];
    int distance = 0;
    int path[limit];
    char temp[2];
    int Lpath = 0;
    char toNode, findNode, input[1], output[0];

    int main() {
        char repeat;
        //do-while loop for continuous
        do{
        int Lpath = 0;
        int c = 0;
        int pathsize = 2;
        int r = fileReader();
        const int n = getNodes(r);
        int distance[n][n];
        int point[n][n];
        printf("\n");
        printf("Starting point node: "); //Asks user to input starting node
        printf("\n");
                // first input scan
                scanf("%s", input);
                upperCase(input);
                toNode = input[0]; //puts input to char toNode
                printf("End point node: "); //ask user for ending node
                printf("\n");
                scanf("%s", output);
                upperCase(output);
                findNode = output[0];
                path[0] = ((int)toNode) - 65;
                path[1] = ((int)findNode) - 65;
                printf("\n");
        for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                        point[i][j] = -1;
                        distance[i][j] = 100000000;
                }
            }
    for (int i = 0; i < r; ++i) {
        distance[((int)data[i][0]) - 65][((int)data[i][1]) - 65] = ((int)data[i][3]) - 48;
}
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                 for (int j = 0; j < n; ++j) {
                    if ((distance[i][k] + distance[k][j]) < distance[i][j]) {
                            point[i][j] = k;
                                distance[i][j] = (distance[i][k] + distance[k][j]);
            }
        }
    }
}
            while(1) {
                if (point[path[c+0]][path[c+1]] > -1) {
                        for (int i = pathsize - 1; i >= c+1; i--)
                                    path[i+1] = path[i];
                                            path[c + 1] = point[path[0+c]][path[1+c]];
                                                        pathsize++;
}
        else {
        Lpath += distance[path[0+c]][path[1+c]]; //Total path cost
        if (pathsize == 2) {
        break;
        }
        c++;
}

            if (pathsize == limit) {
            printf("error exceeded path limit\n"); // If path limit is exceed, print this
            break;
            exit(1);
        }
            if (path[c+1] == 0) {
            break;
        }
    }
        printf("path :");
        for (int i = 0; i < pathsize; ++i) { //outputs the path taken
        printf("%c ", (char)(path[i] + 65));
    }

        printf(" \n\nPaths total cost: %d\n\n", Lpath); // output path and cost
        // ask user for input to run code again.
        // call the reset function
        reset();
        printf(" Run again? (Y/N) \n");
        scanf("%s",&repeat);

    }while(repeat == 'y' || repeat == 'Y');

}
        char* addstr(char* str1, char* str2) {
        char * str3 = (char*) malloc(1 + strlen(str1) + strlen(str2));
        strcpy(str3, str1);
        strcat(str3, str2);
        return str3;
}
        //file reader
        int fileReader() {
        int i = 0;
        //char textfile[];
        char line[50];
        char fileName[30];
        printf("Enter text file(.txt): ");
        scanf("%s", &fileName);
        //read filename
        FILE* fp = fopen(fileName, "r");
        //if user inputs wrong filename give error message
        if(fp != NULL) {
        while (fgets(line, sizeof(line), fp)) {
        strcpy(data[i], line);
        i++;
}
        fclose(fp);
        return i;
}
        else { // if filename is incorrect
        printf("Could not find the file.\n");
        printf("Please try again!\n");
    main();
    }
}
        int getNodes(int i) {
        int k = 1;
        toNode = data[0][0];
        nodes[0][0] = toNode;
        nodes[0][1] = ' ';
        nodes[0][2] = 'x';
        for (int j = 0; j < i; ++j) {
                if (data[j][0] != toNode) {
                toNode = data[j][0];
                nodes[k][0] = toNode;
                nodes[k][1] = ' ';
                nodes[k][2] = 'x';
                k++;
        }

    }
        return k;

}
        int upperCase(char s[]) {
        int c = 0;
        while (s[c] != '\0') {
        if (s[c] >= 'a' && s[c] <= 'z') {
        s[c] = s[c] - 32;
                }
        c++;
    }
}
//reset all the variables after the code runs
// guarantees the buffer is flushed and no variables
// hold a value after a re-run.
void reset(){
        memset(data,0,sizeof data);
        memset(nodes,0,sizeof nodes);
        distance = 0;
        memset(path,0,sizeof path);
        memset(temp,0,sizeof temp);
        toNode,findNode = 0;
        Lpath = 0;

        memset(input,0,sizeof input);
}
