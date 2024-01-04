#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write several test cases for each function.
// Make sure you cover all corner cases!
//-----------------------------------------------------------------------------

TEST(linkedlist, test1){
    //parameterized constructor and convert_to_vector func
    std::vector<int> x = {1, 4, 5, 6, 10};
    SinglyLinkedList y(x);
    std::vector<int> output = y.convert_to_vector();
    EXPECT_EQ(output, x);

    //copy constructor 
    SinglyLinkedList y1(y);
    output = y1.convert_to_vector();
    EXPECT_EQ(output, x);

    //push_back()
    y.push_back(7);
    y.push_back(8);
    std::vector<int> x_expected = {1, 4, 5, 6, 10, 7, 8};
    output = y.convert_to_vector();
    EXPECT_EQ(output, x_expected);

    //pop back
    int size1 = y.size();
    bool pass = y.pop_back();
    EXPECT_TRUE(pass);
    EXPECT_EQ(y.size(), size1 - 1);
    x_expected = {1, 4, 5, 6, 10, 7};
    output = y.convert_to_vector();
    EXPECT_EQ(output, x_expected);

    //empty func
    EXPECT_FALSE(y.empty());
    while(!y.empty()){
        y.pop_back();  
    }
    EXPECT_TRUE(y.empty());

    //back func
    EXPECT_EQ(y.back(), -1); //if empty 
    y.push_back(2);
    EXPECT_EQ(y.back(), 2);

    //erase func
    y.push_back(3);
    y.push_back(4);
    y.push_back(5);
    ListNode* i = y.erase(1);
    EXPECT_TRUE(i != nullptr);
    EXPECT_EQ(i->val, 2);
    x_expected = {2,4,5};
    output = y.convert_to_vector();
    EXPECT_EQ(output, x_expected);

    //getprev func
    ListNode* back = y.GetPrevious(i);
    EXPECT_TRUE(back == nullptr);
    

    //remove dups 
    y.push_back(4);
    y.push_back(5);
    y.push_back(2);
    y.push_back(4);
    y.remove_duplicates();
    x_expected = {2,4,5};
    output = y.convert_to_vector();
    EXPECT_EQ(output, x_expected);

    //reverse func
    y.reverse();
    std::reverse(x_expected.begin(), x_expected.end());
    output = y.convert_to_vector();
    EXPECT_EQ(output, x_expected);

    back = y.GetBackPointer();
    EXPECT_EQ(back->val, 2);
    ListNode* a = y.GetIthPointer(1);
    EXPECT_EQ(a->val, 4);
}