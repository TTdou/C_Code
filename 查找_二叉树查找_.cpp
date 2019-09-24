#include<stdio.h>
#include<stdlib.h>

#define MAX  256 
typedef char TElemType;
typedef struct BiTNode
{
	
	TElemType data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*Bitree;
Bitree  CreateBitree(Bitree &r)
{
	

	char ch;
	scanf("%c",&ch); 
	printf("˳��� %c\n",ch);
	if (ch=='#')
	{
		r= NULL;
		
	}
	else
	{
			//printf("˳���*****************0\n");
	if(!(r=(BiTNode *)malloc(sizeof(BiTNode))))
	{
		exit(-1);
	};
	r->data=ch;
	CreateBitree(r->lchild);
	
	//printf("˳���*****************1\n");
	CreateBitree(r->rchild);
	//printf("˳���*****************2\n");
	}

	
	return 0;
}
void Prefirst(Bitree r) 
{
	if(r!=NULL)
	{
		printf("%c ",r->data);
		Prefirst(r->lchild);
		Prefirst(r->rchild);
	}
	
} 

Bitree D_serach(Bitree r,char key) 
{
	if(r==NULL)
	{
		return NULL;
	}
	if(key==r->data)
	{
		printf("successful->%c",r->data);
		return r;
	}
	else if(key<r->data)
	{;
		return D_serach(r->lchild,key); 
	}
	else if(key>r->data)
	{
		return D_serach(r->rchild,key); 
	}
	
}
Bitree C_serach(Bitree r,char key) 
{
	while(r!=NULL)
	{
		if(key==r->data)
		{
		
		printf("successful->%c",r->data);
		return r;	
		}
		else if(key<r->data)
		{
			r=r->lchild;
		}
		else if(key>r->data)
		{
			r=r->rchild;
		}
		
	}
	return NULL;
	
}

int main()
 {

    int i,a[]={'5','1','8','0','3','7','9','#','#','2','4','#','#','#','#','#','#','#'}; 
    char c;
    Bitree r;
	printf("input˳���Ľṹ��\n���� ��\n");
	CreateBitree(r);
	printf("˳���Ľṹ���ɹ� ��\n");
	
	printf("�������������������� \n");
	Prefirst(r) ;
	printf("\n ");
	//printf("���ҽ����%d \n",C_serach(r,7)->data);
	
	C_serach(r,'7');
	printf("\n ");
	D_serach(r,'7');
	
	
	//54##87##9## ����ķ������� 















	return 0;
}


