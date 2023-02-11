#include <stdio.h>

void function(int p[],int left,int right);    //快速排序函数 (升序) 

int main(void)
{
    int n;                                    //n是希望排序的数字的个数 
	scanf("%d",&n);
	int p[n];                                 //开辟长度为 n 的空间，创建数组p 
	int i;
	
	
	for ( i = 0; i < n; i++ ){                //输入希望排序的n个数字 
		scanf("%d",&p[i]);
	}
	
	function( p, 0, n-1 );                    //调用自定义排序函数 
	
	for ( i = 0; i < n; i++ ){                //遍历输出数组p 
		printf("%d ",p[i]);
	}
	
	return 0;
}

//////////////////////////////////////////////
void function(int p[],int left,int right)     //left和right分别代表数组的最左端和最右端 
{
	int i,j,t,temp;
	
	if ( left > right ){                      //如果left > right，直接跳出函数 
		return;
	}
	
	temp = p[left];                           //选取数组最左端的数作为基准数 
	i = left;
	j = right;
	
	while ( i != j ){                         //如果 i 和 j 不相遇 
		
		while ( p[j] >= temp && i < j){       //j 指的位置只要一直大于基准数，并且 i 和 j 不相遇，j就一直左移 
			j--;
		}
		
		while ( p[i] <= temp && i < j){       //i 指的位置只要一直小于基准数，并且 i 和 j 不相遇，i就一直右移
			i++;
		}
		
		if ( i < j ){                         //交换 i 和 j 所指向的数值 
			t = p[i];
			p[i] = p[j];
			p[j] = t;
		}
		
	}
	
	p[left] = p[i];                            //此时 i 和 j 相遇，将此时 i (或 j) 指向的值，
	p[i] = temp;                               //与数组最左端的temp互换 
	
	
	function( p, left, i-1 );                  //递归调用函数，对 i 左侧重复执行上述过程 
	function( p, i+1, right );                 //递归调用函数，对 j 右侧重复执行上述过程 
	
	return;
	
}



