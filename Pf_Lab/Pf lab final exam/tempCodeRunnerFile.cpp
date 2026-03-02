#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void display(char grid[][3]){
    for (int i = 0 ; i < 3 ; i++){
        for (int j = 0 ; j < 3; j++){
            cout << grid[i][j]<< " ";
        }
        cout << endl;
    }
}
bool validmove(char grid[][3]){
    int bot_row_move = rand()%3;
    int bot_column_move = rand()%3;
    char player_x = 'X';
    char bot_O = 'O';
    int move_row;
    int move_column;
    cout << "Enter the row: "; cin >> move_row;
    cout << "Enter the column: "; cin >> move_column;
    while (move_row > 2 || move_row <  0 || move_column > 2 || move_column <  0 ){
        cout << "Enter the row (0 - 2) & column (0 - 2): ";
        cin >> move_row;
        cin >> move_column;
    } 
    bool player_turn = true;
    bool bot_turn =false;
    if (grid[move_row][move_column]=='.'){
        grid[move_row][move_column]= player_x;
    }
    while (grid[bot_row_move][bot_column_move]!='.'){
         bot_row_move = rand()%3;
         bot_column_move = rand()%3;
    }
    grid[bot_row_move][bot_column_move]= bot_O;
    return true;
}
bool game_over(char grid[][3]){
    
        if (grid[0][0]=='X'&&grid[0][1]=='X'&&grid[0][2]=='X'||grid[1][0]=='X'&&grid[1][1]=='X'&&grid[1][2]=='X'||
        grid[2][0]=='X'&&grid[2][1]=='X'&&grid[2][2]=='X'){
            cout << "Player X wins";
            return true;
        }
        else if(grid[0][0]=='O'&&grid[0][1]=='O'&&grid[0][2]=='O'||grid[1][0]=='O'&&grid[1][1]=='O'&&grid[1][2]=='O'||
        grid[2][0]=='O'&&grid[2][1]=='O'&&grid[2][2]=='O'){
            cout << "Bot O wins";
            return true;
        }
        else if ((grid[0][0]=='X'&&grid[1][1]=='X' &&grid[2][2]=='X')||(grid[0][2]=='X'&&grid[1][1]=='X'&&grid[2][0]=='X')){
            cout << "players X wins diagonally";
            return true;
        }
        else if ((grid[0][0]=='O'&&grid[1][1]=='O'&&grid[2][2]=='O')||(grid[0][2]=='O'&&grid[1][1]=='O'&&grid[2][0]=='O')){
            cout << "Bot O wins diagonally";
            return true;
        }
    return false;
}

int main (){
    srand(time(0));
    char tic_tac_Toe[3][3]={
        {'.','.','.'},
        {'.','.','.'},
        {'.','.','.'}
    };
    display(tic_tac_Toe);
    while (!game_over(tic_tac_Toe)){
        validmove(tic_tac_Toe);
        display(tic_tac_Toe);
    }
    if (game_over(tic_tac_Toe)){
        cout << "Game is over";
    }
}