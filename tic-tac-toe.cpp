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
void checkGame(){
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
    checkGame();
}
void movePlay(std::string move){
    if (move == "A1"){
            if ( board[0][0] == "#"){
                board[0][0] = turn;
            } else {
                std::cout << "Already Taken\n";
                invalidMove();
            }
    } else if (move == "A2"){
            if ( board[0][1] == "#"){
                board[0][1] = turn;
            } else {
                std::cout << "Already Taken\n";
                invalidMove();
            }
    } else if (move == "A3"){
            if ( board[0][2] == "#"){
                board[0][2] = turn;
            } else {
                std::cout << "Already Taken\n";
                invalidMove();
            }
    } else if (move == "B1"){
            if ( board[1][0] == "#"){
                board[1][0] = turn;
            } else {
                std::cout << "Already Taken\n";
                invalidMove();
            }
    } else if (move == "B2"){
            if ( board[1][1] == "#"){
                board[1][1] = turn;
            } else {
                std::cout << "Already Taken\n";
                invalidMove();
            }
    } else if (move == "B3"){
            if ( board[1][2] == "#"){
                board[1][2] = turn;
            } else {
                std::cout << "Already Taken\n";
                invalidMove();
            }
    } else if (move == "C1"){
            if ( board[2][0] == "#"){
                board[2][0] = turn;
            } else {
                std::cout << "Already Taken\n";
                invalidMove();
            }
    } else if (move == "C2"){
            if ( board[2][1] == "#"){
                board[2][1] = turn;
            } else {
                std::cout << "Already Taken\n";
                invalidMove();
            }
    } else if (move == "C3"){
            if ( board[2][2] == "#"){
                board[2][2] = turn;
            } else {
                std::cout << "Already Taken\n";
                invalidMove();
            }
    } else {
            std::cout << "Invalid Move!\n";
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
    checkGame();

    } while (turn != 'E');

    return 0;
}
