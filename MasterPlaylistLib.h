//
// Created by Bobo on 12/5/2018.
//

#ifndef INC_220_DJ_PROJECT_MASTERPLAYLISTLIB_H
#define INC_220_DJ_PROJECT_MASTERPLAYLISTLIB_H

#include <string>
#include "MasterPlayList.h"
#include "LinkedPlayList.h"
std::string toString(const MasterPlayList* arrayPtr, int size);
int find(const MasterPlayList* arrayPtr, int size, LinkedPlayList *PlaylistPtrToFind, int& numLinesRun);
#endif //INC_220_DJ_PROJECT_MASTERPLAYLISTLIB_H
