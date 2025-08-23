#include<iostream>  // For input and output (cin, cout)
#include<conio.h>  // For getch() function (to wait for a key press)
using namespace std;

int main(){
    int choice, first_number, second_number;
    float result = 0;  // Stores calculation result
    int modulus_result = 0;  

    do{
        // Display menu
        system("cls");
        cout<<"\n================================"<<endl;
        cout<<"\tSimple Calculator"<<endl;
        cout<<"================================"<<endl;
        cout<<"\nChoose an operation:"<<endl;
        cout<<"1. Addition (+)"<<endl;
        cout<<"2. Subtraction (-)"<<endl;
        cout<<"3. Multiplication (*)"<<endl;
        cout<<"4. Division (/)"<<endl;
        cout<<"5. Modulus (%)"<<endl;
        cout<<"6. Exit"<<endl;

        // Take user’s menu choice
        cout<<"\nEnter your choice : ";
        cin>>choice;

        // if the user types a Non-Numeric input
        if(cin.fail()){  
            cin.clear();  
            cin.ignore(1000,'\n');
            cout<<"\nInvalid input! \nPlease enter numbers only !!"<<endl;
            cout<<"\nPress any key to continue...";
            getch();
            continue;  // restart loop
        }
        
        // Check for invalid choice
        if(choice<1 || choice>6){
            cout<<"\nInvalid choice! \nPlease try again !!"<<endl;
            cout<<"\nPress any key to continue...";
            getch();
            continue;  // restart loop
        }
        
        if(choice==6) break;  // Exit option

        // Take input numbers
        cout<<"Enter first number : ";
        cin>>first_number;
        cout<<"Enter second number : ";
        cin>>second_number;

        bool valid = true;  // To handle invalid cases like division by zero

        // Perform calculation based on choice
        switch(choice){
            case 1 : // Addition
                result = first_number + second_number;
                break;

            case 2 : // Subtraction
                result = first_number - second_number;
                break;

            case 3 : // Multiplication
                result = first_number * second_number;
                break;

            case 4 : // Division
                if(second_number == 0){  // Division by 0 not allowed
                    cout<<"Error : Division by zero is not defined."<<endl;
                    valid = false;
                }
                else result = first_number / (float)second_number;  // Typecast for float division
                break;

            case 5 : // Modulus
                if(second_number == 0){  // Modulus by 0 not allowed
                    cout<<"Error : Division by zero is not defined."<<endl;  // Modulus works only with integers
                    valid = false;
                }
                else modulus_result = first_number % second_number;
                break;
        }

        // Show result if valid
        if(valid){
            if(choice==5)  cout<<"Result : "<<modulus_result<<endl; 
            else  cout<<"Result : "<<result<<endl;
        }

        cout<<"\nPress any key to continue...";
        getch();  // Wait for key press before showing menu again

    }while(choice!=6);  // Repeat until user chooses Exit


    // Exit message
    cout<<"\nThanks for using this Calculator !!!"<<endl;
    cout<<"Developed by : Kuldip singh"<<endl<<endl;
}
