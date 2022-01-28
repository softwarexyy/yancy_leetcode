class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ret;
        int n = nums.size();
        unordered_set<int> exists;
        for (auto& elem : nums) {
            exists.insert(elem);
        }
        for (int i = 1; i <= n; i++) {
            if (exists.count(i) == 0) {
                ret.emplace_back(i);
            }
        }
        return ret;
    }
};
