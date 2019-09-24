#include<stdio.h>
#include<stdlib.h>
#define max 40
#define  ElemType char
typedef struct ENode
{
	struct ENode *next;
	int child;
}ENode;

typedef struct TNode
{
	ENode *first;
	ElemType data;
}TNode;
typedef struct TreeNode
{
	TNode nodes[max];
	int n,r;
}TreeNode;

int createTree(TreeNode &T)
{
	printf("������ɭ�ֽڵ�����:\n"); 
	scanf("%d",&T.n);
	//printf("������ɭ�ָ��ڵ�ڵ�λ��:\n"); 
	//scanf("%d",&T.r);//����Ĭ�ϴ��㿪ʼ��
	printf("�밴�������ڵ������:\n"); 
	char node_name;
	for(int i=0;i<T.n;i++)
	{
		scanf("%c",&node_name);
		while(node_name=='\n')
		{
			scanf("%c",&node_name);
		}
		T.nodes[i].data=node_name;
		T.nodes[i].first=NULL;
	} 
	/*printf("�ڵ����������Ϊ:\n"); 
	for(int i=0;i<T.n;i++)
	{
		printf("%c\n",T.nodes[i].data);
	} */
	ENode *p;
	for(int i=0;i<T.n;i++)
	{
		printf("��������%c�����Ľڵ���±꣬��������˳����������ڵ�Ϊ0 :\n",T.nodes[i].data);
		//����-1������ֹ��û��������Ҳ����-1 
		while(true) 
		{
			p=(ENode*)malloc(sizeof(ENode));
			scanf("%d",&p->child);
			if(p->child==-1)
			{
				break;
			}
			p->next=T.nodes[i].first;
			T.nodes[i].first=p;
		
		}
	
	} 
	return 0;
}
int printTree(TreeNode T)
{
	for(int i=0;i<T.n;i++)
	{
		printf("%c->",T.nodes[i].data);
		while(T.nodes[i].first)
		{
			printf("%d->",T.nodes[i].first->child);
			T.nodes[i].first=T.nodes[i].first->next;
		}
		printf("NULL\n");
	}
	return 0;
}
int findChild(TreeNode T)
{
	char node_name; 
	printf("������ҪѰ�Һ��ӽڵ�ĸ��ڵ������:\n");
	scanf("%c",&node_name);
	while(node_name=='\n')
	{
		scanf("%c",&node_name);	
	}
	int tag;
	for(int i=0;i<T.n;i++)
	{
		if(T.nodes[i].data==node_name)
		{
			tag=i;
			break;
		}
	}
	printf("%c->",T.nodes[tag].data);
	while(T.nodes[tag].first)
	{
		printf("%d,%c->",T.nodes[tag].first->child,T.nodes[T.nodes[tag].first->child].data);
		T.nodes[tag].first=T.nodes[tag].first->next;
	}
	printf("NULL\n");
	return 0;
	
}
int findParent(TreeNode T)
{
	char node_name; 
	printf("������ҪѰ�Ҹ��ڵ�ĺ��ӽڵ������:\n");
	scanf("%c",&node_name);
	while(node_name=='\n')
	{
		scanf("%c",&node_name);	
	}
	int tag;
	for(int i=0;i<T.n;i++)
	{
		if(T.nodes[i].data==node_name)
		{
			tag=i;
			break;
		}
	}
	
	for(int i=0;i<T.n;i++)
	{
		//printf("%c->",T.nodes[i].data);
		while(T.nodes[i].first)
		{
			if(T.nodes[i].first->child==tag)
			{
				printf("%c\n",T.nodes[i].data);
			}
			//printf("%d->",T.nodes[i].first->child);
			T.nodes[i].first=T.nodes[i].first->next;
		}
		//printf("NULL\n");
	}
	return 0;
}
int main()
{	
	TreeNode T;
	createTree(T);
	printTree(T);
	findChild(T);
	findParent(T); 
	return 0;
} 
