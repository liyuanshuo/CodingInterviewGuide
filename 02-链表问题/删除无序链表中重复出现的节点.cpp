#include <algorithm>
#include <array>
#include <cmath>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* _next) : val(x), next(_next) {}
};

class Solution {
public:
    void removeRep1(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return;
        }
        unordered_set<int> nodeSet;
        ListNode* pre = head;
        ListNode* cur = head->next;
        nodeSet.insert(head->val);
        while (cur != nullptr) {
            if (nodeSet.find(cur->val) != nodeSet.end()) {
                pre->next = cur->next;
                delete (cur);
            } else {
                nodeSet.insert(cur->val);
                pre = cur;
            }
            cur = pre->next;
        }
    }

    void removeRepNode(ListNode* head) {
        ListNode* cur = head;
        ListNode* pre = nullptr;
        ListNode* next = nullptr;
        while (cur != nullptr) {
            pre = cur;
            next = cur->next;
            while (next != nullptr) {
                if (cur->val == next->val) {
                    pre->next = cur->next;
                    delete (cur);
                } else {
                    pre = next;
                }
                next = pre->next;
            }
            cur = cur->next;
        }
    }
};