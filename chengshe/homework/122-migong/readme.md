#122. 迷宫
内存限制：256MiB时间限制：1000 ms标准输入输出
题目类型：传统评测方式：文本比较
上传者： sunh
提交记录讨论
题目描述
给定一个由0（表示墙壁）和1（表示道路）的迷宫，请你判断进入迷宫后，仅通过横向和纵向的行走是否能从迷宫中走出来，即能否从坐标（1，1）走到（n，m）。
输入格式
　　共n+1行。
　　第一行为两个数n，m（1≤n，m≤9），表示迷宫的长和宽。
　　第2行到第n+1行，每行m个数，为一个由0和1组成的n*m的矩阵，表示迷宫，其中0表示墙壁（不通），1表示道路（坐标（1，1）和坐标（n，m）处都为1）。

输出格式
　　仅一行。
　　若该迷宫存在从坐标（1，1）到坐标（n，m）的由数字1组成的通路，则输出YES，否则输出NO。

输入样例
5 5
1 1 1 0 1
0 0 1 0 1
1 1 1 1 1
1 0 1 0 0
1 0 1 1 1
输出样例
YES

特殊提示
　　1．只允许横向和纵向的行走，如下图，从（2，2）到（3，3）的行走是不允许的。
　　1 1 0 0
　　0 1 0 0
　　0 0 1 0
　　0 0 1 1
　　2.输入数据保证不含有下图那样的回路。
　　3 4
　　1 1 1 0
　　1 0 1 0
　　1 1 1 1
　　3．好马不吃回头草，好人不走回头路！！！！！（友情提示，请慎重考虑）

7 9
1 0 0 0 0 0 0 0 1
1 0 0 0 0 1 0 1 1
1 1 0 1 1 1 0 1 0
0 1 1 1 0 1 1 1 0
0 1 0 1 0 1 0 0 0
1 1 0 1 1 0 1 1 1
0 0 0 0 1 1 1 0 1
NO