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
    ListNode* removeLastKNode(ListNode* head, int k) {
        if (head == nullptr || k < 1) {
            return head;
        }
        ListNode* cur = head;
        while (cur != nullptr) {
            --k;
            cur = cur->next;
        }
        if (k == 0) {
            ListNode* del = head;
            head = head->next;
            free(head);
        }
        if (k < 0) {
            cur = head;
            while (++k != 0) {
                cur = cur->next;
            }
            ListNode* del = cur->next;
            cur->next = cur->next->next;
            free(del);
        }
        return head;
    }
};

int main() { return 0; }