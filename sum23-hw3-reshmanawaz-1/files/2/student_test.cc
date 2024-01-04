#include <iostream>
#include <string>


#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write several test cases for each function.
// Make sure you cover all corner cases!
//-----------------------------------------------------------------------------

// Example 1: Input: "(a+b)" Output: true
  // Example 2: Input: "(a+b)[c*d]{5g+h}" Output: true
  // Example 3: Input: "(a+b]" Output: false
  // Example 4: Input: "(7h+[5c)+7]" Output: false
  // Example 5: Input: "{2k+[5j]}" Output: true
  // Example 6: Input: "{2k++[5--*j]}" Output: true

TEST(CheckValidExpression, test1){
    std::string x = "(a+b)";
    CPPLib CheckValidExpression;
    bool output = CheckValidExpression.CheckValidExpression(x);
    EXPECT_EQ(output, true);
}

TEST(CheckValidExpression, test2){
    std::string x = "{2k+[5j]}";
    CPPLib CheckValidExpression;
    bool output = CheckValidExpression.CheckValidExpression(x);
    EXPECT_EQ(output, true);
}

TEST(CheckValidExpression, test3){
    std::string x = "(a+b)[c*d]{5g+h}";
    CPPLib CheckValidExpression;
    bool output = CheckValidExpression.CheckValidExpression(x);
    EXPECT_EQ(output, true);
}
TEST(CheckValidExpression, test4){
    std::string x = "(a+b]";
    CPPLib CheckValidExpression;
    bool output = CheckValidExpression.CheckValidExpression(x);
    EXPECT_EQ(output, false);
}
TEST(CheckValidExpression, test5){
    std::string x = "(7h+[5c)+7]";
    CPPLib CheckValidExpression;
    bool output = CheckValidExpression.CheckValidExpression(x);
    EXPECT_EQ(output, false);
}


TEST(IsPalindrome, test1){
    std::string x = "aba";
    CPPLib IsPalindrome;
    bool output = IsPalindrome.IsPalindrome(x);
    EXPECT_EQ(output, true);
}

TEST(IsPalindrome, test2){
    std::string x = "abc";
    CPPLib IsPalindrome;
    bool output = IsPalindrome.IsPalindrome(x);
    EXPECT_EQ(output, false);
}
//empty string
TEST(IsPalindrome, test3){
    std::string x = "";
    CPPLib IsPalindrome;
    bool output = IsPalindrome.IsPalindrome(x);
    EXPECT_EQ(output, true);
}

TEST(IsPalindrome, test4){
    std::string x = "a";
    CPPLib IsPalindrome;
    bool output = IsPalindrome.IsPalindrome(x);
    EXPECT_EQ(output, true);
}

TEST(OddChar, test1){
     std::string x = "aabcc";
     CPPLib OddChar;
     char output = OddChar.OddChar(x);
     EXPECT_EQ(output, 'b');
}

TEST(OddChar, test2){
    std::string x = "a";
     CPPLib OddChar;
     char output = OddChar.OddChar(x);
     EXPECT_EQ(output, 'a');
}

TEST(OddChar, test3){
    std::string x = "aa";
     CPPLib OddChar;
     char output = OddChar.OddChar(x);
     EXPECT_EQ(output, '\0');
     //bazel test files/2:student_test
}
TEST(OddChar, test4){
    std::string x = "";
     CPPLib OddChar;
     char output = OddChar.OddChar(x);
     EXPECT_EQ(output, '\0');
     //bazel test files/2:student_test
}