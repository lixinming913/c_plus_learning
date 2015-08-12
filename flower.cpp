/**
 *  水仙花数
 *  给定范围，找出范围内所有的水仙花，水仙花数153 = 1*1*1 + 5*5*5 + 3*3*3
 */
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

bool 
isflower(int n)
{
	int sum = 0, num = n;
	while(num > 0) {
		int temp = num %10;
		sum += temp * temp * temp;
		num = num/10;
	}

	if(sum == n)
		return true;
	else
		return false;
}

void 
test(int m, int n)
{
	vector<int> res;
	for(int i = m; i <=n;  i++) {
		if(isflower(i))
			res.push_back(i);
	}

	if(res.empty())
		cout << "no" <<endl;
        
	sort(res.begin(), res.end());
    
	for(vector<int>::iterator iter = res.begin(); iter != res.end(); ++iter)
		cout<< *iter <<' ';
}

int 
main()
{
	int m, n;
    
	while(cin>> m>> n ) {
		test(m, n);
		cout<<endl;
	}
    
	return 0;
}