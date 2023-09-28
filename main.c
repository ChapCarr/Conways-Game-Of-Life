#include <stdio.h>
#include <time.h>
#include <SDL2/SDL.h>
#include <stdbool.h> 

#define ROW 640
#define COL 480


/*
  ************************************************************************************
  *Sorry for anyone reading this... Project was done late at night after homework or *
  *between classes. This code is messy and dirty. My apologies.                      *
  ************************************************************************************
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
// I would not use this function, was used for v1 of this project 
// the board is now quite large for this function call 
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
    int board[ROW][COL];
    
   // int sdl window 
   SDL_Window* window = NULL;
   SDL_Renderer* renderer = NULL;

   SDL_Init(SDL_INIT_VIDEO);
   SDL_CreateWindowAndRenderer(ROW,COL,0, &window, &renderer);

   // Fill board randomly with 1 and 0 to start
    srand(time(0));
    for(i = 0; i < ROW; i++){
        for(j = 0; j < COL; j++){
            if ((rand() % 10) % 2 == 0){
                board[i][j] = 1;
            }else{
                board[i][j] = 0;
            }
            
        }
    }
    
    // run loop until window is closed
    SDL_Event e; 
    bool quit = false;
    while(quit == false){
        // Swap boards for correct evolution of cells 
        for (i = 0; i < ROW; i++) {
            for (j = 0; j < COL; j++) { 
                swapBoard[i][j] = checkRules(board, i, j);
            }
        }
            
        
        // Set Window to black and cells to white
        SDL_SetRenderDrawColor(renderer, 0,0,0,255);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer,255,255,255,255);

        for(int i = 0; i < ROW; i++){
            for(int j = 0; j < COL; j++){
                if(board[i][j] == 1){
                SDL_RenderDrawPoint(renderer, i, j); 
                
                }
            }
        }

        // Render Changes
        SDL_RenderPresent(renderer);
        
        while(SDL_PollEvent(&e)){
            if(e.type == SDL_QUIT)quit = true;
        }
        
        
        // swap the boards afterwards
        for (i = 0; i < ROW; i++) {
            for (j = 0; j < COL; j++) { 
                board[i][j] = swapBoard[i][j];
            }
        }
    }
}

  

    
