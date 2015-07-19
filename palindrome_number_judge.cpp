/*
 *  Palindrome Number 
 *  Example: 12321, yes,; 121, yes;  0, yes; 21,no;  123,no.
 */
 
/* First solution */
class Solution1 {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        if(x == 0)
            return true;
        
        /*if reverse number is still equal with origin number, then it is yes */
        int num = x;
        int reverse_x = 0;
        while(x) {
            reverse_x = reverse_x * 10 + x % 10;
            x /= 10;
        }
        
        if(reverse_x == num)
            return true;
        else 
            return false;
    }
};


/*Second solution*/
class Solution2 {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        
        if(x == 0)
            return true;
        
        /*Judge how much  the number's base is */
        int base = 1;
        while(x / base >= 10) 
            base *= 10;
    
        /*Compare number's left digit and right digit, if equal, yes*/
        while(x) {
            int leftdigit = x / base;
            int rightdigit = x % 10;
            if(leftdigit != rightdigit)
                return false;
        
            x -= leftdigit * base;
            base /= 100;
            x /= 10;
        }
    
        return true;
};