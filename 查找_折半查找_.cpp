#include <stdio.h>
#include <stdlib.h> 
int insertSort(int a[],int low,int high,int key)
{
	int count=0;
	int mid;
	while(low<=high) 
	{ 
		count++;
		mid=(low+high)/2;
		//printf("-->%d-->%d-->%d\n",low,high,mid);
		
		if(key==a[mid]) 
		{
			printf("����->%d����%d��λ��,����-->%d  \n",key,mid+1,count);	
			return mid;
		}	
		else if(key>a[mid]) 
		{
			low=mid+1;
			
		}
		else if(key<a[mid]) 
		{
			high=mid-1;	
		}
		
		if(low>high) 
		{
			printf("failed\n");	
		}	
			//return -1;
   	} 

}
int main()
{
	int a[10],i,m; 
	int num=10; 
	
	printf("10 num is:\n");
	for(i=0;i<num;i++) 
	{
		a[i]=i+1;
	} 
	
	for(i=0;i<num;i++) 
	{
		printf("%d ",a[i]);	
	} 
	
	printf("\n");	
	//printf("please input ���ҵ�����:\n");
	//scanf("%d",&m);
	for(i=0;i<num;i++) 
	{
		insertSort(a,0,num-1,i+1);
	} 
	

	
	
 
}
