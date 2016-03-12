class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        for (int i=size-2; i>=0; i--){      //从倒数第二位开始
            int x = nums[i];
            int min_bigger = INT_MAX;       //比x大的最小的数
            int k = i;                      //记下min_bigger所在的位置
            bool has_bigger = false;
            for (int j=i; j<size; j++){
                if (nums[j]>x && nums[j]<min_bigger){
                    min_bigger = nums[j];
                    k = j;
                    has_bigger = true;
                }
            }
            if (has_bigger == true){        //能找到
                swap(nums[i], nums[k]);
                vector<int>::iterator i_it = nums.begin()+i+1;
                sort(i_it, nums.end());     //将x后所有的数进行排序
                break;
            }
            if (i==0){
                sort(nums.begin(), nums.end());
            }
        }
    }
};






//方法：
//1.从倒数第二个数开始找，设该数为x； 
//2.将x 与 x后所有的数 进行比较，找一个比x大的但是最接近x的数，将它与x进行交换；如果找不到，就废弃当前的x，使x为前一位的数； 
//3.将x后所有的数进行排序，得出即结果。
//4.如果一直到x处于第一位，在x后都没有比x大的数，那么就将所有的数重新排序，得到的升序就是结果（如 5,4,3,2,1  --->  1,2,3,4,5）
