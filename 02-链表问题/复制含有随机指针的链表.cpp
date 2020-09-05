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
    ListNode* random;
    ListNode(int x) : val(x), next(NULL), random(nullptr) {}
    ListNode(int x, ListNode* _next) : val(x), next(_next) {}
};

class Solution {
public:
    ListNode* copyWithRand1(ListNode* head) {
        unordered_map<ListNode*, ListNode*> randMap;
        ListNode* cur = head;
        while (cur != nullptr) {
            randMap[cur] = new ListNode(cur->val);
            cur = cur->next;
        }
        cur = head;
        while (cur != nullptr) {
            randMap[cur]->next = randMap[cur->next];
            randMap[cur]->random = randMap[cur->random];
            cur = cur->next;
        }
        return randMap[head];
    }

    ListNode* copyWithRand2(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        ListNode* cur = head;
        ListNode* next = nullptr;
        while (cur != nullptr) {
            next = cur->next;
            cur->next = new ListNode(cur->val);
            cur->next->next = next;
            cur = next;
        }
        cur = head;
        ListNode* curCopy = nullptr;
        while (cur != nullptr) {
            next = cur->next->next;
            curCopy = cur->next;
            curCopy->random =
                cur->random != nullptr ? cur->random->next : nullptr;
            cur = next;
        }
        ListNode* res = head->next;
        cur = head;
        while (cur != nullptr) {
            next = cur->next->next;
            curCopy = cur->next;
            curCopy->next = next != nullptr ? next->next : nullptr;
            cur = next;
        }
        return res;
    }
};