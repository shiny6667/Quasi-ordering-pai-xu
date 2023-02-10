#include <stdio.h>

void function(int p[],int left,int right);    //¿ìËÙÅÅĞòº¯Êı 

int main(void)
{
    int n;
	scanf("%d",&n);
	int p[n];
	int i;
	
	
	for ( i = 0; i < n; i++ ){
		scanf("%d",&p[i]);
	}
	
	function(p,0,n-1);
	
	for ( i = 0; i < n; i++ ){
		printf("%d ",p[i]);
	}
	getchar();getchar();
	return 0;
}

//////////////////////////////////////////////
void function(int p[],int left,int right)
{
	int i,j,t,temp;
	
	if ( left > right ){
		return;
	}
	
	temp = p[left];
	i = left;
	j = right;
	
	while ( i != j ){
		
		while ( p[j] >= temp && i < j){
			j--;
		}
		
		while ( p[i] <= temp && i < j){
			i++;
		}
		
		if ( i < j ){
			t = p[i];
			p[i] = p[j];
			p[j] = t;
		}
		
	}
	
	p[left] = p[i];
	p[i] = temp;
	
	
	function(p,left,i-1);
	function(p,i+1,right);
	
	return;
	
}



