//
//  main.cpp
//  142. Linked List Cycle II
//
//  Created by Maoqi Li on 2019/6/12.
//  Copyright © 2019 Maoqi Li. All rights reserved.
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
    ListNode *detectCycle(ListNode *head) {
        if (!head) return NULL;
        if (!head->next) return NULL;
        if (!head->next->next) return NULL;
        ListNode *p1 = head;
        ListNode *p2 = head;
        while (p1->next && p2->next && p2->next->next) {
            p1 = p1->next;
            p2 = p2->next->next;
            if (p1 == p2) break;
        }
        if (p1 != p2) return NULL;
        p1 = head;
        while (p1 != p2) {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    ListNode *p1 = new ListNode(1);
    ListNode *p2 = new ListNode(2);
    p1->next = p2;
    Solution().detectCycle(p1);
    return 0;
}
