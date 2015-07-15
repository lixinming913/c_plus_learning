/*
 * 正则表达式匹配
 */

 
#include<iostream>
using namespace std;


/*str匹配字符串，match测试字符串*/
bool
matchCore(char *str, char *match)
{
    if(str == NULL || match == NULL)                            /*如果两输入都是空，则判定为不匹配*/
        return false;
    
    if(*str == '\0' && *match == '\0')                        /*str =“\0”, match =“\0”匹配*/
        return true;
        
    if(*str != '\0' && *match == '\0')                          /*如果match都遍历到最后一个字符，但是str还没有遍历完，说明测试字符串不匹配*/
        return false;
    
    if(*(match + 1) == '*') {                                   /*如果当前字符下一个字符为*，表示其前面一个字符可以出现大于等于0次，查询到这时可以略过看下一个字符*/
        if(*match == '.' && *str != '\0' || *match == *str)     /*如果字符匹配，或者当前字符为.表示匹配任意一个字符，并且保证当前字符不是最后一个字符*/
            return matchCore(str + 1, match + 2);             
        else
            return matchCore(str, match + 2);                   /*否则，查询当前匹配字符串当前字符和测试字符串的*字符下一个字符*/
    }
    
            
    if(*match == '.' && *str != '\0' || *match == *str)         /*如果字符匹配，或者当前字符为.表示匹配任意一个字符，并且保证当前字符不是最后一个字符*/
        return matchCore(str + 1, match + 1);
        
    return false;
}


int 
main()
{
    char *match1 = "ab*ac*a";
    char *str = "aaa";
	char *match2 = "a*.a";
    
    bool result = matchCore(str,  match1);
    if(!result)
        cout<< " no match "<<endl;
    else
        cout<< " match " <<endl;
}