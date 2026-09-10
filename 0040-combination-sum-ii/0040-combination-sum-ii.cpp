class Solution {
public:
    vector<vector<int>> result;

    void backtrack(vector<int>& candidates, int target, int start,
                   vector<int>& current) {

        if (target == 0) {
            result.push_back(current);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {

            // Skip duplicates at the same recursion level
            if (i > start && candidates[i] == candidates[i - 1])
                continue;

            // Since array is sorted, no later number can work
            if (candidates[i] > target)
                break;

            // Choose current number
            current.push_back(candidates[i]);

            // i + 1 because each number can be used only once
            backtrack(candidates, target - candidates[i], i + 1, current);

            // Undo choice
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        // Sort for duplicate removal and early stopping
        sort(candidates.begin(), candidates.end());

        vector<int> current;
        backtrack(candidates, target, 0, current);

        return result;
    }
};