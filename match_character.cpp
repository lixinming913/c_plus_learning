#include<stdio.h>

void sortColors(int* nums, int numsSize) {
    int hash_map[3] = {0, 0, 0};
    
    for(int i = 0; i < numsSize; ++i) {
        ++hash_map[nums[i]];
    }
    
    static int j = 0;
    for(int i = 0; i < 3; ++i) {
        for(int num = hash_map[i]; num != 0; --num, ++j)
            nums[j] = i;
    }
}

void main()
{
	int nums[2] = {0,1};
	sortColors( nums,  2) ;
}