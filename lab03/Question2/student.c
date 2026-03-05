// Question2/student.c
// ------------------------------------------------------------
// CS Lab03 - Swap Nodes in Pairs 
//
// TODO:
//   Implement swapPairs(head) to swap every two adjacent nodes.
//
// Rules:
// - Do not allocate new nodes.
// - Do not swap values; swap nodes (rewire pointers).
// - Return the new head pointer.
// ------------------------------------------------------------
#include "student.h"

struct ListNode* swapPairs(struct ListNode* head) {
      // TODO: implement
      // list not big enough to swap.
    if (head == NULL || head->next == NULL)
        return head;

    //intializing pointers 
    struct ListNode* new = head->next; 
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;

    //loops till there are no pairs left.
    while (curr != NULL && curr->next != NULL) {
       //next pair pointer and second value to swap
        struct ListNode* second = curr->next;
        struct ListNode* next = second->next;

        second->next = curr;
        curr->next = next;

        //for initial value
        if (prev != NULL)
            prev->next = second;


      //moves on to next pair
        prev = curr;
        curr = next;
    }

    return new; // returns switched pairs
}
