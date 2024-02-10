#include <iostream>
#include <cstdlib>
#include <ctime>
class Die 
{
public:
	Die() 
{
	// Initialize the random seed
	srand(static_cast<unsigned int>(time(0)));
}
	int roll() 
{
	// Return a random number between 1 and 6
	return rand() % 6 + 1;
}
};
class DiceRoller 
{
private:
	Die die1, die2;
public:
	void rollDice() 
{
	int result1 = die1.roll();
	int result2 = die2.roll();
	std::cout << "Rolled a pair of dice: " << result1 << " and " << result2 << std::endl;
}
};
class Game 
{
private:
	DiceRoller diceRoller;
public:
	void play() 
{
	std::cout << "Welcome to the Dice Rolling Simulator!" << std::endl;
	char choice;
	do 
{
	diceRoller.rollDice();
	std::cout << "Roll again? (y/n): ";
	std::cin >> choice;
}   
	while (choice == 'y' || choice == 'Y');
}
};
int main() 
{
	Game game;
	game.play();
	return 0;
}