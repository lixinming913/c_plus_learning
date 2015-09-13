/*  输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
 *  使得所有的奇数位于数组的前半部分，所有的偶数位于位于数组
 *  的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
 */
class Solution {
public:
    void reOrderArray(vector<int> &array) {
        if(array.empty())
            return ;
            
        int i, j;
        for(i = 1; i < array.size(); i++) {
        
            if(array[i] % 2 != 0) {
            
                int temp = array[i];
                
                for(j = i-1; j >= 0 && array[j]%2 == 0; j--) {
                    array[j+1] = array[j];
                }
                
                array[j+1] = temp;
            }
        }
    }
};

/*调整数组顺序使奇数位于偶数前面,不关心相对位置是否变化*/

class Solution{
public:
    void reOrderArray(vector<int> &array)
    {
        if(array.empty())
            return ;
        
        int i, j;
        i = 0;
        j = array.size() - 1;
        while(i < j) {
            while((i < j) && array[i] % 2 != 0)
                ++i;
                
            while((i < j) && array[j] % 2 == 0)
                --j;
                
            if(i < j) {
                int temp = array[i];
                array[i]  = array[j];
                array[j]  = temp;
            }
        }
    }
}