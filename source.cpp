#include <stdio.h>
#include <time.h>

int normalMultiplicate(int a, int b);
int bitMultiplicate(int a, int b);
int main()
{
   int a = 1000; int b = 1000;
   time_t bitstart, bitend, normalstart, normalend;
   printf("%d를 %d번 더하는 중...\n",a,b);
   normalstart = time(NULL);
   for (int n = 0; n < 2999999; n++)
   {
       normalMultiplicate(a,b);
   }
   normalend = time(NULL);
   printf("%d를 %d번 더하는 연산을 30만번 반복했을때 걸리는 시간은 %d초입니다.\n",a,b, normalend - normalstart);
   printf("비트시프트를 이용해, %d와 %d를 곱하는 중...\n",a,b);
   bitstart = time(NULL);
   for (int n = 0; n<2999999; n++)
   {
       bitMultiplicate(a,b);
   }
   bitend = time(NULL);
   printf("반면 같은 연산을 비트시프트로 연산했을 떄는 %d초밖에 걸리지 않죠.\n", bitend - bitstart);
}

int normalMultiplicate(int a, int b)
{
    int temp = a;
   for (int n = 0; n < b-1; n++)
   {
       a = a + temp;
   }
   return a;
}

int bitMultiplicate(int a, int b)
{
    int result = 0;
    int count = 0;
    while (b)
    {
        if (b % 2 == 1)
            result += a << count;
        count++;
        b /= 2;
    }
    return result;
}
