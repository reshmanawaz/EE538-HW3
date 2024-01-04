
# HW3 EE538
## University of Southern California
Please clone this repository, edit README.md to answer the questions, and fill up functions to finish the homework.

## Important:
- Use address sanitizer!
- Every time that you use a dereferencing operator (* or ->) make sure your pointer is valid!

Also note that:
- Please find each question in a separate folder under [files](/files).
- For non-coding questions, fill out the answers in the README file.
- For coding questions, edit the files and check them in.
- For coding questions unless specified, you should add unit tests to the student_test.cc. We will clone and test your repo using your tests and some other tests (that are not provided). Your code should pass all of them.
- For submission, please push your answers to Github before the deadline.
- Deadline: July 14th 12:00 pm (noon)


See [cpp-template](https://github.com/ourarash/cpp-template) for help on installing bazel and debugging.


Question 1 Answers: 

Q1:
The non-parameterized constructor is called on by this code block which leads to the the vector v_ being initialized as it is a member variable. The size of v_ would be 0 since it is a non-parameterized constructor.  

Q2: 
There are three destructor calls, one for each object. A non-parameterized constructor is used to create a o1 instance. Instance o2 is created using a parameterized constructor. Copy constructor is used for instance and it is an exact copy of o1.

Q3: 
A non-parameterized constructor is inializing the object o. Then, the 'o' instance is passed as a parameter to the function 'DoSomething1' by value, resulting in the invocation of the copy constructor to create a copy of the parameter. Because of this two objects are created, resulting in the destructor being called twice.

Q4:
In the function 'DoSomething2', which uses pass by value, there is no copy constructor involved. Therefore, only the object 'o' is initialized, and the destructor is called only once. The object 'o' is actually initialized using a non-parameterized constructor. 

Q5:
After being initialized with a non-parameterized constructor, the object 'o' is passed as a parameter to the function 'DoSomething3' using pass by value. As a result, there is no involvement of a copy constructor, and only the object 'o' gets initialized. Consequently, the destructor is called only once.

Q6:
Here too the the object 'o' is initialized using a non-parameterized constructor. 'o' is passed as a reference to the function 'DoSomething4'. Within 'DoSomething4', an internal object is created, which triggered the copy constructor. Once again, two objects are created resulting in the destructor being called twice. The first destructor call occurs at the end of 'DoSomething4', and the second one occurs at the end of the scope where 'Q6' is defined.

Q7:
The parameterized constructor is called, with 'a_' and 'b_' initialized to 1 and 2 respectively. Within the same line, the std::pair is copying objects of the class MyClass and also calling the destructor. 
The 3rd and 4th lines print the size of v_ and the value of 'pair.second'. The 5th line a copy constructor is called to create a copy of 'p1'. The 6th line prints the size of 'v_' within the first class of 'p2'. Lastly, the 7th line prints the value of 'p2.second'. 

Q8:
At the start of the loop, a pair is created using the parameterized constructor. This pair triggers the internal invocation of the copy constructor and the destructor. The indices of the for loop are created based on the value of 'p.second'. During each iteration, the value of 'p.second' is pushed into the 'v_' of 'p.first', which is an instance of the class MyClass. Additionally, the function DoSomething2 is called to perform printing operations. Once the usage of 'p', which is passed by reference, is complete, the destructor is called at the end. This is because we only have a single object of MyClass within the pair.

Q9
A pointer of type MyClass named "o" is created in line 2. The parameterized constructor is called with initial input values of 1 and 2 in line 3. The issue lies at the end of the code where the variable o is lost which results in a memory leak.

q10:
A pointer of type MyClass named "o" is created in line 2. The parameterized constructor with initial input values of 1 and 2 happens in line 3. In line 4, the destructor happens as the memory that is pointing to o is let go. 

Q11
Lines 2 to 5 involve the creation of a map variable with integer and MyClass as the key-value pairs. The instance in the first pair is created using a non-parameterized constructor, where the std::pair internally copies objects of MyClass, triggering the invocation of the copy constructor. The instance in the second pair is created using a parameterized constructor, and again, the std::map internally copies objects of MyClass, resulting in the copy constructor being called. Similarly, the instance in the third pair is created using a parameterized constructor, and the std::map internally copies objects of MyClass, leading to the invocation of the copy constructor.
The destructor is called six times to deallocate the memory of the temporary objects internally created by std::map. In the final loop, during each iteration, a copy of the MyClass instance is made when iterating through the map. At the end of each iteration, a destructor is called for each object that was copied. Finally, at the end of the scope, a destructor is called once for each item in the map.

Q12
Since there are no copies made this results is no calls to the destructor and the copy constructor. 

Q14
Because the parameterized consturor is called 100,000,000 items, this means that it needs alot of time called upon from line 2 and 3. Then in the 4th line it prints the duration of the object construction. In the 5th line, the timer restarts. The for loop goes 3 times and each time making a copy of the o and assigning it to o2 by the help of the copy constructor. After the loop, the amount of time is printed. Since pass by value is used and 'o2' being a copy of 'o', the copy constructor is called numerous times which could also result in alot of time consumption. At the end, the o is destructed.  

Q15:
This is very aligned to q14 but the only difference is that since 'DoSomething2' is pass-by-reference, it not only takes less time but there is also no calls to the copy constructor and destructor within that function. 

Q16:
Line 2, the timer has begun. Lines 3 to 6 use the parameterized constructors to initialize 7 instances of MyClass with various different input values during which the std::vector calls the copy constructor and destructor. For each object in my_vector the copy constructor and destructor is called. The first loop is making copies which are resulting in calls to the copy constructor and the destructor. However, the second loop is creating the references which is faster. The size of v_ is being printed. Lastly, 7 destructor calls are made to deallocate memory. 
