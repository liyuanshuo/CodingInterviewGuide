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
    ListNode* resign1(stack<ListNode*>& nodeStack, ListNode* left,
                      ListNode* right) {
        ListNode* cur = nodeStack.top();
        nodeStack.pop();
        if (left != nullptr) {
            left->next = cur;
        }
        ListNode* next = nullptr;
        while (!nodeStack.empty()) {
            next = nodeStack.top();
            nodeStack.pop();
            cur->next = next;
            cur = next;
        }
        cur->next = right;
        return cur;
    }

    ListNode* reverseKNode(ListNode* head, int k) {
        if (k < 2 || head == nullptr || head->next == nullptr) {
            return head;
        }
        stack<ListNode*> nodeStack;
        ListNode* newHead = head;
        ListNode* cur = head;
        ListNode* pre = nullptr;
        ListNode* next = nullptr;
        while (cur != nullptr) {
            next = cur->next;
            nodeStack.push(cur);
            if (nodeStack.size() == k) {
                pre = resign1(nodeStack, pre, next);
                newHead = newHead == head ? cur : newHead;
            }
            cur = next;
        }
        return newHead;
    }

    void resign(ListNode* left, ListNode* start, ListNode* end,
                ListNode* right) {
        ListNode* pre = start;
        ListNode* cur = start->next;
        ListNode* next = nullptr;
        while (cur != right) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        if (left != nullptr) {
            left->next = end;
        }
        start->next = right;
    }

    ListNode* reverseKNode2(ListNode* head, int k) {
        if (k < 2 || head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* cur = head;
        ListNode* start = nullptr;
        ListNode* pre = nullptr;
        ListNode* next = nullptr;
        int cnt = 1;
        while (cur != nullptr) {
            next = cur->next;
            if (cnt == k) {
                start = pre == nullptr ? head : pre->next;
                head = pre == nullptr ? cur : head;
                resign(pre, start, cur, next);
                pre = start;
                cnt = 0;
            }
            ++cnt;
            cur = next;
        }
        return head;
    }
};