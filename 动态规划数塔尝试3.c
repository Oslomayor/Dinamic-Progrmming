/* ��̬�滮������� */
/*�ο����ϣ� https://www.2cto.com/kf/201711/699915.html*/
/*Level 3 �ݹ�ת��Ϊ����*/
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
    
    
    // �ײ����������
    for(j=1;j<=N;j++)
    {
		Maxsum[N][j] = map[N][j];
    }
    
    
    // �ӵ�N-1�㿪ʼ����
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
