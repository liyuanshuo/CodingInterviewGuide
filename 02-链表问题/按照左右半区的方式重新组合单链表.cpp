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
    void relocate(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return;
        }
        ListNode* mid = head;
        ListNode* right = head->next;
        while (right->next != nullptr && right->next->next != nullptr) {
            mid = mid->next;
            right = right->next->next;
        }
        right = mid->next;
        mid->next = nullptr;
        mergeLR(head, right);
    }

    void mergeLR(ListNode* left, ListNode* right) {
        ListNode* next = nullptr;
        while (left->next != nullptr) {
            next = right->next;
            right->next = left->next;
            left->next = right;
            left = right->next;
            right = next;
        }
        left->next = right;
    }
};