//
//  main.cpp
//  AddTwoNumbers
//
//  Created by limaoqi on 18/08/2017.
//  Copyright © 2017 limaoqi. All rights reserved.
//

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p1 = l1, *p2 = l2;
        ListNode *head = new ListNode(p1->val + p2->val);
        ListNode *tail = head;
        p1 = p1->next, p2 = p2->next;
        while (p1 != NULL || p2 != NULL) {
            if (p1 != NULL && p2 != NULL) {
                tail->next = new ListNode(p1->val + p2->val);
                p1 = p1->next;
                p2 = p2->next;
            } else if (p1 != NULL && p2 == NULL) {
                tail->next = new ListNode(p1->val);
                p1 = p1->next;
            } else if (p2 != NULL && p1 == NULL) {
                tail->next = new ListNode(p2->val);
                p2 = p2->next;
            }
            tail = tail->next;
        }
        ListNode *p = head;
        bool carry = false;
        while (p != NULL) {
            if (carry) {
                p->val += 1;
            }
            if (p->val >= 10) {
                p->val %= 10;
                carry = true;
            } else {
                carry = false;
            }
            p = p->next;
        }
        if (carry) {
            tail->next = new ListNode(1);
            tail = tail->next;
        }
        return head;
    }
};

int main(int argc, const char * argv[]) {
    ListNode *l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);
//    l1->next->next->next = new ListNode(7);
    
    ListNode *l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);
    
    ListNode *result = Solution().addTwoNumbers(l1, l2);
    while (result != NULL) {
        cout << result->val << " ";
        result = result->next;
    }
    return 0;
}
