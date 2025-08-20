#include<iostream>
using namespace std;

// 3x3 board for Tic Tac Toe, filled with numbers 1 to 9 initially
char Board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};

// Variable to track current player's turn ('X' or 'O')
char turn = 'X';

// Variables to store row and column input by the user
int row , column;

// Variable to check if the game ended in a draw
bool draw = false;


// Function to display the current state of the board
void Display_Board(){
    system("cls");
    cout<<"\n\t     Tic Tac Toe Game"<<endl;
    cout<<"\t*========================*"<<endl;
    cout<<"\tPlayer1 [X]"<<endl;
    cout<<"\tPlayer2 [O]"<<endl;
    cout<<endl<<endl;
    cout<<"\t        "<<"|"<<"        "<<"|"<<"        "<<endl;
    cout<<"\t    "<<Board[0][0]<<"   "<<"|"<<"    "<<Board[0][1]<<"   "<<"|"<<"    "<<Board[0][2]<<"   "<<endl;
    cout<<"\t        "<<"|"<<"        "<<"|"<<"        "<<endl;
    cout<<"\t--------*--------*--------"<<endl;
    cout<<"\t        "<<"|"<<"        "<<"|"<<"        "<<endl;
    cout<<"\t    "<<Board[1][0]<<"   "<<"|"<<"    "<<Board[1][1]<<"   "<<"|"<<"    "<<Board[1][2]<<"   "<<endl;
    cout<<"\t        "<<"|"<<"        "<<"|"<<"        "<<endl;
    cout<<"\t--------*--------*--------"<<endl;
    cout<<"\t        "<<"|"<<"        "<<"|"<<"        "<<endl;
    cout<<"\t    "<<Board[2][0]<<"   "<<"|"<<"    "<<Board[2][1]<<"   "<<"|"<<"    "<<Board[2][2]<<"   "<<endl;
    cout<<"\t        "<<"|"<<"        "<<"|"<<"        "<<endl;
    cout<<endl<<endl;
}

// Function to take player's turn
void Player_Turn(){
    int choice;
    
    if(turn=='X'){
        cout<<"\tPlayer1 [X] turn : ";
    }
    if(turn=='O'){
        cout<<"\tPlayer2 [O] turn : ";
    }
    cin>>choice;

    switch(choice){
        case 1 : row = 0; column = 0; break; 
        case 2 : row = 0; column = 1; break; 
        case 3 : row = 0; column = 2; break; 
        case 4 : row = 1; column = 0; break; 
        case 5 : row = 1; column = 1; break; 
        case 6 : row = 1; column = 2; break; 
        case 7 : row = 2; column = 0; break; 
        case 8 : row = 2; column = 1; break; 
        case 9 : row = 2; column = 2; break;
        default : 
            // If user enters invalid input
            cout<<"\n\t\tInvalid Choice !"<<endl;
            cout<<"\t\tPlease try again !!"<<endl<<endl;
            Player_Turn(); // Ask again
            return; 
    }

    // If the chosen cell is empty, mark it with player's symbol
    if(turn=='X' && Board[row][column]!='X' && Board[row][column]!='O'){
        Board[row][column] = 'X';
        turn = 'O'; // Switch turn to other player
    }
    else if(turn=='O' && Board[row][column]!='X' && Board[row][column]!='O'){
        Board[row][column] = 'O';
        turn = 'X';
    }
    else{
        // If the chosen cell is already filled
        cout<<"\n\t\tBox already filled !"<<endl;
        cout<<"\t\tPlease try again !!"<<endl<<endl;
        Player_Turn(); // Ask again
    }
}

// Function to check if the game is over
bool Gameover(){
    // Check win
    for(int i=0 ; i<3 ; i++){
        if((Board[i][0]==Board[i][1] && Board[i][1]==Board[i][2]) || (Board[0][i]==Board[1][i] && Board[1][i]==Board[2][i]))  return false;
    }
    if((Board[0][0]==Board[1][1] && Board[1][1]==Board[2][2]) || (Board[2][0]==Board[1][1] && Board[1][1]==Board[0][2])) return false;


    // If there is any box not filled
    for(int i=0 ; i<3 ; i++){
        for(int j=0 ; j<3 ; j++){
            if(Board[i][j]!='X' && Board[i][j]!='O') return true;
        }
    }

    // Check draw
    draw = true;
    return false;
}


int main(){
    
    while(Gameover()){

        Display_Board(); // Show board
        Player_Turn(); // Take input from player

    }
    Display_Board(); // Final board

    // Show result
    if(draw==true) cout<<"\t\tGAME DRAWN !!"<<endl;
    else if(turn=='X') cout<<"\t\tPlayer2 [O] Wins !!"<<endl;
    else if(turn=='O') cout<<"\t\tPlayer1 [X] Wins !!"<<endl;
    cout<<"\t\tDevloped By : Kuldip Singh"<<endl<<endl;
}