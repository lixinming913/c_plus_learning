/*字符串中最后一个单词的长度*/

#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
	string str;
	vector<string> res;

	while(cin>>str ) 
		res.push_back(str);

	int index = res.size() - 1;
	cout<< res[index].length();

	return 0;
}