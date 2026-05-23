#pragma once
/*
* File:   BDictionary.h -- implement a dictionary use an array-based bag
* Author: Prof Terri Sipantzi
*
* You may use this template to implement your Dictionary
*/

#ifndef BDICTIONARY_H
#define BDICTIONARY_H

#include "ABag.h"
#include "dictionaryADT.h"
#include "kvpair.h"

template <typename Key, typename E>
class BDictionary : public Dictionary<Key, E> {
public:
    BDictionary(int size) {
        dictionary = new ABag<KVpair<Key, E>>(size); // Proper initialization
    }

    ~BDictionary() {
        delete dictionary; // Free allocated memory
        dictionary = nullptr; // Prevent dangling pointer
    }

    void clear() override {
        dictionary->emptyBag(); // Use ABag's emptyBag method to clear all key-value pairs
    }

    bool insert(const Key& k, const E& e) override {
        KVpair<Key, E> pair(k, e); // Create a KVpair with the given key and value
        return dictionary->addItem(pair); // Use ABag's addItem method
    }

    bool remove(const Key& k, E& rtnVal) override {
        KVpair<Key, E> pair(k, rtnVal); // Create a KVpair with the key (value will be updated)
        if (dictionary->remove(pair)) {
            rtnVal = pair.value(); // Extract the value from the removed KVpair
            return true;
        }
        return false; // Key was not found
    }

    bool removeAny(E& rtnVal) override {
        KVpair<Key, E> pair;
        if (dictionary->removeTop(pair)) { // Remove the topmost item from the bag
            rtnVal = pair.value(); // Extract the value
            return true;
        }
        return false; // Dictionary is empty
    }

    bool find(const Key& k, E& rtnVal) const override {
        KVpair<Key, E> pair(k, rtnVal); // Create a KVpair with the key (value will be updated)
        if (dictionary->find(pair)) {
            rtnVal = pair.value(); // Extract the value from the found KVpair
            return true;
        }
        return false; // Key was not found
    }

    int size() override {
        return dictionary->size(); // Use ABag's size method to get the count
    }

private:
    ABag<KVpair<Key, E>>* dictionary;
};

#endif