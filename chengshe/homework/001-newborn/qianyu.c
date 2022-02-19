#include <stdio.h>
int years = 0;
int year;
int Jan1;

int ary[1001][3] = {{'\0'}}; //新生儿
int date[14][40];
int baby[10001][10];
int n, m;

int week[60][10] = {{'\0'}}; //第几周的全部信息
int month_days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};//每个月有多少天
int runyear(int i) { //判断每一年是不是闰年，如果闰年年数加以
	if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0))
		return 1;
	else
		return 0;
}
void calendar(int );
void output();
//void quicksort(int [][], int, int);
//int partition(int [][], int, int);
void sort();



int main() {
	scanf("%d", &year);
	calendar(year);
	for (int i = 1; i <= 54; i++) {
		ary[i][0] = i;
	}

	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) {
			scanf("%d", &baby[i][j]);
		}
		int tmp1 = baby[1];
		int tmp2 = baby[2];
		int tmp = date[tmp1][tmp2];
		ary[tmp][1]++;
		tmp = date[tmp1][tmp2];
		ary[tmp][2] += baby[i][4];
	}
	printf("******");
	sort(ary);
	output();

	return 0;
}
void sort();

void calendar(int year) {
	for (int i = 1969; i < year; i++) {
		years += (365 + runyear(i));
	}
	Jan1 = years % 7 + 3;
	if (Jan1 > 7) {
		Jan1 -= 7; //一月一日是周几
	}
	week[0][0] = 1; //0：周开始第一天的月 1：周开始第一天的日 2：周最后一天的月 3:周最后一天的日 4：那一周的baby数
	week[0][1] = 1;
	week[0][2] = 1;
	week[0][3] = 1 + (7 - Jan1);
	for (int i = 1; i < 54; i++) { //把每周的开始结束标出
		week[i][1] = week[i - 1][1] + 7;
		if (week[i][1] > month_days[week[i - 1][0]]) {
			week[i][0] = week[i - 1][0] + 1;
			week[i][1] -= month_days[week[i - 1][0]];
		} else {
			week[i][0] = week[i][1];
		}
		week[i][3] = week[i][1] + 6;
		if (week[i][3] > month_days[week[i - 1][0]]) {
			week[i][2] = week[i][0] + 1;
			week[i][3] -= month_days[week[i - 1][0]];
		}
	}
	for (int i = 1; i < 12; i++) {
		for (int j = 1; j <= month_days[i]; j++) { //算一下哪天是第几周
			for (int k = 1; k < month_days[k]; k++) { //算一下某天前面的月一共有几天
				date[i][j] += month_days[k];
			}
			date[i][j] += j; //算一下某天在这年前面有多少天
			date[i][j] -= 7 - Jan1 + 1; //算一下某天减去第零周有几天
			date[i][j] = (date[i][j] - (date[i][j] % 7)) / 7; //算一下某天是第几周
		}
	}

}

void sort() {
