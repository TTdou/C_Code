#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct student
{
	char name[30];
	char id[30];
	float score;
	int len;
	struct student *next;
}*Stu,stu;

void creatList(stu *&head)
{
	int n,i;
	stu *p,*tail;
	
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
			head->len=1;
		}
		else
		{
			tail->next=p;
			head->len=head->len+1;
		}
		
		tail=p;
	}
	tail->next=head;
	printf("�����ɹ���\n");	
}
void printList(stu *p )
{
	if(p==NULL)
	{
	printf("����Ϊ�գ�\n");		
	}
	int i=0;
	
	printf("len-->%d\n",p->len);
	while(p!=NULL)
	{
		printf("ѧ����������ѧ�ţ�����Ϊ:\n");	
		printf("%s %s %.2f\n",p->name,p->id,p->score);
		p=p->next; 
		i++;
		if(i==p->len)
		{
			break;
		}
		
	}
} 

 void  select_data(stu *head)
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
		break;
		}
		
		head=head->next;
	}
	
}
int main()
{
	
	Stu head;
	creatList(head);
	printList(head);
	select_data(head);
	return 0;
}
