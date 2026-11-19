#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "array.hpp"

class Queue : public Array {
private:
    int checkpoint; 
    int count;      

public:
    Queue();                                    
    Queue(int maxSize, int checkpointPos = 0);  
    Queue(const Queue& other);                  
    ~Queue() override;                          

    bool Enqueue(double value);                 
    bool ReadCheckpoint(double& value) const;   
    bool ReadBack(double& value) const;         

    bool SetCheckpoint(int newPos);
    bool Resize(int newSize);
    int GetCheckpoint() const { return checkpoint; }
    void Print() const;
};

#endif