#199. 网络日志统计
内存限制：256MiB时间限制：1000 ms标准输入输出
题目类型：传统评测方式：文本比较
上传者： sunh
提交记录讨论
题目描述
　现有一份网络日志，里面记录着用户的上线时间和下线时间。
　　请统计：
　　1、至少有一个用户在线的最长时间段的时长。
　　2、自从有用户在线后，没有用户在线的最长时间段的时长。

输入格式
　　第一行只有一个数字N(1 <= n <= 5000)，表明该日志一共有n个用户的记录。
　　接下来的n行，每一行有两个整数a和b(1 <= a, b <= 2000000000)，该用户在[a, b]时间在线。

输出格式
　　输出只有一行，输出需要统计的两个整数，中间以空格隔开。


输入样例
3
300 1000
700 1200
1500 2100

输出样例
900 300
特殊提示
　　样例中，300到1200以及1500到2100，都至少有一个用户在线，其中900是最长的时间段。
　　从300开始，只有1200到1500之间没有任何用户在线，是没有用户在线的最长时间段300。