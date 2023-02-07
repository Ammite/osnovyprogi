#include<stdio.h>
float InterpolationLagrangePolynomial(float x, float* xes, float* yes, int m, int n, int xi_id){
	float lagrange_pol = 0;
	float basics_pol;
	int i, j, l, r;
	
	l = xi_id - (n+1)/2;
	r = xi_id + (n+1)/2;
	
	if(xi_id - (n+1)/2 < 0){
		l = 0;
	}
	if(xi_id + (n+1)/2 > m){
		r = m-1;
	}
	
	
	for ( i = 0; i <= r; i++)
	{
		basics_pol = 1;
		for ( j = 0; j <= r; j++)
		{
			if (j == i) continue;
			basics_pol *= (x - xes[j])/(xes[i] - xes[j]);		
		}
		lagrange_pol += basics_pol*yes[i];
	}
	return lagrange_pol;
}

void main(){
	// m 130 n 20 
	// -10 ... 119
	int m = 130, i, n = 20;
	float xes[m];
	float yes[m];
	float x;
	float x0=10000000, xm=-1000000, xi;
	int xi_id;
	FILE*file;
	file = fopen("interpolation.txt", "r");
	
	for(i=0; i<m; i++){
		fscanf(file, "%f %f", &xes[i], &yes[i]);
		
		if(xes[i] < x0){
			x0 = xes[i];
		}
		if(xes[i] > xm){
			xm = xes[i];
		}
	}
	
	
	while(1){
		printf("Enter x and n:");
		scanf("%f%d", &x, &n);
		
		for(i=0;i<m;i++){
			if(xes[i] > x){
				xi = xes[i];
				xi_id = i;
				break;
			}
		}
		
		if(x < x0 || x > xm){
			printf("Error! x is not in range!");
			return;
		}
		
		float answer = InterpolationLagrangePolynomial(x, xes, yes, m, n, xi_id);
		
		printf("Answer is: %f\n", answer);
		
	}
	
}

