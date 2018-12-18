//
// Created by Bobo on 12/16/2018.
//
#include <iostream>
#include "MasterPlaylistLib.h"
std::string toString(const int* arrayPtr, int size){
    std::string strArray="{";
    for(int i=0; i< size;i++) {
        if(i!=(size-1)) {
            strArray += std::to_string(arrayPtr[i]) + ", ";
        }
        else if (i==(size-1)){
            strArray+=std::to_string(arrayPtr[i]);
        }
    }
    strArray=strArray + "}";
    std::cout<<strArray<<std::endl;
    return strArray;
}
int find(const int* arrayPtr, int size, int numToFind, int& numLinesRun) {
    (numLinesRun) += 4;
    if (size < 1) {
        (numLinesRun) += 1;
        return -1;
    } else {
        for (int i = 0; i < size; i++) {
            (numLinesRun) += 3;
            if (arrayPtr[i] == numToFind) {
                (numLinesRun) += 2;
                return i;
            }
        }
    }
}