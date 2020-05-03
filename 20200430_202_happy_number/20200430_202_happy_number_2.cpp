class Solution {
public:
    bool isHappy(int n) {
        while (n != 4)//当操作到4的时候就进入闭环。
        {
            if (n == 1)
            {
                return true;
            }
            int sum = 0;
            while (n)
            {
                sum += pow(n % 10,2);
                n /= 10;
            }
            n = sum;
        }
        return false;
    }
};