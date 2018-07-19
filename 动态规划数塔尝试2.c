/* 动态规划求解数塔 */
/*Level 2 带记忆的递归法，优化时间复杂度*/
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
#define N 3
int mapcahe[MAX][MAX];

int max(int a, int b)
{
	return a >= b ? a : b;
}

// 参数：数塔的行，列
int Maxsum(int i, int j)
{
	if(i == N) 
    {
		mapcahe[i][j]=map[i][j];
        return map[i][j];
    }
    else
    {
		if(mapcahe[i][j] != 0)
			return mapcahe[i][j];
        else mapcahe[i][j] = max(Maxsum(i+1,j),Maxsum(i+1,j+1)) + map[i][j];
        return mapcahe[i][j];
    }
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
    printf("%d\n",Maxsum(1,1));
    /*
    for(i=1;i<3;i++)
    {
		for(j=1;j<3;j++)
			printf("%d ",map[i][j]);
        printf("\n");
    }
    */
	system("pause");
	return 0;
}
