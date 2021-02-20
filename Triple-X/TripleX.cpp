#include <iostream>
#include <ctime>
using namespace std;

const int NUM_LEVELS = 10;

/**
 * @brief Gets a random number based on the level
 * 
 * @param level The level of the current level
 * @return A random int within a range specified by the level
 */
int getRandomNumber(int level) {
	return (rand() % level) + 1;
}

/**
 * @brief Prints the hints for the numbers and prompts the user for input
 * 
 * @param level The current level we are on
 * @param sum The sum of the numbers
 * @param product The product of the numbers
 */
void printHintAndPrompt(int level, int sum, int product) {
	cout << endl << "Level: " << level << " of " << NUM_LEVELS << endl;
	cout << "The sum of the three numbers is: " << sum << endl;
	cout << "The product of the three numbers is: " << product << endl;
	cout << "Enter the correct numbers to continue..." << endl;
}

/**
 * @brief Plays a level at a certain level
 * 
 * @param level Specifies the level to play at 
 * @return true if the level was beaten
 * @return false if the level was failed
 */
bool playLevel(int level) 
{
	if (level < 1) {
		return true;
	}

	// Come up with three random numbers
	const int number1 = getRandomNumber(level);
	const int number2 = getRandomNumber(level);
	const int number3 = getRandomNumber(level);
	
	const int sum = number1 + number2 + number3;
	const int product = number1 * number2 * number3;
	
	bool guessedCorrectly = false;
	bool shouldContinue = true;
	int firstPlayerGuess, secondPlayerGuess, thirdPlayerGuess;
	
	while (guessedCorrectly == false && shouldContinue == true) {
		printHintAndPrompt(level, sum, product);
		
		cin >> firstPlayerGuess;
		cin >> secondPlayerGuess;
		cin >> thirdPlayerGuess;
		
		cout << "You entered: " << firstPlayerGuess << " " << secondPlayerGuess << " " << thirdPlayerGuess << endl;
		
		const int playerSum = firstPlayerGuess + secondPlayerGuess + thirdPlayerGuess;
		const int playerProduct = firstPlayerGuess * secondPlayerGuess * thirdPlayerGuess;
		
		guessedCorrectly = (playerSum == sum) && (playerProduct == product);
		shouldContinue = playerProduct != 0;
		
		if (shouldContinue && !guessedCorrectly) {
			cout << "You did not guess correctly :(" << endl;
		}
	}
	
	return shouldContinue;
}

/**
 * @brief Executes the main game loop
 * 
 */
void playGame() 
{
	int currentLevel = 1;

	while (currentLevel <= NUM_LEVELS) {
		bool shouldContinue = playLevel(currentLevel);
		cin.clear();
		cin.ignore();
		if (shouldContinue) {
			currentLevel += 1;
		}
		else {
			break;
		}
	}
}

/**
 * @brief Prints the intro to our game
 * 
 */
void printIntro() 
{
	std::cout << "You are a spy breaking into a top secret facility...\n";
	std::cout << "The facility has " << NUM_LEVELS << " doors that must be opened.\n";
	std::cout << "You must crack the code on each door in order for it to open.\n";
}

/**
 * @brief Prints an outro to our game
 * 
 */
void printOutro() 
{
	std::cout << "Thanks for playing!\n";
}

/**
 * @brief Main running code for the program.
 * 
 * @return int Error code. 0 means no errors
 */
int main()
{
	srand(time(NULL));
	
	printIntro();
	
	playGame();

	printOutro();

	return 0;
}