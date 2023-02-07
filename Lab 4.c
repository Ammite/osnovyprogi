#include<stdio.h>
#include<math.h>
#define PI 3.14159265
float a0, a1, a2, x0, eps = 0.001;

float Fu(float x){
	// F(x) = a0 + a1*cos(3x) + a2 * x
	return a0 + a1 * cos(3*x) + a2 * x;
}
float Fd(float x){
	// F'(x) = -3 * a1 * sin(3x) + a2
	return a2 - 3 * a1 * sin(3*x);
}

float FindRoot(){
	float x, f, fd;
	
	while(1){
		f = Fu(x0);
		fd = Fd(x0);
		x = x0 - f/fd;
		if( fabs(x0 - x) < eps){
			break;
		}
		x0 = x;
		
		//printf("%f, %f, %f\n", x, f, fd);
	}
	
	return x;
}

void main(){

	float x;
	
	
	while(1){
		printf("Enter a0, a1, a2, x0, eps: ");
		scanf("%f%f%f%f%f", &a0, &a1, &a2, &x0, &eps);
	
		x = FindRoot();
	
		printf("Answer:\nX:%f   F(x):%f\n\n", x, Fu(x));
	}
	

}

