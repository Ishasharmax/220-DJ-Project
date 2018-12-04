//
// Created by Bobo on 12/3/2018.
//
#include <iostream>
#include "MasterPlaylist.h"
#include "MasterPlaylistLib.h"
#include <stdexcept>
#include <string>
int numLinesEmpty=0;

ArrayList::ArrayList(int initialCapacity) {
    if(initialCapacity<1){
        throw std::invalid_argument("Size is less than 1");
    }
    else{
        this->currCapacity=initialCapacity;
        array=new int[currCapacity];
        currItemCount=0;
    }

}
//Copy Constructor
ArrayList::ArrayList(const ArrayList& arrayListToCopy){
    this->currCapacity=arrayListToCopy.currCapacity;
    this->array= new int [arrayListToCopy.currCapacity];
    this->currItemCount=arrayListToCopy.currItemCount;
    for(int i=0;i<arrayListToCopy.currItemCount;i++){
        this->array[i]=arrayListToCopy.array[i];
    }
}

//Overloaded Assignment Operator
ArrayList&  ArrayList::operator=(const ArrayList& arrayListToCopy){
    if (this != &arrayListToCopy ) {
        delete array;
        this->array= nullptr;
        this->currCapacity=arrayListToCopy.currCapacity;
        this->array= new int [arrayListToCopy.currCapacity];
        this->currItemCount=arrayListToCopy.currItemCount;
        for(int i=0;i<arrayListToCopy.currItemCount;i++){
            this->array[i]=arrayListToCopy.array[i];
        }
    }
    return *this;
}

//Destructor
ArrayList::~ArrayList(){
    delete[] this ->array;
    this ->array= nullptr;

}

void  ArrayList::doubleCapacity(){
    if(currCapacity<1){
        throw std::invalid_argument("Size is less than 1");
    }
    else{
        currCapacity=currCapacity*2;
        int * temp=new int [currCapacity];
        for(int i=0; i<currItemCount;i++){
            temp[i]=array[i];
        }
        delete[]array;
        array=temp;
    }
}

void  ArrayList::insertAtEnd(int itemToAdd) {
    array[currItemCount++]=itemToAdd;
}

int  ArrayList::getValueAt(int index){
    if(index<0 || index>=currItemCount){
        throw std::out_of_range("Size is less than 1");
    }
    else{
        return array[index];
    }
}

std::string  ArrayList::toString(){
    return  ::toString(array,currCapacity);
}

bool  ArrayList::isEmpty(){
    if(currItemCount==0){
        return true;
    }
    else{
        return false;
    }
}

int  ArrayList::itemCount(){
    if(isEmpty()){
        return 0;
    }
    else{
        return currItemCount;
    }
}

void  ArrayList::clearList(){
    if(isEmpty()){
        throw std::invalid_argument("Size is already 0");
    }
    else{
        currItemCount=0;
    }
}

int ArrayList::find(int numToFind){
    return  ::find(array,currCapacity,numToFind,numLinesEmpty);
}

int ArrayList::findLast(int numToFind){
    return  ::findLast(array,currCapacity,numToFind,numLinesEmpty);
}

int  ArrayList::findMaxIndex(){
    return  ::findMaxIndex(array,currCapacity,numLinesEmpty);
}

void  ArrayList::insertAtFront(int itemToAdd){
    if(currItemCount>=currCapacity+1) {
        doubleCapacity();
    }
    currItemCount++;
    for(int i=currItemCount-1; i>0; i--){
        array[i]=array[i-1];
    }
    array[0]=itemToAdd;
}

void  ArrayList::insertAt(int itemToAdd, int index) {
    if(index<0 || currCapacity<index){
        throw std::out_of_range("Size is less than 1");
    }
    else{
        currItemCount++;
        if(currItemCount+1>=currCapacity){
            doubleCapacity();
        }
        for(int i=currItemCount;i>index;i--){
            array[i]=array[i-1];
        }
        array[index]=itemToAdd;
    }
}

int ArrayList::removeValueAtEnd() {
    if (currItemCount < 1) {
        throw std::out_of_range("List is empty");
    } else {
        currItemCount--;
        int remove=array[currItemCount];
        return remove;
    }
}

int ArrayList::removeValueAtFront() {
    if (currItemCount < 1) {
        throw std::out_of_range("Size is less than 1");
    } else {
        currItemCount--;
        int remove=array[0];
        for(int i=0; i<currItemCount;i++ ){
            array[i]=array[i+1];
        }
        return remove;
    }
}

int ArrayList::removeValueAt(int index) {
    if (currItemCount < 1) {
        throw std::invalid_argument("Size is less than 1");
    } else {
        currItemCount--;
        int remove=array[index];
        for(int i=index; i<currItemCount;i++ ){
            array[i]=array[i+1];
        }
        return remove;
    }
}
