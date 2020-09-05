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
    ListNode* addList1(ListNode* head1, ListNode* head2) {
        stack<int> s1;
        stack<int> s2;
        while (head1 != nullptr) {
            s1.push(head1->val);
            head1 = head1->next;
        }
        while (head2 != nullptr) {
            s2.push(head2->val);
            head2 = head2->next;
        }
        int ca = 0;
        int n1 = 0;
        int n2 = 0;
        int n = 0;
        ListNode* node = nullptr;
        ListNode* pre = nullptr;
        while (!s1.empty() || !s2.empty()) {
            if (s1.empty()) {
                n1 = 0;
            } else {
                n1 = s1.top();
                s1.pop();
            }
            if (s2.empty()) {
                n2 = 0;
            } else {
                n2 = s2.top();
                s2.pop();
            }

            n = n1 + n2 + ca;
            pre = node;
            node = new ListNode(n % 10);
            node->next = pre;
            ca = n / 10;
        }
        if (ca == 1) {
            pre = node;
            node = new ListNode(ca);
            node->next = pre;
        }
        return node;
    }

    ListNode* addList2(ListNode* head1, ListNode* head2) {
        head1 = reverseList(head1);
        head2 = reverseList(head2);
        int ca = 0;
        int n1 = 0;
        int n2 = 0;
        int n = 0;
        ListNode* c1 = head1;
        ListNode* c2 = head2;
        ListNode* node = nullptr;
        ListNode* pre = nullptr;
        while (c1 != nullptr || c2 != nullptr) {
            n1 = c1 != nullptr ? c1->val : 0;
            n2 = c2 != nullptr ? c2->val : 0;
            n = n1 + n2 + ca;
            pre = node;
            node = new ListNode(n % 10);
            node->next = pre;
            ca = n / 10;
            c1 = c1 != nullptr ? c1->next : nullptr;
            c2 = c2 != nullptr ? c2->next : nullptr;
        }
        if (ca == 1) {
            pre = node;
            node = new ListNode(ca);
            node->next = pre;
        }
        head1 = reverseList(head1);
        head2 = reverseList(head2);
        return node;
    }

private:
    ListNode* reverseList(ListNode* head) {
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
};