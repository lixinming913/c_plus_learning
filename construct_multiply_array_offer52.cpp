/*
 * 给定一个数组A[0,1,...n-1],再构建一个数组B[0,1,...n-1]，其中B的元素为B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...A[n-1]
 */


#include<iostream>
#include<vector>
using namespace std;


void
multiply(vector<int>& array1, vector<int>& array2)
{
    int length1 = array1.size();
    int length2 = array2.size();
    
    if(length1 == length2 && length2 > 1) {
        array2[0] = 1;
        for(int i = 1; i < length1; i++)
            array2[i] = array2[i-1] * array1[i-1];
        
        int temp = 1;
        for(int i = length1 - 2; i >= 0; --i) {
            temp *= array1[i+1];
            array2[i] *= temp;
        }
    }
}


int 
main()
{
    vector<int> A;
    
    for(int i = 1; i < 4; ++i)
        A.push_back(i);
    
    int n = A.size();
    vector<int> B(n);
    
    multiply(A, B);
    
    for(vector<int>::iterator iter = B.begin(); iter != B.end(); ++iter)
        cout<<*iter<<" ";
    cout <<endl;
    
    return 0;
}