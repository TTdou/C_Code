#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct student
{
	char name[30];
	char id[30];
	float score;
	struct student *next;
}*Stu,stu;

Stu creatList()
{
	int n,i;
	stu *p,*head,*tail;
	printf("������ѧ������:\n");
	scanf("%d",&n);	
	head=NULL;
	for(i=0;i<n;i++)
	{
		printf("��%d��ѧ��:\n",i+1);	
		p=(stu *)malloc(sizeof(stu));
		printf("������ѧ����������ѧ�ţ�����:\n");	
		scanf("%s %s %f",&p->name,&p->id,&p->score);
		p->next=NULL;
		if(head==NULL)
		{
			head=p;
		}
		else
		{
			tail->next=p;	
		}
		tail=p;
	}
		printf("�����ɹ���\n");	
	return head;
}
Stu printList(stu *p )
{
	if(p==NULL)
	{
	printf("����Ϊ�գ�\n");		
	}
	while(p!=NULL)
	{
		printf("ѧ����������ѧ�ţ�����Ϊ:\n");	
		printf("%s %s %.2f\n",p->name,p->id,p->score);
		p=p->next; 
	}
} 

stu  select_data(stu *head)
{
	char n[40];
	int m;
	if(head==NULL)
	{
	printf("data no exists:\n");	
	}
	printf("intput student name:\n");
	scanf("%s",n);
	while(head!=NULL)
	{
		m=strcmp(n,head->name);
		if(m==0)
		{
		printf("%s,%s,%.2f \n",head->name,head->id,head->score);	
		}
		
		head=head->next;
	}
	
}
int main()
{
	
	stu *p;
	p=creatList();
	printList(p);
	select_data(p);
	return 0;
}
