#include<stdio.h>
#include<stdlib.h>
typedef struct
{
    int id;
    char name[20];
    int sco[3];
}STU;
int sums(STU s1)
{
    int tot=0, i;
    for(i=0; i<3; i++)
    {
        tot+=s1.sco[i];
    }
    return tot;
}
void read(STU *s1)
{
    int i;
    printf("\nEnter student id:");
    scanf("%d", &(s1->id));
    printf("\nEnter student name:");
    scanf("%s", (s1->name));
    printf("\nEnter student mark in q, l, e:");
    for(i=0; i<3; i++)
    {
        scanf("%d", &(s1->sco[i]));
    }
}
void main(int n1, char *arg[])
{
    if(n1!=3)
    {
        printf("\nIncorrect arguements");
        exit(0);
    }
    int n, i, ch;
    FILE *fp;
    int total;
    FILE *fo;
    fp=fopen(arg[1], "r+");
    {
        if(fp==NULL)
        {
           // fclose(fp);
            fp=fopen(arg[1], "w+");
        }
        else
        {
            printf("\nDo you want to use existing data(1) or enter(2)");
            scanf("%d", &ch);
            if(ch==1)
            {
                goto l1;
            }
        }
    }
    STU st[20];
    printf("\nEnter no of students:");
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        read(&(st[i]));
        fwrite(&st[i], sizeof(STU), 1, fp);
    }
    l1:
    fo=fopen(arg[2], "w+");
    fseek(fp, 0, 0);
    for(i=0; i<n; i++)
    {
        fread(&st[i], sizeof(STU), 1, fp);
        total=sums(st[i]);
        fprintf(fo, "%d", total);
    }
}
