class Solution {
public:
    int solver(vector<int>& height, int begin, int end){    //左右两端下标
        if (begin+1 == end){        //元素相邻
            return 0;
        }
        int sum = 0;
        int minbound = height[begin]<height[end] ? height[begin] : height[end];  //tmp取两端较小值
        int maxtmp = 0;             //中间元素的最大值
        int maxcur = begin+1;                 //中间最大值所在的位置
        for (int i=begin+1; i<end; i++){
            if (height[i] > maxtmp){
                maxtmp = height[i];
                maxcur = i;
            }
        }
        if (maxtmp < minbound){          //两端都高，累积水量
            for (int i=begin+1; i<end; i++){
                sum += (minbound-height[i]);
            }
            return sum;
        }
        if (maxtmp >= minbound){         //中间有元素大于或等于两端元素中的一个      
            return (solver(height, begin, maxcur) + solver(height, maxcur, end));
        }
    }
    int trap(vector<int>& height){
        if (height.size()==0 || height.size()==1)
            return 0;
        return solver(height, 0, height.size()-1);
    }
};





//方法：
//      两个指针，分别从左从右开始，往中间靠拢
//          当中间元素都小于两端元素时，能存水，计算存水量，return
//          当中间有元素大于或等于两端元素中的一个时，分别计算左半段和右半段的存水量(递归)
//          当两端元素相邻时，退出递归过程，return
