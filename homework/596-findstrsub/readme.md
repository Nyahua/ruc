#596. string(函数提交版）
内存限制：256MiB时间限制：1000 ms标准输入输出
题目类型：传统评测方式：文本比较
上传者： sunh编译环境: cpp
提交记录
题目描述
【问题描述】
给定两个字符串 s1 和 s2，写一个函数来判断 s2 是否包含 s1 的排列。若存在则输出s2中第一次包含s1的某种排列的字符串；若不存在输出false。即s1的排列之一是s2 的子串，并且在s2中最先出现，则输出s1的这个排列。
【输入格式】
2行。
第1行，字符串s1。
第2行，字符串s2。
【输出格式】
1行，若存在则输出符合条件的s1的某个排列，若不存则输出false


【输入样例1】
abc
ecdbacbooo
【输出样例1】
bac

【输入样例2】
aabaabcdefghijkmnlopqrst
eidaabaabcdefghijkmnlopqrsuvtxyz
【输出样例2】
false
【样例说明】
样例1中bac是s1 = "abc"的一个排列，且在s2中最早出现，所以输出bac；acb是s1的另一种排列方式，但是出现在bac之后，所以并非所求。
      样例2中s1="aabaabcdefghijkmnlopqrst"的任何一个排列都不在s2中，所以输出false。
【数据规模】

50%的数据，输入字符串s1的长度≤20
100%的数据，输入的字符串只包含小写字母，两个字符串的长度均不大于200
【说明】
本题为补充函数题，只需补充框架代码缺少部分，核心内容如下：
//需补充的代码
int main()
{
    char s1[220], s2[220];
    char *pRes = NULL;
    scanf("%s%s", s1, s2);
    pRes = checkSubstr(s1, s2); 
    if ( pRes == NULL )
        printf("false ");
    else{
        pRes[strlen(s1)] = '';
        printf("%s", pRes);
    }
    return 0;
}