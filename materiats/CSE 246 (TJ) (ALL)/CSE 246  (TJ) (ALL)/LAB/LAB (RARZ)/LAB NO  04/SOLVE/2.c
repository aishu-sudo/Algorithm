#include<stdio.h>
#include<string.h>

int main()
{
    int i, j, k;
    char T[10001], P[1001];

    scanf("%s %s", &T, &P);
    int a=strlen(T);
    int b=strlen(P);

    for(i=0; i<=a-b; i = i+1)
    {
        int flg =0;

        for(j=i, k=0; j<i+b; j = j+1, k = k+1)
        {
            if(T[j]!=P[k])
            {
                flg=1;
                break;
            }
        }
        if(flg==0) printf("%d %d\n", i, i+b-1);
    }
    return 0;
}
