
#include "SortedList.h"


template<class T>
SortedList<T>::SortedList() {
    length = 0;
    currentPos = -1;  // 0
}

template<class T>
void SortedList<T>::MakeEmpty() {
    length = 0;
}

template<class T>
bool SortedList<T>::IsFull() const {
    return length == MAX_ITEMS;
}

template<class T>
int SortedList<T>::GetLength() const {
    return length;
}

template<class T>
bool SortedList<T>::Contains(T someItem) {

    return false;
}

template<class T>
void SortedList<T>::PutItem(T item) {
    // There will be 2 loops
    // 1st loop starts from the beginning of array and moves forward.
    // 2nd loop starts at the first empty space (after last item) and moves backwards.
    // Find where item goes
    int i;
    for (i = 0; i < length; i++) {
        // Find the correct position
        if (item <= info[i]) {
            break;
        }
    }
    // Slide over items
    for (int j = length; j >= i + 1; j--) {
        info[j] = info[j - 1];
    }
    info[i] = item;
    ++length;
}

template<class T>
void SortedList<T>::DeleteItem(T item) {
    // Find the item
    for (int i = 0; i < length; i++) {
        // Find the correct position
        if (item == info[i]) {
            // Move everything back a space to fill in deleted number.
            // We want j to START at the target we want to delete ( i )
            // and stop at the last nuber in the array.
            for (int j = i; j < length; j++) {
                // We move the info of the NEXT index in the array
                // back a space. Continue to do this until the
                // end of the array.
                info[j] = info[j + 1];
            }
            --length;
            // Function will delete first instance only
            // so return and bail out
            return;
        }
    }
}

template<class T>
void SortedList<T>::ResetIterator() {
    currentPos = -1;
}

template<class T>
int SortedList<T>::GetNextItem() {
    if (currentPos >= length) {
        throw "Out of bounds";
    }
    currentPos++;
    return info[currentPos];
}

