/*
*/

#include<string.h>
#include<stdio.h>
int check(char A[100],int b1)
{
  int i=-1;
  while(++i<strlen(A))
    if(((A[i]>='0'&&A[i]<='9')?A[i]-'0':A[i]-'A'+10)>=b1)
      return 0;
  return 1;
}
long long int b1todec(char A[100],int b1)
{
   int i=-1;
   long long int num=0;
    while(++i<strlen(A))
        num=num*b1+(A[i]>='0'&&A[i]<='9'?A[i]-'0':A[i]-'A'+10);
    return num;
}
void dectob2(long long int num,int b2)
{
    char A[100];
    int i=-1;
    while(num)
    {
        A[++i]=num%b2<10?num%b2+'0':(num%b2+'A'-10);
        num/=b2;
    }
    while(i>-1)
        printf("%c",A[i--]);
    printf("\n");
}
main()
{
    int b1,b2;
    long long int temp;
    char A[100];
    printf("Enter b1 b2 and the number in base1: ");
   scanf("%d%d%s",&b1,&b2,&A);
   printf("Number in b2: ");
   if(check(A,b1))
    {
       temp=b1todec(A,b1);
       dectob2(temp,b2);
    }
   else
    printf("0\n");
}
