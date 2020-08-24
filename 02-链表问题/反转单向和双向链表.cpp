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

struct DoubleListNode {
    int val;
    DoubleListNode* next;
    DoubleListNode* last;
    DoubleListNode(int x) : val(x), next(nullptr), last(nullptr) {}
};

class Solution {
public:
    ListNode* reversList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* next = nullptr;
        while (head != nullptr) {
            next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }

    DoubleListNode* reveseDoubleList(DoubleListNode* head) {
        DoubleListNode* pre = nullptr;
        DoubleListNode* next = nullptr;
        while (head != nullptr) {
            next = head->next;
            head->next = pre;
            head->last = next;
            pre = head;
            head = next;
        }
        return pre;
    }
};
