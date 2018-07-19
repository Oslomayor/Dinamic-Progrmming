/* 动态规划求解数塔 */
/*参考资料： https://www.2cto.com/kf/201711/699915.html*/
/*Level 3 递归转换为递推*/
/*
在上面的数字三角形中寻找一条从顶部到底边的路径，使得路径上所经过的数字之和最大。
路径上的每一步都只能往左下或 右下走。只需要求出这个最大和即可，不必给出具体路径。 
三角形的行数大于1小于等于100，数字为 0 - 99。
输入格式：
                     
    7                  //第1层
    3   8
    8   1   0
    2   7   4   4
    4   5   2   6   5  //第N层
    要求输出最大和
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int map[MAX][MAX];
#define N 5
int Maxsum[MAX][MAX];

int max(int a, int b)
{
	return a >= b ? a : b;
}

int main()
{
	
    int i=1,j=1;
    int c;
    //从键盘读取map[][]
	while((c = getchar()) != EOF)
    {
		if(c == '\n') 
        {
			i++;
            j=1;
        }
        else if(c != ' ')
        {
				map[i][j] = c - '0';
				j++;
        }
    }
    
    
    // 底层等于它本身
    for(j=1;j<=N;j++)
    {
		Maxsum[N][j] = map[N][j];
    }
    
    
    // 从第N-1层开始递推
    for(i=N-1;i>0;i--)
    {
        for(j=1;j<=i;j++)
        {
			Maxsum[i][j] = map[i][j] + max(Maxsum[i+1][j],Maxsum[i+1,j+1]);
            printf("map[%d][%d]:%d\n",i,j,map[i][j]);
            printf("Maxsum[%d+1][%d]:%d\n",i,j,Maxsum[i+1][j]);
            printf("Maxsum[%d+1][%d+1]:%d\n",i,j,Maxsum[i+1][j+1]);
        }
    }
    
    printf("%d\n",Maxsum[1][1]);
    
    for(i=1;i<=N;i++)
    {
		for(j=1;j<=N;j++)
			printf("%d ",Maxsum[i][j]);
        printf("\n");
    }
    
	system("pause");
	return 0;
}
