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
    ListNode* merge(ListNode* head1, ListNode* head2) {
        if (head1 == nullptr || head2 == nullptr) {
            return head1 == nullptr ? head2 : head1;
        }
        ListNode* head = head1->val < head2->val ? head1 : head2;
        ListNode* cur1 = head == head1 ? head1 : head2;
        ListNode* cur2 = head == head1 ? head2 : head1;
        ListNode* pre = nullptr;
        ListNode* next = nullptr;
        while (cur1 != nullptr && cur2 != nullptr) {
            if (cur1->val <= cur2->val) {
                pre = cur1;
                cur1 = cur1->next;
            } else {
                next = cur2->next;
                pre->next = cur2;
                cur2->next = cur1;
                pre = cur2;
                cur2 = next;
            }
        }
        pre->next = cur1 == nullptr ? cur2 : cur1;
        return head;
    }
};