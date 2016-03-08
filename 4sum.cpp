class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int size = nums.size();
        if (size < 4)
            return res;
        sort(nums.begin(), nums.end());
        for (int i=0; i<size; i++){
            if (i!=0 && nums[i]==nums[i-1])
                continue;
            int threeSum = target-nums[i];      // [i+1, end()-1]范围内
                                                // 求出p/q/r
                                                //使得nums[p]+nums[q]+nums[r]=threeSum
            for (int p=i+1; p<size; p++){
                if (p!=i+1 && nums[p]==nums[p-1])   //重复答案,略过
                    continue;
                int q=p+1, r=size-1;
                while (q<r){
                    int sumTmp = nums[p] + nums[q] + nums[r];
                    if(sumTmp<threeSum)
                        q++;
                    else if (sumTmp>threeSum)
                        r--;
                    else{       //get the answer
                        vector<int> resTmp;
                        resTmp.push_back(nums[i]);
                        resTmp.push_back(nums[p]);
                        resTmp.push_back(nums[q]);
                        resTmp.push_back(nums[r]);
                        res.push_back(resTmp);
                        q++;
                        while(nums[q] == nums[q-1])
                            q++;
                    }
                }
            }
        }
        return res;
    }
};
