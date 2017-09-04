//
//  main.cpp
//  23. Merge k Sorted Lists
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for (auto itr = lists.begin(); itr != lists.end(); ) {
            if (*itr == NULL)
                itr = lists.erase(itr);
            else
                ++itr;
        }
        if (lists.empty()) return NULL;
        vector<int> vals;
        for (int i = 0; i < lists.size() - 1; ++i) {
            if (lists[i] == NULL) continue;
            ListNode *p = lists[i];
            while (p->next != NULL) {
                vals.push_back(p->val);
                p = p->next;
            }
            vals.push_back(p->val);
            p->next = lists[i + 1];
        }
        ListNode *p = lists[(int)lists.size() - 1];
        while (p != NULL) {
            vals.push_back(p->val);
            p = p->next;
        }
        p = lists[0];
        sort(vals.begin(), vals.end());
        for (int i = 0; i < vals.size(); ++i) {
            p->val = vals[i];
            p = p->next;
        }
        return lists[0];
    }
};


int main(int argc, const char * argv[]) {
    ListNode *head1 = new ListNode(0);
    ListNode *head2 = new ListNode(10);
    ListNode *head3 = new ListNode(3);
    ListNode *p1 = head1, *p2 = head2, *p3 = head3;
    vector<int> vals1 = {0, 1, 4, 5, 7, 11, 20};
    vector<int> vals2 = {10, 12, 13, 14, 21};
    vector<int> vals3 = {3, 6, 10, 15, 17, 30};
    for (int i = 1; i < vals1.size(); ++i) {
        p1->next = new ListNode(vals1[i]);
        p1 = p1->next;
    }
    for (int i = 1; i < vals2.size(); ++i) {
        p2->next = new ListNode(vals2[i]);
        p2 = p2->next;
    }
    for (int i = 1; i < vals3.size(); ++i) {
        p3->next = new ListNode(vals3[i]);
        p3 = p3->next;
    }
    vector<ListNode*> data = {head1, head2, head3};
    Solution().mergeKLists(data);
    return 0;
}
