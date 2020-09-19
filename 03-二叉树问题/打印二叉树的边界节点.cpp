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
    void printEdge1(TreeNode* head) {
        if (head == nullptr) {
            return;
        }
        int height = getHeight(head, 0);
        vector<vector<TreeNode*>> edgeMap(height, vector<TreeNode*>(2));
        setEdgeMap(head, 0, edgeMap);
        for (int i = 0; i, edgeMap.size(); ++i) {
            cout << edgeMap[i][0]->val << " ";
        }
        printLeafNotInMap(head, 0, edgeMap);
        for (int i = edgeMap.size() - 1; i >= 0; --i) {
            if (edgeMap[i][0] != edgeMap[i][1]) {
                cout << edgeMap[i][1]->val << " ";
            }
        }
    }

    int getHeight(TreeNode* head, int h) {
        if (head == nullptr) {
            return h;
        }
        return max(getHeight(head->left, h + 1), getHeight(head->right, h + 1));
    }

    void setEdgeMap(TreeNode* head, int h, vector<vector<TreeNode*>>& edgeMap) {
        if (head == nullptr) {
            return;
        }
        edgeMap[h][0] = edgeMap[h][0] == nullptr ? head : edgeMap[h][0];
        edgeMap[h][1] = head;
        setEdgeMap(head->left, h + 1, edgeMap);
        setEdgeMap(head->right, h + 1, edgeMap);
    }

    void printLeafNotInMap(TreeNode* head, int h,
                           vector<vector<TreeNode*>>& m) {
        if (head == nullptr) {
            return;
        }
        if (head->left == nullptr && head->right == nullptr &&
            head != m[h][0] && head != m[h][1]) {
            cout << head->val << endl;
        }
        printLeafNotInMap(head->left, h + 1, m);
        printLeafNotInMap(head->right, h + 1, m);
    }

    void printLeftEdge(TreeNode* head, bool print) {
        if (head == nullptr) {
            return;
        }
        if (print || (head->left == nullptr && head->right == nullptr)) {
            cout << head->val << " ";
        }
        printLeftEdge(head->left, print);
        printLeftEdge(head->right,
                      print && head->left == nullptr ? true : false);
    }

    void printRightEdge(TreeNode* head, bool print) {
        if (head == nullptr) {
            return;
        }
        printRightEdge(head->left,
                       print && head->right == nullptr ? true : false);
        printRightEdge(head->right, print);
        if (print || (head->left == nullptr && head->right == nullptr)) {
            cout << head->val << " ";
        }
    }
};