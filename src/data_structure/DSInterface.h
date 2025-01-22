#pragma once

typedef int Position;
template <typename LValueType>
struct LNode{ 
    LNode<LValueType>* next; 
    LValueType value;
};
template <typename LValueType>
class ILinkedList {
public:
    virtual ~ILinkedList() = default;
public:
    virtual void Insert( LValueType item, Position pos ) = 0;
    virtual void Delete( Position pos ) = 0;
    virtual LNode<LValueType>* Findith( Position pos ) = 0;
    virtual LNode<LValueType>* Find( LValueType item ) = 0;
    virtual int getLength() = 0;
    virtual LNode<LValueType>* getValue() = 0;
};