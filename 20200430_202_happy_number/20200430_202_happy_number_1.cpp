class Solution {
public:
    int separateNum(int n)
{
        int res = 0;
        while (n)
        {
            res += pow(n % 10, 2);
            n /= 10;
        }
        return res;
    }
    bool isHappy(int n) {
        if (n == 1)  return true;//注意细节
        int fast = separateNum(n), slow = n;
        while (fast != slow)
        {
            fast = separateNum(separateNum(fast));//快指针走两倍速度
            if( fast == 1)
                return true;
            slow = separateNum(slow);            
        }
        return false;
    }
};