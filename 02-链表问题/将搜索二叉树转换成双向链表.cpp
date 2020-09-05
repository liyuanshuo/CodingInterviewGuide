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
    ListNode* left;
    ListNode* right;
    ListNode(int _val) : val(_val), left(nullptr), right(nullptr) {}
};

struct ReturnType {
    ListNode* start;
    ListNode* end;
    ReturnType(ListNode* _start, ListNode* _end) : start(_start), end(_end) {}
};

class Solution {
public:
    void inOrderToQueue(ListNode* head, deque<ListNode*> nodeQueue) {
        if (head == nullptr) {
            return;
        }
        inOrderToQueue(head->left, nodeQueue);
        nodeQueue.push_back(head);
        inOrderToQueue(head->right, nodeQueue);
    }
    ListNode* convert(ListNode* head) {
        deque<ListNode*> nodeQueue;
        inOrderToQueue(head, nodeQueue);
        if (nodeQueue.empty()) {
            return head;
        }
        head = nodeQueue.front();
        nodeQueue.pop_front();
        ListNode* pre = head;
        pre->left = nullptr;
        ListNode* cur = nullptr;
        while (!nodeQueue.empty()) {
            cur = nodeQueue.front();
            nodeQueue.pop_front();
            pre->right = cur;
            cur->left = pre;
            pre = cur;
        }
        pre->right = nullptr;
        return head;
    }

    // 这种办法会不会存在内存泄漏的问题
    ReturnType* process(ListNode* head) {
        if (head == nullptr) {
            return new ReturnType(nullptr, nullptr);
        }
        ReturnType* leftList = process(head->left);
        ReturnType* rightList = process(head->right);
        if (leftList->end != nullptr) {
            leftList->end->right = head;
        }
        head->left = leftList->end;
        head->right = rightList->start;
        if (rightList->start != nullptr) {
            rightList->start->left = head;
        }
        return new ReturnType(
            leftList->start != nullptr ? leftList->start : head,
            rightList->end != nullptr ? rightList->end : head);
    }
    ListNode* convert2(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        return process(head)->start;
    }
};