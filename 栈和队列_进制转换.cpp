#include<stdio.h>
#include<stdlib.h>

#define Max 100
#define False -1
#define True 1

typedef struct Stack
{
	int data[Max];
	int top;
}stack;

int init_stack(stack &s)
{
	s.top=-1;
	return 0;	
}
int push_stack(stack &s,int e)
{
	if(s.top>Max-1)
	{
		return False;
	}
	s.data[++s.top]=e;
	//printf("pop-->%d\n",e);
	return True;
}

int pop_stack(stack &s,int e)
{
	if(s.top>-1)
	{
	    e=s.data[s.top--];
	    //printf("push-->%d\n",e);
	    return e;
	}
	return False;
}

int top_stack(stack s)
{
	if(s.top>-1)
	{
	    return s.data[s.top];
	}
	return False;
}
int print_stack(stack s,int e)
{
	while(s.top!=-1)
	{
	    e=s.data[s.top--];
	    printf("push-->%d\n",e);
	}
	return True;
	
}
int len_stack(stack s)
{
	int m=0;
	while(s.top!=-1)
	{
		s.data[s.top--];
	    //printf("push-->%d\n",s.data[s.top--]);
	    m++;
	}
	return m;
	
}
int empty_stack(stack s)
{
	if(s.top==-1)
	{
	    return NULL;
	}
	return True;
	
}
int main()
{
	stack s;
	init_stack(s);
	int N,e,t;
	printf("������ת��������:\n");
	scanf("%d",&N);
	printf("������ת��Ϊ������:\n");
	scanf("%d",&e);
	while(N)
	{
	push_stack(s,N%e);
	N=N/e; 
	}
	printf("ת��Ϊ��%d������Ϊ:\n",e);
	while(empty_stack(s)!=NULL)
	{
//printf("---------------\n");	
	t=pop_stack(s,t);
	printf("%d ",t);
	}
	
	return 0;
}
