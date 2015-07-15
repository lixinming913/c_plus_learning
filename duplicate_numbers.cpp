/*
 *数组中重复的数字,
 */


#include<iostream>
#include<stdlib.h>
using namespace std;


void swap(int numbers[ ], int i, int j)
{
    int temp;
    
    temp = numbers[i];
    numbers[i] = numbers[j];
    numbers[j] = temp;
}


bool 
duplicate(int numbers[ ], int length, int *duplication, int d_length)
{
    if(numbers == NULL || length <= 0)
        return false;
        
    for(int i = 0; i < length; i++) {
        if(numbers[i] < 0 || numbers[i] > length - 1)
            return false;
    }
    
    for(int i = 0; i < length; i++) {
        while(numbers[i] != i) {
            if(numbers[i] == numbers[numbers[i]]) {
                duplication[d_length++] = numbers[i];
				break;
            }
            
            swap(numbers, i, numbers[i]);
        }
    }

	if(duplication != NULL)
		return true;
	return false;
}


void 
print(int numbers[],int n)
{
    for(int i = 0; i < n; i++)
        cout<<numbers[i]<<endl;
}


void 
main()
{
    int data[ ] = {2,3,1,0,2,5,3};
    int n = 7;
    int *duplication = new int[n];
    int d_length = 0;
    
    if(duplicate(data, n, duplication, d_length))
        print(duplication, d_length);
    else
        cout<<"no duplicate numbers"<<endl;
    
}