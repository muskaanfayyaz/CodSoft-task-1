#include<iostream>
#include<stdlib.h> // Include the standard library for functions such as srand() and rand()
#include<time.h>  // Include the time library for functions such as time()
#include<limits>  // Include the limits library for numeric_limits<>

using namespace std;

int main(){
	
	srand(time(0));  // Seed the random number generator with the current time
	
	int randomNumber = rand() % 100 + 1 ;  // Generate a random number between 1 and 100
	int guess;
	int attempts = 0 ;
	
	cout<<"Welcome to Number Guessing Game Extreme Edition\n ";
    cout << "I have selected a number between 1 and 100. Can you guess what it is?\n";
    
    do{
    	
    	cout<<"Enter your guess (1-100) : ";
    	cin>>guess;
    	attempts ++ ;  // Increment the attempts counter
    	
    	if(cin.fail() || guess<1 || guess>100) // Check if the input other than number or out of range
		{ 
    		
    		cin.clear();  // Clear the error flag
    		cin.ignore(numeric_limits<streamsize>::max() , '\n'); // Discard invalid input
    		cout << "Invalid input. Please enter a number between 1 and 100.\n"; 
            continue; // Skip the rest of the loop and start over
            
		}
		
		if (guess > randomNumber){
			cout<<"Too high ! Try Again ... \n";
		}
		else if (guess < randomNumber){
			cout<<"Too low ! Try Again ... \n";
		}
		else{
		    cout << "Congratulations! You guessed it right in " << attempts << " attempts.\n";
		}
	
	} while (guess != randomNumber); // Repeat the loop until the guess is correct

     return 0 ;
}
