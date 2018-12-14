//
// Created by Bobo on 12/3/2018.
//
#include <iostream>
#include "MasterPlayList.h"
#include "LinkedPlayList.h"

#include <stdexcept>
#include <string>

int numLinesEmpty=0;

template <class T>
MyLinkedListMapT<T>::MyLinkedListMapT(){
    keyFront= nullptr;
    valueFront= nullptr;
}

template <class T>
MyLinkedListMapT<T>::MyLinkedListMapT(const MyLinkedListMapT& mapToCopy){
    this->key= mapToCopy.key;
    this->value = mapToCopy.value;
    this->next = nullptr;
}

template <class T>
MyLinkedListMapT<T>::~MyLinkedListMapT(){
    while(keyFront!= nullptr && valueFront== nullptr) {
        LinkedNodeT<std::string> * temp=keyFront;
        keyFront=keyFront->getNext();
        LinkedNodeT<T> *temp2=valueFront;
        valueFront=valueFront->getNext();
        delete temp;
        delete temp2;
    }
}
template <class T>
void MyLinkedListMapT<T>::put(std::string key, const T& value) {
    LinkedNodeT<std::string>* newKey = new LinkedNodeT<std::string>(key);
    LinkedNodeT<T>* newValue = new LinkedNodeT<T>(value);
    LinkedNodeT<std::string> * temp1=keyFront;
    LinkedNodeT<T> * temp2=valueFront;
    if (keyFront==nullptr && valueFront==nullptr){
        keyFront=newKey;
        valueFront=newValue;
    }else{
        while (temp1->getNext()!=nullptr && temp2->getNext()!=nullptr) {
            if (temp1->getItem()==key){
                temp2->setItem(value);
                return;
            }
            temp1=temp1->getNext();
            temp2=temp2->getNext();
        }if (temp1->getItem()==key){
            temp2->setItem(value);
            return;
        }
        LinkedNodeT<std::string>* keyNodeAfter = temp1->getNext();
        LinkedNodeT<T>* valueNodeAfter=temp2->getNext();
        temp1->setNext(newKey);
        temp2->setNext(newValue);
        newKey->setNext(keyNodeAfter);
        newValue->setNext(valueNodeAfter);
    }
}

template <class T>
T MyLinkedListMapT<T>::get(std::string key){
    LinkedNodeT<std::string> * temp1=keyFront;
    LinkedNodeT<T> * temp2=valueFront;
    if (!containsKey(key)){
        throw std::invalid_argument("Key not present");
    }else{
        while (temp1!= nullptr && temp2!= nullptr) {
            if (temp1->getItem()==key) {
                T item = temp2->getItem();
                return item;
            }temp1 = temp1->getNext();
            temp2 = temp2->getNext();
        }
    }
}

template <class T>
bool MyLinkedListMapT<T>::containsKey(std::string key) {
    LinkedNodeT<std::string> * temp1=keyFront;
    LinkedNodeT<T> * temp2=valueFront;
    while (temp1!= nullptr && temp2!= nullptr){
        if (temp1->getItem()==key){
            return true;
        }temp1=temp1->getNext();
        temp2=temp2->getNext();
    }return false;
}
