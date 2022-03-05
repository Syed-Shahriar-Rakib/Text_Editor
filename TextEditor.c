#include<stdio.h>
#include<conio.h>
#include<process.h>
int ec;
char fn[20],c;
FILE *fp1;
void Create();
void Edit();
void Delete();
void Display();

void main()
{
 while(1)
{
  system("cls");
  printf("\n\t\t***** WELCOME TO TEXT EDITOR *****");
  printf("\n\n\tMENU:\n\t-----\n ");
  printf("\n\t1.CREATE\n\t2.DISPLAY\n\t3.EDIT\n\t4.DELETE\n\t5.EXIT\n");
  printf("\n\tEnter your choice : ");
  scanf("%d",&ec);
  switch(ec)
  {
   case 1:
     Create();
     break;
   case 2:
     Display();
     break;
   case 3:
     Edit();
     break;
   case 4:
     Delete();
     break;
   case 5:
     printf("\n\tThank you for using 'Text Editor'\n\tpress any key to exit");
     getch();
     exit(0);
   default :
    printf("\n\n\tYour input choice is incorrect. \n\tPress any key to continue and input your choice again.  ");
    getch();
  }
 }
}


void Create()
{
    printf("\n\tEnter your new filename where your text will be save : ");
    scanf("%s",fn);
    fp1=fopen(fn,"r");
    if(fp1==NULL)
    {
        fclose(fp1);
        fp1=fopen(fn,"w");
    printf("\n\tType the text and press 'Ctrl+S' to save\n\n\t");
     while(1)
    {
     c=getch();
    if(c==19)
        {fclose(fp1);
        printf("\n\n\n\tPress any key to continue....");
        getch();
        break;}
    if(c==13)
    {
        c='\n';
        printf("\n\t");
        fputc(c,fp1);
   }
   else
   {
        printf("%c",c);
        fputc(c,fp1);

    }
   }}
   else
    {
        printf("\n\n\tYour file is already create. Please input another file name or edit it. \n\tThank you.\n\n\tPress any key to continue...");
        getch();}

}




void Display()
{
  printf("\n\tEnter the file name: ");
  scanf("%s",fn);
  fp1=fopen(fn,"r");
  if(fp1==NULL)
  {
   printf("\n\tFile not found!");
   goto last ;
  }
  printf("\n\n");
  while(!feof(fp1))
  {
   c=getc(fp1);
   printf("%c",c);
  }
  printf("\n\n");
last :
  fclose(fp1);
  printf("\n\n\tPress any key to continue...");
  getch();
}





void Delete()
{
  printf("\n\tEnter the file name: ");
  scanf("%s",fn);
  fp1=fopen(fn,"r");
  if(fp1==NULL)
  {
   printf("\n\tFile not found!");
   goto last1;
  }
  fclose(fp1);
  if(remove(fn)==0)
  {
   printf("\n\n\tFile has been deleted successfully!");
   goto last1;
  }
  else
   printf("\n\tError!\n");
last1:
    printf("\n\n\tPress any key to continue...");
  getch();
}





void Edit()
{
  printf("\n\tEnter the file name: ");
  scanf("%s",fn);
  fp1=fopen(fn,"r");
  if(fp1==NULL)
  {
   printf("\n\tFile not found!");
   goto last2;
  }
  while(!feof(fp1))
  {
   c=getc(fp1);
   printf("%c",c);
  }
  fclose(fp1);
  printf("\n\tType the text and press 'Ctrl+S' to append.\n");
  fp1=fopen(fn,"a");
  while(1)
  {
   c=getch();
   if(c==19)
    goto last2;
   if(c==13)
   {
    c='\n';
    printf("\n\t");
    fputc(c,fp1);
   }
   else
   {
    printf("%c",c);
    fputc(c,fp1);
   }
  }
last2:
    fclose(fp1);
  getch();
}
