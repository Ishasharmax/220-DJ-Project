//
// Created by Bobo on 12/3/2018.
//
#ifndef INC_220_DJ_PROJECT_MASTERPLAYLISTLIB_H
#define INC_220_DJ_PROJECT_MASTERPLAYLISTLIB_H

#include <string>

int* genRandArray(int size, int min, int max, int& numLinesRun);

std::string toString(const int* arrayPtr, int size);int find(const int* arrayPtr, int size, int numToFind, int& numLinesRun);

int findLast(const int* arrayPtr, int size, int numToFind, int& numLinesRun);

int findMaxIndex(const int* arrayPtr, int size, int& numLinesRun);

int* copyArray(const int* arrayToCopy, int size, int& numLinesRun);

int* genShuffledArray(int size, int& numLinesRun);

int countOccurrences(const int* arrayPtr, int size, int numToFind, int& numLinesRun);

void sort(int* arrayToSort, int size, int& numLinesRun);

int binFind(const int* const arrayPtr, const int size, const int numToFind, int& numLinesRun);

#endif //INC_220_DJ_PROJECT_MASTERPLAYLISTLIB_H
