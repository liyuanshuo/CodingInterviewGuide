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
    vector<int> printCommonPart(ListNode* _head1, ListNode* _head2) {
        ListNode* head1 = _head1;
        ListNode* head2 = _head2;
        vector<int> ans;
        while (head1 != nullptr && head2 != nullptr) {
            if (head1->val < head2->val) {
                head1 = head1->next;
            } else if (head1->val > head2->val) {
                head2 = head2->next;
            } else {
                ans.push_back(head1->val);
                head1 = head1->next;
                head2 = head2->next;
            }
        }
        return ans;
    }
};

int main() { return 0; }