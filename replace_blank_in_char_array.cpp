/**
 *  替换字符串中的空格成"%20"
 */
 
 void ReplaceBlank(char str[], int length)
 {
    if(str == NULL || length <= 0)
        return ;
        
    int oldlen = 0;
    int blank  = 0;
    int i = 0;
    while(str[i] != '\0') {
        ++oldlen;
        
        if(str[i] == ' ')
            ++blank;
        
        ++i;
    }
    
    int newlen = oldlen + blank*2;
    if(newlen > length)
        return ;
        
    int index1 = oldlen;
    int index2 = newlen;
    while(index1 >= 0 && index1 < index2) {
        if(str[index1] == ' ') {
            str[index2--] = '0';
            str[index2--] = '2';
            str[index2--] = '%';
        } else {
            str[index2--] = str[index1];
        }
        
        --index1;
    }
 }