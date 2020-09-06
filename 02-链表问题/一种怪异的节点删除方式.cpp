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
    void deleteNodeWired(ListNode* node) {
        if (node == nullptr || node->next == nullptr) {
            return;
        }
        ListNode* next = node->next;
        node->val = next->val;
        node->next = next->next;
        delete (next);
    }
};