#include <stdio.h>
#include <time.h> //실행속도를 측정하기 위한 헤더파일입니다. 이상한거라고 지우면 에러남.

//함수프로토타입선언입니다. 컴파일러마다 다르지만, 이것도 없으면 에러 날 수도 있어요.
int normalMultiplicate(int a, int b);
int bitMultiplicate(int a, int b);
int main()
{
    //a와 b값은 곱하는 값이고, rep은 a*b연산의 실행횟수입니다.
    //a,b,rep값을 조절하면서 갖고 놀아보세요.
   int a = 1000;
   int b = 1000;
   int rep = 3000000;


   //이 밑은 실행코드 입니다.
   time_t bitstart, bitend, normalstart, normalend;
   printf("%d를 %d번 더하는 중...\n",a,b);
   normalstart = time(NULL);
   for (int n = 0; n < rep-1; n++)
   {
       normalMultiplicate(a,b);
   }
   normalend = time(NULL);
   printf("%d를 %d번 더하는 연산을 %d번 반복했을때 걸리는 시간은 %d초입니다.\n",a,b,rep, normalend - normalstart);
   printf("비트시프트를 이용해, %d과 %d를 곱하는 중...\n",a,b);
   bitstart = time(NULL);
   for (int n = 0; n < rep-1; n++)
   {
       bitMultiplicate(a,b);
   }
   bitend = time(NULL);
   printf("반면 같은 연산을 비트시프트로 연산했을 떄는 %d초밖에 걸리지 않죠.\n", bitend - bitstart);
   return 0;
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
