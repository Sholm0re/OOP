#ifndef ARRAY_HPP
#define ARRAY_HPP

class Array {
protected:
    int size;       
    double* data;   

public:
    Array();                            
    Array(int initialSize);             
    Array(const Array& other);          
    virtual ~Array();                   

    bool Resize(int newSize);           
    int GetSize() const { return size; }
};

#endif