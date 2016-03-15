class Solution {
public:
    void backtracking(vector<vector<int>>& res, vector<int>& candidates, vector<int>& tmp, int target, int index){
        int sum = 0;
        for (int i=0; i<tmp.size(); i++)
            sum += tmp[i];
        
        if (sum == target){
            bool repeat = false;
            for (int i=0; i<res.size(); i++){   //判断是否有重复元组
                if (tmp == res[i]){
                    repeat = true;
                    break;
                }
            }
            if (repeat == false)
                res.push_back(tmp);
        }
        if (sum < target){
            for (int i=index; i<candidates.size(); i++){    //从index开始添加元素
                tmp.push_back(candidates[i]);
                backtracking(res, candidates, tmp, target, i+1);
                tmp.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> tmp;
        backtracking(res, candidates, tmp, target, 0);
        return res;
    }
};






//方法：
//  逐个添加元素，验证已选元素的和sum是否有sum==target
//  如果sum<target 说明还可以添加元素(用递归添加)
//  如果sum==target 说明当前已添加的元素符合条件，纳入结果res中
//  注意：先给candidates排序
