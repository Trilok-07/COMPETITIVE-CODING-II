class Solution {
public:
    void solve(vector<int>& nums, int index, vector<int>& current,
               vector<vector<int>>& ans) {
        
        ans.push_back(current);

        for (int i = index; i < nums.size(); i++) {
            
            // Skip duplicates
            if (i > index && nums[i] == nums[i - 1])
                continue;

            current.push_back(nums[i]);

            solve(nums, i + 1, current, ans);

            current.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> current;

        // Important: put duplicates together
        sort(nums.begin(), nums.end());

        solve(nums, 0, current, ans);

        return ans;
    }
};