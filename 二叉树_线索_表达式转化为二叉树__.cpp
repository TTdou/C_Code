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
}TNode;


/**
expr:ָ����ʽ�ַ�����ָ��
start:ΪҪװ���ı��ʽ�ַ�������ʼλ��
end:ΪҪװ���ı��ʽ�ַ����Ľ���λ�õĺ�һλ
root_pos:��¼��ǰҪת���ı��ʽ���ɶ������ĸ��ڵ��������λ��
flag:��¼�Ƿ��ǵ�ǰ��������������
multiplication_division_pos:��¼��ǰ���ʽ�������������Ҷ˵�*��/��^λ��
plus_minus_pos:��¼��ǰ���ʽ�������������Ҷ˵�+��-λ��
**/
void buildTree(TNode *&T,char expr[],int start,int end)
{
	//printf("����ı��ʽ:%s\n",expr);
	//printf("���ʽ����:%d\n",end-start);
	if(end-start==1)
	{
		//if(isdigit(expr[start]))
		{
		T=(struct TNode *)malloc(sizeof(struct TNode));
		T->data=expr[start];
		printf("%c->1->\n",T->data);
		T->lChild=NULL;
		T->rChild=NULL;
		return;
		}
	}
	else if (end-start==0)
	{
		T=NULL;
		return;
	}
	
	int root_pos = 0;
    int arc_pos_l = 0;
    int arc_pos_r = 0;
    int plus_minus_pos = 0;
    int multiplication_division_pos = 0;
    
    for(int i=start;i<end;i++)//l���治��ͻ������ȫ��if 
    {
	    	if(expr[i]=='(' || expr[i]=='[' )
	    	{
	    		arc_pos_l=i;
			}
			else if(expr[i]==')' || expr[i]==']')
	    	{
	    		arc_pos_r=i;
			}
			else if(expr[i]=='*' || expr[i]=='/' || expr[i]=='^')
			{
				multiplication_division_pos = i;
			}
			else if(expr[i]=='+' || expr[i]=='-')
			{
				plus_minus_pos=i;
			}
	}
	//cout<<" "<<plus_minus_pos<<" "<<multiplication_division_pos<<endl;
	if(arc_pos_r>0)//�������ȼ�����+-��*/����˳��
	{
		root_pos=arc_pos_r;
	}
    else if(plus_minus_pos>0)
    {
    	root_pos=plus_minus_pos;
	}
	else if(multiplication_division_pos>0)
	{
		root_pos=multiplication_division_pos;
	}
	else if(arc_pos_l>0)
	{
		root_pos=arc_pos_l;
	}
	
	T=(struct TNode *)malloc(sizeof(struct TNode));
	T->data=expr[root_pos];
	printf("%c--\n",T->data);
	buildTree(T->lChild,expr,start,root_pos);
    buildTree(T->rChild,expr,root_pos+1,end);
	
}
int visit(TNode *&T) 
{
	printf("%c",T->data);
}
int PreOrderTraverse(TNode *&T) 
{
	if(T)
	{
		visit(T);
		PreOrderTraverse(T->lChild);
		PreOrderTraverse(T->rChild);
	}
}

int InOrderTraverse(TNode *&T) 
{
	if(T)
	{
		InOrderTraverse(T->lChild);
		visit(T);
		InOrderTraverse(T->rChild);
	}
}

int PostOrderTraverse(TNode *&T) 
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
    
    struct TNode* T;
    buildTree(T,expr,start,end);
    
    printf("\n\n");
    printf("��������:\n");
    PreOrderTraverse(T);
    printf("\n\n");
    printf("��������:\n");
    InOrderTraverse(T);
    printf("\n\n");
    printf("��������:\n");
    PostOrderTraverse(T);
    
    //printf("Your result is %d\n",cal(b));   

}
