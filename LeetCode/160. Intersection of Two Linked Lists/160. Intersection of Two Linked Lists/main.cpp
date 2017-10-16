//
//  main.cpp
//  160. Intersection of Two Linked Lists
//
//  Created by limaoqi on 16/10/2017.
//  Copyright © 2017 limaoqi. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    // 39ms, AC, O(m + n), 需要两个辅助数组来存放节点
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        vector<ListNode*> nodes1, nodes2;
        ListNode *p1 = headA, *p2 = headB;
        while (p1 != NULL) {
            nodes1.push_back(p1);
            p1 = p1->next;
        }
        while (p2 != NULL) {
            nodes2.push_back(p2);
            p2 = p2->next;
        }
        if (nodes1.empty() || nodes2.empty()) return NULL;
        reverse(nodes1.begin(), nodes1.end());
        reverse(nodes2.begin(), nodes2.end());
        if (nodes1[0] != nodes2[0]) return NULL;
        for (int i = 1; i < nodes1.size() && i < nodes2.size(); i++) {
            if (nodes1[i] != nodes2[i]) return nodes1[i - 1];
        }
        return nodes1.size() < nodes2.size() ? headA : headB;
    }
    // 49ms, AC, O(m + n), 需要一个辅助集合来存放一个链表的节点
    ListNode *getIntersectionNode1(ListNode *headA, ListNode *headB) {
        set<ListNode*> se;
        ListNode *p1 = headA, *p2 = headB;
        while (p1 != NULL) {
            se.insert(p1);
            p1 = p1->next;
        }
        while (p2 != NULL) {
            if (se.find(p2) != se.end()) return p2;
            p2 = p2->next;
        }
        return NULL;
    }
    // 33ms, AC, 时间复杂度:O(m + n), 空间复杂度：O(1)
    ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return NULL;
        ListNode *p1 = headA, *p2 = headB;
        int iterations = 0;
        while (p1 != p2 && iterations <= 1) {
            if (p1->next == NULL)  {
                iterations++;
                p1 = headB;
            } else {
                p1 = p1->next;
            }
            if (p2->next == NULL) {
                p2 = headA;
            } else {
                p2 = p2->next;
            }
        }
        if (iterations > 1) {
            return NULL;
        } else {
            return p1;
        }
    }
};

int main(int argc, const char * argv[]) {
    ListNode *headA = new ListNode(1);
    ListNode *headB = NULL;
//    ListNode *node = new ListNode(3);
//    headA->next = node;
//    headB->next = node;
    Solution().getIntersectionNode2(headA, headB);
    return 0;
}
