//
// Created by Bobo on 11/29/2018.
//
#ifndef INC_220_DJ_PROJECT_MASTERPLAYLIST_H
#define INC_220_DJ_PROJECT_MASTERPLAYLIST_H

#include <string>
#include <stdexcept>
#include "LinkedPlayList.h"
#include "PlayList.h"

class MasterPlayList {
    private:
        LinkedNodeT<std::string>* keyFront;
        LinkedNodeT<T>* valueFront;
        MyLinkedListMapT(const MyLinkedListMapT<T>& mapToCopy);
        MyLinkedListMapT& operator=(const MyLinkedListMapT<T>& mapToCopy);

    public:
        MyLinkedListMapT();
        ~MyLinkedListMapT();

        /*
        * @post if the key is new, the key-value pair is added to the map
        *       if the key was already present, the new value overwrites the old value
        *       (i.e., the new value will be returned by get instead of the old value)
        */
        void put(std::string key, const T& value);

        /*
        * @return the value associated with the given key
        * @throws std::invalid_argument if the key is not present
        */
        T get(std::string key);

        /*
     * @return true if the given key is associated with a value in the map, false otherwise
     */
        bool containsKey(std::string key);

    };


#endif //INC_220_DJ_PROJECT_MASTERPLAYLIST_H
