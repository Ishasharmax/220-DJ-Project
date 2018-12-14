//
// Created by Bobo on 12/5/2018.
//
#include "MasterPlayListLib.h"
#include "MasterPlayList.h"
#include "LinkedPlayList.h"
#include <string>
std::string toString(const MasterPlayList* arrayPtr, int size){
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
int find(const MasterPlayList* arrayPtr, int size, LinkedPlayList *PlaylistPtrToFind, int& numLinesRun) {
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
