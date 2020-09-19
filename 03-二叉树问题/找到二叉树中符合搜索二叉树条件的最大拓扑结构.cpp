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
    bool isBSTNode(TreeNode* head, TreeNode* n, int val) {
        if (head == nullptr) {
            return false;
        }
        if (head == n) {
            return true;
        }
        return isBSTNode(head->val > val ? head->left : head->right, n, val);
    }

    int maxTopo(TreeNode* head, TreeNode* n) {
        if (head != nullptr && n != nullptr && isBSTNode(head, n, n->val)) {
            return maxTopo(head, n->left) + maxTopo(head, head->right) + 1;
        }
        return 0;
    }
    int bstTopSize1(TreeNode* head) {
        if (head == nullptr) {
            return 0;
        }
        int _max = maxTopo(head, head);
        _max = max(bstTopSize1(head->left), _max);
        _max = max(bstTopSize1(head->right), _max);
        return _max;
    }
};

class Solution2 {
public:
    
};
