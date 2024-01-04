#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc

// struct ListNode {
//   int val;
//   ListNode *next;
//   ListNode(int x) : val(x), next(nullptr) {}
// };

// class SinglyLinkedList {
//  private:
//   ListNode *head_;  // Pointer to the head of the list.
//   int size_;        // The current size of the list.
//   int minusOne_ = -1;

//  public:
//   // Constructor. Already implemented. No need to change.
//   SinglyLinkedList() {
//     head_ = nullptr;
//     size_ = 0;
//   }

  // *********************************************************************
  // TODO: Implement the following functions in q.cc.
  // *********************************************************************
  // Write a new parameterized constructor that takes a vector as an input and
  // crates a linked list based on that. Note that your constructor should
  // assign a valid value for head_. Example:
  // Input:  v = {1, 4, 5, 6, 10}
  // The created list: 1->4->5->6->10, and head_ will point to the first node
  // with value 1.
  
  SinglyLinkedList::SinglyLinkedList(const std::vector<int> &v){
    head_ = nullptr;
    size_ = 0;
    for(int x : v){ //for each element x, pushback creates a new node 
        push_back(x);
    }
  }

  // Copy constructor.
  SinglyLinkedList::SinglyLinkedList(const SinglyLinkedList &rhs){
    head_ = nullptr;
    size_ = 0; //empty list 
    ListNode *node_x = rhs.head_; //new node set to the head of right hand side 
    while(node_x != nullptr){
        push_back(node_x->val); //add value of node_x to the new list 
        node_x = node_x->next; //move node_x to next node in rhs 
    }
  }

  // Destructor should de-allocate the entire list.
  SinglyLinkedList::~SinglyLinkedList(){
    ListNode *node_x = head_; //new node set to the head of right hand side 
    if(node_x == nullptr){
      return; 
    }
    while(node_x != nullptr){
        ListNode *node_x1 = node_x->next; 
        delete node_x; //delete the current node
        node_x = node_x1; //set the current node to the next node
    }
    head_ = nullptr;
  }

  // Returns true if the list is empty, false otherwise.
  bool SinglyLinkedList::empty(){
    return head_ == nullptr;
  }

  // Returns the current size of the list.
  int SinglyLinkedList::size(){
    return size_;
  }

  // Returns a pointer to the head of the list.
  ListNode *SinglyLinkedList::head(){
    return head_;
  }

  // Insert i at the back of the list.
  void SinglyLinkedList::push_back(int i){
    ListNode *x = new ListNode(i); //new node created
    ListNode* node_x = head_;
    //base case
    if(head_ == nullptr){
        head_ = x; //if empty then set the new node as head
        size_ = 1; 
        return; 
    }else{
        while(node_x->next != nullptr){ //iterates until the last node
            node_x = node_x->next; //adds the new node 
    }
    node_x->next = x; //sets to the new node 
    }
    size_++; //size increases after new node added 
  }

  // Removes an item from the back of the list. Returns true if it was
  // successful.
  bool SinglyLinkedList::pop_back(){
    ListNode* node_x = head_; //new node created and set to head
    ListNode* back = nullptr; 
    //base case (empty)
    if(head_ == nullptr){
        return false; 
    }
    //base case (only 1 node)
    if(head_->next == nullptr){
        delete head_; 
        head_ = nullptr; 
    }else{
        while(node_x->next != nullptr){ //iterate until it reaches second to last node 
            back = node_x;
            node_x = node_x->next;
        }
        delete node_x; //delete the last node once it reaches the second to last node 
        back->next = nullptr; //indicates the end of the list 
    }
    size_--; //removing the last node = size-1
    return true; 
  }

  // Returns the item in the back of the list. Returns -1 if empty.
  int SinglyLinkedList::back(){
    ListNode* node_x = head_;
    //base case
    if(head_ == nullptr){
        return -1; //return -1
    }else{
        while(node_x->next != nullptr){ //goes until last node in list 
            node_x = node_x->next; //updating the node 
        }
    }
    return node_x->val; //returns val stored in last node 
  }

  // Returns a pointer to the back of the list.
  ListNode *SinglyLinkedList::GetBackPointer(){
    ListNode* node_x = head_;
    //base case
    if(head_ == nullptr){
        return nullptr; 
    }else{
        while(node_x->next != nullptr){ //goes until last node in list 
            node_x = node_x->next; //updating the node 
        }
    }
    return node_x; //returns new node 
  }

  // Returns a pointer to the i(th) element in the list. nullptr if it doesn't
  // exist.
  ListNode *SinglyLinkedList::GetIthPointer(int i){
    if(i<0 || i>size()-1 || empty()){
        return nullptr; 
    }
    ListNode* node_x = head_;
    int x = 0; 
    while(x<i){
      node_x = node_x->next; 
      x++;
    }
    return node_x; 
  }

  // Returns the i(th) element in the list. -1 if it doesn't exits.
  int &SinglyLinkedList::operator[](int i){
    ListNode* node_x = GetIthPointer(i);
    if(node_x == nullptr){
        return minusOne_; //return -1
    }
    return node_x->val;
  }

  // Prints the items in the list.
  void SinglyLinkedList::print(){
    ListNode* node_x = head_;
    if(node_x == nullptr){
      return; 
    }
    while(node_x != nullptr){
        std::cout << node_x->val << " ";
        node_x = node_x ->next;
    }
  }

  // Write a function that converts the list into a vector. Example:
  // The list: 1->4->5->6->10
  // Output: a vector with value: {1, 4, 5, 6, 10}
  std::vector<int> SinglyLinkedList::convert_to_vector(){
    ListNode* node_x = head_;
    std::vector<int> output; 
        while(node_x != nullptr){
            output.push_back(node_x->val);
            node_x = node_x->next;
        }
    return output;
  }

  // Erases element i from the list if it exists and returns a pointer to item
  // i-1. If item i doesn't exist, returns nullptr. The first item in the list
  // has index 0.

  // Example:
  // Input: 1 -> 5 -> 10 ->20, i= 2.
  // Output: 1 -> 5 -> 20, return value: a pointer to element 5.
  ListNode *SinglyLinkedList::erase(int i){
    ListNode *back = GetIthPointer(i-1); 
    if(back == nullptr || back->next == nullptr){
        return nullptr;
    }
    ListNode *curr = back->next;
    ListNode* temp = head_; 
    if(i<0 || i>=size() || empty()){
        return nullptr; 
    }
    back->next = curr->next;
    delete curr;
    size_--;

    if(i == 0){
        head_ = head_->next;
        delete temp;
        return nullptr;
    }
    return back;
  }

  // Given a pointer p, erases the element that p is pointing to from the list
  // and returns a pointer to item before that if it exists and returns nullptr
  // otherwise. If p is nullptr, return nullptr.

  // Example:
  // Input: 1 -> 5 -> 10 ->20, p points to element with value 10.
  // Output: 1 -> 5 -> 20, return value: a pointer to element 5.
  ListNode *SinglyLinkedList::erase(ListNode *p){
    ListNode *back = GetPrevious(p); //previous p
    //base case if empty
    if(p == nullptr){ //check if p is nullptr 
        return nullptr;
    }
    ListNode *next = p->next; //node after p
    if(back != nullptr){
        back->next = next; 
    }else{
        head_ = next; 
    }
    delete p; 
    return back; 
  }

  // Returns a pointer to the element before p. Returns nullptr if it does not
  // exist.
  ListNode *SinglyLinkedList::GetPrevious(ListNode *p){
    ListNode* node_x = head_;
    if(p == head_ || p == nullptr || empty()){
        return nullptr;
    }
    while(node_x != nullptr && node_x->next != p){
        node_x = node_x->next;
    }
    return node_x; 
  }

  // Removes duplicate elements and only keeps the first one.
  // Example:
  // Input: 1 -> 5 -> 1 -> 20 -> 4 -> 5 -> 32
  // Output: 1 -> 5 -> 20 -> 4 -> 32
  void SinglyLinkedList::remove_duplicates(){
    std::set<int> new_set;
    ListNode* node_x = head_;
    ListNode* back = nullptr;
   //base case 
    if(head_ == nullptr || head_->next == nullptr){
        return; 
    }
    while(node_x != nullptr){
      int x = node_x->val;
      ListNode *next1 = node_x->next;
      if(new_set.find(x) != new_set.end()){
        if(back != nullptr){
          back->next = next1;
          }else{
            head_ = next1; 
            }
            delete node_x;
            node_x = next1; 
            size_--;
        }else{
            new_set.insert(x);
            back = node_x; 
            node_x = node_x->next;
        }
    }
  }

  // Reverses the list.
  // Example:
  // Input: 1 -> 5 -> 1 -> 20
  // Output: 20 -> 1 -> 5 -> 1
  void SinglyLinkedList::reverse(){
   ListNode *back = nullptr;
   ListNode *node_x = head_;

   //base cases
    if(head_ == nullptr || head_->next == nullptr){
        return; 
    }
    while(node_x != nullptr){
        ListNode *next = node_x->next;
        node_x->next = back; 
        back = node_x;
        node_x = next; 
    }
    head_ = back; 
  }
