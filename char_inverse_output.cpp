/*
 * 将字符串反转输出
 */


#include <iostream>
using namespace std;
 
 
void 
main()
{
	char a[50];
	int i=0,j;
	char temp;

	memset(a, 0, sizeof(a)); /*void *memset( void *s, int ch, size_t n) 将s中前n个字节替换为ch并返回s*/
	cin.getline(a, 50, '\n');/*一次读取多个字符，cin.getline(字符指针（char *），字符个数，结束符)*/

	for(i = 0, j = strlen(a) - 1; i < strlen(a) / 2; i++, j--){ 
		temp = a[i];  
		a[i] = a[j];
		a[j] = temp;  
	}
	
	cout << a << endl; 
}