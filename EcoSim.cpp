/*
Alexander Gill
CS 3505 Assignment 1\

This program is an ecological simulation for the interaction between rabbit
and fox populations in the wild.
*/



#include <iostream>
#include <math.h>
using namespace std;

// Declaring Functions before main so they will all be recognized and searched for when called
void runSimulation(int numIters, double numRabbits, double numFoxes);
void incrementCounter(int* counter);
void plotPopulations(double numRabbits, double numFoxes, double scaleFactor);
void plotCharacter(int spaces, char dispChar);
void test_cin();
void updatePopulations(double g, double p, double c, double m, double K,
 double& numRabbits, double& numFoxes);

int main(){
	double Rabbits, Foxes;
	// Retrieving initial values for Rabbit and Fox Populations from the user
	cout << "Enter initial rabbit population: ";
	cin >> Rabbits;
	cout << endl;
	test_cin();
	cout << "Enter initial fox population: ";
	cin >> Foxes;
	cout << endl;
	test_cin();
	// This activates the simulation for 500 iterations with the initial populations given
	runSimulation(500,Rabbits,Foxes);
}

void runSimulation(int numIters, double numRabbits, double numFoxes){
	double g = 0.2, p = 0.0022, c = 0.6, m = 0.2, K = 1000.0,s = 0.1;
	int counter = 0;
	//While loop exits the simulation if either of the populations falls below one,
	// or if the simulation iterates to completion
	while(numFoxes >= 1 and numRabbits >= 1 and counter < numIters){
		updatePopulations(g,p,c,m,K,numRabbits,numFoxes);
		plotPopulations(numRabbits,numFoxes,s);
		// Moved the endline from plotPopulations because it was causing the function test to fail
		// in gradescope
		cout << endl;
		// passing the address of the counter to incrementCounter
		incrementCounter(&counter);
	}
}

void incrementCounter(int* counter){
	//Increment counter receives a pointer to counter, then dereferences it and adds 1 to the 
	// actual value by looking at the value at that address
	*counter = *counter + 1;
}

void plotPopulations(double numRabbits, double numFoxes, double scaleFactor){
	int spaces;
	int spaces2;
	// Scaling populations down to be plotted
	int posRabbits = floor(numRabbits*scaleFactor);
	int posFoxes = floor(numFoxes*scaleFactor);
	//This first condition is for when the scaled populations are equal
	if (posRabbits == posFoxes){
		//ensures the asterik will be spaced properly
		spaces = posRabbits;
		plotCharacter(spaces, '*');
	}
	// These are conditions for the rabbit having greater population and vice versa
	else if (posRabbits > posFoxes){
		// need 2 separate spaces in this case, one to the first character, and the other
		// from the first character to the second
		spaces = posFoxes;
		spaces2 = posRabbits - posFoxes - 1;
		//also need two calls to plotCharacter, since it can only plot one at a time
		plotCharacter(spaces, 'F');
		plotCharacter(spaces2, 'r');
	}
	else if (posFoxes > posRabbits){
		// need 2 separate spaces in this case, one to the first character, and the other
		// from the first character to the second
		spaces = posRabbits;
		spaces2 = posFoxes - posRabbits - 1;
		//also need two calls to plotCharacter, since it can only plot one at a time
		plotCharacter(spaces, 'r');
		plotCharacter(spaces2, 'F');
	}
}

void plotCharacter(int spaces, char dispChar){
	//prints spaces for the number given in "spaces"
	for(int i = 0; i < spaces; i++){
		cout << " ";
	}
	// then prints whatever character was sent immediately after
	cout << dispChar;
}

//This is a short function I created to check if the input matches the variable type,
// it returns an error if not
void test_cin(){
	if(cin.fail()){
		cout << "ERROR: Population must be a number" << endl;
		exit;
	}
}

void updatePopulations(double g, double p, double c, double m, double K,
 double& numRabbits, double& numFoxes){
 	// Calculating changes in the populations based off of the equations given
	double deltaRabbit = g * numRabbits * (1 -(numRabbits/K)) - p * numRabbits * numFoxes;
	double deltaFoxes = c * p *numRabbits * numFoxes - m * numFoxes;
	// Changing the populations values by their changes, this works because they were passed by
	//value
	numRabbits = numRabbits + deltaRabbit;
	numFoxes = numFoxes + deltaFoxes;
}