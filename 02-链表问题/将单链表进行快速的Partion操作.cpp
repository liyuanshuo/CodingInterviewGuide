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
    void arrPartition(vector<ListNode*> nodeArr, int pivot) {
        int small = -1;
        int big = nodeArr.size();
        int idx = 0;
        while (idx != big) {
            if (nodeArr[idx]->val < pivot) {
                swap(nodeArr[++small], nodeArr[idx++]);
            } else if (nodeArr[idx]->val == pivot) {
                idx++;
            } else {
                swap(nodeArr[--big], nodeArr[idx]);
            }
        }
    }

    ListNode* listPartition1(ListNode* head, int pivot) {
        if (head == nullptr) {
            return head;
        }
        ListNode* cur = head;
        vector<ListNode*> nodeArr;
        int i = 0;
        while (cur != nullptr) {
            ++i;
            nodeArr.push_back(cur);
            cur = cur->next;
        }
        arrPartition(nodeArr, pivot);
        for (int i = 1; i != nodeArr.size(); ++i) {
            nodeArr[i - 1]->next = nodeArr[i];
        }
        nodeArr[i - 1]->next = nullptr;
        return nodeArr[0];
    }

    ListNode* listPartition2(ListNode* head, int pivot) {
        ListNode* smallHead = nullptr;
        ListNode* smallTail = nullptr;
        ListNode* equalHead = nullptr;
        ListNode* equalTail = nullptr;
        ListNode* bigHead = nullptr;
        ListNode* bigTail = nullptr;
        ListNode* next = nullptr;
        while (head != nullptr) {
            next = head->next;
            head->next = nullptr;
            if (head->val < pivot) {
                if (smallHead == nullptr) {
                    smallHead = head;
                } else {
                    smallTail->next = head;
                }
                smallTail = head;
            } else if (head->val == pivot) {
                if (equalHead == nullptr) {
                    equalHead = head;
                } else {
                    equalTail->next = head;
                }
                equalTail = head;
            } else {
                if (bigHead == nullptr) {
                    bigHead = nullptr;
                } else {
                    bigTail->next = head;
                }
                bigTail = head;
            }
            head = next;
        }
        if (smallTail != nullptr) {
            smallTail->next = equalHead;
            equalTail = equalTail == nullptr ? smallTail : equalTail;
        }
        if (equalTail != nullptr) {
            equalTail->next = bigHead;
        }
        return smallHead != nullptr
                    ? smallHead
                    : equalHead != nullptr ? equalHead : bigHead;
    }
};