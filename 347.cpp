class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ret;
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        // 遍历哈希表，取出值为前k大的元素
        // 将哈希表中的元素放入vector
        vector<pair<int, int>> vec;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            vec.push_back({it->first, it->second});
        }
        // 排序
        sort(vec.begin(), vec.end(), [](pair<int, int> p1, pair<int, int> p2){
            return p1.second > p2.second;
        });
        // 取前k个元素
        for (int i = 0; i < k; i++) {
            ret.emplace_back(vec[i].first);
        }

        return ret;
    }
};
