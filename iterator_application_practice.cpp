/*
 *  去掉所有重复的单词
 *  按照单词的长度排序
 *  统计长度等于或者超过6个字符的单词个数
 */
 
 
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

/*当计数器ctr>1时，返回该单词的复数版本*/
string
make_plural(size_t ctr, const string &word, const string & ending)
{
	return (ctr == 1)? word : word+ending;
}


bool 
isShorter(const string &s1, const string &s2)
{
	return s1.size() < s2.size();
}


bool
GT6(const string &s)
{
	return s.size() >= 6;
}

int
main()
{
	vector<string> words;
	string next_word;

	while(cin >> next_word) {
		words.push_back(next_word);
	}
    
    /*按字典序排序*/
	sort(words.begin(), words.end());   

    /*将不重复的单词序列放在前面，重复的放在后面*/
	vector<string>::iterator end_unique = 
		unique(words.begin(), words.end()); 
        
    /*删除重复的单词*/
	words.erase(end_unique, words.end());          
    
    /*按照单词长度排序，长度相等的按字典序排序*/
	stable_sort(words.begin(), words.end(), isShorter);
    
    /*如果范围内的元素符合第三个谓词函数则计数*/
	vector<string>::size_type wc = count_if(words.begin(), words.end(), GT6);

	cout<<wc<<" "<<make_plural(wc, "word", "s")
		  <<" 6 characters or longer" << endl;

	return 0;

}