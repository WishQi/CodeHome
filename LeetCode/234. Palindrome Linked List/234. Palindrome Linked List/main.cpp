//
//  main.cpp
//  234. Palindrome Linked List
//
//  Created by limaoqi on 03/11/2017.
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
    // 23ms, AC, 时间复杂度O(n), 空间复杂度O(n)
    bool isPalindrome(ListNode* head) {
        vector<int> vals;
        while (head != NULL) {
            vals.push_back(head->val);
            head = head->next;
        }
        int len = (int)vals.size();
        for (int i = 0; i < len / 2; i++) {
            if (vals[i] != vals[len - i - 1]) return false;
        }
        return true;
    }
    // 19ms, AC, 时间复杂度O(n), 空间复杂度O(1)
    ListNode* reverseList(ListNode *head) {
        ListNode *pre = NULL;
        while (head != NULL) {
            ListNode *tmp = head->next;
            head->next = pre;
            pre = head;
            head = tmp;
        }
        return pre;
    }
    // 思路：将后半段链表翻转，然后再与前半段逐一比较
    bool isPalindrome1(ListNode* head) {
        if (head == NULL || head->next == NULL) return true;
        ListNode *slow = head, *fast = head;
        while (slow->next != NULL && fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = reverseList(slow->next);
        slow = slow->next;
        while (slow != NULL) {
            if (head->val != slow->val) return false;
            head = head->next;
            slow = slow->next;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    node1->next = node2;
    node2->next = new ListNode(2);
    node2->next->next = new ListNode(1);
    cout << Solution().isPalindrome1(node1) << endl;
    
    return 0;
}
