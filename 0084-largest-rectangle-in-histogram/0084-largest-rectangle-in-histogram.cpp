#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int max_area = 0;
        int n = heights.size();
        for (int i = 0; i <= n; i++) {
            int currentHeight = (i == n) ? 0 : heights[i];
            while (!s.empty() && currentHeight < heights[s.top()]) {
                int height = heights[s.top()];
                s.pop();
                int width = s.empty() ? i : i - s.top() - 1;
                max_area = max(max_area, height * width);
            }
            s.push(i);
        }
        return max_area;
    }
};