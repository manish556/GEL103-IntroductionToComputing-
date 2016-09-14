/*
    This prints diamonds
*/


#include<stdio.h>
main(){
    int n,i,j;
    printf("Enter a number between 0 to 40: ");
    scanf("%d",&n);
 for(i=1;i<2*n;i++)
        for(j=1;j<=2*n;j++)
            j!=2*n?(((i+j==n+1)||(i+j==3*n-1)||(i-j==n-1)||(j-i==n-1))?printf("*"):printf(" ")):printf("\n");
}
