#include "Test.h"
#include <windows.h>
#include <iostream>

Test::Test()
{
	this->gTestGrid.InitiateGrid();
	this->gEndGrid.InitiateGrid();
}

bool Test::CheckGrid(Grid grid1, Grid grid2)
{
	for (int q = 0; q < 16; q++)
	{
		if (grid1[q].iValue != grid2[q].iValue)
		{
			return false;
		}
	}
	return true;
}

void Test::IntegrationTest1()
{
	bool bVerified;
	int iNewIndex, iTemp;
	for (int k = 0; k < 16; k++)
	{
		this->gTestGrid[k].iValue = 2;
		this->gTestGrid[k].isMerged = false;
	}
	for (int g = 0; g < 9; g++)
	{
		this->gEndGrid[g].iValue = 0;
	}
	for (int d = 8; d < 16; d++)
	{
		this->gEndGrid[d].iValue = 4;
	}
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
	bVerified = this->CheckGrid(this->gTestGrid, this->gEndGrid);
	if (bVerified == true)
		std::cout << "Test 1 is a success \n";
	else
		std::cout << "Test 1 is a failure`\n";
}

void Test::IntegrationTest2()
{
	int config[4][4] =
	{
		{4, 2, 0, 2},
		{0, 4, 0, 8},
		{0, 0, 0, 0},
		{0, 8, 0, 8}
	};
	int config2[4][4] =
	{
		{4, 4, 0, 0},
		{4, 8, 0, 0},
		{0, 0, 0, 0},
		{16, 0, 0, 0}
	};

	bool bVerified;
	int iNewIndex, iTemp;
	for (int n = 0; n < 4; n++)
	{
		for (int m = 0; m < 4; m++)
		{
			this->gTestGrid[this->gTestGrid.BiToMono(n, m)].iValue = config[n][m];
			this->gEndGrid[this->gEndGrid.BiToMono(n, m)].iValue = config2[n][m];
			this->gTestGrid[this->gTestGrid.BiToMono(n, m)].isMerged = false;
		}
	}

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
	bVerified = this->CheckGrid(this->gTestGrid, this->gEndGrid);
	if (bVerified == true)
		std::cout << "Test 2 is a success \n";
	else
		std::cout << "Test 2 is a failure \n";
}

void Test::IntegrationTest3()
{
	int config[4][4] =
	{
		{2, 4, 2, 2},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0}
	};
	int config2[4][4] =
	{
		{0, 2, 4, 4},
		{0, 0, 0, 0},
		{0, 0, 0, 0},
		{0, 0, 0, 0}
	};

	bool bVerified;
	int iNewIndex, iTemp;
	for (int n = 0; n < 4; n++)
	{
		for (int m = 0; m < 4; m++)
		{
			this->gTestGrid[this->gTestGrid.BiToMono(n, m)].iValue = config[n][m];
			this->gEndGrid[this->gEndGrid.BiToMono(n, m)].iValue = config2[n][m];
			this->gTestGrid[this->gTestGrid.BiToMono(n, m)].isMerged = false;
		}
	}

	for (int i = 15; i > -1; i--)
	{
		iNewIndex = this->gTestGrid.Move("Right", i);
		iTemp = this->gTestGrid.cGrid[i].iValue;
		this->gTestGrid.cGrid[i].iValue = 0;
		this->gTestGrid.cGrid[iNewIndex].iValue = iTemp;
		if ((iNewIndex-3)%4 != 0 && this->gTestGrid.cGrid[iNewIndex + 1].iValue == this->gTestGrid.cGrid[iNewIndex].iValue && this->gTestGrid.cGrid[iNewIndex + 1].isMerged == false) // We check if the case downward the selected one has the same value
		{ // If indeed they're equal, we merge them and increment the score
			this->gTestGrid.cGrid[iNewIndex + 1].iValue *= 2;
			this->gTestGrid.cGrid[iNewIndex].iValue = 0;
			this->gTestGrid.cGrid[iNewIndex + 1].isMerged = true;
		}
	}
	bVerified = this->CheckGrid(this->gTestGrid, this->gEndGrid);
	if (bVerified == true)
		std::cout << "Test 3 is a success \n";
	else
		std::cout << "Test 3 is a failure \n";
}

void Test::IntegrationTest4()
{
	int config[4][4] =
	{
		{2, 2, 8, 16},
		{4, 8, 16, 4},
		{8, 16, 4, 8},
		{16, 32, 64, 128}
	};

	bool bVerified;
	int iNewIndex, iTemp;
	for (int n = 0; n < 4; n++)
	{
		for (int m = 0; m < 4; m++)
		{
			this->gTestGrid[this->gTestGrid.BiToMono(n, m)].iValue = config[n][m];
			this->gTestGrid[this->gTestGrid.BiToMono(n, m)].isMerged = false;
		}
	}
	
	for (int i = 15; i > -1; i--)
	{
		iNewIndex = this->gTestGrid.Move("Right", i);
		iTemp = this->gTestGrid.cGrid[i].iValue;
		this->gTestGrid.cGrid[i].iValue = 0;
		this->gTestGrid.cGrid[iNewIndex].iValue = iTemp;
		if ((iNewIndex - 3) % 4 != 0 && this->gTestGrid.cGrid[iNewIndex + 1].iValue == this->gTestGrid.cGrid[iNewIndex].iValue && this->gTestGrid.cGrid[iNewIndex + 1].isMerged == false) // We check if the case downward the selected one has the same value
		{ // If indeed they're equal, we merge them and increment the score
			this->gTestGrid.cGrid[iNewIndex + 1].iValue *= 2;
			this->gTestGrid.cGrid[iNewIndex].iValue = 0;
			this->gTestGrid.cGrid[iNewIndex + 1].isMerged = true;
		}
	}
	this->gTestGrid[0].iValue = 2;
	if (this->gTestGrid.isFull() == true && this->gTestGrid.noPossibility() == true)
		std::cout << "Test 4 is a success \n";
	else
		std::cout << "Test 4 is a failure \n";
}

void Test::IntegrationTest5()
{
	int config[4][4] =
	{
		{512, 64, 64, 1024},
		{0, 8, 32, 0},
		{128, 8, 16, 1024},
		{0, 2, 4, 8}
	};

	bool bVerified;
	int iNewIndex, iTemp;
	for (int n = 0; n < 4; n++)
	{
		for (int m = 0; m < 4; m++)
		{
			this->gTestGrid[this->gTestGrid.BiToMono(n, m)].iValue = config[n][m];
			this->gTestGrid[this->gTestGrid.BiToMono(n, m)].isMerged = false;
		}
	}

	for (int i = 0; i < 16; i++) // We go through our array the same way we did to go left, from top left to bottom right
	{
		if (i >= 4 && this->gTestGrid.cGrid[i].iValue != 0) // We check if we're not on the 1st line by seeing if the index is at least 4, and if the actual case is also not 0, we can move up
		{
			iNewIndex = this->gTestGrid.Move("Up", i);
			iTemp = this->gTestGrid.cGrid[i].iValue;
			this->gTestGrid.cGrid[i].iValue = 0;
			this->gTestGrid.cGrid[iNewIndex].iValue = iTemp;

			if (iNewIndex >= 4 && this->gTestGrid.cGrid[iNewIndex - 4].iValue == this->gTestGrid.cGrid[iNewIndex].iValue && this->gTestGrid.cGrid[iNewIndex - 4].isMerged == false) // We look if the upward case has the same value
			{ // If therefore, the case on top of ours whom value equals the selected one, we mix them and increment the score
				this->gTestGrid.cGrid[iNewIndex - 4].iValue *= 2;
				this->gTestGrid.cGrid[iNewIndex].iValue = 0;
				this->gTestGrid.cGrid[iNewIndex - 4].isMerged = true;
			}
		}
	}

	if (this->gTestGrid.Win())
		std::cout << "Test 5 is a success \n";
	else
		std::cout << "Test 5 is a failure \n";
}