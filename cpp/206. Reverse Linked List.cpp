//
//  main.cpp
//  206. Reverse Linked List
//
//  Created by limaoqi on 18/10/2017.
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
    // 9ms, AC, literative
    ListNode* reverseList1(ListNode* head) {
        if (head == NULL) return NULL;
        ListNode *pre = NULL;
        while (head != NULL) {
            ListNode *tmp = head->next;
            head->next = pre;
            pre = head;
            head = tmp;
        }
        return pre;
    }
    // 6ms, AC, recursive
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode *p = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return p;
    }
};

int main(int argc, const char * argv[]) {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    Solution().reverseList(head);
    return 0;
}
