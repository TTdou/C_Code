#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include <iostream>
#include <malloc.h>
using namespace std;

typedef struct  TNode
{
    char data;
    struct TNode * lChild;//���� 
    struct  TNode * rChild;//�Һ��� 
}TNode,*BitTree;


/**
expr:ָ����ʽ�ַ�����ָ��
start:ΪҪװ���ı��ʽ�ַ�������ʼλ��
end:ΪҪװ���ı��ʽ�ַ����Ľ���λ�õĺ�һλ
root_pos:��¼��ǰҪת���ı��ʽ���ɶ������ĸ��ڵ��������λ��
flag:��¼�Ƿ��ǵ�ǰ��������������
multiplication_division_pos:��¼��ǰ���ʽ�������������Ҷ˵�*��/��^λ��
plus_minus_pos:��¼��ǰ���ʽ�������������Ҷ˵�+��-λ��
**/
BitTree buildTree(char expr[],int start,int end)
{
	//printf("����ı��ʽ:%s\n",expr);
	//printf("���ʽ����:%d\n",end-start);
	if(end-start==1)
	{
		BitTree T=(BitTree)malloc(sizeof(TNode));
		T->data=expr[start];
		//printf("[%c]\n",T->data);
		T->lChild=NULL;
		T->rChild=NULL;
		return T;
	}
	
	int root_pos = 0;
    int flag = 0;
    int plus_minus_pos = 0;
    int multiplication_division_pos = 0;
    
    for(int i=start;i<end;i++)
    {
    	if(expr[i]=='(' || expr[i]=='[')
    	{
    		flag++;	
		}
		if(expr[i]==')' || expr[i]==']')
		{
			flag--;
		}
		if(flag==0)
		{
			if(expr[i]=='*' || expr[i]=='/' || expr[i]=='^')
			{
				multiplication_division_pos = i;
			}
			else if(expr[i]=='+' || expr[i]=='-')
			{
				plus_minus_pos=i;
			}
		}
	}

	if((plus_minus_pos==0) && (multiplication_division_pos == 0))
	{
		buildTree(expr,start+1,end-1);
	}
    else
    {
    	if(plus_minus_pos>0)
    	{
    		root_pos=plus_minus_pos;
		}
		else if(multiplication_division_pos>0)
		{
			root_pos=multiplication_division_pos;
		}
		BitTree T=(BitTree)malloc(sizeof(TNode));
		T->data=expr[root_pos];
		//printf("%d\n",root_pos);
		cout<<start<<" "<<root_pos<<endl;
		T->lChild=buildTree(expr,start,root_pos);
    	T->rChild=buildTree(expr,root_pos+1,end);
    	return T;
	}
}
int visit(TNode *&T) 
{
	printf("%c",T->data);
}
int PreOrderTraverse(BitTree T) 
{
	if(T)
	{
		visit(T);
		PreOrderTraverse(T->lChild);
		PreOrderTraverse(T->rChild);
	}
}

int InOrderTraverse(BitTree T) 
{
	if(T)
	{
		InOrderTraverse(T->lChild);
		visit(T);
		InOrderTraverse(T->rChild);
	}
}

int PostOrderTraverse(BitTree T) 
{
	if(T)
	{
		PostOrderTraverse(T->lChild);
		PostOrderTraverse(T->rChild);
		visit(T);
	}
}
int main()
{
	char expr[200];
	int start,end;
    printf("��������ʽ:");
    scanf("%s", expr);
    
    start=0;
    end=strlen(expr);
    BitTree T;
    T=buildTree(expr,start,end);
    
    printf("\n\n");
    printf("��������:\n");
    PreOrderTraverse(T);
    printf("\n\n:");
    printf("��������:\n");
    InOrderTraverse(T);
    printf("\n\n");
    printf("��������:\n");
    PostOrderTraverse(T);
    //printf("Your result is %d\n",cal(b));   

}
