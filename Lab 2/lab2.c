
#include <stdio.h>
#include <conio.h>

struct HDCL{
    //array to store user input
char hdclFlag[70];
};


// display the in for
void displayinfo(struct HDCL fa_HDCL, int flagcount){

    int j = 1;
    printf("\n the end of the flag has been detected.");
    printf("\n Information between flags was: ");
    for(j; j<flagcount ; j++){
        printf("%c",fa_HDCL.hdclFlag[j]);
        fflush(stdout);

    }
}


main(){
    // calling the structure
    struct HDCL a_HDCL;

    char input;
    // keep track of the flag
    int flag = 0;
    int c = 1;
    int i = 0;
    printf(" Please enter character or number input. If HDCL flag \n");
    printf(" is detected, 01111110, a warning message will be displayed. \n");
    printf(" To exit, press '*': \n");
    // while loop with breakaway if flag is less than 2,
    // or the user decides to exit the program
    while(input != '*' && flag != 2 && c<64){
            // if statements to keep track of the flag input
        if(i == 0){
            input = getche();
        }
        // if statement for first input of 0
        if(input == '0'){
        input = getche();
        i++;
        // if statement for first input of 1
        if(input == '1'){  // 2
        input = getche();
        i++;
        // if statements for the remaining bits in the flag
        if(input == '1'){
            input = getche();
            if(input == '1'){
                input = getche();
                i++;

                if(input == '1'){
                    input = getche();
                    i++;

                    if(input == '1'){
                        input = getche();
                        i++;

                        if(input == '1'){
                            input = getche();
                            i++;
                            if(input == '0'){
                                if(flag == 0){
                                    printf("HDCL flag has been detected! ");
                                }
                                i = 0;
                                flag++;
                                input ='\n';
                                }
                               else if(input != '01111110'){
                                    input = getche();
                                    i = 0;
                                    input = '\n';
                                }
                            }
                    }
                }
            }
        }
    }
    }
        if(flag == 1){
            a_HDCL.hdclFlag[c] = input;
            c++;
        }
    }
        if(input == '*'){
            printf("\n the program will now exit!");
        }else{
            displayinfo(a_HDCL,c);
        }


    }


