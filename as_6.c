/*struct*/
#include<stdio.h>
#include<time.h>
struct TIME_info
{
        int h;
        int m;
        double s;
};
void read_t(struct TIME_info *a)
{
    printf("\nEnter time in hh::mm::ss format:");
    scanf("%d::%d::%lf", &(a->h), &(a->m), &(a->s));
}
void print_t(struct TIME_info a)
{
    printf("\nTime is %02d::%02d::%02.4lf", a.h, a.m, a.s);
}
struct TIME_info convertTime( double realTime )
{
    struct TIME_info a;
    int w_s=realTime;
    a.h = w_s/3600;
    realTime-=a.h*3600;
    w_s = w_s - (a.h*3600);
    a.m = w_s/60;
    realTime-=a.m*60;
    a.s = realTime;
    return a;
}
struct TIME_info add_Times(struct TIME_info one, struct TIME_info two)
{
    struct TIME_info a;
    a.s=one.s+two.s;
    int ss;
    ss=a.s;
    if(ss>=60)
    {
        ss=ss/60;
        a.s-=(60*ss);
    }
    else
    {
        ss=0;
    }
    a.m=one.m+two.m+ss;
    a.h=one.h+two.h;
    if(a.m>60)
    {
        a.h+=(a.m/60);
        a.m=a.m%60;
    }
    return a;
}
struct TIME_info sub_times(struct TIME_info one, struct TIME_info two)
{
    struct TIME_info a;
    if(one.s<two.s)
    {
        one.s+=60;
        one.m-=1;
    }
    a.s=one.s-two.s;
    if(one.m<two.m)
    {
        one.m+=60;
        one.h-=1;
    }
    a.m=one.m-two.m;
    a.h=one.h-two.h;
    return a;
}
void main()
{
    time_t s;
    double second;
    struct tm *cur_time;
    s=time(NULL);
    cur_time=localtime(&s);
    struct TIME_info cur={cur_time->tm_hour, cur_time->tm_min, cur_time->tm_sec};
    printf("\n1.Printing current time after initialisation:\n");
    print_t(cur);
    struct TIME_info t1, t2, t3;
    printf("\n2. Input time:\n");
    read_t(&t1);
    print_t(t1);
    printf("\n3. Converting t in seconds to standard time:\n");
    printf("\nEnter time in seconds:");
    scanf("%lf", &second);
    t1=convertTime(second);
    print_t(t1);
    printf("\n4. Adding 2 times:");
    read_t(&t1);
    read_t(&t2);
    t1 = add_Times(t1, t2);
    print_t(t1);
    printf("\n5. Subtracting 2 times:");
    read_t(&t1);
    read_t(&t2);
    t1 = sub_times(t1, t2);
    print_t(t1);

}
