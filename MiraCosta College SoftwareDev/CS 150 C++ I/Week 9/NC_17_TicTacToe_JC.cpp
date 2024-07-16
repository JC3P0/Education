/*____________________
* AUTHOR: Josh Clemens
* COURSE: CS 150: C++ Programming 1
* NC (PROJECT)#: NC_17
* LAST MODIFIED: April 01, 2022
*__________
* TicTacToe
*_____________________
* PROGRAM DESCRIPTION:
* Uses a two-dimension char array to display a tic tac toe game. players one and two enter moves into the array per row and column.
*___________
* ALGORITHM:
* INITIALIZE and output playing board per const int SIZE
* INITIALIZE and incriment ++turns for player one and two turns. also counts board to verify a tie game
* INPUT row and column to place a maker on the board per player one and two
* CALCULATE all possible win layouts for the board and test the board per 'O' and 'X'
* OUTPUT Player 1 win or player 2 win, per bool function and ++turn(10) for tie game 
*___________________________________________
* ALL IMPORTED LIBRARIES NEEDED AND PURPOSE:
* <cstdlib> Provides standard functions, including dynamic memory management,
* random number generation, communication with the environment,
* integer arithmetics, searching, sorting and converting.
* <iostream> Used for console input and output (cin and cout).
*____________________________________________*/

#include <cstdlib>
#include <iostream>
using namespace std;

const int SIZE = 3;
void initializeBoard(char board [][SIZE]);
void displayBoard(char board[][SIZE]);
bool checkWinner(char board[][SIZE], char symbol);

int main(int argc, char* argv[]) {
    
    int turn = 1; // player one starts
    char board[SIZE][SIZE]; //board array size per const int SIZE
    int right = 0; //row input
    int down = 0; //column input
  
    initializeBoard(board);

    do{
        //cout << turn << endl; //test line
        if (turn != 10){
            cout << "Welcome to the tic tac toe game!\n";
            cout << "Player 1 is 'X'\n" << "Player 2 is 'O'\n";
            cout << endl;
            displayBoard(board); 
    
            if (turn % 2 !=0){ //decides player based on even or odd "turn" value
                cout << "\nPlayer 1's turn\n";
                cout << "Enter row: ";
                cin >> right;
                cout << "Enter column: ";
                cin >> down;
                board[right-1][down-1] = 'X'; //changes the array on the board to 'X' per input
            }
            else{
                cout << "\nPlayer 2's turn\n";
                cout << "Enter row: ";
                cin >> right;
                cout << "Enter column: ";
                cin >> down;
                board[right-1][down-1] = 'O'; //changes the array on the board to 'O' per input
        }

        checkWinner(board, 'O');    
        checkWinner(board, 'X');
        }
        else{
            cout << "Thank you for playing the tic tac toe game!\n";
            cout << "Player 1 is 'X'\n" << "Player 2 is 'O'\n";
            cout << endl;
            displayBoard(board);
            cout << "\nTie game!!!\n";
            return EXIT_SUCCESS;
        }
        
       //cout << "trueX-1-" << checkWinner(board, 'X') <<endl;  //testing lines
       //cout << "falseX-0-" << checkWinner(board, 'X') <<endl; //testing lines
       //cout << "trueO-1-" << checkWinner(board, 'O') <<endl;   //testing lines
       //cout << "falseO-0-" << checkWinner(board, 'O') <<endl;  //testing lines
        
        system("clear"); 
        ++turn;
    }while (checkWinner(board, 'X') != true && checkWinner(board, 'O') != true);

    if (checkWinner(board, 'O') == true){
        cout << "Thank you for playing the tic tac toe game!\n";
        cout << "Player 1 is 'X'\n" << "Player 2 is 'O'\n";
        cout << endl;
        displayBoard(board);
        cout << "\nPlayer 2 is winner!!!\n";
    }
    else{
        cout << "Thank you for playing the tic tac toe game!\n";
        cout << "Player 1 is 'X'\n" << "Player 2 is 'O'\n";
        cout << endl;
        displayBoard(board);
        cout << "\nPlayer 1 is winner!!!\n";
    }

    // system("PAUSE"); //for DevC++ on windows
    return EXIT_SUCCESS;
}

    /***** Function Definitions *****/

void initializeBoard(char board [][SIZE]) {
    //initialize board
    for (int row = 0; row < SIZE; row++) {
        for(int column = 0; column < SIZE; column++) {
            board[row][column] = '*';
        }
    }
}
void displayBoard(char board[][SIZE]) {
    
    cout << "  |";
    
    for (int column = 0; column < SIZE; column++) {
        cout << column + 1 << "|";
    }
    cout << endl;   
    cout << "--|";
    
    for(int column = 2; column < SIZE; column++) {
        cout << "-----|";
    }        
    cout << endl;
    
    for (int row = 0; row < SIZE; row++) {
        
        cout << row+1 << " |";
        
        for(int column = 0; column < SIZE; column++) {
            cout << board[row][column] << "|";
        }
        cout << endl;
        cout << "--|";
        
        for(int column = 2; column < SIZE; column++) {
            cout << "-----|";
        }        
        cout << endl;
    }
}

bool checkWinner(char board[][SIZE], char symbol) {
    
    //first check if a row has a winner   
    for(int row = 0; row < SIZE; row++) {
        bool matched = true;
        for (int column = 0; column < SIZE; column++) {
            if (board[row][column] != symbol) {
                matched = false;
            }
        }
        if(matched) {
            return matched;
        }            
    }
    //next if column has a winner
    //check each column for winner
    for (int column = 0; column < SIZE; column++) {
        bool matched = true;
        for (int row = 0; row < SIZE; row++) {
            if(board[row][column] != symbol) {
                matched = false;
            }                
        }
        if(matched) {
            return matched;
        }
    }
    //check for diagonal match upper left to lower right
    bool matched = true;
    for (int i = 0; i < SIZE; i++) {
        if(board[i][i] != symbol) {
            matched = false;
        }
    }
    if(matched) {
        return matched;
    }
    //check for diagonal match upper right to lower left
    matched = true;
    for (int i = 0; i < SIZE; i++) {
        if(board[i][SIZE-1-i] != symbol) {
            matched = false;
        }
    }
    if(matched) {
        return matched;
    }
    
    return false;
}

/*    //testing loser
    board[0][0] = 'X'; board[0][1] = 'X'; board[0][2] = '*';
    board[1][0] = 'O'; board[1][1] = 'O'; board[1][2] = '*';
    board[2][0] = 'X'; board[2][1] = '*'; board[2][2] = '*';
    displayBoard(board);
    cout << "Is winner?(0)" << checkWinner(board, 'O') << endl;;
    //testing loser for O but winner for X
    board[0][0] = 'X'; board[0][1] = 'X'; board[0][2] = 'O';
    board[1][0] = 'O'; board[1][1] = 'X'; board[1][2] = 'O';
    board[2][0] = 'X'; board[2][1] = 'O'; board[2][2] = 'X';
    displayBoard(board);
    cout << "Is winner?(0)" << checkWinner(board, 'O') << endl;    
    cout << "Is winner?(1)" << checkWinner(board, 'X') << endl;    
    
    //testing winner
    board[0][0] = 'X'; board[0][1] = 'X'; board[0][2] = 'X';
    board[1][0] = 'O'; board[1][1] = 'O'; board[1][2] = '*';
    board[2][0] = 'X'; board[2][1] = '*'; board[2][2] = '*';
    displayBoard(board);
    cout << "Is winner?(1)" << checkWinner(board, 'X') <<endl;
    //testing winner for O
    board[0][0] = 'X'; board[0][1] = 'O'; board[0][2] = 'X';
    board[1][0] = 'O'; board[1][1] = 'O'; board[1][2] = '*';
    board[2][0] = 'O'; board[2][1] = 'O'; board[2][2] = 'X';
    displayBoard(board);
    cout << "Is O winner?(1)" << checkWinner(board, 'O') <<endl; 
    cout << "Is X winner?(0)" << checkWinner(board, 'X') <<endl;    
    
    //testing winner for X
    board[0][0] = 'X'; board[0][1] = 'O'; board[0][2] = 'X';
    board[1][0] = 'O'; board[1][1] = 'X'; board[1][2] = '*';
    board[2][0] = 'O'; board[2][1] = '*'; board[2][2] = 'X';
    displayBoard(board);
    cout << "Is winner?(1)" << checkWinner(board, 'X') <<endl;
   //testing winner X diagonal ur to ll
    board[0][0] = 'X'; board[0][1] = '*'; board[0][2] = 'X';
    board[1][0] = 'O'; board[1][1] = 'X'; board[1][2] = '*';
    board[2][0] = 'X'; board[2][1] = '*'; board[2][2] = '*';
    displayBoard(board);
    cout << "Is winner?(1)" << checkWinner(board, 'X') <<endl;
*/
