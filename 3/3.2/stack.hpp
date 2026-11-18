#ifndef STACK_HPP
#define STACK_HPP

class Stack {
private:
    double* data;    
    int top;         
    int capacity;    

public:
    
    Stack();                                            
    Stack(const Stack& other);                          
    ~Stack();                                           

    
    Stack(double value);                                
    Stack(int count, const double* arr);                
    Stack(int maxCapacity, double value, int count);    

    
    void Print() const;              
    bool Push(double value);         
    bool Pop(double& removedValue);  
    double Sum() const;              

    int GetTop() const { return top; }
};

#endif