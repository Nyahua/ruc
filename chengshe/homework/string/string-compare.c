#include <stdio.h>

// find the index of char in string
int strIndex(char ch, char str[])
{
    int idx = 0;
    while (str[idx]) // while not eof string '\0'==0==false
    {
        if (ch == str[idx])
        {
            return idx;
        }
        idx++;
    }
    // ch not found
    return -1;
}

// compare chars by strOrder
int charCompare(char ch1, char ch2, char strOrder[])
{
    if (ch1 == ch2) // same chars
    {
        return 0;
    }

    int idx1 = strIndex(ch1, strOrder);
    int idx2 = strIndex(ch2, strOrder);
    if (idx1 < idx2)
    {
        return 1;
    }
    if (idx1 > idx2) // ch2 before ch1
    {
        return -1;
    }
}

// compare strings by strorder
int strCompare(char str1[], char str2[], char strOrder[])
{
    int idx = 0;
    while (str1[idx] && str2[idx]) // while both not eof
    {
        if (str1[idx] == str2[idx]) // continue to next when chars are equal
        {
            idx++;
        }
        else // compare chars when not equal
        {
            return charCompare(str1[idx], str2[idx], strOrder);
        }
    }
    // you get here because one of the string gets end
    if (str1[idx] == '\0')
    {
        if (str2[idx] == '\0') // both get ends
        {
            return 0;
        }
        else // only str1 gets end 
        {
            return 1;
        }
    }
    else // only str2 gets end
    {
        return -1;
    }
}

int main()
{
    char strOrder[] = "ACGT";
    printf("%d\n", strCompare("ACTG", "ACGT", strOrder));

    return 0;
}
