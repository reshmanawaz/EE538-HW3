#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <algorithm>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc

//constructor 
 DoubleStack::DoubleStack(){
 }

  // Pushes the number in evenVec_ if the input is even
  // Pushes the number in oddVec_ if the input is odd
  void DoubleStack::push(int num){
    if(num % 2 != 0){
        oddVec_.push_back(num);
    }else{
        evenVec_.push_back(num);
    }
  }

  // Removes the maximum number from the top of both vectors.
  // It does not do anything if both stacks are empty.
  void DoubleStack::pop(){
    //base cases 
    //odd empty 
    if(oddVec_.empty()){
        evenVec_.pop_back();
        return; 
    }
    //even empty 
    if(evenVec_.empty()){
        oddVec_.pop_back();
        return; 
    }
    //both empty 
    if(oddVec_.empty() && evenVec_.empty()){
        return; 
    }

    //check if vectors have atleast one element 
    int even = evenVec_.back(); //Returns a reference to the last element in the even vector.
    int odd = oddVec_.back(); //Returns a reference to the last element in the odd vector.
    if(odd >= even){
        oddVec_.pop_back();
    }else{
        evenVec_.pop_back();
    }
  }

  // Returns the maximum number from the top of both vectors.
  // It returns -1 if both stacks are empty.
  int DoubleStack::top(){
    
    if(oddVec_.empty() && evenVec_.empty()){
        return -1; 
    }else if(evenVec_.empty()){
        return oddVec_.back();
    }else if(oddVec_.empty()){
        return evenVec_.back();
    }else{
        return std::max(oddVec_.back(), evenVec_.back()); //output the max 
    }
  }

  // Returns the size of evenVec_ plus the size of oddVec_
  int DoubleStack::size(){
    return oddVec_.size() + evenVec_.size();
  }

  // Returns true if both vectors are empty, false otherwise
  bool DoubleStack::empty(){
    if(oddVec_.empty() && evenVec_.empty()){
        return true; 
    }else{
        return false; 
    } 
  }