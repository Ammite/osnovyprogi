#include<stdio.h>
void main(){
	float M[20][20];
	int n, m, i, j, k;
	float sum[20], tmp_sum, tmp_swap;
	FILE *file;
	FILE *file_w;
	file = fopen("matrix.txt", "r");
	file_w = fopen("sorted_matrix.txt", "w");
	printf("enter matrix size (n*m):\n");
	scanf("%d%d", &n, &m);
	
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			fscanf(file, "%f ", &M[i][j]);
			tmp_sum += M[i][j];
		}
		sum[i] = tmp_sum;
		tmp_sum = 0;
	}
	
	
	float a;
	for(i=0; i<n; i++){
		for(k=0; k<n-1; k++){
			
			if(sum[k] < sum[k+1]){
				tmp_swap = sum[k];
				sum[k] = sum[k+1];
				sum[k+1] = tmp_swap;
				
				for(j=0;j<n;j++){
					tmp_swap = M[k][j];
					M[k][j] = M[k+1][j];
					M[k+1][j] = tmp_swap;
				}
				 
			}
			
		}
	}
	
	
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			printf("%f ", M[i][j]);
			fprintf(file_w, "%f ", M[i][j]);
			
		}
		printf("\n");
		fprintf(file_w, "\n");
	}
	
}

