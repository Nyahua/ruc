#include <stdio.h>

int main() {
int m = 5;
int red, green, blue;
char *remain_str;

// max length of each line: 100*3*6 = 1800
scanf("R %d G %d B %d %1800[^\n]", &red, &green, &blue, remain_str);
printf("%d, %d, %d \n %s\n", red, green, blue, remain_str);
return 0;

}