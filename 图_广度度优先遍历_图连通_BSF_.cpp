#include<stdio.h>
#include<stack>
#include<queue>
#include<iostream>
using namespace std;


#define Max_vexs 25
#define status int
#define Max_type -1


typedef struct 
{
	status arcs[Max_vexs][Max_vexs];
	status vexnum,arcnum;	
}graph;

status createUDG(graph *G)
{
	int i,j,w;
	
    printf("�x�ȵ��������ݔ�뤷�Ƥ���������\n");
    scanf("%d %d",&G->vexnum,&G->arcnum);
	
	for(i=1;i<G->vexnum+1;i++) 
	{
		for(j=1;j<G->vexnum+1;j++) 
		{ 	
		if(i==j)
		{
			G->arcs[i][j]= 0; 
		}
		else
		{
			G->arcs[i][j]= Max_type; 
		}

		}
	}

	cout<<"������ߣ�vi, vj)��Ȩֵw,���������ո�ָ����ɣ�"<<endl;
	for(int k=1;k<G->arcnum+1;k++) 
	{
		cin>>i>>j>>w;
		G->arcs[i][j]=w;
		G->arcs[j][i]=w;
	}
}
status printUDG(graph *G)
{
	int i,j;
    printf("�x�ȵ��������ݔ�����ޤ���\n");
    printf("%d %d\n",G->vexnum,G->arcnum);
	
	
	printf("ȫ�Ƶ���B�j�����֤�ݔ�����ޤ���\n");
	for(i=1;i<G->vexnum+1;i++) 
	{
		for(j=1;j<G->vexnum+1;j++) 
		{ 
		printf("%5d",G->arcs[i][j]);
		}
		printf("\n");
	}
	
}

void Graph_Bfs(graph M,int visiting_Node)
{
	int isVisited[M.vexnum+1]={0};
	
	queue<int> p;
	int count=0;
	
	while(count<M.vexnum)
	{
		if(isVisited[visiting_Node]==0)
		{
            cout<<"-->"<<visiting_Node<<" \n";
            count++;
        }
		
		p.push(visiting_Node);
		isVisited[visiting_Node]=1;
		for(int j=1;j<M.vexnum+1;j++)
		{
			//printf("\n------>%d\n",M.arcs[visiting_Node][j]) ;
            if(M.arcs[visiting_Node][j]!=0 && isVisited[j]==0 && M.arcs[visiting_Node][j]!=Max_type )
			{
				//printf("\n------>%d\n",j) ;
                p.push(j); 
            }
        }
        
        p.pop();
        visiting_Node=p.front();
        

	}
	
}
int main()
{
	graph gh;
	
	createUDG(&gh);
	printUDG(&gh); 
    cout<<"\n��ͼ�Ĺ�ȱ���Ϊ��\n"<<endl;
    Graph_Bfs(gh,1);
	
	
	
	return 0;
}
