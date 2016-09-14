/* Hangman game */

#include<stdio.h>
#include<string.h>

int main()
{
    int len;
    char B[20];
    char A[5][20]={"misunderstanding","computer","acknowledgement","chair","blabber"};

    srand(time(NULL));                      // so that rand generates different number each time
    strcpy(B,A[rand()%4]);                  // copies a random word to B
    len=strlen(B);
    char c,ch[20],D[20];                    // ch[] takes input each time while D[] tracks the record of entered words
    int w,correct=0,attempt=10,i,t=0,flag=0;   // attempt keep tracks how many incorrect attempts left
    while (correct!=len)                    // correct keep tracks how many alphabets you have guessed correctly
    {
        if(flag==0)                         // flag is zero first time then print all dashes
          {
            for(i=0;i<len;i++)
                printf("_ ");
            printf("\n");
            flag=1;
          }

            printf("Enter an alphabet(%d incorrect attempts left):",attempt);
            gets(ch);                    // each time input taken in array and first char is used
             c=(ch[0]>='A'&&ch[0]<='Z')?ch[0]-'A'+'a':ch[0];
            // c=ch[0];
            if(ch[0]=='\0')
            {
                printf("Enter atleast one character.\n");
            }
            else if(ch[1]!='\0')                   // if we enter more than 1 char it displays error
            {
               printf("Enter only one character at a time.\n");
            }
            else if(!((ch[0]>='A'&&ch[0]<='Z')||(ch[0]>='a'&&ch[0]<='z')))
            {
               printf("Enter only alphabets.\n");
            }
           else
            {
              for(i=0;i<t;i++)
               {
                  if(D[i]==c)        // if we enter a char again
                   {
                      printf("you have entered this char before, enter another one:\n");
                      break;
                   }
               }
              if(i==t)       // if we enter a new char keep it in D
               {
                 D[t]=c;
                 t++;                     // t keep tracks of how many char in D


                 for(w=0;w<len;w++)
                  {
                   if(B[w]==c)              // if entered char is there in word
                    {
                      printf("correct attempt.\n");
                      break;
                    }
                  }
                 if(w==len)                 // if entered char is not present in word
                  {
                   printf("wrong attempt.\n");
                   attempt--;
                  }

                }
             }

               int p,q;
               correct=0;              // keeps track of how many char guessed correctly after each guessing
               printf("\n");
               for(p=0;p<len;p++)      // this loop prints the status of word guessed after each guessing
                {
                 for(q=0;q<t;q++)
                  {
                   if(D[q]==B[p])
                    {
                      printf("%c ",B[p]);
                      correct++;
                      break;
                    }
                  }
                 if(q==t)
                 printf("_ ");
                }
               printf("\n");

              if(correct==len)
               {
                printf("You win !!!\n");
                break;
               }

              if(attempt==0)                   // if 0 attempts left
               {
                printf("You loose.\n");
                break;
               }
    }      // end of while

  return 0;
}   // end of main
