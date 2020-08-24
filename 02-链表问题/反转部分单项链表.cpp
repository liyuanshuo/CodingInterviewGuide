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
    ListNode* reversePart(ListNode* head, int from, int to) {
        int len = 0;
        ListNode* node = head;
        ListNode* fPre = nullptr;
        ListNode* tPos = nullptr;

        while (node != nullptr) {
            ++len;
            fPre = len == from - 1 ? node : fPre;
            tPos = len == to + 1 ? node : tPos;
            node = node->next;
        }
        if (from > to || from < 1 || to > len) {
            return head;
        }
        node = fPre == nullptr ? head : fPre->next;
        ListNode* node2 = node->next;
        node->next = tPos;
        ListNode* next = nullptr;
        while (node2 != tPos) {
            next = node2->next;
            node2->next = node;
            node = node2;
            node2 = next;
        }
        if (fPre != nullptr) {
            fPre->next = nullptr;
            return head;
        }
        return node;
    }
};