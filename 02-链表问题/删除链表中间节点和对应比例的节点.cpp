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
    ListNode* removeMidNode(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        if (head->next->next == nullptr) {
            ListNode* dele = head;
            head = head->next;
            free(dele);
            return head;
        }

        ListNode* pre = head;
        ListNode* cur = head->next->next;
        while (cur->next != nullptr && cur->next->next != nullptr) {
            pre = pre->next;
            cur = cur->next->next;
        }
        ListNode* dele = cur->next;
        cur->next = cur->next->next;
        free(dele);
        return head;
    }

    ListNode* removeByRatio(ListNode* head, int a, int b) {
        if (a < 1 || a > b) {
            return head;
        }
        int n = 0;
        ListNode* cur = head;
        while (cur != nullptr) {
            ++n;
            cur = cur->next;
        }
        n = ceil((1.0 * a * n) / b);
        if (n == 1) {
            cur = head;
            head = head->next;
            free(cur);
            return head;
        }
        if (n > 1) {
            cur = head;
            while (--n != 1) {
                cur = cur->next;
            }
            ListNode* dele = cur->next;
            cur->next = cur->next->next;
            free(dele);
        }
        return head;
    }
};