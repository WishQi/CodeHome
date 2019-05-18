//
//  main.cpp
//  24. Swap Nodes in Pairs
//
//  Created by limaoqi on 04/09/2017.
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
    ListNode* swapPairs(ListNode* head) {
        ListNode *proceed = new ListNode(0);
        proceed->next = head;
        ListNode *p = proceed;
        while (p != NULL && p->next != NULL && p->next->next != NULL) {
            ListNode *tmp1 = p->next->next->next;
            ListNode *tmp2 = p->next->next;
            p->next->next->next = p->next;
            p->next->next = tmp1;
            p->next = tmp2;
            p = p->next->next;
        }
        return proceed->next;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> arr = {1, 2, 3, 4};
    ListNode *head = new ListNode(1), *p = head;
    for (int i = 1; i < arr.size(); ++i) {
        p->next = new ListNode(arr[i]);
        p = p->next;
    }
    Solution().swapPairs(head);
    return 0;
}
