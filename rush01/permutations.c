#include <stdio.h>

void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
int cnt = 0;
  
void permutations(int *a, const int k, const int m)
{
  int i;            
  int temp;
 
       
  if(k == m) //순열을 출력
  {
    for(i = 0 ; i <= m ; i ++)
    {
	   	printf("%d ",a[i]);}
	    printf("\n");
		cnt++; // 총 몇가지 경우의 수인지 확인 
  }
 
  else // a[k] a[m]에 있는 여러 순열을 순환적으로 생성
  {
    for(i = k ; i <= m ; i++)  
    {
      swap(&a[k],&a[i]); // a[k]와 a[i]를 교환
      permutations(a,k+1,m); // a[k+1],...a[m]에 대한 모든 순열
                             // 원래 상태로 되돌리기 위해 a[k]와 a[i]를 다시 교환
      swap(&a[k],&a[i]); 
    }
  }
}
int main(void)
{
	int n;
	int arr[] = {1, 2, 3, 4};

	permutations(arr, 0, 3);
	printf("cnt = %d\n", cnt);
}
