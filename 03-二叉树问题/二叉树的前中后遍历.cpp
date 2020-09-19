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
    void preOrderRecur(TreeNode* head) {
        if (head == nullptr) {
            return;
        }
        cout << head->val << endl;
        preOrderRecur(head->left);
        preOrderRecur(head->right);
    }

    void inOrderRecur(TreeNode* head) {
        if (head == nullptr) {
            return;
        }
        inOrderRecur(head->left);
        cout << head->val << endl;
        inOrderRecur(head->right);
    }

    void posOrderRecur(TreeNode* head) {
        if (head == nullptr) {
            return;
        }
        posOrderRecur(head->left);
        posOrderRecur(head->right);
        cout << head->val << endl;
    }

    void preOrderUnRecur(TreeNode* head) {
        if (head == nullptr) {
            return;
        }
        stack<TreeNode*> nodeStack;
        nodeStack.push(head);
        while (!nodeStack.empty()) {
            head = nodeStack.top();
            nodeStack.pop();
            cout << head->val << endl;
            if (head->right != nullptr) {
                nodeStack.push(head->right);
            }
            if (head->left != nullptr) {
                nodeStack.push(head->left);
            }
        }
    }

    void inOrderUnRecur(TreeNode* head) {
        if (head == nullptr) {
            return;
        }
        stack<TreeNode*> nodeStack;
        while (!nodeStack.empty() || head != nullptr) {
            if (head != nullptr) {
                nodeStack.push(head);
                head = head->left;
            } else {
                head = nodeStack.top();
                nodeStack.pop();
                cout << head->val << endl;
                head = head->right;
            }
        }
    }

    void posOrderUnRecur1(TreeNode* head) {
        if (head == nullptr) {
            return;
        }
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        s1.push(head);
        while (!s1.empty()) {
            head = s1.top();
            s1.pop();
            s2.push(head);
            if (head->left != nullptr) {
                s1.push(head->left);
            }
            if (head->right != nullptr) {
                s1.push(head->right);
            }
        }
        while (!s2.empty()) {
            cout << s2.top()->val << endl;
            s2.pop();
        }
    }

    void preOrderUnRecur2(TreeNode* head) {
        if (head == nullptr) {
            return;
        }
        stack<TreeNode*> nodeStack;
        nodeStack.push(head);
        TreeNode* cur = nullptr;
        while (!nodeStack.empty()) {
            cur = nodeStack.top();
            if (cur->left != nullptr && head != cur->left &&
                head != cur->right) {
                nodeStack.push(cur->right);
            } else if (cur->right != nullptr && head != cur->right) {
                nodeStack.push(cur->right);
            } else {
                cout << nodeStack.top()->val << endl;
                nodeStack.pop();
                head = cur;
            }
        }
    }
};