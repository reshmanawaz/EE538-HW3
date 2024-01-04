#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write several test cases for each function.
// Make sure you cover all corner cases!
//-----------------------------------------------------------------------------


TEST(DoubleStack, test1){
    DoubleStack DoubleStack; 
    DoubleStack.push(2);
    DoubleStack.push(7);
    DoubleStack.push(5);
    DoubleStack.push(9);
    EXPECT_EQ(DoubleStack.size(), 4); 
    EXPECT_EQ(DoubleStack.top(), 9); 
    DoubleStack.pop();
    EXPECT_EQ(DoubleStack.size(), 3); 
    EXPECT_EQ(DoubleStack.empty(), false); 
    
}
//empty 
TEST(DoubleStack, test2){
    DoubleStack DoubleStack; 
    DoubleStack.push(3);
    DoubleStack.pop();
    //stack size
    EXPECT_EQ(DoubleStack.size(), 0); 
    //test if empty -output should be true 
    EXPECT_EQ(DoubleStack.empty(), true); 
}
//even only 
TEST(DoubleStack, test3){
    DoubleStack DoubleStack; 
    DoubleStack.push(2);
    DoubleStack.push(4);
    EXPECT_EQ(DoubleStack.size(), 2); 
    DoubleStack.pop();
    EXPECT_EQ(DoubleStack.size(), 1); 
    //test if empty -output should be true 
    EXPECT_EQ(DoubleStack.empty(), false); 
}
    


//odd only 
TEST(DoubleStack, test4){
    DoubleStack DoubleStack; 
    DoubleStack.push(9);
    DoubleStack.push(3);
    DoubleStack.push(7);
    DoubleStack.push(5);
    EXPECT_EQ(DoubleStack.size(), 4); 
    DoubleStack.pop();
    EXPECT_EQ(DoubleStack.size(), 3); 
    EXPECT_EQ(DoubleStack.empty(), false); 
    
}
