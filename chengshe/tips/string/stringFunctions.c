#include <stdio.h>
#include <string.h>

int main()
{

    // to substitute "my" with "your"
    char str[] = "This is my example.";
    char strFind[] = "my";
    char strSub[] = "your";
    

    char *pch; // pointer(address) to the find place
    pch = strstr(str, strFind); 
    printf("string from pch: %s\n", pch);

    /* 
    length of head comes from
    address offset = find adress - first char address
     */
    int lenHead = pch - str; 
    printf("length of head: %d\n", lenHead);

    int lenFind = strlen(strFind);
    char *strTail = pch + lenFind;
    printf("string tail: %s\n", strTail);
    int lenTail = strlen(strTail);
    printf("length of tail: %d\n", lenTail);


    // put head + sub + tail togeter:
    char strDest[100];
    int lenSub = strlen(strSub);
    strcpy(strDest, str);
    strcpy(strDest + lenHead, strSub);
    strcpy(strDest + lenHead + lenSub, strTail);

    printf("%s\n", strDest);

    return 0;
}