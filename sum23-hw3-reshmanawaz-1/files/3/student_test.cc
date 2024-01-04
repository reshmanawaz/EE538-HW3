#include <iostream>
#include <string>

#include "gtest/gtest.h"
#include "q.h"

//-----------------------------------------------------------------------------
// Write several test cases for each function.
// Make sure you cover all corner cases!
//-----------------------------------------------------------------------------

TEST(Queue, test1){
    //Enqueue + Front
    Queue q; 
    q.Enqueue(1);
    q.Enqueue(2);
    EXPECT_EQ(q.Front(), 1); 
    while(!q.IsEmpty()){
        std::cout << "Dequeued: " << q.Front() << std::endl; 
        q.Dequeue();
    }
    EXPECT_EQ(q.IsEmpty(), true); 

    //operator+
    Queue q1;
    q1.Enqueue(3);
    q1.Enqueue(4);

    Queue q2;
    q2.Enqueue(5);
    q2.Enqueue(6);

    Queue q3 = q1 + q2;
    EXPECT_EQ(q3.Front(), 3);
    EXPECT_EQ(q3.IsEmpty(), false); 
}