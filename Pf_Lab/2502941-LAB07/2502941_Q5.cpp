#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;
int main(){
    srand(time(0));
    /*keep tracking of computer's score*/
    int attempt=0;
    char choice;
    /*keep tracking of user's score*/
    int users_Score=0;
    int computer_score=0;
    while (users_Score < 3 && computer_score < 3)
    {
    cout << "-------------------------------------"<<endl;
    cout << "ROCK , PAPER AND SCISSOR GAME!"<<endl;
    cout << "CHOOSE ONE OF FOLLOWING OPTION"<<endl;
    cout << "(r) for rock"<<endl;
    cout << "(p) for paper"<<endl;
    cout << "(s) for scissor"<<endl;
    cout << "-------------------------------------"<<endl;
    cin >> choice; 
    int Random_Word=rand()%3+1;
    switch (Random_Word)
    {
    case 1:
    cout << "Computer choice is rock"<<endl;
    break;
    case 2:
    cout << "Computer choice is paper"<<endl;
    break;
    case 3:
    cout << "Computer choice is scissor"<<endl;
    break;
    default:
    break;
    }
    /*If users enter appropirate input*/

    /* For tie winner*/
    if ((choice =='r' && Random_Word==1) ||(choice =='p' && Random_Word==2)||(choice =='s' && Random_Word==3))
    {
        cout << "It's a tie"<<endl;
        continue;
    }
    else if (choice == 's' || choice=='r'|| choice=='p')
    {
    /*_________________________________USER___________________________________________*/

    /*Increase attempt no.2 if users beat computer.
    There are 3 option to beat computer*/

    /*From if user chooses rock and computer chooses paper*/
        if ( choice == 'r' && Random_Word==3)
        {
            cout << "You win. Rock smashes scissor. "<<endl;
            users_Score++;
            cout << "User's score "<< ":"<< users_Score<<endl;
        }
        /*From if user paper rock and computer chooses rock*/
        else if ( choice == 'p'&& Random_Word==1)
        {
            cout << "You win. Paper wraps rock. "<<endl;
            users_Score++;
            cout << "User's score "<< ":"<< users_Score<<endl;
        }
            /*From if user chooses scissor and computer chooses paper*/
        else if ( choice == 's'&& Random_Word==2)
        {
            cout << "You win. Scissor cuts paper. "<<endl;
            users_Score++;
            cout << "User's score "<< ":"<< users_Score<<endl;}
        else
        {
        /*_____________________________________COMPUTER___________________________________________*/
            cout << "COmputer wins"<<endl;
            computer_score++;
            cout << "Computer's score :"<<" "<< computer_score<<endl;
        }
    }
    else
    /*If user enter inappropirate input*/
    {
        cout << "Invalid. choose one of follwoing option"<<endl;
        cout << "(r) for rock"<<endl;
        cout << "(p) for paper"<<endl;
        cout << "(s) for scissor"<<endl;
    }
}
if (users_Score==3)
{
    cout << "Users win with a score of "<<" " << users_Score<<endl;
}
else if (computer_score==3)
{
    cout << "Computer wins with a  score of "<<" " << computer_score<<endl;
}
}

