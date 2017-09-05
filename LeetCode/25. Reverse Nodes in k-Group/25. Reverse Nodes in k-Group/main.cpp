//
//  main.cpp
//  25. Reverse Nodes in k-Group
//
//  Created by limaoqi on 05/09/2017.
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *cur = head;
        int count = 0;
        while (cur != NULL && count != k) {
            cur = cur->next;
            ++count;
        }
        if (count != k) return head;
        cur = reverseKGroup(cur, k);
        while (count > 0) {
            ListNode *tmp = head->next;
            head->next = cur;
            cur = head;
            head = tmp;
            --count;
        }
        return cur;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    ListNode *head = new ListNode(1);
    ListNode *p = head;
    for (int i = 1; i < arr.size(); ++i) {
        p->next = new ListNode(arr[i]);
        p = p->next;
    }
    ListNode *h2 = Solution().reverseKGroup(head, 1);
    return 0;
}
