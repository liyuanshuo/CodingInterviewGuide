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
private:
    int getLive(int i, int m) {
        if (i == 1) {
            return 1;
        }
        return (getLive(i - 1, m) + m - 1) % i + 1;
    }

public:
    ListNode* josephusKill(ListNode* head, int m) {
        if (head == nullptr || head->next == head || m < 1) {
            return head;
        }
        ListNode* last = head;
        while (last->next != head) {
            last = last->next;
        }
        int cnt = 0;
        while (head != last) {
            ListNode* dele = nullptr;
            if (++cnt == m) {
                dele = head;
                last->next = head->next;
                cnt = 0;
            } else {
                last = last->next;
            }
            head = head->next;
            free(dele);
        }
        return head;
    }

    ListNode* josephusKill2(ListNode* head, int m) {
        if (head == nullptr || head->next == head || m < 1) {
            return head;
        }
        ListNode* cur = head->next;
        int tmp = 1;
        while (cur != head) {
            tmp++;
            cur = cur->next;
        }
        tmp = getLive(tmp, m);
        while (--tmp != 0) {
            cur = head;
            head = head->next;
            free(cur);
        }
        head->next = head;
        return head;
    }
};