/*
LeetCode 1: Two Sum

Approach: Hash Map
Time Complexity: O(n)
Space Complexity: O(n)

Explanation:
Store visited numbers in a map.
For each element, check if (target - nums[i]) exists.
If yes, return indices.
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            int comp = target - nums[i];

            if (mp.find(comp) != mp.end()) {
                return {mp[comp], i};
            }

            mp[nums[i]] = i;
        }
        return {};
    }
};
