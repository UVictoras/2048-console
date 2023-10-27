#include "Game.h"
#include <iostream>
#include <conio.h>

Game::Game()
{
    this->iPoints = 0;
    this->gGameGrid.InitiateGrid();
}

void Game::GameLoop()
{
    int iNewIndex, iTemp, iAsciiValue, iScore = 0;
    char sKey; // Initiating our char variable which will be use to get the pressed key
    bool bIsGame = true, isWin = false;
    while (bIsGame)
    {
        for (int h = 0; h < 16; h++)
        {
            this->gGameGrid.cGrid[h].isMerged = false;
        }
        std::cout << "Score :" << iScore << "\n";
        this->gGameGrid.PrintGrid();
        if (this->gGameGrid.isFull() == true && this->gGameGrid.noPossibility() == true)  // Checking if the grid is full of tiles and if there is no movement possible, if so we end the game.
        {
            break;
        }
        if (this->gGameGrid.Win() == true)
        {
            isWin = true;
            break;
        }
        sKey = _getch(); // Function to get the pressed key
        iAsciiValue = sKey; // Getting the ASCII Value of the key
        if (iAsciiValue == 75) // 75 is the ASCII Value of the left arrow key
        {
            for (int i = 0; i < 16; i++) // We go through our array from the top left corner to the bottom right corner
            {
                if (i % 4 != 0 && this->gGameGrid.cGrid[i].iValue != 0) // i%4 = 0 means we're on the left column so we can't move to the left & it's useless to move left if the value is 0
                {
                    iNewIndex = this->gGameGrid.Move("Left", i);
                    iTemp = this->gGameGrid.cGrid[i].iValue;
                    this->gGameGrid.cGrid[i].iValue = 0;
                    this->gGameGrid.cGrid[iNewIndex].iValue = iTemp;
                    if (iNewIndex % 4 != 0 && this->gGameGrid.cGrid[iNewIndex - 1].iValue == this->gGameGrid.cGrid[iNewIndex].iValue && this->gGameGrid.cGrid[iNewIndex - 1].isMerged == false) // We check if the case on the left of the selected one has the same value
                    { // If that's the case, we merge them and increment the score
                        this->gGameGrid.cGrid[iNewIndex - 1].iValue *= 2;
                        iScore += this->gGameGrid.cGrid[iNewIndex].iValue;
                        this->gGameGrid.cGrid[iNewIndex].iValue = 0;
                        this->gGameGrid.cGrid[iNewIndex - 1].isMerged = true;
                    }
                }
            }
            this->gGameGrid.RandNumber();
        }

        else if (iAsciiValue == 77) // 77 is the ASCII Value of the right arrow key
        {
            for (int i = 15; i > -1; i--) // We go through our array from the bottom right corner to the top left corner
            {
                if ((i - 3) % 4 != 0 && this->gGameGrid.cGrid[i].iValue != 0) // We substract 3 to our value to have a usable intenger for the % so we can check if we're on the right column
                { // If we're not on the right column and the value is not 0 then we can move the case
                    iNewIndex = this->gGameGrid.Move("Right", i);
                    iTemp = this->gGameGrid.cGrid[i].iValue;
                    this->gGameGrid.cGrid[i].iValue = 0;
                    this->gGameGrid.cGrid[iNewIndex].iValue = iTemp;

                    if ((iNewIndex - 3) % 4 != 0 && this->gGameGrid.cGrid[iNewIndex + 1].iValue == this->gGameGrid.cGrid[iNewIndex].iValue && this->gGameGrid.cGrid[iNewIndex + 1].isMerged == false) // We check if the case on the right of the selected one has the same value
                    { // If so, we merge them and increment the score
                        this->gGameGrid.cGrid[iNewIndex + 1].iValue *= 2;
                        iScore += this->gGameGrid.cGrid[iNewIndex].iValue;
                        this->gGameGrid.cGrid[iNewIndex].iValue = 0;
                        this->gGameGrid.cGrid[iNewIndex + 1].isMerged = true;
                    }
                }
            }
            this->gGameGrid.RandNumber();
        }

        else if (iAsciiValue == 80) // 80 is the ASCII Value of the down arrow key
        {
            for (int i = 15; i > -1; i--) // We go through our array the same way we do for moving right, bottom right to top left
            {
                if (i < 12 && this->gGameGrid.cGrid[i].iValue != 0) // If i < 12, this means the value is not the index of a case from the last line, if that's the case and the value is not 0, we can move down the case
                {
                    iNewIndex = this->gGameGrid.Move("Down", i);
                    iTemp = this->gGameGrid.cGrid[i].iValue;
                    this->gGameGrid.cGrid[i].iValue = 0;
                    this->gGameGrid.cGrid[iNewIndex].iValue = iTemp;

                    if (iNewIndex < 12 && this->gGameGrid.cGrid[iNewIndex + 4].iValue == this->gGameGrid.cGrid[iNewIndex].iValue && this->gGameGrid.cGrid[iNewIndex + 4].isMerged == false) // We check if the case downward the selected one has the same value
                    { // If indeed they're equal, we merge them and increment the score
                        this->gGameGrid.cGrid[iNewIndex + 4].iValue *= 2;
                        iScore += this->gGameGrid.cGrid[iNewIndex].iValue;
                        this->gGameGrid.cGrid[iNewIndex].iValue = 0;
                        this->gGameGrid.cGrid[iNewIndex + 4].isMerged = true;
                    }
                }
            }
            this->gGameGrid.RandNumber();
        }


        else if (iAsciiValue == 72) // 72 is the ASCII Value of the up arrow key
        {
            for (int i = 0; i < 16; i++) // We go through our array the same way we did to go left, from top left to bottom right
            {
                if (i >= 4 && this->gGameGrid.cGrid[i].iValue != 0) // We check if we're not on the 1st line by seeing if the index is at least 4, and if the actual case is also not 0, we can move up
                {
                    iNewIndex = this->gGameGrid.Move("Up", i);
                    iTemp = this->gGameGrid.cGrid[i].iValue;
                    this->gGameGrid.cGrid[i].iValue = 0;
                    this->gGameGrid.cGrid[iNewIndex].iValue = iTemp;

                    if (iNewIndex >= 4 && this->gGameGrid.cGrid[iNewIndex - 4].iValue == this->gGameGrid.cGrid[iNewIndex].iValue && this->gGameGrid.cGrid[iNewIndex - 4].isMerged == false) // We look if the upward case has the same value
                    { // If therefore, the case on top of ours whom value equals the selected one, we mix them and increment the score
                        this->gGameGrid.cGrid[iNewIndex - 4].iValue *= 2;
                        iScore += this->gGameGrid.cGrid[iNewIndex].iValue;
                        this->gGameGrid.cGrid[iNewIndex].iValue = 0;
                        this->gGameGrid.cGrid[iNewIndex - 4].isMerged = true;
                    }
                }
            }
            this->gGameGrid.RandNumber();
        }

        if (iAsciiValue == 27) // 27 is the ASCII Value of the Escape key, if we press it we end the game
            bIsGame = false;
        system("cls"); // Clearing the console logs 
    }
    if (isWin == false)
    {
        cout << "You loose";
    }
    else
    {
        std::cout << "You won !";
    }
    //this->gGameGrid.DeleteGrid();
}