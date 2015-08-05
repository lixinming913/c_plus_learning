/*
 *  a[0,mid-1] 和 a[mid, num-1] merge 成 a[0,num-1]
 */
 
 
 #include<iostream>
 using namespace std;
 
 
 void 
 merge(int a[ ], int mid, int n)
 {
    int i = 0;
    int j = mid;
    
    for(; i < n && j < n; ) {
        if(a[i] < a[j]) {
            ++i;
        } else {
            int tmp = a[j];
            int index = j;
            for( ; index > i; --index) {
                a[index] = a[index-1];
            }
            
            a[i] = tmp;
            j++;
            i++;
        }
    }
 }
 
 
 int 
 main()
 {
    int a[] = {1,4,6,7,10,2,3,5,8,9};
    
    merge(a, 5, 10);
    
    for(int i = 0; i < 10; ++i)
        cout<<a[i]<<" ";
    cout<<endl;
    
    return 0;
 }