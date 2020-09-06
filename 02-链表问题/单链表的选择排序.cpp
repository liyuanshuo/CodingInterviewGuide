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
    ListNode* getSmallestPreNode(ListNode* head) {
        ListNode* smallPre = nullptr;
        ListNode* small = head;
        ListNode* pre = head;
        ListNode* cur = head->next;
        while (cur != nullptr) {
            if (cur->val < small->val) {
                smallPre = pre;
                small = pre;
            }
            pre = cur;
            cur = cur->next;
        }
        return smallPre;
    }

    ListNode* selectSort(ListNode* head) {
        ListNode* tail = nullptr;
        ListNode* cur = head;
        ListNode* smallPre = nullptr;
        ListNode* small = nullptr;

        while (cur != nullptr) {
            small = cur;
            smallPre = getSmallestPreNode(cur);
            if (smallPre != nullptr) {
                small = smallPre->next;
                smallPre->next = small->next;
            }
            cur = cur == small ? cur->next : cur;
            if (tail == nullptr) {
                head = small;
            } else {
                tail->next = small;
            }
            tail = small;
        }
        return head;
    }
};