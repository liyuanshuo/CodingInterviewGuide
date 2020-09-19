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

vector<string> str_split(string& str, char ch) {
    vector<string> ans;
    string s;
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] == ch && !s.empty()) {
            ans.push_back(s);
            s.clear();
        } else {
            s += str[i];
        }
    }
    return ans;
}

class SolutionByPre {
public:
    string serialByPre(TreeNode* head) {
        if (head == nullptr) {
            return "#!";
        }
        string res = to_string(head->val) + "!";
        res += serialByPre(head->left);
        res += serialByPre(head->right);
        return res;
    }

    TreeNode* reconByPreString(string preStr) {
        vector<string> values = str_split(preStr, '!');
        queue<string> strs;
        for (string val : values) {
            strs.push(val);
        }
        return reconPreOrder(strs);
    }

    TreeNode* reconPreOrder(queue<string>& strs) {
        string val = strs.front();
        strs.pop();
        if (val == "#") {
            return nullptr;
        }
        TreeNode* head = new TreeNode(stoi(val));
        head->left = reconPreOrder(strs);
        head->right = reconPreOrder(strs);
        return head;
    }
};

class SolutionByLevel {
public:
    string serial(TreeNode* head) {
        if (head == nullptr) {
            return "#!";
        }
        string ans = to_string(head->val) + "!";
        queue<TreeNode*> nodes;
        nodes.push(head);
        while (!nodes.empty()) {
            TreeNode* tmp = nodes.front();
            nodes.pop();
            if (tmp->left != nullptr) {
                ans += to_string(tmp->left->val) + "!";
                nodes.push(tmp->left);
            } else {
                ans += "#!";
            }
            if (tmp->right != nullptr) {
                ans += to_string(tmp->right->val) + "!";
                nodes.push(tmp->right);
            } else {
                ans += "#!";
            }
        }
        return ans;
    }

    TreeNode* reconByString(string& str) {
        vector<string> values = str_split(str, '!');
        int idx = 0;
        TreeNode* head = generateNodeByString(values[idx++]);
        queue<TreeNode*> nodes;
        if (head != nullptr) {
            nodes.push(head);
        }
        TreeNode* node = nullptr;
        while (!nodes.empty()) {
            node = nodes.front();
            nodes.pop();
            node->left = generateNodeByString(values[idx++]);
            node->right = generateNodeByString(values[idx++]);
            if (node->left != nullptr) {
                nodes.push(node->left);
            }
            if (node->right != nullptr) {
                nodes.push(node->right);
            }
        }
        return head;
    }

    TreeNode* generateNodeByString(string str) {
        if (str == "#") {
            return nullptr;
        }
        return new TreeNode(stoi(str));
    }
};