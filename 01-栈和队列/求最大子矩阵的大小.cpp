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

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        // Special situation
        if(matrix.size() == 0) {
            return 0;
        }

        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<vector<int>>> dp(row, vector<vector<int>>(col, {0, 0, 0}));

        // Base Case
        if(matrix[0][0] == '1') {
            dp[0][0] = {1, 1, 1};
        }
        int result = dp[0][0][2];
        for (int i = 1; i < col; ++i)
        {
            if(matrix[0][i] == '1') {
                dp[0][i] = {dp[0][i - 1][0] + 1, 1, dp[0][i - 1][2] + 1};
                result = max(result, dp[0][i][2]);
            }
        }
        for (int i = 1; i < row; ++i) {
            if(matrix[i][0] == '1') {
                dp[i][0] = {1, dp[i - 1][0][1] + 1, dp[i - 1][0][2] + 1};
                result = max(result, dp[i][0][2]);
            }
        }

        // Dp operation
        for (int i = 1; i < row; ++i) {
            for (int j = 1; j < col; ++j) {
                if(matrix[i][j] == '1' ) {
                    dp[i][j][0] = dp[i][j - 1][0] + 1;
                    dp[i][j][1] = dp[i - 1][j][1] + 1;
                    int colMin = dp[i][j][0];
                    int heigh = dp[i][j][1];
                    for (int k = 0; k < heigh; ++k) {
                        colMin = min(colMin, dp[i - k][j][0]);
                        dp[i][j][2] = max(dp[i][j][2], colMin * (k + 1));
                    }
                }
                result = max(result, dp[i][j][2]);
            }
        }

        // return Result
        return result;
    }
};