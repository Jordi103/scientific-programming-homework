#include<stdio.h>
#include<math.h>

double funcio(double x);

int main(){

	printf("El intervalo que tenemos es [1,2]. Segun los resultados del ejercicio 5, h=1/2, h es la medida de los subintervalos.\n");

	double a=1, b=2, c;
	c = (a+b)/2.;	

	double S;
	S= (1/6.)*(funcio(a) + 4*funcio(c) + funcio(b));
	printf("Por lo tanto, el valor de la integral del ejercicio por la fórmula Simpson és %.16G \n",S);










	return 0;
}

double funcio(double x){
	double f;
	f = log(x);
	return f;
}