#include "Test.h"
#include <windows.h>

Test::Test()
{
	this->gTestGrid.InitiateGrid();
}

void Test::IntegrationTest1()
{

	int iNewIndex, iTemp;
	for (int k = 0; k < 16; k++)
	{
		this->gTestGrid[k].iValue = 2;
		this->gTestGrid[k].isMerged = false;
	}
	this->gTestGrid.PrintGrid();
	for (int i = 15; i > -1; i--)
	{
		iNewIndex = this->gTestGrid.Move("Down", i);
		iTemp = this->gTestGrid.cGrid[i].iValue;
		this->gTestGrid.cGrid[i].iValue = 0;
		this->gTestGrid.cGrid[iNewIndex].iValue = iTemp;
		if (iNewIndex < 12 && this->gTestGrid.cGrid[iNewIndex + 4].iValue == this->gTestGrid.cGrid[iNewIndex].iValue && this->gTestGrid.cGrid[iNewIndex + 4].isMerged == false) // We check if the case downward the selected one has the same value
		{ // If indeed they're equal, we merge them and increment the score
			this->gTestGrid.cGrid[iNewIndex + 4].iValue *= 2;
			this->gTestGrid.cGrid[iNewIndex].iValue = 0;
			this->gTestGrid.cGrid[iNewIndex + 4].isMerged = true;
		}
	}
	Sleep(2000);
	system("cls");
	this->gTestGrid.PrintGrid();
	for (int l = 0; l < 16; l++)
	{
		this->gTestGrid[l].isMerged = false;
	}
	for (int j = 15; j > -1; j--)
	{
		iNewIndex = this->gTestGrid.Move("Down", j);
		iTemp = this->gTestGrid.cGrid[j].iValue;
		this->gTestGrid.cGrid[j].iValue = 0;
		this->gTestGrid.cGrid[iNewIndex].iValue = iTemp;
		if (iNewIndex < 12 && this->gTestGrid.cGrid[iNewIndex + 4].iValue == this->gTestGrid.cGrid[iNewIndex].iValue && this->gTestGrid.cGrid[iNewIndex + 4].isMerged == false) // We check if the case downward the selected one has the same value
		{ // If indeed they're equal, we merge them and increment the score
			this->gTestGrid.cGrid[iNewIndex + 4].iValue *= 2;
			this->gTestGrid.cGrid[iNewIndex].iValue = 0;
			this->gTestGrid.cGrid[iNewIndex + 4].isMerged = true;
		}
	}
	Sleep(2000);
	system("cls");
	this->gTestGrid.PrintGrid();
}

void Test::IntegrationTest2()
{
	int iNewIndex, iTemp;
	this->gTestGrid[0].iValue = 4;
	this->gTestGrid[1].iValue = 2;
	this->gTestGrid[3].iValue = 2;
	this->gTestGrid[5].iValue = 4;
	this->gTestGrid[7].iValue = 8;
	this->gTestGrid[13].iValue = 8;
	this->gTestGrid[15].iValue = 8;

	this->gTestGrid.PrintGrid();
	for (int l = 0; l < 16; l++)
	{
		this->gTestGrid[l].isMerged = false;
	}
	for (int i = 0; i < 16; i++)
	{
		iNewIndex = this->gTestGrid.Move("Left", i);
		iTemp = this->gTestGrid.cGrid[i].iValue;
		this->gTestGrid.cGrid[i].iValue = 0;
		this->gTestGrid.cGrid[iNewIndex].iValue = iTemp;
		if (iNewIndex % 4 != 0 && this->gTestGrid.cGrid[iNewIndex - 1].iValue == this->gTestGrid.cGrid[iNewIndex].iValue && this->gTestGrid.cGrid[iNewIndex - 1].isMerged == false) // We check if the case downward the selected one has the same value
		{ // If indeed they're equal, we merge them and increment the score
			this->gTestGrid.cGrid[iNewIndex - 1].iValue *= 2;
			this->gTestGrid.cGrid[iNewIndex].iValue = 0;
			this->gTestGrid.cGrid[iNewIndex - 1].isMerged = true;
		}
	}
	Sleep(2000);
	system("cls");
	this->gTestGrid.PrintGrid();
}