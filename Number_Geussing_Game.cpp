#include<iostream>
#include<ctime>
using namespace std;

int main(){
    int guess,random_Number;  // Variables for user guess and the secret number
    int attempts = 0;  // To count how many guesses the user makes

    srand(time(0));  // Seed the random number generator with current time
    random_Number = rand() % 100 + 1;  // Generate random number between 1 and 100

    // Welcome message
    cout<<"\n  Welcome to the world of Guessing Numbers."<<endl;
    cout<<"*==========================================*";

    // Loop until the user guesses the correct number
    do{
        cout<<"\n\nPlease enter your Guess between (1 to 100) : ";
        cin>>guess;  // Take user input
        attempts++;  // Increase attempts count 

        // Check if input is valid or Not
        if(guess<1 || guess>100){
            cout<<"Invalid Guess, TRY AGAIN !!";
            continue;  // Skip rest of loop and ask again
        }

        if(guess < random_Number){
            cout<<"Guess a larger number.";  // If guess is small
        }
        else if(guess > random_Number){
            cout<<"Guess a smaller number.";  // If guess is big
        }
        else{
            // If guess is correct
            cout<<"\nCongratulation !!! You have Sucessfully guessed the Number."<<endl;
            cout<<"You take "<<attempts<<" attempts to guess the Number."<<endl;
            cout<<"Developed by : Kuldip singh"<<endl<<endl;
        }
    }while(guess!=random_Number);  // Repeat until number is guessed
}
