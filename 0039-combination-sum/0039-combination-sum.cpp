class Solution {
public:
    void solve(vector<int>& candidates, int target, int start,
               vector<int>& current, vector<vector<int>>& ans) {

        // Target reached
        if (target == 0) {
            ans.push_back(current);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {

            // If current number is greater than target,
            // no need to continue
            if (candidates[i] > target)
                continue;

            current.push_back(candidates[i]);

            // Use i again because the same number
            // can be used unlimited times
            solve(candidates, target - candidates[i], i,
                  current, ans);

            // Backtrack
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> current;

        solve(candidates, target, 0, current, ans);

        return ans;
    }
};
