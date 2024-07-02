#include "World.h"

World::World(const int rows, const int columns) : mRows(rows), mColumns(columns), mArr(new int* [rows]) {
    for (int i = 0; i < rows; i++)
        mArr[i] = new int[columns];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++)
            mArr[i][j] = 0;
    }
}

World::~World() {
    for (int i = 0; i < mRows; i++) {
        delete[] mArr[i];
    }
    delete[] mArr;
}


void World::setValueAtIndex(const int i, const int j, const int value) {
    mArr[i][j] = value;
}

int World::getValueAtIndex(const int i, const int j) {
    return mArr[i][j];
}

void World::clearLines(int& score, int& line, const int rows, const int columns) {
    int bottomLine = rows - 1;

    for (int i = rows - 1; i >= 0; i--) {
        int count = 0;
        for (int j = 0; j < columns; j++) {
            if (mArr[i][j])
                count++;
        }
        if (count < columns) {
            for (int j = 0; j < columns; j++)
                mArr[bottomLine][j] = mArr[i][j];
            bottomLine--;
        }
        else {
            score += 100;
            line++;
        }
    }
}


bool World::endGameCheck(const int columns) {
    for (int i = 0; i < columns; i++) {
        if (mArr[0][i])
            return true;
    }
    return false;
}

