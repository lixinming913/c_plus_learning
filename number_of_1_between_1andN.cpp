/*整数中1出现的次数（从1到n整数中1出现的次数）*/
class Solution {
public:
    int numberof1(int n)
    {
        int cnt = 0;
        while(n) {
            if(n % 10 == 1)
                cnt++;
            n = n/10;
        }
        
        return cnt;
    }
    int NumberOf1Between1AndN_Solution(int n)
    {
        if(n <= 0)
            return 0;
        
    	int number_1 = 0;
        for(int i = 1; i <= n ; i++)
            number_1 += numberof1(i);
        
        return number_1;
    }
};