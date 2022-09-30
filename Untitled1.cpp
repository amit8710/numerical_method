#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int main(){
	int **a, **b, **c, i, j, m=1, r1, c1, r2, c2;
	clrscr();
	printf("Enter size of first matrix");
	scanf("%d%d",&r1,&c1);
	printf("Enter size of second matrix");
	scanf("%d%d",&r2,&c2);
	for(i=0;i<r1;i++){
		*(a+i)=(int*)malloc(size0f(int)*c1);
		*(b+i)=(int*)malloc(size0f(int)*c1);
		*(c+i)=(int*)malloc(size0f(int)*c1);
	}
	printf("Enter element of first matrix:\n");
	for(i=o;i<r1;i++){
		for(j=0;j<c1;j++){
			scanf("%d",(*(a+i)+j));
		}
	}
	printf("Enter element of second matrix:\n");
	for(i=o;i<r2;i++){
		for(j=0;j<c2;j++){
			scanf("%d",(*(b+i)+j));
		}
		}
		if(c1==r2){
			for(i=0;i<r1;i++){
				for(j=0;j<c2;j++){
					*(*(c+i)+j)=0;
					for(k=0;k<c1;k++){
						*(*(c+i)+j)=*(*(c+i)+j)+*(*(a+i)+k)**(*(b+k)+j);
					}
				}
			}
		}
		printf("The result");
		for(i=0;i<r1;i++){
			for(j=0;j<c2;j++){
				printf("%d\t",*(*(c=i)+j));
			}
			printf("\n");
		}
		getch();
}
