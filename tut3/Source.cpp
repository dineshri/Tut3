#include<iostream>
#include<cstdio>
#include<cmath>
#include<ctime>
#include<string>

using namespace std;


class Dice
{
private:  
	int result;   
public:		
	int accresult; //accumulated result of dice rolls 
			
     Dice() {                               // Default Constructor
			srand((unsigned)time(NULL)); //seed the randomizer
			rand();             // call rand function a few times to get a good seed
			rand();
			rand();
			result = 0;       // set default parameters when dice not rolled	
			accresult = 0;
}

		Dice(int resnew) {   //Overloading constructor
			srand((unsigned)time(NULL));
			rand(); 
			rand(); 
			rand();
			result = resnew;  //result when dice is rolled
			accresult = 0;
		}

		int roll() {                       
			result = rand() % 6 + 1;         // Value of the result is changed randomly 
			accresult = accresult + result; //accumulating result at each roll

			return result;
		}                               

		~Dice() {} //default constructor
};



//Defining global overloaded functions prototypes

float average(Dice d, int rolls);          //receives a dice object and the number of rolls
float average(int arr[], int arraylength); // receives an integer array as well as the number of integers for that array

int main()
{
	int temp = 0;          //temporarily hold the result of the roll 
	int rolls = 0;
	int *pointer = NULL;   // initialize array pointer
	pointer = new int[rolls];
	
	char userinput = 'x';   //User input variable to continue or stop program

	Dice *d1 = new Dice();  // creating a dice object with default constructor

	//The user should be able to keep rolling his dice unless he enters a specific character to terminate the game
	while (userinput != 's')
	{
		cout << "Enter any character to do a dice roll. Enter 's' to stop the dice roll " << endl;
		cin >> userinput;
		rolls++;                  //increment roll counter after every roll

		temp = d1->roll();
		cout << "Result: " << temp << endl;
		cout << "Rolls: " << rolls << endl;
		cout << "Accumulated result: " << d1->accresult << endl;
		cout << "Average from Dice Overloaded Function : " << average(*d1, rolls) << endl;  

		//Setting up array for passing it to overloaded function
		//pointer[rolls - 1] = temp;    ***This method is correct too for referencing arrays with pointers
		*(pointer + (rolls - 1)) = temp;
		cout << "Average from Array Overloaded Function: " << average(pointer, rolls) << endl;	//Function works successfully up to 19 rolls. Don't pass array using pointer reference
	}                                                                                           //Break point is triggered upon termination

	//delete [] pointer; 
	pointer = NULL; //setting this to NULL seems to reduce possibility of break point run time error

	delete d1;  //Done using dice object so remove it from memory
	return 0;
}

float average(Dice d, int rolls)
{
	float ave = (float)d.accresult / (float)rolls; //Used typecasting to force floating point calculations
	//useful when the variables cannot be changed to float due to program conflicts
	return ave;
}

float average(int arr[], int arraylength)
{
	float ave = 0.00;
	int addresult = 0;

	for (int counter = 0; counter <arraylength; counter++)
	{
		addresult = addresult + arr[counter]; //Could also write *(arr + counter)
		cout << "Roll " << counter + 1 << " is " << *(arr + counter) << endl; //Display the values stored in the array with each roll
	}
	ave = (float)addresult / (float)arraylength;

	return ave;
}
