#include <iostream>

using namespace std;
string board[][3] ={{"#", "#", "#"},               // [dikey][yatay]
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
    cout << "Again? y/n " << endl;
    cin >> again;
        if ( again == 'y' || again == 'Y'){
            resetGame();
        } else if ( again == 'n' || again == 'N' ){
            turn = 'E';
            cout << "# X's Score: " << scorex << endl;
            cout << "# O's Score: " << scoreo << endl;
        } else {
            cout << "Invalid option" << endl;
            againGame();
        }
}
void boardShow(){
    int size = 3;
    char line;
    // COLUMN
    cout << "# | 1 | 2 | 3 |" << endl;
    cout << "--|---|---|---|" << endl;
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
        cout << line << " | ";
        for(int j = 0; j < size; j++){

        cout << board[i][j] << " | ";
        }
        cout << endl << "--|---|---|---|" << endl;
}
}
void gameOver(){
    if (turn == 'X'){
        scorex++;
        boardShow();
        cout << "X WON" << endl;
        againGame();
    } else if ( turn == 'O'){
        scoreo++;
        boardShow();
        cout << "O WON" << endl;
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
                cout << "IT'S DRAW" << endl;
                againGame();

    } else {
        turnSwitch();
    }
}
void invalidMove(){
    checkGame();
}
void movePlay(string move){
    if (move == "A1"){
            if ( board[0][0] == "#"){
                board[0][0] = turn;
            } else {
                cout << "Already Taken" << endl;
                invalidMove();
            }
    } else if (move == "A2"){
            if ( board[0][1] == "#"){
                board[0][1] = turn;
            } else {
                cout << "Already Taken" << endl;
                invalidMove();
            }
    } else if (move == "A3"){
            if ( board[0][2] == "#"){
                board[0][2] = turn;
            } else {
                cout << "Already Taken" << endl;
                invalidMove();
            }
    } else if (move == "B1"){
            if ( board[1][0] == "#"){
                board[1][0] = turn;
            } else {
                cout << "Already Taken" << endl;
                invalidMove();
            }
    } else if (move == "B2"){
            if ( board[1][1] == "#"){
                board[1][1] = turn;
            } else {
                cout << "Already Taken" << endl;
                invalidMove();
            }
    } else if (move == "B3"){
            if ( board[1][2] == "#"){
                board[1][2] = turn;
            } else {
                cout << "Already Taken" << endl;
                invalidMove();
            }
    } else if (move == "C1"){
            if ( board[2][0] == "#"){
                board[2][0] = turn;
            } else {
                cout << "Already Taken" << endl;
                invalidMove();
            }
    } else if (move == "C2"){
            if ( board[2][1] == "#"){
                board[2][1] = turn;
            } else {
                cout << "Already Taken" << endl;
                invalidMove();
            }
    } else if (move == "C3"){
            if ( board[2][2] == "#"){
                board[2][2] = turn;
            } else {
                cout << "Already Taken" << endl;
                invalidMove();
            }
    } else {
            cout << "Invalid Move!" << endl;
            invalidMove();
    }
    }

int main(){

    string move;
    do{
        boardShow();
    cout << turn <<"'s Turn" << endl;
    cin >> move;

    movePlay(move);
    checkGame();

    } while (turn != 'E');

    return 0;
}