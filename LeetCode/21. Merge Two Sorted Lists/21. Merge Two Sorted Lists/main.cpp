//
//  main.cpp
//  21. Merge Two Sorted Lists
//
//  Created by limaoqi on 01/09/2017.
//  Copyright © 2017 limaoqi. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL && l2 == NULL) return NULL;
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        ListNode *head = NULL;
        if (l1->val <= l2->val) {
            head = l1;
            l1 = l1->next;
        } else {
            head = l2;
            l2 = l2->next;
        }
        ListNode *p = head;
        while (l1 != NULL || l2 != NULL) {
            if (l1 == NULL && l2 != NULL) {
                p->next = l2;
                l2 = l2->next;
            } else if (l2 == NULL && l1 != NULL) {
                p->next = l1;
                l1 = l1->next;
            } else if (l1->val <= l2->val) {
                p->next = l1;
                l1 = l1->next;
            } else if (l1->val > l2->val) {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        return head;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> arr1 = {2};
    vector<int> arr2 = {1};
    ListNode *head1 = new ListNode(arr1[0]), *head2 = new ListNode(arr2[0]);
    ListNode *l1 = head1, *l2 = head2;
    for (int i = 1; i < arr1.size(); ++i) {
        l1->next = new ListNode(arr1[i]);
        l1 = l1->next;
    }
    for (int i = 1; i < arr2.size(); ++i) {
        l2->next = new ListNode(arr2[i]);
        l2 = l2->next;
    }
    Solution().mergeTwoLists(head1, head2);
    return 0;
}
