#include<bits/stdc++.h>
using namespace std;

int space_count(int year){
    int y=year, d=0;
    if(y>=400){
        y%=400;
        if(!(y%400)) return 6;
    }
    if(y>=300){
        y%=300;
        d+=1;
    }
    if(y>=200){
        y%=200;
        d+=3;
    }
    if(y>=100){
        y%=100;
        d+=5;
        if(!(y%100)) return 3;
    }
    if(y>=20){
        d+=(4*y/20);
        y%=20;
        if(!(y%20)) return d-1;
    }
    switch(y){
        case 19: d+=1;
        case 18: d+=1;
        case 17: d+=1;
        case 16: d+=2;
        case 15: d+=1;
        case 14: d+=1;
        case 13: d+=1;
        case 12: d+=2;
        case 11: d+=1;
        case 10: d+=1;
        case 9: d+=1;
        case 8: d+=2;
        case 7: d+=1;
        case 6: d+=1;
        case 5: d+=1;
        case 4: d+=2;
        case 3: d+=1;
        case 2: d+=1;
        case 1: d+=1;
    }
    return d%7;
}
int month_days_count(int year, int i){
    if(!(year%400) or (year%100 and !(year%4))){
        int a[]= {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        return a[i];
    }
    else{
        int a[]= {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        return a[i];
    }
}
void print_months(int i){
    string months[12]= {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    cout<<"\n\n----------"<<months[i]<<"----------\n\n";
    return ;
}
void print_calender(int year) {
    printf("calender of %d \n", year);
    int weekday=0;
    weekday=weekday+space_count(year);
    for(int i=0; i<12; i++){
        //function for months;
        print_months(i);
        //week printing;
        cout<<"  SUN MON TUE WED THU FRI SAT\n\n";
        
        //Day generator;
        int b= month_days_count(year,i);
        if(weekday>6)
            weekday=weekday%7;
        //space counter;
        for(int w=0; w<weekday; w++)
            cout<<"    ";
        for(int d= 1; d<=b; d++){
            cout << setw(4) << d;
            if(weekday%7>=6)
                printf("\n");
            weekday++;
        }
    }
    return;
}
int main() {
    int year;
    cout<<"Enter your year :";
    cin>>year;
    //function will apear here;
    print_calender(year);

    cout<<endl<<endl<<endl;
    return 0;
}