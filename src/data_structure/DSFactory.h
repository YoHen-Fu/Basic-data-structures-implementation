#pragma once
#include <memory>
#include "DSInterface.h"
#include "LinkedList.h"

// class DSFactory {
// public:
//     template <typename T>
//     static std::unique_ptr<LinkedList<T>> createLinkedList(){
//         return std::make_unique<LinkedList<T>>();
//     }
// };

class DSFactory {
public:
    template <typename T>
    static ILinkedList<T>* createLinkedList(){
        return new LinkedList<T>();
    }
};
