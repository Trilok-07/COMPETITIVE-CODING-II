
class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();

        unordered_map<int, unordered_set<int>> dp;

        for (int stone : stones) {
            dp[stone] = {};
        }

        dp[0].insert(0);

        for (int i = 0; i < n; i++) {
            int pos = stones[i];

            for (int k : dp[pos]) {

                for (int jump = k - 1; jump <= k + 1; jump++) {

                    if (jump <= 0) continue;

                    int next = pos + jump;

                    if (dp.find(next) != dp.end()) {
                        dp[next].insert(jump);
                    }
                }
            }
        }

        return !dp[stones[n - 1]].empty();
    }
};
