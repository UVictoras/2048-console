#include "Grid.h"
#include <iostream>

Grid::Grid()
{
	this->bIsFull = false;
}

int Grid::BiToMono(int x, int y)
{   // Method used to convert monodimensional coordinate to bidimensional coordinate
    int result = x * 4 + y;
    return result;
}

/*
int* Grid::MonoToBi(int i)
{   // Method used to convert bidimensional coordinate to monodimensional coordinate
    int* array;
    array[0] = i / 4;
    array[1] = i % 4;
    return array;
}*/

int Grid::Rnd(int n)
{
    int iNumber = rand() % n;
    return iNumber;
}

void Grid::InitiateGrid()
{   // Method from the grid class to iniate the grid's elements as Cases
    cGrid = new Case[16];
    for (int f = 0; f < 16; f++)
    {
        this->cGrid[f].iValue = 0;
    }
    this->RandNumber();
    this->RandNumber();
}

void Grid::PrintGrid()
{   // Method from the grid class which prints the grid in the console log
    int iCaseNb = 0;
    for (int i = 0; i < 9; i++)
    {
        if (i % 2 == 0)
        {
            std::cout << "---------------------";
        }
        else
        {
            for (int j = 0; j < 9; j++)
            {
                if (j % 2 == 0)
                    std::cout << "|";
                else
                {
                    if (this->cGrid[iCaseNb].iValue < 10 && this->cGrid[iCaseNb].iValue > 0)
                    {
                        std::cout << "  " << this->cGrid[iCaseNb].iValue << " ";
                    }
                    else if (this->cGrid[iCaseNb].iValue < 100 && this->cGrid[iCaseNb].iValue > 10)
                    {
                        std::cout << " " << this->cGrid[iCaseNb].iValue << " ";
                    }
                    else if (this->cGrid[iCaseNb].iValue > 100 && this->cGrid[iCaseNb].iValue < 1000)
                    {
                        std::cout << " " << this->cGrid[iCaseNb].iValue;
                    }
                    else if (this->cGrid[iCaseNb].iValue > 1000)
                    {
                        std::cout << this->cGrid[iCaseNb].iValue;
                    }
                    else if (this->cGrid[iCaseNb].iValue == 0)
                    {
                        std::cout << "    ";
                    }

                    iCaseNb++;
                }
            }
        }
        std::cout << "\n";
    }
}

int Grid::Move(string sDirection, int iIndex)
{ // Method from the grid class used to move the sent tiles to the furthest case to the said direction using recursion
    if (sDirection == "Left")
    {
        if (this->cGrid[iIndex - 1].iValue == 0 && iIndex % 4 != 0)
        {
            return this->Move("Left", iIndex - 1);
        }
        else
        {
            return iIndex;
        }
    }
    else if (sDirection == "Right")
    {
        if (this->cGrid[iIndex + 1].iValue == 0 && (iIndex - 3) % 4 != 0)
        {
            return this->Move("Right", iIndex + 1);
        }
        else
        {
            return iIndex;
        }
    }
    else if (sDirection == "Up")
    {
        if (this->cGrid[iIndex - 4].iValue == 0 && iIndex >= 4)
        {
            return this->Move("Up", iIndex - 4);
        }
        else
        {
            return iIndex;
        }
    }
    else if (sDirection == "Down")
    {
        if (this->cGrid[iIndex + 4].iValue == 0 && iIndex < 12)
        {
            return this->Move("Down", iIndex + 4);
        }
        else
        {
            return iIndex;
        }
    }
}

vector<int> Grid::ListEmptyCases()
{
    //Renvoie la liste des indices dont les valeurs sont 0
    vector<int> vAray;

    for (int i = 0; i < 16; i++)
    {
        if (this->cGrid[i].iValue == 0)
            vAray.push_back(i);
    }

    return vAray;
}

void Grid::RandNumber()
{ // Modifie la valeur de la case choisis aléatoirement parmis celles vides
    vector<int> iTab = this->ListEmptyCases();
    int iSize = iTab.size();
    int iRandomNumber = iTab[this->Rnd(iSize)];

    this->cGrid[iRandomNumber].iValue = 2;
}

Case& Grid::operator[](int index)
{
    return cGrid[index];
}

bool Grid::isFull()
{   // Method from the grid class to check if the grid is full a values, returns true or false
    for (int i = 0; i < 16; i++) {
        if (this->cGrid[i].iValue == 0) {
            return false;
        }
    }
    return true;
}

bool Grid::noPossibility()
{   // Method from the grid class to check if there is still a movement possibility in the actual grid, returns true or false
    for (int l = 0; l < 16; l++)
    {
        if (l > 3 && this->cGrid[l].iValue == this->cGrid[l - 4].iValue)
        {
            return false;
        }
        else if (l < 12 && this->cGrid[l].iValue == this->cGrid[l + 4].iValue)
        {
            return false;
        }
        else if (l % 4 != 0 && this->cGrid[l].iValue == this->cGrid[l - 1].iValue)
        {
            return false;
        }
        else if ((l - 3) % 4 != 0 && this->cGrid[l].iValue == this->cGrid[l + 1].iValue)
        {
            return false;
        }
    }
    return true;
}

bool Grid::Win()
{
    for (int p = 0; p < 16; p++)
    {
        if (this->cGrid[p].iValue == 2048)
        {
            return true;
        }
    }
    return false;
}