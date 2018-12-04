//
// Created by Isha Sharma on 12/3/18.
//

//
// Created by Toby Dragon on 9/10/18.
//

#ifndef COMP220LAB_ARRAYLIB_H
#define COMP220LAB_ARRAYLIB_H

#include <string>
int binarySearch(std::string names[], int size, std::string value) {
    int first = 0,
             last = size - 1,
             middle,
             position = -1;
    bool found = false;

    while (!found && first <= last) {
        middle = (first + last) / 2;
        if (names[middle].compare(value)) {
            found = true;
            position = middle;
        }
        else if (names[middle].compare(value))
            last = middle - 1;
        else
            first = middle + 1;
    }
    return position;
}


void bubbleSort(std::string songArr[], int size) {
    int minIndex;
    std::string minValue;

    for (int i = 0; i < (size - 1); i++) {
        minIndex = i;
        minValue = songArr[i];
        for (int index = i + 1; index < size; index++) {
            if (songArr[index].compare(minValue)) {
                minValue = songArr[index];
                minIndex = index;
            }
        }
        songArr[minIndex] = songArr[i];
        songArr[i] = minValue;
    }
}


#endif //COMP220LAB_ARRAYLIB_H
