#include <stdio.h>

void function(int p[],int left,int right);    //���������� (����) 

int main(void)
{
    int n;                                    //n��ϣ����������ֵĸ��� 
	scanf("%d",&n);
	int p[n];                                 //���ٳ���Ϊ n �Ŀռ䣬��������p 
	int i;
	
	
	for ( i = 0; i < n; i++ ){                //����ϣ�������n������ 
		scanf("%d",&p[i]);
	}
	
	function( p, 0, n-1 );                    //�����Զ��������� 
	
	for ( i = 0; i < n; i++ ){                //�����������p 
		printf("%d ",p[i]);
	}
	
	return 0;
}

//////////////////////////////////////////////
void function(int p[],int left,int right)     //left��right�ֱ�������������˺����Ҷ� 
{
	int i,j,t,temp;
	
	if ( left > right ){                      //���left > right��ֱ���������� 
		return;
	}
	
	temp = p[left];                           //ѡȡ��������˵�����Ϊ��׼�� 
	i = left;
	j = right;
	
	while ( i != j ){                         //��� i �� j ������ 
		
		while ( p[j] >= temp && i < j){       //j ָ��λ��ֻҪһֱ���ڻ�׼�������� i �� j ��������j��һֱ���� 
			j--;
		}
		
		while ( p[i] <= temp && i < j){       //i ָ��λ��ֻҪһֱС�ڻ�׼�������� i �� j ��������i��һֱ����
			i++;
		}
		
		if ( i < j ){                         //���� i �� j ��ָ�����ֵ 
			t = p[i];
			p[i] = p[j];
			p[j] = t;
		}
		
	}
	
	p[left] = p[i];                            //��ʱ i �� j ����������ʱ i (�� j) ָ���ֵ��
	p[i] = temp;                               //����������˵�temp���� 
	
	
	function( p, left, i-1 );                  //�ݹ���ú������� i ����ظ�ִ���������� 
	function( p, i+1, right );                 //�ݹ���ú������� j �Ҳ��ظ�ִ���������� 
	
	return;
	
}



