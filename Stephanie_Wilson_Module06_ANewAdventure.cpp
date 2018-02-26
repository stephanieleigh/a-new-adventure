// Stephanie Wilson IN200
// Module 06 
// Chapter 5 Assignment
// A New Adventure

#include <iostream>
#include <string>
#include <chrono>  // used for sleep
#include <thread>  // used for sleep

using namespace std;

// global variables
string playerName;
int health = 30;
int totalTreasure = 0;
int totalBlocks = 0;
char answer;

// function prototypes
void story();
void adventure();
char askYesNo(string question);
int rollDie(int min, int max);
int bonusHealth(int blocks);
void ending();


int main() 
{
  // welcome player and prompt for name
  cout << "Welcome to A New Adventure!!\n\n";
  cout << "Please enter your first name: ";
  cin >> playerName;
  this_thread::sleep_for(chrono::milliseconds(500));  // pause for 500 milliseconds
  cout << "\n\nHello, " << playerName <<  "!" << endl;
  
  // call the function that tells the story
  story();

  return 0;
}

// function that tells the story
void story()
{
  cout << "\nIt's a beautiful new day." << endl;
  cout << "\nYou have " << health << " health points. Block the enemy attack and win treasure!" << endl;
  this_thread::sleep_for(chrono::milliseconds(1000));   // pause for 1 second
  
  // store the value returned from askYesNo function in answer variable
  answer = askYesNo("\n\nWould you like to go adventuring?");
  
  if (answer == 'y')
  {
    // call the function that keeps track of the adventure
    adventure();
  }
  else
  {
    cout << "Thank you for playing.";
  }
}

// function to get a yes or no response from player
char askYesNo(string question)
{
  cout << question << " (y/n): ";
  cin >> answer;
  
  return answer;
}

// function to keep track of score
void adventure()
{
    do
  {
    --health;    // subtract 1 point from health for each player turn
    srand(time(0)); // seed random generator with current time
    int attack = rollDie(1, 6);  // select random number between 1 and 6
    int block = rollDie(1, 6);   // select random number between 1 and 6
    int treasure = rollDie(5, 20);   // select random number between 5 and 20
    
    this_thread::sleep_for(chrono::milliseconds(1000)); // pause 1 second between turns
    
    if (block >= attack)
    {
      totalTreasure += treasure;  // add new treasure to total treasure
      cout << "\nSuccessful block! Way to go! You receive " << treasure << " treasure points." << endl;
      totalBlocks += block;  // add amount of block to total blocks
      if (totalBlocks >= 20)
      {
        bonusHealth(totalBlocks);  // call the function to add bonus health points
      }
    }
    else
    {
      health -= attack; // subtract attack from health and store result in health
      cout << "\nSorry, you missed. Better luck next time!" << endl;
    }
    
    cout << "Your health is now " << health << ", and you have " << totalTreasure << " treasure points.\n\n";
    
    if (health > 0) 
    {
      answer = askYesNo("\nWould you like to go adventuring again?");
    }   
      
  } while ((health > 0) && (answer == 'y'));
  
  // call the function that displays the ending
  ending();
}

// function to randomly generate a number for block, attacks, and treasure
int rollDie(int min, int max)
{
  int num;
  num = (rand() % max) + min; // generate a random number 
  
  return num;
}

// function to add bonus health points
int bonusHealth(int blocks)
{
  int bonusHealth = 5;
  health += bonusHealth;  // add bonus health points to total health
  cout << "\nCongratulations! You just earned 5 bonus points added to your health!\n";
  
  return health;
}

// function to thank player and give final results 
void ending()
{
  if (health > 0)
  {
    cout << "\n\nYou return home with your health at " << health << " and " << totalTreasure << " treasure!\n";
  }
  else
  {
    cout << "\n\nSorry, you're DEAD, but you earned " << totalTreasure << " treasure for your loved ones!\n";
  }
  
  cout << "\nThank you for playing, " << playerName << ".  Goodbye.";
}