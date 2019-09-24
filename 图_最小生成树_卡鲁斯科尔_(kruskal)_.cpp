#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
#define MAXN 15		//������������ֵ
#define MAXM 40		//�ߵĸ��������ֵ
struct edge			//��
{
	int a, b, w;
}edges[MAXM];		//�ߵ�����

int parent[MAXN];	//parent[i]Ϊ����i���ڼ��϶�Ӧ�����еĸ����
int n, m;			//����������ߵĸ���
int i, j;			//ѭ������

void UFset()		//��ʼ�� 
{
	for(i = 1; i <= n; i++)
	{
		parent[i] = -1;
	} 
}
int Find(int x)		//���Ҳ����ؽ��x�������ϵĸ����
{
	int s;			//����λ��
	for(s = x; parent[s] >=0; s = parent[s]) ;
	while(s != x)	//�Ż���������ѹ��·����ʹ�����Ĳ��Ҳ�������
	{
		int tmp = parent[x];
		parent[x] = s;
		x = tmp;
	}
	return s;
}

//���ò��鼯����������ͬ���ϵ�Ԫ�ؽ��кϲ���ʹ������������������Ԫ�ض���ͨ
void Union(int R1, int R2)
{
	int r1 = Find(R1), r2 = Find(R2);		//r1��r2�ֱ�ΪR1��R2�ĸ����
	int tmp = parent[r1] + parent[r2];		//�������Ͻ����֮�ͣ�������
	//���R2������������ > R1��������������ע��parent[r1]�Ǹ�����
	if(parent[r1] > parent[r2])
	{
		parent[r1] = r2;
		parent[r2] = tmp;
	}
	else
	{
		parent[r2] = r1;
		parent[r1] = tmp;
	}
}
int cmp(const void *a, const void *b)		//ʵ�ִ�С����ıȽϺ���
{
	edge aa = *(const edge *)a, bb = *(const edge *)b;
	return aa.w-bb.w;
}
void Kruskal()
{
	
	int sumweight = 0;		//��������Ȩֵ
	int num = 0;			//��ѡ�õıߵ���Ŀ
	UFset();
	for(i = 0; i < m; i++)
	{   
	    printf("(%d , %d) -> %d\n", edges[i].a, edges[i].b, edges[i].w);	
		if(Find(edges[i].a) != Find(edges[i].b))
		{
			printf("\t\t%d %d %d\n", edges[i].a, edges[i].b, edges[i].w);
			sumweight += edges[i].w; 
			num++;
			Union(edges[i].a, edges[i].b);
		}
	
	}
	printf("The weight of MST is : %d\n", sumweight);		

}


int main()
{
	
	m=7;
	n=5;

	edges[0].a=1;
	edges[0].b=2;
	edges[0].w=3;
	edges[1].a=1;
	edges[1].b=3;
	edges[1].w=7;
	edges[2].a=1;
	edges[2].b=5;
	edges[2].w=1;
	edges[3].a=2;
	edges[3].b=3;
	edges[3].w=9;
	edges[4].a=2;
	edges[4].b=4;
	edges[4].w=7;
	edges[5].a=2;
	edges[5].b=5;
	edges[5].w=5;	
	edges[6].a=3;
	edges[6].b=4;
	edges[6].w=6;	
	
	printf("The edges chosen are :\n");
	qsort(edges, m, sizeof(edges[0]), cmp);	//�Ա߰�Ȩֵ��С��������
	
	
	//for(int i = 0; i < m; i++)
		//printf("(%d , %d) -> %d\n", edges[i].a, edges[i].b, edges[i].w);	//����ߵ������յ�
		
	
	


	Kruskal();
}

/*kural(Graph &G,Edge *edge,int *parent)
{
	head_sort(edge);
	Initial(parent)
	for(int i=0;i<G.arcnum;i++)
	{
		if(Find(parent[i].a)!=Find(parent[i].b))
		{
			Union(parent,a,b) ;
		}
	}
}*/
