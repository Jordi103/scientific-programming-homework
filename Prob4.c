#include<stdio.h>
#include<math.h>

double funcio(double x);


int main(){
	int n;

	printf("Calcularemos el valor aproximado de la integral del ejercicio 4 por el método de los trapecios\n\n");
	printf("Escriba el número de veces que quiere partir el intervalo de la integral n=4,8,16,32,64\n");
	scanf("%i",&n);

	if(n==4 || n==8 || n==16 || n==32 || n==64){
	double v[n];
		for (int i = 0; i <= n; ++i){
			v[i]=1 + (4./n)*i;
		}

	double T, ft, nt;
	nt = (2./n);
	ft = funcio(v[0]) + funcio(v[n]);
	for (int j = 1; j <= n-1; ++j)
	{
		ft = ft + 2*funcio(v[j]);
	}
	
	T = nt * ft;
	printf("El valor de la integral del ejercicio por la fórmula del trapezio és %.16G \n",T);
	}

	else{
		printf("El número de divisiones del intervalo no es correcto, tiene que ser n=4,8,16,32,64 \n");
	}

	double e;
	e= 8072./(75*n*n);
	printf("Sabemos que el error será más pequeño que %16.G\n",e);



	return 0;
}

double funcio(double x){
	double f;
	f = exp(x)/x;
	return f;
}