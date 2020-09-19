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
    void morris(TreeNode* head) {
        if (head == nullptr) {
            return;
        }
        TreeNode* cur = head;
        TreeNode* mostRight = nullptr;
        while (cur != nullptr) {
            mostRight = cur->left;
            while (mostRight->right != nullptr && mostRight->right != cur) {
                mostRight = mostRight->right;
            }
            if (mostRight->right == nullptr) {
                mostRight->right = cur;
                cur = cur->left;
                continue;
            } else {
                mostRight->right = nullptr;
            }
            cur = cur->right;
        }
    }

    vector<int> morrisPre(TreeNode* head) {
        vector<int> ans;
        if (head == nullptr) {
            return ans;
        }
        TreeNode* cur = head;
        TreeNode* mostRight = nullptr;
        while (cur != nullptr) {
            mostRight = cur->left;
            if (mostRight != nullptr) {
                while (mostRight->right != nullptr && mostRight->right != cur) {
                    mostRight = mostRight->right;
                }
                if (mostRight->right == nullptr) {
                    mostRight->right = cur;
                    ans.push_back(cur->val);
                    cur = cur->left;
                    continue;
                } else {
                    mostRight->right = nullptr;
                }
            } else {
                ans.push_back(cur->val);
            }
        }
        return ans;
    }

    vector<int> morrisIn(TreeNode* head) {
        vector<int> ans;
        if (head == nullptr) {
            return ans;
        }
        TreeNode* cur = head;
        TreeNode* mostRight = nullptr;
        while (cur != nullptr) {
            mostRight = cur->left;
            if (mostRight != nullptr) {
                while (mostRight->right != nullptr && mostRight->right != cur) {
                    mostRight = mostRight->right;
                }
                if (mostRight->right == nullptr) {
                    mostRight->right = cur;
                    cur = cur->left;
                    continue;
                } else {
                    mostRight->right = nullptr;
                }
            }
            ans.push_back(cur->val);
            cur = cur->right;
        }
        return ans;
    }

    vector<int> morrisPos(TreeNode* head) {
        vector<int> ans;
        if (head == nullptr) {
            return ans;
        }
        TreeNode* cur = head;
        TreeNode* mostRight = nullptr;
        while (cur != nullptr) {
            mostRight = cur->left;
            if (mostRight != nullptr) {
                while (mostRight->right != nullptr && mostRight->right != cur) {
                    mostRight = mostRight->right;
                }
                if (mostRight->right == nullptr) {
                    mostRight->right = cur;
                    cur = cur->left;
                    continue;
                } else {
                    mostRight->right = nullptr;
                    printEdge(cur->left, ans);
                }
            }
            cur = cur->right;
        }
        printEdge(head, ans);
        return ans;
    }

private:
    TreeNode* reverseEdge(TreeNode* from) {
        TreeNode* pre = nullptr;
        TreeNode* next = nullptr;
        while (from != nullptr) {
            next = from->right;
            from->right = pre;
            pre = from;
            from = next;
        }
        return pre;
    }
    void printEdge(TreeNode* head, vector<int>& ans) {
        TreeNode* tail = reverseEdge(head);
        TreeNode* cur = tail;
        while (cur != nullptr) {
            ans.push_back(cur->val);
            cur = cur->right;
        }
    }
};