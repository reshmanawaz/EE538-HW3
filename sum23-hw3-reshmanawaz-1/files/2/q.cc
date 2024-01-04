#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <map>


// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc

//  Given an expression string, find if the input has valid brackets (i.e. { }
  //  or [ ] or ( ) ).
  // An input expression is valid if:
  // Open brackets are closed by the same type of brackets. Open brackets must
  // be closed in the correct order. An empty string is also considered valid.
  // You should only check for the validity of brackets based on the above
  // rules, i.e. ‘(‘, ‘)’, ‘[‘, ‘]’, ‘{‘, ‘}’, not the rest of the expression.
  // Example 1: Input: "(a+b)" Output: true
  // Example 2: Input: "(a+b)[c*d]{5g+h}" Output: true
  // Example 3: Input: "(a+b]" Output: false
  // Example 4: Input: "(7h+[5c)+7]" Output: false
  // Example 5: Input: "{2k+[5j]}" Output: true
  // Example 6: Input: "{2k++[5--*j]}" Output: true
bool CPPLib::CheckValidExpression(const std::string& input){
    std::stack<char> var; 
    std::set<char> open = {'(', '[', '{'};
    std::set<char> close = {')', ']', '}'};
    auto len = input.length();
    int i = 0; 
    std::map<char, char> combine = {
        {'(', ')'}, {'[', ']'}, {'{', '}'}
    };

    while(i < len){
        char x = input[i]; //stores variable i in x
        if(open.find(x) != open.end()){ //if open bracket then push into the 'var' stack
            var.push(x);
        }else if(close.find(x) != close.end()){ //if closed bracket then check if the stack is empty first
            if(var.empty()){ //if false then exit because it implies that there was no corresponding open bracket
                return false; 
            }
            char top = var.top();
            var.pop(); 
            if(combine[top] != x){ 
                return false; 
            }
        }
        i++;
    }
    return var.empty();
}


// Checks if a string is a palindrome.
  // An empty string is a palindrome.
  // A non empty string is a palindrome if it is equal to its reverse string.

  // Example 1: Input: "aba", output: true
  // Example 2: Input: "abba", output: true

  // You cannot use any std:: function.
  // Your memory usage should be O(1).
bool CPPLib::IsPalindrome(const std::string& input){
    auto size = input.size(); 
    auto right_side = size -1; 
    auto left_side = 0;

    //check for empty string
    if(size == 0){
        return true; 
    }

    while(left_side < right_side){
        if(input[left_side] != input[right_side]){
            return false;
        }
        right_side--; //decrement right to left 
        left_side++; //increment left to right
    }
    return true; 
}

// Given a string, every letter appears even number of times except for one.
  // Find that letter!

  // Any solution that work is acceptable, but see if you can implement it while
  // keeping your memory usage as O(1).

int CPPLib::OddChar(const std::string& input){
//need to find letter that appears odd number of times - use XOR logic 
//XOR logic - output is true if odd and false is even 

    char output = 0; 
    int x = 0; 
    for (auto x : input){
        output ^= x; 
    }
    return output; 
}