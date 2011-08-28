//
//  stack1.hpp
//  stack1
//
//  Created by 中野 俊亮 on 11/08/27.
//  Copyright 2011年 __MyCompanyName__. All rights reserved.
//

#ifndef stack1_stack1_hpp
#define stack1_stack1_hpp

#include <vector>
#include <stdexcept>

template <typename T>
class Stack {
private:
    std::vector<T> elems;     // elements
    
public:
    void push(T const&);      // push element
    void pop();               // pop element
    T top() const;            // return top element
    bool empty() const {      // return whether the stack is empty
        return elems.empty();
    }
};

template <typename T>
void Stack<T>::push (T const& elem)
{
    elems.push_back(elem);    // append copy of passed elem
}

template<typename T>
void Stack<T>::pop ()
{
    if (elems.empty()) {
        throw std::out_of_range("Stack<>::pop(): empty stack");
    }
    elems.pop_back();         // remove last element
}

template <typename T>
T Stack<T>::top () const
{
    if (elems.empty()) {
        throw std::out_of_range("Stack<>::top(): empty stack");
    }
    return elems.back();      // return copy of last element
}

//ポインタに対するStackのデストラクタ特殊化
template <typename T>
class Stack<T*>
{
private:
    std::vector<T*> elems;     // elements

public:
    void push(T* const&);      // push element
    void pop();                // pop element
    T* top() const;            // return top element
    bool empty() const {       // return whether the stack is empty
        return elems.empty();
    }
    ~Stack<T*>();
};


template <typename T>
void Stack<T*>::push (T* const& elem)
{
    elems.push_back(elem);    // append copy of passed elem
}

template<typename T>
void Stack<T*>::pop ()
{
    if (elems.empty()) {
        throw std::out_of_range("Stack<>::pop(): empty stack");
    }
    elems.pop_back();         // remove last element
}

template <typename T>
T* Stack<T*>::top () const
{
    if (elems.empty()) {
        throw std::out_of_range("Stack<>::top(): empty stack");
    }
    return elems.back();      // return copy of last element
}

template <typename T>
Stack<T*>::~Stack() {
    for(int i=0; i<elems.size(); i++){
        delete elems.at(i);
    }
}

#endif
