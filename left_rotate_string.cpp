/*汇编语言中有一种移位指令叫做循环左移（ROL），
  *现在有个简单的任务，就是用字符串模拟这个指令的
  *运算结果。对于一个给定的字符序列S，请你把其循环左移K位后的序列输出
  */
  
class Solution {
public:
    string LeftRotateString(string str, int n) {
        if(n <= 0 || str.empty())
            return str;
        
        int len = str.length();
        n = n%len;
        str += str;
        
        return str.substr(n, len);
    }
};