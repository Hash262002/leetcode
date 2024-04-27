class Solution {
public:
    int findRotateSteps(const string& ring, const string& key) {
        unordered_map<char, vector<int>> positions;
        for (int i = 0; i < ring.size(); ++i) {
            positions[ring[i]].push_back(i);
        }
        vector<vector<int>> memo(key.size(), vector<int>(ring.size(), -1));
        return helper(0, 0, positions, key, ring, memo);
    }
    
    int helper(int keyIndex, int ringPos, unordered_map<char, vector<int>>& positions, const string& key, const string& ring, vector<vector<int>>& memo) {
        if (keyIndex == key.size()) {
            return 0;
        }
        if (memo[keyIndex][ringPos] != -1) {
            return memo[keyIndex][ringPos];
        }
        int minSteps = INT_MAX;
        for (int pos : positions[key[keyIndex]]) {
            int steps;
            if (pos >= ringPos) {
                steps = min(pos - ringPos, static_cast<int>(ringPos + ring.size()) - pos);
            } else {
                steps = min(ringPos - pos, static_cast<int>(pos + ring.size()) - ringPos);
            }
            int nextSteps = helper(keyIndex + 1, pos, positions, key, ring, memo);
            minSteps = min(minSteps, steps + nextSteps);
        }
        memo[keyIndex][ringPos] = minSteps + 1;
        return minSteps + 1;
    }
};