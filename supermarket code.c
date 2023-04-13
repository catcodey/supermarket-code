#include <stdio.h>
#include<string.h>
void switchh();
void star();
void start();
void star2();
int main()
{
    start();
    return 0;
}
void star()
{
    int i;
    for(i=0;i<25;i++)
    {
    printf("*");
    }
}
void start()
{
    int a;
    char cooi;
    FILE *fp6;
    star();
    printf("\n SURYA DEPARTMENTAL STORE\n");
    star();
    printf("\n Items available");
    printf("\n 1. Milk");
    printf("\n 2. Bread");
    printf("\n 3. Vegetables");
    printf("\n 4. Fruits");
    printf("\n 5. Biscuits");
    printf("\n");
    fp6=fopen("textfile.txt","r+");
    while((cooi=fgetc(fp6))!=EOF){  
            printf("%c",cooi);  
        }
    printf("\n enter choice(numbers)");
    
    scanf("%d",&a);
    switchh(a);
    
}
void switchh(int a)
{
   char y[10]; 
   int price,choosefromoption;
   switch(a) 
   {
       case 1:;
       
       
       char ans='y';
       
       while(ans=='y')
       {
           printf("add to cart?:");
           scanf("%s",y);
           if (strcmp(y,"yes")==0)
           {
               price=40;
               ans='n';
               star2(price,a);
               break;
           }
           
           else
           {
               printf("enter valid word\n");
               ans='y';
           }
          
           
       }
       break;
       
       case 2:;
       char ans1='y';
       
       while(ans1=='y')
       {
           printf("add to cart?:");
           scanf("%s",y);
           if (strcmp(y,"yes")==0)
           {
               price=50;
               ans='n';
               star2(price,a);
               break;
           }
           
           else
           {
               printf("enter valid word\n");
               ans='y';
           }
          
           
       }
       break;
       case 3:;
       char ans2='y';
       
       while(ans2=='y')
       {
           printf("enetr which one you wanna choose(only numbers):");
           scanf("%d",&choosefromoption);
           printf("add to cart?:");
           scanf("%s",y);
           if (strcmp(y,"yes")==0)
           {
               switch(choosefromoption)
               {
                   case 1:
                   price=20;
                   ans2='n';
                   star2(price,a);
                   break;
                   
                   case 2:
                   price=40;
                   ans2='n';
                   star2(price,a);
                   break;
                   
                   case 3:
                   price=80;
                   ans2='n';
                   star2(price,a);
                   break;
               }
           }
           
           else
           {
               printf("enter valid word\n");
               ans='y';
           }
          
           
       }
       break;
       case 4:;
       char ans3='y';
       
       while(ans3=='y')
       {
           printf("add to cart?:");
           scanf("%s",y);
           if (strcmp(y,"yes")==0)
           {
               price=100;
               ans='n';
               star2(price,a);
               break;
           }
           
           else
           {
               printf("enter valid word\n");
               ans='y';
           }
          
           
       }
       break;
       case 5:;
       char ans4='y';
       
       while(ans4=='y')
       {
           printf("add to cart?:");
           scanf("%s",y);
           if (strcmp(y,"yes")==0)
           {
               price=55;
               ans='n';
               star2(price,a);
               break;
           }
           
           else
           {
               printf("enter valid word\n");
               ans='y';
           }
          
           
       }
       break;
       default:
       printf("invalid choice");
       
   }
}
void star2(int price,int a)
{
    FILE *fp;
    char sno[10],coo,ch[300],p1[10],p2[10],p3[10];
    static int p=0;
    static int c=0;
    int coupno,discount1;
    static int discount=0;
    char itemname[20];
    char itemnumber[20];
    char disyes[20];
    int noitems;
    char b[10];
    star();
    printf("\n\tSALES PAGE\n");
    star();
    fp=fopen("amm.txt","r+");
    p=p+1;
    fseek(fp, 0, SEEK_END);
    fprintf(fp,"\n");
    fputs("\t\t",fp);
    sprintf(sno,"%d",p);
    fputs(sno,fp);
    fputs("\t",fp);
    printf("\nenter item name:");
    scanf("%s:",itemname);
    printf("\nenter item no:");
    scanf("%s:",itemnumber);
    printf("\nunit price: %d\n",price);
    printf("\nenter no of items needed:");
    fputs(itemnumber,fp);
    fputs("\t",fp);
    fputs(itemname,fp);
    //fprintf(fp,"\n");
    scanf("%d",&noitems);
    c=c+price*noitems;
    //discount=c-(c*(0.2));
    sprintf(p2,"%d",noitems);
    sprintf(p1,"%d",price);
    //sprintf(p3,"%d",discount);
    
    fputs("\t",fp);
    fputs(p2,fp);
    fputs("\t",fp);
    fputs(p1,fp);
    //fputs("\t",fp);
    //fputs(p3,fp);
    printf("apply discount coupon?");
    scanf("%s",disyes);
    if (strcmp(disyes,"yes")==0)
    {
        printf("enetr coupon number(ENTER ONLY ONCE)"); //DISCOUNT COUPON NO:2000
        scanf("%d",&coupno);
        if (coupno==2000)
        {
            printf("successful!!!");
            discount1=price*noitems-(price*noitems*0.2);
            discount=discount+discount1;
            sprintf(p3,"%d",discount1);
            fputs("\t",fp);
            fputs(p3,fp);
        }
        else
        {
            printf("sorry wrong code.goodbye");
        }
    }
    printf("do you want to continue shopping");
    scanf("%s",b);
    if (strcmp(b,"yes")==0)
    {
        fclose(fp);
        start();
    }
    else
    {
        printf("\t\t");
        star();
        printf("\tBILL\t");
        star();
        printf("\n");
        fseek( fp, 0, SEEK_SET ); 
        while((coo=fgetc(fp))!=EOF){  
            printf("%c",coo);  
        }
          
        fclose(fp);
        if (strcmp(disyes,"yes")==0)
        {
            printf("\nsubtotal: %d\n",discount);
        }
        else
        {
            printf("\nsubtotal: %d\n",c);
        }
        printf("Thank you for shopping!!");
    }
    
}
