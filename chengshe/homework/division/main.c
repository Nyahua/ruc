#include <stdio.h>

int Int, Dec[100], Rem[100]; //Int整数部分，Dec小数部分，Rem余数部分，
int pos; //记录循环节的起始位置

// to check if continue to divide to next
// 根据余数r，商con判断是否已出现循环, q为当前计算到的小数点位数
int findNext(int r, int con, int q)
{
    int i;
    for (i = 0; i < q; i++)
    {
        if (Rem[i] == r && Dec[i] == con) //当余数和商都相等的时候，说明出现循环点
        {
            pos = i; //记录循环点的起始位置
            return 0;
        }
    }
    return 1;
}

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    int r, con; //r临时余数，con临时商
    int p = 0;                           //Dec的[position]
    int q = 0;                           //Rem的[position]
    int e = 0;                           //结束的位置

    Int = a / b; // C语言整数除法只得出整数商
    printf("%d.", Int); // 输出整数部分
    if (a % b == 0)     // 2、 当结果为整数时，记得在输出时输出小数点后一位，即xxx =〉xxx.0
    {
        printf("0\n");
        return 0;  // 商为整数直接退出
    }

    if (a >= b)
    {
        a = a % b;
    }
    con = a * 10 / b; //算出第一组的商
    r = (a * 10) % b; //算出第一组的余数

    int i, j;

    while (findNext(r, con, q))
    {
        Dec[p++] = con;
        Rem[q++] = r;
        //寻找之后的余数和商
        r = r * 10;
        con = r / b;
        r = r % b;
        e++; //小数循环结束的位置
    }

    for (i = 0; i < pos; i++) //输出不循环的部分
    {
        printf("%d", Dec[i]);
    }

    if (Dec[pos] == 0)
    {
        printf("\n");
        return 0;
    }
    printf("("); //从循环点到最后为循环的部分
    for (i = pos; i < e; i++)
    {
        printf("%d", Dec[i]);
    }
    printf(")\n");
    return 0;
}