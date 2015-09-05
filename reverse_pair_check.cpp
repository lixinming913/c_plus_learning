/*编程题：给定一个文件每一行是字符串，找出所有的逆序对，比如abc和cba是逆序的对*/

#include"iostream"
#include"string"
#define MAX 100
using namespace std;

bool 
check(string str1,string str2)
{
    bool flag = true;
    for(int i=0; i<str1.length(); i++)
    {
        if(str1[i]!=str2[str1.length()-1-i])
        {
            flag = false;
            return flag;
        }
    }
    return flag;
}


int 
main(int argc, char* argv[])
{
    string str[MAX];
    int n,a[MAX];
    bool flag[MAX];
    
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>str[i];
        a[i] = str[i].length();
        flag[i] = true;
    }
    
    int num = 0;
    for(int i=0; i<n; i++)
    {
        int len = a[i];
        if(flag[i]==true)
        {
            for(int j=0;j<n;j++)
            {
                if(flag[j]==true&&len==a[j])
                {
                    if(check(str[i],str[j]))
                    {
                        num++;
                        flag[i] = false;
                        flag[j] = false;
                        break;
                    }
                }
            }
        }
    }
    
    for(int i=0; i<n; i++)
        cout<<str[i]<<'\t';
    cout<<endl;
    cout<<"The Number of Matched String Is: "<<num<<endl;
    getchar();
    getchar();
    
    return 0;
}