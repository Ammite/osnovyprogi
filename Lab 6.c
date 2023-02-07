#include<stdio.h>
#include<math.h>
double Func(double x){
	double answer = (pow(x,2) + cos(x)) / pow(x,3);
	return answer;
}
double RiemannL(double a, double b, double h){
	double answer = 0;
	double point = a;
	while(point < b-h){
		answer += Func(point);
		point+=h;
	}
	answer *= h;
	
	return answer;
	
}
double RiemannR(double a, double b, double h){
	double answer = 0;
	double point = a+h;
	while(point < b){
		answer += Func(point);
		point+=h;
	}
	answer *= h;
	
	return answer;
	
}
double RiemannC(double a, double b, double h){
	double answer = 0;
	double point = a;
	while(point < b-h){
		answer += Func(point+h/2);
		point+=h;
	}
	answer *= h;
	
	return answer;
}
double Trapezoidal(double a, double b, double h){
	double answer = 0;
	double point = a+h;
	while(point < b){
		answer += Func(point);
		point+=h;
	}
	answer += ( (Func(a) + Func(b)) / 2 );
	answer *= h;
	
	return answer;
}
double Simpson(double a, double b, int n){
	double answer = 0;
	double point = a;
	double h = (b-a)/n;
	int i;
	for(i=0; i<n;i++){
		if(i == n-1 || i == 0){
			answer += Func(point);
		}
		if(i%2==0){
			answer += (2 * Func(point));
		}else{
			answer += (4 * Func(point));
		}
		point += h;
	}
	answer *= (h/3);
	
	return answer;
	
}
void CalculateAll(double a, double b, int n){
	double h = (b-a)/n;
	
	printf("RiemannL: %f\n", RiemannL(a, b, h));
	printf("RiemannR: %f\n", RiemannR(a, b, h));
	printf("RiemannC: %f\n", RiemannC(a, b, h));
	printf("Trapezoidal: %f\n", Trapezoidal(a, b, h));
	if(n%2!=0){
		n++;
	}
	printf("Simpson: %f\n\n", Simpson(a, b, n));
	
	
}
void main(){
	// F(x) = (x^2 + cos(x)) / (x^3)
	double a, b;
	int n;
	
	while(1){
		printf("Enter a, b, n: ");
		scanf("%lf%lf%d", &a, &b, &n);
		
		
		CalculateAll(a, b, n);
	}
}

