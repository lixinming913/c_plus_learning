/*
 * 字符流中第一个不重复的字符，google第一个不重复的字符为l
 */
 
 
#include<iostream>

using namespace std;

char FirstAppearOnce(char *str)
{
    if(str == NULL)
        return '\0';
    
    const int tableSize = 256;
    unsigned int hashtable[tableSize];
    for(int i = 0; i < tableSize; ++i)
        hashtable[i] = 0;
    
    char *pHashKey = str;
    while(*pHashKey != '\0')
        hashtable[*pHashKey++] += 1;
    
    pHashKey = str;
    while(*pHashKey != '\0') {
        if(hashtable[*pHashKey] ==1)
            return *pHashKey;
        
        pHashKey++;
    }
    
    return '\0';
}


int 
main()
{
    char *s = "fool";
    char first_appear_once = FirstAppearOnce(s);
    
    cout<< first_appear_once << endl;
}