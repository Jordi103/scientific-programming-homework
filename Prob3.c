#include<stdio.h>
#include<math.h>

double funcio(double x);
void menu();
void trapezio();
void simpson();

int main(){

	menu();

	return 0;
}

void menu(){
	int opc;

	do{
		printf("\n1. Método de los trapezios.");
		printf("\n2. Método de Simpson.");
		printf("\n3. Salir.");
		printf("\nOpción:");
		scanf("%i",&opc);

		switch(opc){ //condicional múltiple, la sentencia switch
			case 1: trapezio();break;
			case 2: simpson();break;
			case 3: printf("Saliendo\n");break;
			default: printf("No ha puesto un número correcto\n");
		}

	}while(opc != 3);
}

void trapezio(){
	double x0,x1,x2,x3,x4;
	double T;
	x0=0;
	x1=0.25;
	x2=0.5;
	x3=0.75;
	x4=1;
	T = (1/8.)*(funcio(x0) + 2*funcio(x1) + 2*funcio(x2) + 2*funcio(x3) + funcio(x4));
	printf("Dividimos el intervalo [0,1], en cuatro partes iguales, obteniendo x0 = 0, x1 = 0.25, x2 = 0.5, x3 = 0.75, x4 = 1\n\n");
	printf("El valor de la integral del ejercicio por la fórmula del trapezio és %.16G \n",T);
}

void simpson(){
	double x0,x1,x2,x3,x4;
	double S;
	x0=0;
	x1=0.25;
	x2=0.5;
	x3=0.75;
	x4=1;
	S = (1/12.)*(funcio(x0) + 4*funcio(x1) + 2*funcio(x2) + 4*funcio(x3) + funcio(x4));
	printf("Dividimos el intervalo [0,1], en cuatro partes iguales, obteniendo x0 = 0, x1 = 0.25, x2 = 0.5, x3 = 0.75, x4 = 1\n\n");
	printf("El valor de la integral del ejercicio por la fórmula Simpson és %.16G \n",S);

}

double funcio(double x){
	double f;
	f = 1/(1 + x*x);
	return f;
}