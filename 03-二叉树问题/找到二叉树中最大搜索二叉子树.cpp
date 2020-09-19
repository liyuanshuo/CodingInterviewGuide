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

class ReturnType {
public:
    TreeNode* maxBSTHead;
    int maxBSTSize;
    int minVal;
    int maxVal;
    ReturnType(TreeNode* head, int _size, int _min, int _max) {
        maxBSTHead = head;
        maxBSTSize = _size;
        minVal = _min;
        maxVal = _max;
    }
};

class Solution {
public:
    ReturnType process(TreeNode* head) {
        if (head == nullptr) {
            return ReturnType(nullptr, 0, INT_MAX, INT_MIN);
        }
        ReturnType lData = process(head->left);
        ReturnType rData = process(head->right);
        int _min = min(head->val, min(lData.minVal, rData.minVal));
        int _max = max(head->val, max(lData.maxVal, rData.maxVal));
        int _size = max(lData.maxBSTSize, rData.maxBSTSize);
        TreeNode* _head = lData.maxBSTSize > rData.maxBSTSize
                              ? lData.maxBSTHead
                              : rData.maxBSTHead;
        if (lData.maxBSTHead == head->left && rData.maxBSTHead == head->right &&
            head->val > lData.maxVal && head->val < rData.minVal) {
            _size = lData.maxBSTSize + rData.maxBSTSize + 1;
            _head = head;
        }
        return ReturnType(_head, _size, _min, _max);
    }

    TreeNode* getMaxBST(TreeNode* head) { return process(head).maxBSTHead; }
};