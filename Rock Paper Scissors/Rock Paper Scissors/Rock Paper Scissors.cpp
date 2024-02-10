#include <iostream>
#include <ctime>
#include <cstdlib>
// Enum for the three choices
enum class Choice { ROCK, PAPER, SCISSORS };
class Player 
{
public:
	// Function to get the player's choice
	virtual Choice makeChoice() const = 0;
};
class HumanPlayer : public Player 
{
public:
	// Implementation of makeChoice for the human player
	Choice makeChoice() const override 
{
	int choice;
	std::cout << "Enter your choice (0 for Rock, 1 for Paper, 2 for Scissors): ";
	std::cin >> choice;
	// Validate the input
	while (choice < 0 || choice > 2) 
{
	std::cout << "Invalid choice. Please enter a valid choice: ";
	std::cin >> choice;
}
	return static_cast<Choice>(choice);
}
};
class ComputerPlayer : public Player 
{
public:
	// Implementation of makeChoice for the computer player
	Choice makeChoice() const override 
{
	// Generate a random number (0, 1, or 2) for the computer's choice
	int randomChoice = rand() % 3;
	return static_cast<Choice>(randomChoice);
}
};
class RPSGame 
{
private:
	Player* humanPlayer;
	Player* computerPlayer;
public:
	// Constructor to initialize the players
	RPSGame(Player* human, Player* computer) : humanPlayer(human), computerPlayer(computer) {}
	// Function to determine the winner of the game
	void playGame() 
{
	Choice humanChoice = humanPlayer->makeChoice();
	Choice computerChoice = computerPlayer->makeChoice();
	std::cout << "You chose ";
	printChoice(humanChoice);
	std::cout << ". Computer chose ";
	printChoice(computerChoice);
	std::cout << ". ";
	// Determine the winner
	if (humanChoice == computerChoice) 
{
	std::cout << "It's a tie!" << std::endl;
}
	else if ((humanChoice == Choice::ROCK && computerChoice == Choice::SCISSORS) || (humanChoice == Choice::PAPER && computerChoice == Choice::ROCK) || (humanChoice == Choice::SCISSORS && computerChoice == Choice::PAPER)) {
	std::cout << "You win!" << std::endl;
}
	else 
{
	std::cout << "Computer wins!" << std::endl;
}
}
	// Function to print the choice
	void printChoice(Choice choice) const 
{
	switch (choice) 
{
	case Choice::ROCK:
	std::cout << "Rock";
	break;
	case Choice::PAPER:
	std::cout << "Paper";
	break;
	case Choice::SCISSORS:
	std::cout << "Scissors";
	break;
}
}
};
int main() 
{
	// Seed the random number generator
	srand(static_cast<unsigned>(time(nullptr)));
	// Create instances of HumanPlayer and ComputerPlayer
	HumanPlayer human;
	ComputerPlayer computer;
	// Create an instance of the game and play it
	RPSGame game(&human, &computer);
	game.playGame();
	return 0;
}