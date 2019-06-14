//
//  main.cpp
//  148. Sort List
//
//  Created by Maoqi Li on 2019/6/14.
//  Copyright © 2019 Maoqi Li. All rights reserved.
//

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// insert sort
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* curr = head->next;
        ListNode* curr_prev = head;
        while (curr) {
            ListNode* p = head;
            ListNode* p_prev = NULL;
            while (p != curr) {
                if (p->val <= curr->val) {
                    p_prev = p;
                    p = p->next;
                } else {
                    ListNode* curr_next = curr->next;
                    curr_prev->next = curr_next;
                    curr->next = p;
                    if (p_prev) {
                        p_prev->next = curr;
                    } else {
                        head = curr;
                    }
                    curr = curr_next;
                    break;
                }
            }
            if (p == curr) {
                curr_prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};

class Solution1 {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* prev = NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = NULL;
        ListNode* p1 = sortList(head);
        ListNode* p2 = sortList(slow);
        return mergeList(p1, p2);
    }

    ListNode* mergeList(ListNode* p1, ListNode* p2) {
        ListNode* nl = new ListNode(0);
        ListNode* p = nl;
        while (p1 && p2) {
            if (p1->val <= p2->val) {
                p->next = p1;
                p1 = p1->next;
            } else {
                p->next = p2;
                p2 = p2->next;
            }
            p = p->next;
        }
        if (p1) p->next = p1;
        if (p2) p->next = p2;
        return nl->next;
    }
};

int main(int argc, const char * argv[]) {
    ListNode* p1 = new ListNode(-1);
    ListNode* p2 = new ListNode(5);
    ListNode* p3 = new ListNode(3);
    ListNode* p4 = new ListNode(4);
    ListNode* p5 = new ListNode(0);
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;
    Solution1().sortList(p1);
    return 0;
}
