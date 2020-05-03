class Solution {
public:
    int jump(vector<int>& nums) {
        int curMaxPos = 0;
        int step = 0;
        int target = 0;
        for (int i=0;i<nums.size()-1;i++)//不要包含终点，否则可能多跳一步
        {
            curMaxPos = max(curMaxPos, i+nums[i]);
            //贪心，用这一步的最大解和现在已经能访问的区间比较
            if (i == target)//若已到达上一步可以访问的最大值，则更新下一个目标为当前这步能走到的最大值
            {
                target = curMaxPos;
                step++;
            }
        }
        return step;
    }
};