#include<stdio.h>

#define Max 50
#define VertexType int
typedef struct
{
	VertexType vexs[Max ][Max ];
	int vexnum,arcnum; 
}MGraph;
int CreateGraph(MGraph &G)
{
	/*int a,b,w;
	printf("����������ͼ�ĵ�ĸ���:\n");
	scanf("%d",&G.vexnum);
	printf("����������ͼ�ıߵ�����:\n");
	scanf("%d",&G.arcnum);
	for(int i=1;i<G.vexnum+1;i++)
	{
		
		for(int j=1;j<G.vexnum+1;j++)
		{
			
			if(i==j)
			{
				G.vexs[i][j]=0;
			}
			else
			{
				G.vexs[i][j]=Max;
			}
		} 
	} 
	printf("�����������ĵ����ţ���Ȩ��:\n");
	for(int i=1;i<G.arcnum+1;i++)
	{
		scanf("%d%d%d",&a,&b,&w);
		G.vexs[a][b]=w;
		G.vexs[b][a]=w;
	}
		*///����һ��mÿ������̫�鷳 
		
		
		
		
	int i,j,w;
	
	bool isDirected=1;
    
	G.vexnum=5;
	G.arcnum=7;
	for(i=1;i<G.vexnum+1;i++) 
	{
		for(j=1;j<G.vexnum+1;j++) 
		{ 	
		if(i==j)
		{
			G.vexs[i][j]= 0; 
		}
		else
		{
			G.vexs[i][j]= Max; 
		}

		}
	}
	
	G.vexs[1][2]=5;
	G.vexs[1][3]=3;
	G.vexs[1][5]=8;
	G.vexs[2][3]=2;
	G.vexs[2][4]=1;
	G.vexs[3][5]=4;
	G.vexs[4][3]=1;
	
	
	
}
int PrintGraph(MGraph G)
{
	printf("���ͼ�Ľ��Ϊ:\n");
	for(int i=1;i<G.vexnum+1;i++)
	{
		for(int j=1;j<G.vexnum+1;j++)
		{
			printf("%3d ",G.vexs[i][j]);		
		} 
		printf("\n");	
	} 
}
int Find_Graph_Way(MGraph &G)//����ķ�㷨 
{
	int min_weight[G.vexnum+1];
	int from_adjvex[G.vexnum+1];
	int i,j,minvex,minarc;
	for(int i=1;i<G.vexnum+1;i++)
	{
		min_weight[i]=G.vexs[1][i];
		from_adjvex[i]=1;
	}
	
	for(int i=2;i<G.vexnum+1;i++)
	{
		minarc=Max;
		for(int j=1;j<G.vexnum+1;j++)
		{
			if(minarc>min_weight[j]&&min_weight[j]!=0)
			{
				minarc=min_weight[j];
				minvex=j;
			}
		}
		min_weight[minvex]=0;
		printf("ѡ��ĵ�Ϊ�� . %d == %d\n",minvex,minarc); 
		for(int j=1;j<G.vexnum+1;j++)
		{
			if(G.vexs[minvex][j]<min_weight[j]&&min_weight[j]!=0)
			{
				min_weight[j]=G.vexs[minvex][j];
				from_adjvex[j]=minvex;
			}
		}
	
	}
	
	


   	
			
	
		   
	
}
int main()
{
	MGraph G;
	//��������㣬��Ӧ���������Ϊ1,2,3,4,5�� 
	CreateGraph(G);
	//PrintGraph(G);
	Find_Graph_Way( G);
	
	
	return 0;
} 
