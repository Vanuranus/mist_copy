// name: yongheng Fan
// unikey: yfan3576
// SID: 500654934

/**
 * 1 make a loop in a main that it will continuously ask you input until I type term:           check
 * 2 make "who":                                                                                check
 * 3 make resign:                                                                               check
 * 4 make place:
            1 recognize the "place "                                                            check
            2 recognize the secondpart eg: "A1" right "A11"right "AA1"/"A111" wrong             check
            3 store the right rule secondpart in history                                        check
            4 make sure the step is not in history                                              check
            5 let the place function change the board make sure black # white o                 check
            6 get new mistcenter after place a stone
 * 5 make view:
            1 check the last view position
            2 make int to be string
            3 get the list of 7*7

 * 5 build the game:
            1 build the board                                                                   check
            2 struct the position so that I could get 2 int for x-axis and y-axis               check
            3 function to make string to be position                                            check
            4 design the rules so that it could recognize 5 stone in a role                     check

procedure: checkalphaint


*/
#include <stdio.h>
#include <string.h>
//#include <stdlib.h>

struct position {//func postion for place and view
    int x;
    int y;
};
char* checkalphaint(char* secondpart); //prototype the check alphaint

struct position xandy (char *secondpart){
    secondpart = checkalphaint(secondpart);
//    printf("secondpart:%s \n",secondpart);
    struct position location = {0,0};

    if (strcmp(secondpart, "error")==0){
        location.x = -1;
        location.y = -1;
    }
    if(strlen(secondpart) == 2){
        location.x = secondpart[0] - 'A';
        location.y = secondpart[1] - 49;// ascii 1 is 49
    }
    if(strlen(secondpart) == 3){
        location.x = secondpart[0] - 'A';
        location.y = ((secondpart[1] -48)* 10) + (secondpart[2]-48) - 1;
    }
    return location;
}
int ifwin(char board[20][20], char player,char *secondpart){
    struct position location ={0,0};
    location = xandy(secondpart);
    int count = 0, x = 0, y = 0;
    x = location.x;
    y = location.y;

    //y=k
    if(player == 'B'){
        while(board[x][y] == '#' && x > -1){
            x--;
            count++;
            if(count == 5){
                return 1;
            }
        }
        while(board[x][y] == '#' && x < 19){
            x++;
            count++;
            if(count == 5){
                return 1;
            }
        }

        //reset
        count = 0;
        x = location.x;
        y = location.y;
        //x=k
        while(board[x][y] == '#' && y > -1){
            y--;
            count++;
            if(count == 5){
                return 1;
            }
        }
        while(board[x][y] == '#' && y < 19){
            y++;
            count++;
            if(count == 5){
                return 1;
            }
        }

        //reset
        count = 0;
        x = location.x;
        y = location.y;
        //y=x
        while(board[x][y] == '#' && x > -1 && y > -1){
            x--;
            y--;
            count++;
            if(count == 5){
                return 1;
            }
        }
        while(board[x][y] == '#' && x < 19 && y < 19){
            x++;
            y++;
            count++;
            if(count == 5){
                return 1;
            }
        }

        //reset
        count = 0;
        x = location.x;
        y = location.y;
        //y=-x
        while(board[x][y] == '#' && x > -1 && y < 19){
            x--;
            y++;
            count++;
            if(count == 5){
                return 1;
            }
        }
        while(board[x][y] == '#' && x < 19 && y > -1){
            x++;
            y--;
            count++;
            if(count == 5){
                return 1;
            }
        }
    }

    //reset
    count = 0;
    x = location.x;
    y = location.y;

    if(player == 'W'){
        //y=k
        while(board[x][y] == 'o' && x > -1){
            x--;
            count++;
            if(count == 5){
                return 1;
            }
        }
        while(board[x][y] == 'o' && x < 19){
            x++;
            count++;
            if(count == 5){
                return 1;
            }
        }

        //reset
        count = 0;
        x = location.x;
        y = location.y;
        //x=k
        while(board[x][y] == 'o' && y > -1){
            y--;
            count++;
            if(count == 5){
                return 1;
            }
        }
        while(board[x][y] == 'o' && y < 19){
            y++;
            count++;
            if(count == 5){
                return 1;
            }
        }

        //reset
        count = 0;
        x = location.x;
        y = location.y;
        //y=x
        while(board[x][y] == 'o' && x > -1 && y > -1){
            x--;
            y--;
            count++;
            if(count == 5){
                return 1;
            }
        }
        while(board[x][y] == 'o' && x < 19 && y < 19){
            x++;
            y++;
            count++;
            if(count == 5){
                return 1;
            }
        }

        //reset
        count = 0;
        x = location.x;
        y = location.y;
        //y=-x
        while(board[x][y] == 'o' && x > -1 && y < 19){
            x--;
            y++;
            count++;
            if(count == 5){
                return 1;
            }
        }
        while(board[x][y] == 'o' && x < 19 && y > -1){
            x++;
            y--;
            count++;
            if(count == 5){
                return 1;
            }
        }

    }
    return 0;
}



char who(int turns) {//who function
    if (turns % 2 == 1) {
        return 'B';
    }
    else {
        return 'W';
    }
}

char* checkalphaint(char* secondpart) {//2 situations size2 and size3 size2 situation is in size3
    int lenth = strlen(secondpart);

    if (lenth < 2 || lenth > 3) {
        return "error";
    }
    if (secondpart[0] < 'A' || secondpart[0] > 'S') {
        return "error";
    }
    for (int i = 1; i < lenth; i++) {
        if (secondpart[i] < '1' || secondpart[i] > '9') {
            return "error";
        }
    }
    if (lenth == 3 && (secondpart[2] < '0' || secondpart[2] > '9' || secondpart[1]!='1')) {
        return "error";
    }
    return secondpart;
}
int historycheck(char *secondpart, char*history){

    int lensecondpart= strlen(secondpart);
    int lenhistory= strlen(history);
//    printf("history length: %d\n", lenhistory);
//    printf("history in history check: %s\n", history);
//    printf("secondpart in history check: %s\n", secondpart);

    for (int i = 0; i < lenhistory; i++) {
        if (secondpart[0] == history[i]) {
            int ph = i + 1;//pointer for history
            int ps = 1;//pointer for secondpart
            while (ph < lenhistory && ps < lensecondpart && secondpart[ps] == history[ph]) {
                ps++;
                ph++;
            }
            if ((ps == lensecondpart && history[ph]>='A' && history[ph]<='S') || (ps == lensecondpart && history[ph]=='\0')) {//at this moment s[ps]='\0' and h[ph] have to ='A-S'
                return 1;
            }
        }
    }
    return 0;
}

int view(char board[20][20], struct position mistcenter){
    for (int i = 18; i > -1; i--) {
        for (int j = 0; j < 19; j++) {
            printf("%c ", board[j][i]);
        }
        printf("\n");
    }
    int x = 9, y = 9;
    x = mistcenter.x;
    y = mistcenter.y+1;
    //get the first part convert position to be string. eg 9,9-> J10 whatever just print it out
    char ystring[2]="";
    char char_x = 'A'+x;
    printf("%c",char_x);
    sprintf(ystring,"%d",y);
    printf("%s,",ystring);

    //get the second part of string
    int scan_x = x-3, scan_y = y-1+3;
    for (int i = 0; i < 7; i++){
        for (int j=0; j < 7; j++) {
            printf( "\nx: %d , y: %d   ", scan_x+j,scan_y-i);
            if(scan_x + j < 0 || scan_x + j > 18 || scan_y - i < 0 || scan_y - i > 18){

                printf("x");
            }
            else{
                printf("%c", board[scan_x][scan_y]);
            }
        }
    }
    printf("\n");
    return 0;
}

struct position place(char board[20][20], char *secondpart, char *history,char player, struct position mistcenter) {
//    printf("secondpart: %s\n",secondpart);
    secondpart = checkalphaint(secondpart);
    if (strcmp(secondpart, "error") == 0) {
        printf("invalid! unrecognized step\n");
    } else {//now it is a valid step need to check player and place the stone
        struct position location ={0,0};
        location = xandy(secondpart);
//        printf("x: %d\n",location.x);
//        printf("y: %d\n", location.y);
        if (player == 'B'){
            board[location.x][location.y] = '#';
        };
        if (player == 'W'){
            board[location.x][location.y] = 'o';
        }

        if (historycheck(secondpart, history) == 0) {
            strcat(history, secondpart);
            //printf("history: %s\n", history);
            //do things

        }
        int newx = location.x+1;
        mistcenter.x = (5 * (newx * newx) + 3 * newx + 4) % 19;
        printf("location.x %d\n", location.x);
        printf("mistcenter.x %d\n", mistcenter.x);
        mistcenter.y = (4 * (newx * newx) + 2 * newx - 4) % 19;
        printf("location.y %d\n", location.y);
        printf("mistcenter.y %d\n", mistcenter.y);
    }
    return mistcenter;
}

int main() {
    //variable prepare to use
    char input[100]="";
    char history[1000]="";
    char player = 'B';
    int turns=1;
    struct position mistcenter = {9,9};
//    printf("history length %ld \n", strlen(history));
    //build the board
    char board[20][20];
    // initial the board
    for (int row = 0; row < 20; row++) {
        for (int col = 0; col < 20; col++) {
            board[row][col] = '.';
        }
    }
//    struct position location = {0,0};
//    location = xandy("A1");
//    printf("A1: %d %d\n", location.x, location.y);
//    location = xandy("A11");
//    printf("A11: %d %d\n", location.x, location.y);
//    location = xandy("AB");
//    printf("AB: %d %d\n", location.x, location.y);
//    location = xandy("11");
//    printf("11: %d %d\n", location.x, location.y);
//    location = xandy("A21");
//    printf("A21: %d %d\n", location.x, location.y);
//    location = xandy("z1");
//    printf("z1: %d %d\n", location.x, location.y);

    while (1) {
        scanf(" %[^\n]", input);//^\n so that it will not scanf words one by one
//        printf("check what is reading:%s\n", input);

        //who
        if (strcmp(input, "who") == 0) {
            player= who(turns);
            printf("%c\n", player);
        }

        //term
        else if (strcmp(input, "term") == 0) {
            printf("Terminated.\n");
            break;
        }

        else if (strcmp(input, "resign") == 0) {
            if (player == 'B'){
                printf("White wins!\n");
                printf("%s\n", history);
                printf("Thank you for playing!\n");
            }
            else if (player == 'W'){
                printf("Black wins!\n");
                printf("%s\n", history);
                printf("Thank you for playing!\n");
            }
            break;
        }
        //place <><>

        else if (strncmp(input, "place ", 6) == 0) {//check the "place " is correct
            char* secondpart = &input[6];

            //put place
            player = who(turns);
//            printf("turns %d and player %c\n", turns, player);
            mistcenter = place(board,secondpart,history, player, mistcenter);
            if (ifwin(board,player,secondpart)==1){
                printf("%c win!\n", player);
                return 0;
            }
            turns++;
        }
        //view
        else if (strcmp(input, "view") == 0) {
            view(board,mistcenter);
        }

        //printall
        else if (strcmp(input, "printall") == 0){
            for (int i = 18; i > -1; i--) {
                for (int j = 0; j < 19; j++) {
                    printf("%c ", board[j][i]);
                }
                printf("\n");
            }

        }
        else{
            printf("invalid! unrecognized input. last input is %s\n", input);
        }
    }
    return 0;
}


