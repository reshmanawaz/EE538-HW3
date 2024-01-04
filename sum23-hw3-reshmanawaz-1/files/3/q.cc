#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc

// Copy constructor.
  Queue::Queue(const Queue& rhs){
    v_ = rhs.v_; 
  }

  // Copy assignment.
  // It is used when you have a code like this:
  // Queue q1, q2;
  // q1 = q2;
  // It returns a reference to *this, i.e., at the end of the function, add
  // "return *this;";
  // The return value is used for cases like this:
  // q1 = q2 = q3;
  // This will first call q2.operator=(q3)
  // then the result of this function is passed to q1.operator=(result);
  Queue& Queue::operator=(const Queue& rhs){
    v_ = rhs.v_; 
    return *this;
  }

  // Returns a new queue that has all elements of q2 followed by q1 in order.
  // Example:
  // q1={1, 2, 3}, i.e. front is 1, back is 3
  // q2={4, 5}, i.e. front is 4, back is 5
  // q3 = q1 + q2 = {4, 5, 1, 2, 3}, i.e. front is 4, back is 3
  Queue Queue::operator+(const Queue& rhs){
    Queue output = *this; 
    std::vector<int> newrhs = rhs.v_; 
    if(!newrhs.empty()){
        output.v_.push_back(newrhs.front()); //adding the elements to the back 
        newrhs.erase(newrhs.begin()); //remove the front 
        output.v_.insert(output.v_.end(), newrhs.begin(), newrhs.end()); //combine the elements 
    }
    return output; 
  }

  // Inserts in the back of the queue.
  bool Queue::Enqueue(int value){
    v_.push_back(value);
    return true; 

  }

  // Removes from the front of the queue. If the queue is empty, return false,
  // otherwise true.
  bool Queue::Dequeue(){
    if(v_.size() == 0){
        return false; //indicate that the queue is empty 
    } 
    v_.erase(v_.begin());
    return true; 
  }

  // Returns true if the queue is empty.
  bool Queue::IsEmpty(){
    if(v_.size() == 0){
        return true; 
    }else{
        return false;
    }
  }

  // Returns the value in the front of the queue. If the queue is empty, return
  // -1.
  int Queue::Front(){
    if(v_.size() == 0){
        return -1; 
    }
    return v_.front();
  }