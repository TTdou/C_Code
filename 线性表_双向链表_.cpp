#include<stdio.h>
#include<stdlib.h>

typedef struct datanum
{
	int num;
	struct datanum *right;
	struct datanum *left;
}dat,*dap;
struct datanum* create()
{
	int i,j,n;
	dat *head,*s,*p;
	
	
	printf("�����������\n");
	scanf("%d",&n);
	
	head=(datanum*)malloc(sizeof(datanum));
	p=head;
	head->right=NULL;
	head->left=NULL;
	for(i=n;i>0;i--)
	{
		printf("�������%d�����֣�\n",n-i+1);
		s=(datanum*)malloc(sizeof(datanum));
		scanf("%d",&s->num);
		p->right=s;
		s->left=p;
		p=s;
			
	}
	s->right=NULL;
	printf("���������!\n");
	return head; 
}
int print1(struct datanum *p)
{

	printf("������Ϣ��ʾ��\n");
	while(p->right!=NULL)
	{
		printf("%d<--->",p->right->num);
		p=p->right; 
	}
	

	printf("over!\n");
	
}
struct datanum* w_insert(struct datanum *p)
{
	int n;
	dat *t,*head;
	printf("�������������֣�\n");
	t=(datanum*)malloc(sizeof(datanum));
	scanf("%d",&t->num);
	
	
	head=p;
	
	while(p->right!=NULL)
	{
		//printf("%d<--->\n",p->right->num);
		p=p->right; 
	}
	p->right=t;
	t->right=NULL; 
	t->left=p;


	return head;
	
	
}

struct datanum* t_insert(struct datanum *p)
{
	int n;
	dat *t,*head;
	printf("�������������֣�\n");
	t=(datanum*)malloc(sizeof(datanum));
	scanf("%d",&t->num);
	
	
	head=p;
	
	
	t->right=p->right; 
	p->right->left=t;
	
	p->right=t;
	t->left=p;
	
	//t->left=p;


	return head;
	
	
}
int main()
{
	dat *p,*q;
	p=create();
	print1(p);
	q=w_insert(p);
	print1(q);
	q=t_insert(p);
	print1(q);
	
	return 0;
} 
