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
    ListNode* getLoopNode(ListNode* head) {
        if (head == nullptr || head->next == nullptr ||
            head->next->next == nullptr) {
            return head;
        }
        ListNode* n1 = head->next;
        ListNode* n2 = head->next->next;
        while (n1 != n2) {
            if (n2->next == nullptr || n2->next->next == nullptr) {
                return nullptr;
            }
            n2 = n2->next->next;
            n1 = n1->next;
        }
        n2 = head;
        while (n1 != n2) {
            n1 = n1->next;
            n2 = n2->next;
        }
        return n1;
    }

    ListNode* noLoop(ListNode* head1, ListNode* head2) {
        if (head1 == nullptr || head2 == nullptr) {
            return nullptr;
        }
        ListNode* cur1 = head1;
        ListNode* cur2 = head2;
        int n = 0;
        while (cur1->next != nullptr) {
            ++n;
            cur1 = cur1->next;
        }
        while (cur2->next != nullptr) {
            n--;
            cur2 = cur2->next;
        }
        if (cur1 != cur2) {
            return nullptr;
        }
        cur1 = n > 0 ? head1 : head2;
        cur2 = cur1 == head1 ? head2 : head1;
        n = abs(n);
        while (n != 0) {
            n--;
            cur1 = cur1->next;
        }
        while (cur1 != cur2) {
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        return cur1;
    }

    ListNode* bothLoop(ListNode* head1, ListNode* loop1, ListNode* head2,
                       ListNode* loop2) {
        ListNode* cur1 = nullptr;
        ListNode* cur2 = nullptr;
        if (loop1->val == loop2->val) {
            cur1 = head1;
            cur2 = head2;
            int n = 0;
            while (cur1 != loop1) {
                ++n;
                cur1 = cur1->next;
            }
            while (cur2 != loop2) {
                --n;
                cur2 = cur2->next;
            }
            cur1 = n > 0 ? head1 : head2;
            cur2 = cur1 == head1 ? head2 : head1;
            n = abs(n);
            while (n != 0) {
                --n;
                cur1 = cur1->next;
            }
            while (cur1 != cur2) {
                cur1 = cur1->next;
                cur2 = cur2->next;
            }
            return cur1;
        } else {
            cur1 = loop1->next;
            while (cur1 != loop1) {
                if (cur1 != loop2) {
                    return loop1;
                }
                cur1 = cur1->next;
            }
            return nullptr;
        }
    }

    ListNode* getIntersectNode(ListNode* head1, ListNode* head2) {
        if (head1 == nullptr || head2 == nullptr) {
            return nullptr;
        }
        ListNode* loop1 = getLoopNode(head1);
        ListNode* loop2 = getLoopNode(head2);
        if (loop1 == nullptr && head2 == nullptr) {
            return noLoop(head1, head2);
        }
        if (loop1 != nullptr && loop2 != nullptr) {
            return bothLoop(head1, loop1, head2, loop2);
        }
        return nullptr;
    }
};