#include <iostream>

std::string board[][3] ={{"#", "#", "#"},               // [dikey][yatay]
                    {"#", "#", "#"},
                    {"#", "#", "#"}};

int scorex = 0, scoreo = 0;
char turn = 'X';


void turnSwitch(){
    switch(turn){
            case 'X':
            turn = 'O';
                break;
            case 'O':
            turn = 'X';
                break;
    }
}
void resetGame(){
    int size = 3;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            board[i][j] = '#';
        }
    }
}
void againGame(){
    char again;
    std::cout << "Again? y/n \n";
    std::cin >> again;
        if ( again == 'y' || again == 'Y'){
            resetGame();
        } else if ( again == 'n' || again == 'N' ){
            turn = 'E';
            std::cout << "# X's Score: " << scorex << '\n';
            std::cout << "# O's Score: " << scoreo << '\n';
        } else {
            std::cout << "Invalid option" << '\n';
            againGame();
        }
}
void boardShow(){
    int size = 3;
    char line;
    // COLUMN
    std::cout << "# | 1 | 2 | 3 |\n";
    std::cout << "--|---|---|---|\n";
    for (int i = 0; i < size; i++){
        // ROW
        switch (i){
            case 0 :
            line = 'A';
                break;
            case 1 :
            line = 'B';
                break;
            case 2 :
            line = 'C';
                break;     
        }
        std::cout << line << " | ";
        for(int j = 0; j < size; j++){

        std::cout << board[i][j] << " | ";
        }
        std::cout << "\n--|---|---|---|\n";
}
}
void gameOver(){
    if (turn == 'X'){
        scorex++;
        boardShow();
        std::cout << "X WON\n";
        againGame();
    } else if ( turn == 'O'){
        scoreo++;
        boardShow();
        std::cout << "O WON\n";
        againGame();
    }
}
void checkWin(){
    if ( board[0][0] == board[0][1] && board[0][0] == board[0][2] && board[0][0] != "#" ){
        gameOver(); 
    } else if ( board[1][0] == board[1][1] && board[1][0] == board[1][2] && board[1][0] != "#" ){
        gameOver();
    } else if ( board[2][0] == board[2][1] && board[2][0] == board[2][2] && board[2][0] != "#" ){
        gameOver(); // X - X - X HORIZONTAL -------------------
    } else if ( board[0][0] == board[1][0] && board[0][0] == board[2][0] && board[0][0] != "#" ){
        gameOver(); 
    } else if ( board[0][1] == board[1][1] && board[0][1] == board[2][1] && board[0][1] != "#" ){
        gameOver();
    } else if ( board[0][2] == board[1][2] && board[0][2] == board[2][2] && board[0][2] != "#" ){
        gameOver(); // VERTICAL -----------------------------
    } else if ( board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != "#" ){
        gameOver();
    } else if ( board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] != "#" ){
        gameOver(); // DIAGONAL ----------------------------
    } else if (board[0][0] != "#" && board[0][1] != "#" && board[0][2] != "#" 
            && board[1][0] != "#" && board[1][1] != "#" && board[1][2] != "#" 
            && board[2][0] != "#" && board[2][1] != "#" && board[2][2] != "#" ) {
                boardShow();
                std::cout << "IT'S DRAW\n";
                againGame();

    } else {
        turnSwitch();
    }
}
void invalidMove(){
    checkWin();
}
void movePlay(std::string move){

    int row, column;
    if (move[0] == 'A') {
        row = 0;
    } else if (move[0] == 'B'){
        row = 1;
    } else if (move[0] == 'C'){
        row = 2;
    }

    if (move[1] == '1'){
        column = 0;
    } else if (move[1] == '2'){
        column = 1;
    } else if (move[1] == '3'){
        column = 2;
    }

    if ( board[row][column] == "#"){
        board[row][column] = turn;
    } else if (board[row][column] == "X" || board[row][column] == "O") {
        std::cout << "Already Taken\n";
        invalidMove();
    } else {
        std::cout << "Invalid Move\n";
        invalidMove();
    }
    }

int main(){
    std::string move;
    do{
        boardShow();
    std::cout << turn <<"'s Turn\n";
    std::cin >> move;

    movePlay(move);
    checkWin();

    } while (turn != 'E');

    return 0;
}
