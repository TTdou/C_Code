#include <stdio.h>
 
int main()  
{  
    int i,j,m; 
 	int a[10]={49,38,65,97,49,13,27,76};
	int n=8;
  
  
    for(i=0;i<n-1;i++)          //n����Ҫ����n-1�˱Ƚ�
    {  
        for(j=0;j<n-1-i;j++)       //ÿ�˱Ƚ�n-i��  
            if(a[j]>a[j+1])      //���αȽ��������ڵ�������С������ǰ�棬�������ں���  
            {  
                int temp=a[j];   //temp�Ǿֲ�����
                a[j]=a[j+1];  
                a[j+1]=temp;  						  
            }  
		     for(m=0;m<8;m++)
			{
				printf("%d  ",a[m]);
			}
			printf("\n");
    }  
    printf("\n");
  
    for(i=0;i<8;i++)            //����Ƚ�֮�������  
        printf("%d ",a[i]); 
		
    getchar();                   //���Microsoft Visual Studio���������ˣ������û��鿴�������н��
    return 0;
}  
