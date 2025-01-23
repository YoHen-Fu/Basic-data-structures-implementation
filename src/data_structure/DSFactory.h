#pragma once
#include <memory>
#include "DSInterface.h"
#include "LinkedList.h"
#include "Stack.h"
#include "Queue.h"


class DSFactory {
public:
    template <typename T>
    static ILinkedList<T>* createLinkedList(){
        return new LinkedList<T>();
    }    
    template <typename T>
    static IStack<T>* createStack(){
        return new Stack<T>();
    }
    template <typename T>
    static IQueue<T>* createQueue(){
        return new Queue<T>();
    }
};

// class DSFactory {
// public:
//     template <typename T>
//     static std::unique_ptr<LinkedList<T>> createLinkedList(){
//         return std::make_unique<LinkedList<T>>();
//     }
// };
