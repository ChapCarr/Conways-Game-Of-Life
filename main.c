#include <stdio.h>

#define ROW 20
#define COL 20


/*

    TODO: ADD graphics via SDL
    TODO: Find starter board too produce more interesting results
    TODO: more test to make sure game is running correctly 

*/

int checkRules(int array[ROW][COL], int row, int col){
    int friend = 0;
    int dead = 0;
    int returnCode; 

     // Check for left neighbor
    if (col > 0) {
        if (array[row][col - 1] == 1) {
            friend++;
        } else {
            dead++;
        }
        if (row > 0 && array[row - 1][col - 1] == 1) {
            friend++;
        } else {
            dead++;
        }
        if (row < ROW - 1 && array[row + 1][col - 1] == 1) {
            friend++;
        } else {
            dead++;
        }
    }

    // Check for top neighbor
    if (row > 0) {
        if (array[row - 1][col] == 1) {
            friend++;
        } else {
            dead++;
        }
    }

    // Check for right neighbor
    if (col < COL - 1) {
        if (array[row][col + 1] == 1) {
            friend++;
        } else {
            dead++;
        }
        if (row > 0 && array[row - 1][col + 1] == 1) {
            friend++;
        } else {
            dead++;
        }
        if (row < ROW - 1 && array[row + 1][col + 1] == 1) {
            friend++;
        } else {
            dead++;
        }
    }

    // Check for bottom neighbor
    if (row < ROW - 1) {
        if (array[row + 1][col] == 1) {
            friend++;
        } else {
            dead++;
        }
    }

    // Check the three rules for conway game of life 
    if((array[row][col] == 1) && (friend == 2 || friend == 3 )){
        returnCode = 1;
    }else if(array[row][col] == 0 && friend == 3){
        returnCode = 1; 
    }else{
        returnCode = 0; 
    }

    return returnCode; 
}

void printBoard(int array[ROW][COL]){
    int i,j;

    for(i = 0; i < ROW;i++){
        for(j = 0; j < COL; j++){
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}  


int main(){
    int test;
    int i,j;  
    int returnedVal; 
    int swapBoard[ROW][COL]; 
    int board[ROW][COL] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0}
};


    for(test = 0; test < 50; test++){

        for (i = 0; i < ROW; i++) {
            for (j = 0; j < COL; j++) { 
                swapBoard[i][j] = checkRules(board, i, j);
            }
        }

        printBoard(swapBoard);
        printf("\n");


        for (i = 0; i < ROW; i++) {
            for (j = 0; j < COL; j++) { 
                board[i][j] = swapBoard[i][j];
            }
        }
    }


}

    
