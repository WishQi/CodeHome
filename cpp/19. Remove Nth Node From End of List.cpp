//
//  main.cpp
//  19. Remove Nth Node From End of List
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
    // time exceeds
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL) return head;
        ListNode *p = head;
        vector<ListNode*> arr;
        int length = 0;
        while (p != NULL) {
            ++length;
            arr.push_back(p);
            p = p->next;
        }
        if (length == n) {
            head = head->next;
        } else {
            arr[length - n - 1]->next = arr[length - n + 1];
        }
        return head;
    }
    //思路：维护前后两个指针，间距为n，当后一个指针为NULL的时候，前一个指针到达预期的位置
    ListNode* removeNthFromEnd1(ListNode* head, int n) {
        ListNode *start = new ListNode(0);
        start->next = head;
        ListNode *lo = start, *hi = start;
        for (int i = 0; i <= n; ++i) {
            hi = hi->next;
        }
        while (hi != NULL) {
            lo = lo->next;
            hi = hi->next;
        }
        lo->next = lo->next->next;
        return start->next;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> arr = {1};
    ListNode *head = new ListNode(1);
    ListNode *p = head;
    for (int i = 1; i < arr.size(); ++i) {
        p->next = new ListNode(arr[i]);
        p = p->next;
    }
    Solution().removeNthFromEnd1(head, 1);
    return 0;
}
