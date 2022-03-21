#include <stdio.h>
int DAY = 3; // first day of current year, Wed for 1969, sunday=0
int month_days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int weeks[54][3] = {0}; // weeks[0]: weeknum; [1]: brithnum, [2]: boynum
int weekdate[4];        // 某个周的起止日期[m1, d1, m2, d2]

int runyear(int year)
{
    if (
        ((year % 4 == 0) && (year % 100 != 0)) || year % 400 == 0)
        return 1;
    else
        return 0;
}

// 日期转为week数
int date2week(int m, int d)
{
    int days = month_days[m - 1] + d; // 日期为本年第几天
    if (days <= (7 - DAY))            // 比第一周天数后还小， 则为第0周
        return 0;
    else
        return (days - (7 - DAY) + 6) / 7; //除以7向上取整
    // round up: https://stackoverflow.com/questions/2745074/fast-ceiling-of-an-integer-division-in-c-c
}

// week数转为日期
void week2date(int w)
{
    int days; // 这周第一天为本年第几天
    if (w == 0)
        days = 1;
    else
        days = (7 - DAY) + 1 + (w - 1) * 7;

    int i = 1;
    while (month_days[i] < days)
        i++;
    weekdate[0] = i;
    weekdate[1] = days - month_days[i - 1];

    days = days + 6;
    if (days > month_days[12])
    {
        weekdate[2] = 12;
        weekdate[3] = 31;
    }
    else
    {
        while (month_days[i] <= days)
            i++;
        weekdate[2] = i;
        weekdate[3] = days - month_days[i - 1];
    }
}

void swap(int i, int j) //交换weeks数组的i和j行
{
    int temp;
    int col;
    for (col = 0; col < 3; col++) // 分别交换格列col
    {
        temp = weeks[i][col];
        weeks[i][col] = weeks[j][col];
        weeks[j][col] = temp;
    }
}

int main()
{
    int i, j;

    int year;
    scanf("%d", &year);

    // 计算各月份累积天数
    month_days[2] += runyear(year);
    for (i = 1; i <= 12; i++)
        month_days[i] += month_days[i - 1];

    // 计算本年第一天为周几
    for (i = 1969; i < year; i++)
        DAY += (365 + runyear(i)); // days to 1969.1.1
    DAY = DAY % 7;

    int m, n; // n kids, output top m;
    scanf("%d %d", &n, &m);

    for (i = 0; i < 54; i++)
        weeks[i][0] = i;
    int id, mon, date, sex;
    for (i = 0; i < n; i++)
    {
        scanf("%d %d %d %d", &id, &mon, &date, &sex);
        int weeknum = date2week(mon, date);
        weeks[weeknum][0] = weeknum;
        weeks[weeknum][1]++;
        weeks[weeknum][2] += sex;
    }

    // sorting top m rows
    for (i = 0; i < m; i++)
        for (j = i + 1; j < 54; j++)
            if (weeks[i][1] < weeks[j][1])
                swap(i, j);

    for (i = 0; i < m; i++)
    {
        week2date(weeks[i][0]);
        printf("[%2d.%2d-%2d.%2d]:%d(B%d)\n", weekdate[0], weekdate[1], weekdate[2], weekdate[3], weeks[i][1], weeks[i][2]);
    }
}
