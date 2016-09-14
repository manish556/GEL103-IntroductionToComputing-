#include<stdio.h>
#include<string.h>

char arg[50][50];

struct student
    {
        int entry_number;
        char name[100];
        char mobile_no[100];
        float percent;
        struct student* next;
    };

 struct student* first=NULL;
 struct student* last=NULL;

 char arg[50][50];

 void print_details(struct student* p)
{
   printf("%d | %s | %s | %.1f\n",p->entry_number,p->name,p->mobile_no,p->percent);
}

int getarg(char A[100])
{
    int i=-1;
    while(A[i+1]==' ')
        i++;
    int j=-1,k=-1;
    if(A[i+1]!='\0')
    {
        j=0;

        while(A[++i]!='\0')
        {
         if(A[i]!=' ')
             arg[j][++k]=A[i];
         else
          {
             arg[j][++k]='\0';
             while(A[i+1]==' ')
                 i++;
             if(A[i+1]!='\0')
             {
                 j++;
                 k=-1;
             }
          }
        }
    }
  if(A[i-1]!=' ')
        arg[j][++k]='\0';

    return j+1;
}  // fn end

int isnum(char A[50])
{
    int i=-1;
    while(A[++i]!='\0')
    {
        if(!isdigit(A[i]))
          {
            return 0;
          }
    }
    return 1;
}

int isname(char A[50])
{
    int i=-1;
    while(A[++i]!='\0')
    {
        if( !( isupper(A[i])|| islower(A[i]) ) )
        {
            return 0;
        }
    }
    return 1;
}

int isper(char A[50])
{
    int i=-1;
    while(A[++i]!='\0')
    {
        if( !(A[i]=='.' || isdigit(A[i])) )
            return 0;
    }
    return 1;
}

 void do1(int nofarg)
 {
     if( nofarg!=2 || !isnum(arg[1]) )
        printf("OPERATION CANNOT BE PERFORMED\n");
     else
     {
            int eno=atoi(arg[1]);
            struct student* temp=first;
                while(temp!=NULL)
                {
                    if(temp->entry_number==eno)
                    {
                        print_details(temp);
                        return;
                    }
                    temp=temp->next;
                }
                printf("NO SUCH RECORD FOUND\n");
    }
 }  // end of fn

 void do2(int nofarg)
 {
    if( nofarg!=4 || !isname(arg[1]) || !isnum(arg[2]) || !isper(arg[3]) )
        printf("OPERATION CANNOT BE PERFORMED\n");
    else
    {
        int eno;
        if(last!=NULL)
        {
        last->next=(struct student*)malloc(sizeof(struct student));
        eno=last->entry_number;
        last=last->next;
        }
        else
        {
           last=(struct student*)malloc(sizeof(struct student));
           first=last;
           eno=0;
        }
          float per=atoi(arg[3]);
          int z=-1;
          while(arg[3][++z]!='\0')
          {
            if(arg[3][z]=='.')
            {
                 per=per+(float)(arg[3][z+1]-48)/10;
                 break;
            }
          }

        last->entry_number=eno+1;
        strcpy(last->name,arg[1]);
        strcpy(last->mobile_no,arg[2]);
        last->percent=per;
        last->next=NULL;

        printf("RECORD ADDED SUCCESSFULLY\n");
    }

 }   // fn end



void do3(int nofarg)
{
    if( nofarg!=2 || !isnum(arg[1]) )
    {
        printf("OPERATION CANNOT BE PERFORMED\n");
    }
    else
    {
        int eno=atoi(arg[1]);
        if(last==NULL)
            printf("NO SUCH RECORD FOUND\n");
        else if(first->next==NULL)
        {
            if(first->entry_number==eno)
              {
                  first=NULL;
                  last=NULL;
                  printf("RECORD DELETED SUCCESSFULLY\n");
                  return;
              }
        }
        else  // atleast 2 records
        {
           if(first->entry_number==eno)   // if first record match
           {
               first=first->next;
               printf("RECORD DELETED SUCCESSFULLY\n");
               return;
           }
           struct student* temp1=first;
           struct student* temp2=first->next;
           while(temp2->next!=NULL)
           {
               if(temp2->entry_number==eno)
               {
                   temp1->next=temp2->next;
                   printf("RECORD DELETED SUCCESSFULLY\n");
                   return;
               }
               temp1=temp2;
               temp2=temp2->next;
           }
           if(temp2->entry_number==eno)  // if last record match
           {
               last=temp1;
               temp1->next=NULL;
           }

        }
     printf("NO SUCH RECORD FOUND\n");

    }

} // fn end


void do4(int nofarg)
{
    if( nofarg!=5 || !isnum(arg[1]) || !isname(arg[2]) ||!isnum(arg[3]) || !isper(arg[4]) )
    {
        printf("OPERATION CANNOT BE PERFORMED\n");
    }
    else
    {

       int eno=atoi(arg[1]);
       struct student* temp=first;
       while(temp!=NULL)
       {
           if(temp->entry_number==eno)
           {
               float per=atoi(arg[4]);
               int z=-1;
               while(arg[4][++z]!='\0')
               {
                if(arg[4][z]=='.')
                {
                 per=per+(float)(arg[4][z+1]-48)/10;
                 break;
                }
               }

              strcpy(temp->name,arg[2]);
              strcpy(temp->mobile_no,arg[3]);
              temp->percent=per;

              printf("RECORD MODIFIED SUCCESSFULLY\n");

               return;
           } // end of if
           temp=temp->next;
       }
       printf("NO SUCH RECORD FOUND\n");
    }

}  // fn end

void do5(int nofarg)
{
    if(nofarg!=1)
    {
        printf("OPERATION CANNOT BE PERFORMED\n");
    }
    else
    {
        if(first==NULL)
        printf("NO RECORDS\n");
        else
        {
            struct student* temp=first;
            while(temp!=NULL)
            {
                print_details(temp);
                temp=temp->next;
            }
        }
    }
}


int main(int argc, char* argv[])
{
    int i=0;
    while(++i<argc)
    {

        int nofarg=getarg(argv[i]);
        int choice=atoi(argv[i]);
        if(isnum(arg[0]))
        {
             switch(choice)
              {
              case 1:
               do1(nofarg);
               break;
              case 2:
               do2(nofarg);
               break;
              case 3:
               do3(nofarg);
               break;
              case 4:
               do4(nofarg);
               break;
              case 5:
               do5(nofarg);
               break;
              default:
               printf("OPERATION CANNOT BE PERFORMED\n");
              }  //switch end
        }  // if end
        else
        {
            printf("OPERATION CANNOT BE PERFORMED\n");
        }


    }   // while end

    return 0;
}  // main end
