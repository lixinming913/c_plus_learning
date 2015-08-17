/*
 *  二维数组中的查找
 *  在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列按照从上到下递增的顺序排序
 *  函数：bool find(int *matrix, int rows, int columns, int number)
 */

 
bool 
find(int *matrix, int rows, int columns, int number)
{
    bool find = false;
    
    if(matrix != NULL && rows > 0 && columns > 0) {
        int x = 0;
        int y = columns - 1;
        
        while(x < rows && y > 0) {
            if(matrix[x * columns + y] == number) {
                find == true;
                break;
            } 
            else if(matrix[x * columns + y] > number) {
                --y;
            } 
            else
                ++x;
        }
    
    }
    
    return find;
}