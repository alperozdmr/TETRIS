#pragma once
#include<vector>
using namespace std;

class World {
private:
    int** mArr;
    //vector<vector<int>> mArr;
    int mRows;
    int mColumns;
public:
    World(const int rows, const int columns);
    ~World();
    void setValueAtIndex(const int i, const int j, const int value);
    int getValueAtIndex(const int i, const  int j);
    void clearLines(int& score, int& line, const int rows, const int columns);
    bool endGameCheck(const int columns);
};
