#ifndef STACK_HPP
#define STACK_HPP

#include "array.hpp"

class Stack : public Array {
private:
    int depth; 

public:
    Stack();                        
    Stack(int maxDepth);            
    Stack(const Stack& other);      
    ~Stack() override;              

    bool Push(double value);        
    bool Pop(double& value);        
    bool Peek(double& value) const; 

    bool Resize(int newSize);       
    int GetDepth() const { return depth; }
    void Print() const;
};

#endif