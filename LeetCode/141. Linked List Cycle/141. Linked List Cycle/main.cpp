//
//  main.cpp
//  141. Linked List Cycle
//
//  Created by limaoqi on 12/10/2017.
//  Copyright © 2017 limaoqi. All rights reserved.
//

#include <iostream>
#include <set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // 23ms, AC, O(n)
    bool hasCycle(ListNode *head) {
        set<ListNode *> se;
        ListNode *p = head;
        while (p != NULL) {
            if (se.count(p) == 0) {
                se.insert(p);
            } else {
                return true;
            }
            p = p->next;
        }
        return false;
    }
    // 一快一慢双指针
    // 9ms, AC
    bool hasCycle1(ListNode *head) {
        if (head == NULL || head->next == NULL) return false;
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (slow != fast) {
            if (slow == NULL || fast == NULL || fast->next == NULL) return false;
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
