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
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* _left, TreeNode* _right)
        : val(x), left(_left), right(_right) {}
};

class Solution {
public:
    int getMaxLength(TreeNode* head, int sum) {
        unordered_map<int, int> sumMap;
        sumMap[0] = 0;
        return preOrder(head, sum, 0, 1, 0, sumMap);
    }
    int preOrder(TreeNode* head, int sum, int preSum, int level, int maxLen,
                 unordered_map<int, int>& sumMap) {
        if (head == nullptr) {
            return maxLen;
        }
        int curSum = preSum + head->val;
        if (sumMap.find(curSum) == sumMap.end()) {
            sumMap[curSum] = level;
        }
        if (sumMap.find(curSum - sum) != sumMap.end()) {
            maxLen = max(level - sumMap[curSum - sum], maxLen);
        }
        maxLen = preOrder(head->left, sum, curSum, level + 1, maxLen, sumMap);
        maxLen = preOrder(head->right, sum, curSum, level + 1, maxLen, sumMap);
        if (level == sumMap[curSum]) {
            sumMap.erase(sumMap.find(curSum));
        }
        return maxLen;
    }
};