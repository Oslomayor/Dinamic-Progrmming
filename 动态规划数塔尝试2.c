/* ��̬�滮������� */
/*Level 2 ������ĵݹ鷨���Ż�ʱ�临�Ӷ�*/
/*
�������������������Ѱ��һ���Ӷ������ױߵ�·����ʹ��·����������������֮�����
·���ϵ�ÿһ����ֻ�������»� �����ߡ�ֻ��Ҫ���������ͼ��ɣ����ظ�������·���� 
�����ε���������1С�ڵ���100������Ϊ 0 - 99��
�����ʽ��
                     
    7                  //��1��
    3   8
    8   1   0
    2   7   4   4
    4   5   2   6   5  //��N��
    Ҫ���������
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

// �������������У���
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
    //�Ӽ��̶�ȡmap[][]
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
