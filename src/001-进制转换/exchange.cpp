#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#define arrmax 100

int arr[arrmax];// 倒叙输出即为转换后的结果
int len; // 位数
char table[21] = {'0','1','2','3','4','5','6','7','8','9',
                 'A','B','C','D','E','F','G','H','I','J'};

int exchange(int n, int base)
{
    // 初始化
    memset(arr,0,sizeof(arr));
    len =0;

    int quotient; // 商
    int reminder; // 余数

    while(n != 0 && len < arrmax) // 转换结束 或 位数限制
    {
        quotient = n / base;
        reminder = n % base; 
        //printf("original: %d %d\n",quotient, reminder);
        // 负余数调整
        if(reminder < 0){
            reminder = abs(base) + reminder; // 正余数
            if(base <0)
                quotient++; 
            else if(base > 0)
                quotient--;
            /* It's error!
            if(quotient > 0) // |商| + 1
                quotient = quotient + 1; 
            else if(quotient < 0)
                quotient = quotient - 1;
            */
        }

        //printf("modified: %d %d\n",quotient, reminder);
        arr[len++] = reminder;// 记录余数
        n = quotient; // 商作为下一轮的n
    }
    return 0;
}

int main(int argc,char const * argv[]){
    int n, base;
    if(argc == 1) //输入
    {  
        scanf("%d %d",&n,&base);
    }
    else if(argc == 3)
    {
        n = atoi(argv[1]);
        base = atoi(argv[2]);
    }

    exchange(n,base);

    // 输出
    printf("%d=",n);
    for(int i = len-1;i>=0; i--){
        printf("%c", table[arr[i]]);
    }
    printf("(base%d)\n",base);
    return 0;
}