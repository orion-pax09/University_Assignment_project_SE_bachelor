#include <iostream>
using namespace std;
void display(char grid[5][5]){
    for (int i = 0 ; i < 5 ; i++){
        for (int j = 0 ; j < 5 ; j++){
            if (grid[i][j]=='0'){
                cout << ". ";
            }
            else{
                cout << grid[i][j]<<" ";
            }
        }
        cout << endl;
    }
}
char validmove(char grid[5][5]){
    int rows ; 
    cout << "Enter the rows: ";
    cin >> rows;
    int column;
    cout << "Enter the column: ";
    cin >> column;
    char letter;
    cout << "Enter the letter: ";
    cin >> letter;
    while (letter < 'A' || letter > 'Z'){
        cout << "Enter the capital letter: ";
        cin >> letter;
    }
    if ((int)letter >= 65 && (int)letter<= 90)
    {
        if (rows < 0 || rows > 4 || column < 0 || column > 4){
        cout << "Enter the rows and column (0 - 4): "<<endl;
        cin >> letter;
    }
    else if (grid[rows][column]=='0'){
        grid[rows][column] = letter;
    }
    else{
        cout << "Enter the letter from (A - Z)";
    }
    return grid[rows][column];
}
}

bool gameover(char grid[5][5]){
    for (int i = 0 ; i < 5 ; i++){
        for (int j = 0 ; j < 5 ; j++){
            if(grid[i][j]=='0'){
                return false;
            }
        }
    }
    return true;
}
int main(){
    char crossgridpuzzle[5][5]={
        {'C','A','T','0','0'},
        {'0','0','A','0','0'},
        {'D','O','G','0','0'},
        {'0','0','0','0','0'},
        {'0','0','0','0','0'}
    };
        while (!gameover(crossgridpuzzle)){
            display(crossgridpuzzle);
            validmove(crossgridpuzzle);
            display(crossgridpuzzle);
        
    };
    if (gameover(crossgridpuzzle)){
        cout << "Whole cell is filled. Game over";
    };

}