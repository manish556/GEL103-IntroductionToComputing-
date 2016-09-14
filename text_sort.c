/*
  Sort several text lines of input using merge sort
*/


#include<stdio.h>
#include<string.h>
#include<ctype.h>

int no_of_calls=-1;

int issmaller(char A[15][50],int fh,int sh)
 {
    int i=0,len1=strlen(*(A+fh)),len2=strlen(*(A+sh));
    while(i<len1 && i<len2)
     {
       if( (isdigit(*(*(A+fh)+i))?*(*(A+fh)+i)+100:*(*(A+fh)+i)) < (isdigit(*(*(A+sh)+i))?*(*(A+sh)+i)+100:*(*(A+sh)+i)) )
            return 1;
       if( (isdigit(*(*(A+fh)+i))?*(*(A+fh)+i)+100:*(*(A+fh)+i)) > (isdigit(*(*(A+sh)+i))?*(*(A+sh)+i)+100:*(*(A+sh)+i)) )
            return 0;
        i++;
     }

    if(i==len1)
        return 1;

    return 0;
 }

void merge(char A[15][50], int s, int e)
 {
    int fh,sh,so;
    char temp[15][50];
    fh=s;
    sh=(s+e)/2+1;
    so=s-1;
     while(fh<=(s+e)/2 && sh<=e)
      {
        if(issmaller(A,fh,sh))
          {
             so++;
             strcpy(*(temp+so),*(A+fh));
             fh++;
          }
         else
          {
             so++;
             strcpy(*(temp+so),*(A+sh));
             sh++;
          }
      }
     if(fh<=(s+e)/2)
      {
         while(fh<=(s+e)/2)
          {
             so++;
             strcpy(*(temp+so),*(A+fh));
             fh++;
          }
      }
     else
      {
         while(sh<=e)
          {
             so++;
             strcpy(*(temp+so),*(A+sh));
             sh++;
          }
      }

     int t;
     for(t=s;t<=e;t++)
        strcpy(*(A+t),*(temp+t));

 }

void msort(char A[15][50], int s, int e)
 {
    no_of_calls++;
    if(s<e)
     {
        msort(A,s,(s+e)/2);
        msort(A,(s+e)/2+1,e);

        merge(A,s,e);
     }
 }

int main(int argc,char *argv[])
 {
    int n;
    int i;
    char A[15][50];
    for(i=1;i<argc;i++)
        strcpy(*(A+i-1),*(argv+i));

    msort(A,0,argc-2);

   // printf("Sorted sequence is:\n");

     for(i=0;i<argc-1;i++)
     printf("%s\n",*(A+i));

     printf("%d\n",no_of_calls);

    return 0;
 }
