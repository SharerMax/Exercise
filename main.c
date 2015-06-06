#include <stdio.h>
/*************
    @description draw a rhombus
    @parameter int l: left position
    @parameter int r: right position
    @parameter int i: level counts
*************/
void rhombus(int l, int r, int i)
{
    if(i <=0)
    {
        return;
    }
    for(int m = 0; m < i; m++)
    {
        if(m == l || m == r)
        {
            printf("*");
        }
        else
        {
            printf(" ");
        }
        if(m+1 == i)
        {
            printf("\n");
        }
    }
    if(l == 0)
    {
        return;
    }
    rhombus(l-1, r+1, i);
    for(int m = 0; m < i; m++)
    {
        if(m == l || m == r)
        {
            printf("*");
        }
        else
        {
            printf(" ");
        }
        if(m+1 == i)
        {
            printf("\n");
        }
    }
}

/*************
    @description output a Rectangle with size N * N in Clockwise
    @parameter int first: first value
    @parameter int n: Rectangle size
*************/
void rect(int first, int n)
{
    int rec[10][10] = {0};
    int r=0;
    int d=0;
    int temp = first-1;
    int temp1 = 0;
    int temp2 = 0;
    int temp3 = 0;
    for(int i=0; i<(n+1)/2; i++)
    {
        for(int j =i; j<n-i; j++)
        {
            r = j;
            rec[d][r] = ++temp;
        }
        temp1 = rec[d][r];
        for(int m=i+1; m<n-i; m++)
        {
            d = m;
            rec[d][r] = ++temp1;

        }
        temp2 = rec[d][r];
        for(int x=r-1; x>=i; x--)
        {
            rec[d][x] = ++temp2;
            r = x;
        }
        temp3=rec[d][r];
        for(int y=d-1; y>i; y--)
        {
            rec[y][r] = ++temp3;
            d = y;
        }
        temp = rec[d][r];
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            printf("%2d ", rec[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int times = 0;
    scanf("%d", &times);
   // rhombus(times-1, times-1, 2*times -1);
    //rect(1, times/2, times, times);
    rect(1, times);
    return 0;
}
