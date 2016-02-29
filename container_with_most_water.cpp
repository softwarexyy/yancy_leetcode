class Solution {
public:
    int maxArea(vector<int>& height) {
        vector<int>::iterator left = height.begin();
        vector<int>::iterator right = height.end()-1;
        int max=0;
        int temp=0;
        while (left != right){
            if (*left < *right){
                temp = (*left) * (right-left);
                left ++;
            }
            else{
                temp = (*right) * (right-left);
                right --;
            }
            max = temp>max ? temp : max;
        }
        return max;
    }
};
