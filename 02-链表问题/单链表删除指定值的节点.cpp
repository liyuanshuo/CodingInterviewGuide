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
    ListNode* removeValue(ListNode* head, int val) {
        deque<ListNode*> nodeQueue;
        while (head != nullptr) {
            if (head->val != val) {
                nodeQueue.push_back(head);
            }
            head = head->next;
        }
        ListNode* ans = new ListNode(-1);
        head = ans;
        while (!nodeQueue.empty()) {
            head->next = nodeQueue.front();
            nodeQueue.pop_front();
            head = head->next;
        }
        head = ans->next;
        delete (ans);
        return head;
    }

    ListNode* removeValue2(ListNode* head, int val) {
        while (head != nullptr) {
            if (head->val != val) {
                break;
            }
            ListNode* tmp = head->next;
            delete (head);
            head = tmp;
        }
        ListNode* pre = head;
        ListNode* cur = head;
        while (cur != nullptr) {
            if (cur->val == val) {
                pre->next = cur->next;
                delete (cur);
            } else {
                pre = cur;
            }
            cur = pre->next;
        }
        return head;
    }
};