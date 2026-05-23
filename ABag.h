#pragma once
/*
* File:   ABag.h
* Author: Prof Terri Sipantzi
*
* You may use this template to implement your ABag.
*/

#ifndef ABAG_H
#define ABAG_H

#include "book.h"
#include "bagADT.h"

template <typename E>
class ABag : public Bag<E> {
public:
    // Default constructor with a default capacity
    ABag() : used(0), capacity(10) { // Default capacity set to 10
        data = new E[capacity]; // Initialize the array
    }

    // Constructor with initial capacity
    ABag(int initialCapacity) : used(0), capacity(initialCapacity) {
        data = new E[capacity]; // Initialize the array
    }

    ~ABag() {
        delete[] data; // Free memory
    }

    bool addItem(const E& item) override {
        if (used == capacity) return false; // Bag is full
        data[used++] = item; // Add item and increment used
        return true;
    }

    bool remove(E& item) override {
        for (int i = 0; i < used; ++i) {
            if (data[i] == item) {
                item = data[i]; // Update item with the value being removed
                for (int j = i; j < used - 1; ++j) {
                    data[j] = data[j + 1];
                }
                --used; // Decrement size
                return true;
            }
        }
        return false; // Item not found
    }

    bool removeTop(E& returnValue) override {
        if (used == 0) return false; // Bag is empty
        returnValue = data[used - 1]; // Get the last item
        --used; // Decrement size
        return true;
    }

    bool find(E& returnValue) const override {
        for (int i = 0; i < used; ++i) {
            if (data[i] == returnValue) {
                returnValue = data[i]; // Update returnValue with the found item
                return true;
            }
        }
        return false; // Item not found
    }

    bool inspectTop(E& item) const override {
        if (used == 0) return false; // Bag is empty
        item = data[used - 1]; // Get the last item
        return true;
    }

    int size() const override {
        return used; // Current number of items
    }

    int bagCapacity() const override {
        return capacity; // Total capacity
    }

    void emptyBag() override {
        used = 0; // Clear the bag
    }

    bool operator+=(const E& addend) override {
        return addItem(addend); // Reuse addItem method
    }

private:
    E* data;            // an array of items
    int used;           // number of items the data array currently holds
    int capacity;       // the number of items the bag can hold (size of array)
};

#endif