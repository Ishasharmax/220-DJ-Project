//
// Created by Isha Sharma on 12/3/18.
//

#include <string>
int binFind(const int* const arrayPtr, const int size, const int numToFind, int& numLinesRun, int low, int high);
int binFind(const int* const arrayPtr, const int size, const int numToFind, int& numLinesRun, int low, int high) {
    int mid;
    numLinesRun+=7;
    if (high>=low){
        numLinesRun+=2;
        mid=low+(high-low)/2;
        if (arrayPtr[mid]==numToFind){
            numLinesRun+=1;
            return mid;
        }else if (arrayPtr[mid]>numToFind){
            numLinesRun+=1;
            return binFind(arrayPtr,size,numToFind, numLinesRun,low,mid-1);                       //It is a tail recursion
        }else{
            numLinesRun+=1;
            return binFind(arrayPtr,size,numToFind, numLinesRun, mid+1,high);                          //It is a tail recursion
        }
    }else{
        numLinesRun+=1;
        return -1;
    }
}

int binFind(const int* const arrayPtr, const int size, const int numToFind,int& numLinesRun){
    numLinesRun+=4;
    return binFind(arrayPtr, size, numToFind, numLinesRun, 0, size);
}


void bubbleSort(std::string arr[], int n) {
    bool swapped = true;
    int j = 0;
    std::string tmp;

    while (swapped){
        swapped = false;
        j++;
        for (int i = 0; i < n - j; i++)
        {
            if ( arr[i].compare(arr[i + 1]) )
            {

                tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
                swapped = true;
            }
        }
    }
}
