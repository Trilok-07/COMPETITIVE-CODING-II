class Solution {
public:
    void solve(int n, int k, int start, vector<int>& current,
               vector<vector<int>>& ans) {
        
        // If we have selected k numbers
        if (current.size() == k) {
            ans.push_back(current);
            return;
        }

        // Try numbers from start to n
        for (int i = start; i <= n; i++) {
            
            current.push_back(i);

            // Choose next number after i
            solve(n, k, i + 1, current, ans);

            // Backtrack
            current.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> current;

        solve(n, k, 1, current, ans);

        return ans;
    }
};