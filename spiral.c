/* Enter a number n, It will arrange 1-n in a spiral fashion going outward clockwise */


#include<stdio.h>
#include<math.h>
int main()
{
  int n,z,r=0;
  printf("Enter a number between 1 to 320: ");
  scanf("%d",&n);
  printf("\n");
  while(pow((r=r+2),2)<n);
  int A[r+2][r+2];
  int cond=1,x=1,count=0,temp=1;

/* initialize i and j first */
int i=r/2;
int j=i-1;
A[i][j]=1;
  while(temp<=(r*r))
  {
    if(count==2)
     {count=0; x++;}

    if(cond==1)        //up
       {
         for(z=0;z<x;z++)
           {A[--i][j]=++temp;}
         count++;
         cond=2;
       }
     else if(cond==2)  //rt
       {
         for(z=0;z<x;z++)
           {A[i][++j]=++temp;}
         count++;
         cond=3;
       }
     else if(cond==3)  //dwn
       {
          for(z=0;z<x;z++)
            {A[++i][j]=++temp;}
          count++;
          cond=4;
       }
     else if(cond==4)  //lft
      {
          for(z=0;z<x;z++)
             {A[i][--j]=++temp;}
          count++;
          cond=1;
      }

  }  //end of while

   for(i=0;i<r;i++)
     {
        for(j=0;j<r;j++)
           {
              if(A[i][j]<=n)
                printf("%4d",A[i][j]);
              else printf("    ");
           }
         printf("\n");
     }
}
