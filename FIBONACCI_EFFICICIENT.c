
#include <stdio.h>

#define N 5000

void add(char num1[], char num2[], char res[])
{
  int carry = 0;
  for (int i = N - 1; i >= 0; i--)
  {
    int digit = (num1[i] - '0') + (num2[i] - '0') + carry;
    res[i] = (digit % 10) + '0';
    carry = digit / 10;
  }
}

void copy(char num1[], char num2[])
{
  for (int i = N - 1; i >= 0; i--)
    num1[i] = num2[i];
}

char fib1[N];
char fib2[N];
char res[N];

int main()
{

  for (int i = 0; i < N; i++)
  {
    fib1[i] = fib2[i] = res[i] = '0';
  }
  fib2[N - 1] = '1';

  int n;
  printf("Enter n\n");
  scanf("%d", &n);

  if (n == 0 || n == 1)
  {
    printf("%d", n );
  }
  else
  {
    for (int i = 2; i <= n; i++)
    {
      add(fib1, fib2, res);
      copy(fib1, fib2);
      copy(fib2, res);
    }

    int start = 0;
    for (int i = 0; i < N; i++)
    {
      if (start == 0 && res[i] == '0')
        continue;

      if (start == 0 && res[i] != '0')
        start = 1;
      printf("%c", res[i]);
    }
    printf("\n");
  }
  return 0;
}
