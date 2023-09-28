#include <stdio.h>
#include <time.h>
#include <SDL2/SDL.h>
#include <stdbool.h> 

#define ROW 640
#define COL 480


/*

    TODO: ADD graphics via SDL
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

    SDL_Event e; 
    bool quit = false;
    while(quit == false){
    //for(test = 0; test < 500; test++){
        // check the board
        for (i = 0; i < ROW; i++) {
            for (j = 0; j < COL; j++) { 
                swapBoard[i][j] = checkRules(board, i, j);
            }
        }
        
       // printBoard(swapBoard);
       // printf("\n");
       // PrintBoard
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

     // This may need to be inside loop? 
     SDL_RenderPresent(renderer);

   /* if(window) {
    // Go through the pending event queue once
    SDL_Event event;
    while(SDL_PollEvent(&event)){
        // do nothing
    }
    SDL_Delay(100);
    */
    //SDL_Event e; 
    //bool quit = false;
    
                
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

  

    
