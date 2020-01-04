#include<stdio.h>
void main()
{
    FILE *f1, *f2, *f3;
    int m, c, n, i, j, ID[20], n4, ID4[4];
    f1=fopen("file1.dat", "r+");
    m=0;
    if(f1==NULL)
    {
        //fclose(f1);
        f1=fopen("file1.dat", "w+");
        m=1;
    }
    if(m==0)
    {
        printf("\nDo you want to enter data(1) or use existing(2) for file 1:");
        scanf("%d", &c);
        if(c==2)
        {
            goto l1;
        }
        else
        {
            fclose(f1);
            f1=fopen("file1.dat", "w+");
        }
    }
    printf("\nEnter no of IDs:");
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        scanf("%d", ID+i);

    }
    fwrite(ID, sizeof(int), n, f1);

    l1:
    f2=fopen("file2.dat", "r+");
    m=0;
    if(f2==NULL)
    {
        //fclose(f2);
        f2=fopen("file2.dat", "w+");
        m=1;
    }
    if(m==0)
    {
        printf("\nDo you want to enter data(1) or use existing(2) for file 2:");
        scanf("%d", &c);
        if(c==2)
        {
            goto l2;
        }
        else
        {
            fclose(f2);
            f2=fopen("file2.dat", "w+");
        }
    }
    printf("\nEnter no of IDs:");
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        scanf("%d", ID+i);

    }
    fwrite(ID, sizeof(int), n, f2);

    l2:
    f3=fopen("file3.dat", "r+");
    m=0;
    if(f3==NULL)
    {
        //fclose(f3);
        f3=fopen("file3.dat", "w+");
        m=1;
    }
    if(m==0)
    {
        printf("\nDo you want to enter data(1) or use existing(2) for file 3:");
        scanf("%d", &c);
        if(c==2)
        {
            goto l3;
        }
        else
        {
            fclose(f3);
            f3=fopen("file3.dat", "w+");
        }
    }
    printf("\nEnter no of IDs:");
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        scanf("%d", ID+i);

    }
    fwrite(ID, sizeof(int), n, f3);

    l3:
    printf("\nProducing final list ...");
    /*Taking data from files*/
    int number;
    fseek(f1, 0, 0);
    n=0;
    while( fread(&ID[n], sizeof(int), 1, f1))
    {
           // printf("(%d)", ID[n]);
            n++;
    }
    fseek(f2, 0, 0);
    while(fread(&ID[n], sizeof(int), 1, f2))
    {

                      //  printf("(%d)", ID[n]);
            n++;
    }
    fseek(f3, 0, 0);
    while(fread(&ID[n], sizeof(int), 1, f3))
    {

                      //  printf("(%d)", ID[n]);
            n++;
    }
    fclose(f1);
    fclose(f2);
    fclose(f3);
    /*Data stored in array*/
    n4=0;
    for(i=0; i<n-1; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(ID[i]>=ID[j])
            {
                m=ID[i];
                ID[i]=ID[j];
                ID[j]=m;
            }
        }
    }

    for(i=0; i<n; i++)
    {
        m=ID[i];
       /* printf("(%d)", m);*/
        n4=0;
        for(j=i; j<n; j++, i++)
        {
            if(ID[j]==m)
            {
                n4++;
         /*       printf("(%d)", n4);*/
            }
            else
                break;
        }
        if(n4>=2)
        {
            printf("%d\n", m);
        }
        i--;
    }
    /*Printing the final list*/
    /*Done*/
}
