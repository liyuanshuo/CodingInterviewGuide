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
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode* _next) : val(x), next(_next) {}
};

class Solution {
public:
    bool isPalindrome1(ListNode* _head) {
        stack<ListNode*> nodeStack;
        ListNode* cur = _head;
        while (cur != nullptr) {
            nodeStack.push(cur);
            cur = cur->next;
        }
        ListNode* head = _head;
        while (head != nullptr) {
            if (head->val != nodeStack.top()->val) {
                return false;
            }
            head = head->next;
            nodeStack.pop();
        }
        return true;
    }

    bool isPalindrome2(ListNode* _head) {
        if (_head == nullptr || _head->next == nullptr) {
            return true;
        }
        ListNode* right = _head->next;
        ListNode* cur = _head;
        while (cur->next != nullptr && cur->next->next != nullptr) {
            right = right->next;
            cur = cur->next->next;
        }
        stack<ListNode*> nodeStack;
        while (right != nullptr) {
            nodeStack.push(right);
            right = right->next;
        }
        ListNode* head = _head;
        while (!nodeStack.empty()) {
            if (head->val != nodeStack.top()->val) {
                return false;
            }
            head = head->next;
            nodeStack.pop();
        }
        return true;
    }

    bool isPalindrome3(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return true;
        }
        ListNode* node1 = head;
        ListNode* node2 = head;
        while (node2->next != nullptr && node2->next->next != nullptr) {
            node1 = node1->next;
            node2 = node2->next->next;
        }
        node2 = node1->next;
        node1->next = nullptr;
        ListNode* node3 = nullptr;
        while (node2 != nullptr) {
            node3 = node2->next;
            node2->next = node1;
            node1 = node2;
            node2 = node3;
        }
        node3 = node1;
        node2 = head;
        bool res = true;
        while (node1 != nullptr && node2 != nullptr) {
            if (node1->val != node2->val) {
                res = false;
                break;
            }
            node1 = node1->next;
            node2 = node2->next;
        }
        node1 = node3->next;
        node3->next = nullptr;
        while (node1 != nullptr) {
            node2 = node1->next;
            node1->next = node3;
            node3 = node1;
            node1 = node2;
        }
        return res;
    }
};