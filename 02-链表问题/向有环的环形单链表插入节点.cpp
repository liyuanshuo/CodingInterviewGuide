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
    ListNode* insertNum(ListNode* head, int num) {
        ListNode* node = new ListNode(num);
        if (head == nullptr) {
            node->next = node;
            return node;
        }
        ListNode* pre = head;
        ListNode* cur = head->next;
        while (cur != head) {
            if (pre->val <= num && cur->val >= num) {
                break;
            }
            pre = cur;
            cur = cur->next;
        }
        pre->next = node;
        node->next = cur;
        return head->val < num ? head : node;
    }
};