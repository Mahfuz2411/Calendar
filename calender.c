#include<stdio.h>
int space_count(int year)
{
    int y,h=0,d=0;
    y=year;
    if(y>=400)
    {
        y=y%400;
        d=d+0;
        //printf("%d", d);
        if(y%400==0)
            return 6;
    }
    if(y>=300)
    {
        y=y%300;
        d=d+1;
    }
    if(y>=200)
    {
        y=y%200;
        d=d+3;
    }
    if(y>=100)
    {
        y=y%100;
        d=d+5;
        if(y%100==0)
            return 3;
    }
    if(y>=20)
    {
        h=y/20;
        y=y%20;
        d=d+(4*h);
        if(y%20==0)
        {
            d-=1;
            return d;
        }
    }
    switch(y)
    {
    case 19:
        d+=1;
    case 18:
        d+=1;
    case 17:
        d+=1;
    case 16:
        d+=2;
    case 15:
        d+=1;
    case 14:
        d+=1;
    case 13:
        d+=1;
    case 12:
        d+=2;
    case 11:
        d+=1;
    case 10:
        d+=1;
    case 9:
        d+=1;
    case 8:
        d+=2;
    case 7:
        d+=1;
    case 6:
        d+=1;
    case 5:
        d+=1;
    case 4:
        d+=2;
    case 3:
        d+=1;
    case 2:
        d+=1;
    case 1:
        d+=1;
        break;
    }
    d=d%7;
    return d;
}
int print_days(int year, int i)
{
    if(year%400==0||(year%100!=0&&year%4==0))
    {
        int a[]= {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        return a[i];
    }
    else
    {
        int a[]= {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        return a[i];
    }
}
void print_months(int i)
{
    char ch[12][15]= {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    printf("\n\n----------%s----------\n\n", ch[i]);
    return ;
}
void print_calender(int year)
{
    printf("calender of %d \n", year);
    int weekday=0;
    weekday=weekday+space_count(year);
    for(int i=0; i<12; i++)
    {
        //function for months;
        print_months(i);
        //week printing;
        printf("  SUN MON TUE WED THU FRI SAT\n\n");
        //space counter;

        //Day generator;
        int b= print_days(year,i);
        if(weekday>6)
            weekday=weekday%7;
        for(int w=0; w<weekday; w++)
            printf("    ");
        for(int d= 1; d<=b; d++)
        {
            printf("%4d", d);
            if(weekday%7>=6)
                printf("\n");
            weekday++;
        }
    }
    return;
}
int main()
{
    int year;
    printf("Enter your year :");
    scanf("%d", &year);
    //function will apear here;
    print_calender(year);

    printf("\n\n\n");
    return 0;
}



