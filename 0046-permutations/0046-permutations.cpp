class Solution {
public:
    void solve(vector<int>& nums, vector<int>& current,
               vector<vector<int>>& ans, vector<bool>& used) {
        
        // If current permutation has all elements
        if (current.size() == nums.size()) {
            ans.push_back(current);
            return;
        }

        // Try every element
        for (int i = 0; i < nums.size(); i++) {
            
            // Skip if already used
            if (used[i])
                continue;

            used[i] = true;
            current.push_back(nums[i]);

            solve(nums, current, ans, used);

            // Backtrack
            current.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> current;
        vector<bool> used(nums.size(), false);

        solve(nums, current, ans, used);

        return ans;
    }
};