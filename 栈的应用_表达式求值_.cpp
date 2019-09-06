#include <stdio.h>
#include <stdlib.h>


#define ElemType char
#define STACKINCEMENT 20
#define STACK_INIT_SIZE 50

#define Status int
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef struct
{
    ElemType *base;
    ElemType *top;
    int stacksize;
}stack;
char prior[7][7]=
{
{'>','>','<','<','<','>','>'},
{'>','>','<','<','<','>','>'},
{'>','>','>','>','<','>','>'},
{'>','>','>','>','<','>','>'},
{'<','<','<','<','<','=','!'},
{'>','>','>','>','!','>','>'},
{'<','<','<','<','<','!','='}
};//�������֮�����ȹ�ϵ�Ķ�ά���� 

Status init_stack(stack &s)
{
	s.top=s.base=(ElemType *)malloc(STACK_INIT_SIZE*sizeof(ElemType));
	if(!s.top)
	{
		exit(OVERFLOW);
	}
	s.stacksize=STACK_INIT_SIZE;
	
}
Status push_stack(stack &s,ElemType e)
{
	if(s.top-s.base>=s.stacksize)
	{
		s.top=(ElemType *)realloc(s.base,(s.stacksize+STACKINCEMENT)*sizeof(ElemType));
		s.top=s.base+s.stacksize;
		s.stacksize+=STACKINCEMENT;
	}
	*s.top++=e;
	//printf("%d\n",e);
	return OK;
	
}

Status pop_stack(stack &s,ElemType &e)
{
	if(s.top-s.base==0)
	{
		return ERROR;
	}
	e=*--s.top;
	//printf("%d\n",e);
	return e;
	
}

ElemType get_stack_top(stack &s)
{
	if(s.top-s.base==0)
	{
		return ERROR;
	}
	//printf("%d\n",*(s.top-1));
	return *(s.top-1);;
	
}

//ȷ��������ַ�����ǲ������Ļ��ж��ڶ�ά�����е��±� �������ֵĻ�����������������ֿ� ������������ʽʱ�����ĸ�ջ 
int Index(char c){
	switch(c){
		case '+': return 0;
		case '-': return 1;
		case '*': return 2;
		case '/': return 3;
		case '(': return 4;
		case ')': return 5;
		case '#': return 6;
		default:  return 7;
	}
}
//�ж����ȼ�,���ش�С < > = !
char Priority(char a,char b){
	int x,y;
	x = Index(a); y = Index(b);
	if(x!=7&&y!=7)
		return prior[x][y];
	else
		return '!';
}

ElemType Operate(ElemType a, ElemType x, ElemType b){
    switch (x){
    case '+':
        return a  + b;
    case '-':
        return a  - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    }
}//Operator

Status isdigit(char ch){
	if(ch>='0'&&ch<='9') 
	{
		return OK;
	}
	return ERROR;
} 
int Expression_eval()
{

	char c[1000];
	char  result;
	stack num;
	stack ope;
	init_stack(num); 
	init_stack(ope); 
	push_stack(ope,'#');//�����������ڲ������ĵ׶�  
	char ct,ch = getchar();
	//gets(c);
	while(ch!='#'||get_stack_top(ope)!='#') 
	{
		
		if(isdigit(ch))
		{
			
			int data[10];
			int i,re;
			i = re =0;
			while(isdigit(ch))
			{
				data[i] = ch-'0';
				i++;
				
				ch = getchar();
				if(ch=='\n')
				 {
				     ch='#';
				 }


			}
			for(int j=0;j<i;j++)
			{
				re = re*10+data[j];
			}

			push_stack(num,re);
			
		}
		else
		{
			ElemType a,b,theta;//a b theta���������ز�����ջ�Ͳ�����ջ���Ԫ�ص�
			switch(Priority(get_stack_top(ope),ch))
			{//�Ƚϼ�����ջ���ַ���ջ�� �����������ȼ���ϵ 
			
				case '<':
						 push_stack(ope,ch); 
						 ch = getchar();
						 if(ch=='\n')
						 {
						 	ch='#';
						 }	
						 break;
				case '>':
						 
						 pop_stack(num,b);
						 pop_stack(num,a);
						 //printf("---->%c%c\n",a,b);
						 pop_stack(ope,theta);
						 push_stack(num,Operate(a,theta,b));
						 //printf("---------------------\n");
						 break;//�������ջ 
				case '=':
						 pop_stack(ope,theta);
						 //printf("---------------------\n");
						 ch = getchar();
						 if(ch=='\n')
						 {
						 	ch='#';
						 }
						 break;//˵���������� ɾ��ջ�����ż��� 
				default:break;
			}
		}
	}
	int num1;
	num1=get_stack_top(num);
	printf("����ǣ�%d\n",num1);

	return 0;
}

int main()
{
	stack l;
	//char e;
	//init_stack(l); 
	printf("��������ʽ��\n");
	Expression_eval();
	//push_stack(l,1);
	//get_stack_top(l);
	//e=pop_stack(l,e);
	//printf("%d",e);
	return 0;
} 
