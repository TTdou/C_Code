#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define STACK_INIT_SIZE 100
#define addsize 60
typedef int Status;
typedef char elemment;

//ö�٣�LinkΪ0��ThreadΪ1
typedef enum 
{
    Link,
    Thread
}Tag;
typedef struct BitNode
{
	elemment data;
	struct BitNode *lchild ,*rchild;
	int ltag,rtag;
}BitNode, *BitTree;

BitTree pre=NULL;
//����Զ���������������


void CreateBtree(BitTree &T )
{
    //����������
    char ch;
    scanf("%c",&ch);
    //printf("-->%c\n",ch);
    if(ch==' ') 
	{
		T=NULL;
	} 
    else
	{
        if(!(T=(BitNode * )malloc(sizeof(BitNode)))) 
		{
			exit(OVERFLOW);
		} 
		T->ltag = T->rtag = Link;
        T->data=ch;
        CreateBtree(T->lchild);
        CreateBtree(T->rchild);
    }
}
print(BitTree T)
{
	if(T)
	{
		printf("%c\n",T->data);
		print(T->lchild);
		print(T->rchild);
	}
}



//����Զ���������������
int InThreading(BitTree &T)
{
	if(T)
	{
		InThreading(T->lchild);
		if(!T->lchild)
		{
			T->lchild=pre;
			T->ltag=Thread;
		}
		if(pre&&!pre->rchild)
		{	
			pre->rchild=T;
			pre->rtag=Thread;
		}
		
		pre=T;
		InThreading(T->rchild);//�ݹ�����������������
	}
	return 0; 
}
int InOrderThraverse_Thr(BitTree T)
{
	while(T)
	{
		while(T->ltag == Link)
		{
            T = T->lchild;
        }
		printf("%c\n", T->data);  //�����������
		while(T->rtag==Thread  &&  T->rchild!=NULL)
		{
			T=T->rchild;
			printf("%c\n", T->data);  //�����������
		}
		T=T->rchild;
	} 
	return 0; 
}
int main()
{
	BitTree T;
	CreateBtree(T);
	printf("�����������:\n");
	print(T);
	InThreading(T);
    printf("���������������:\n");
    InOrderThraverse_Thr(T);
	// �����������룬����124  5  36  7   �� 

	/*
     1
    / \
   2   4
   \  / \
   6 3  7
	
	*/
	
	
	return 0;
}


