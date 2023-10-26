#include "Case.h"
#include <vector>
#include <string>

using namespace std;

class Grid
{
public:
    bool bIsFull;
    Case* cGrid;

    Grid();

    int BiToMono(int x, int y);

    //int* MonoToBi(int i);

    int Rnd(int n);

    void InitiateGrid();

    void PrintGrid();

    int Move(string sDirection, int iIndex);

    vector<int> ListEmptyCases();

    void RandNumber();

    Case& operator[](int index);

    bool isFull();

    bool noPossibility();

    bool Win();
};