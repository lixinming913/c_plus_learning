/*
 *扑克牌的顺子，王设为0，A设为1，K设为13，Q设为12，J设为11
 */
 
 

#include<iostream>
#include<qsort>


/*arg1应该排在arg2前面，返回负数，排在后面，返回正数*/
int
compare(const void *arg1, const void *arg2)
{
    return *(int *)arg1 - *(int *)arg2; 
}


bool 
IsContinuous(int *numbers, int length)
{
    if( numbers == NULL || length < 1)
        return false;
        
    qsort(numbers, length, sizeof(int), compare);
    
    int NumberOfZero = 0;
    int NumberOfGap = 0;
    
    /*统计0的个数*/
    
    for(int i = 0; i < length && numbers[i] == 0; ++i) {
        ++NumberOfZero;
    }
    
    /*统计数组中的间隔，如果大于0的个数，肯定不是顺子*/
    
    int small = NumberOfZero;   /*已排好序，最后一个零的位置就是起始位置*/
    int big = small + 1;
    while(big < length) {
        if(numbers[small] == numbers[big])
            return false;
        
        NumberOfGap += numbers[big] - numbers[small] - 1;
        small = big;
        ++big;
    }
    
    return (NumberOfGap > NumberOfZero) ? false : true;        
}


int 
main()
{
    int data[ ] = {3, 2, 4, 5, 0};
    
    if( IsContinuous(data, 5) ) {
        printf("您抽到的是顺子。\n");
    } else {
        printf("没那么幸运啊！\n");
    }
    
    return 0;
}