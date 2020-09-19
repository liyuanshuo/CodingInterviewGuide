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
    void printTree(TreeNode* head) { printInOrder(head, 0, "H", 17); }

    void printInOrder(TreeNode* head, int height, string to, int len) {
        if (head == nullptr) {
            return;
        }
        printInOrder(head->right, height + 1, "v", len);
        string val = to + to_string(head->val) + to;
        int lenM = val.length();
        int lenL = (len - lenM) / 2;
        int lenR = len - lenL - lenM;
        val = getSpace(lenL) + val + getSpace(lenR);
        cout << getSpace(height * len) + val << endl;
        printInOrder(head->left, height + 1, "^", len);
    }

    string getSpace(int num) {
        string space = "";
        for (int i = 0; i < num; ++i) {
            space += ' ';
        }
        return space;
    }
};