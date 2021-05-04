#include<stdio.h>


int main(){
	int n,i,j;
	double x0,x1,x2,x3,x4,x5;

	printf("Ponga el grado del polinomio (1, 3 o 5)\n");
	scanf("%i",&n);
	printf("Por lo tanto :\n");

if(n==1){
		x0= -0.048383776468198;
		x1= -0.096804954397038;
		
		double coef[n+1][n+1];
		coef[1][1]=0;
		coef[0][0]=2.5;
		coef[1][0]=2.6;
		coef[0][1]= (coef[1][0] - coef[0][0])/(x1 - x0);

		for (i = 0; i <= n; ++i){
			j=0;
			printf("Componente f[x_%i]: %.16G, \t",i,coef[i][j]);
		}
		printf("\n");
		printf("\t Componente f[x_0x_1]: %.16G, \n",coef[0][1]);
	
	    double raiz; //Cuando el polinomio interpolador se evalua en x=0
	    raiz = coef[0][0] - coef[0][1]*x0;
	    printf("El valor de la raiz cuando el polinomio interpolador es de grado 1 es P(x=0)=\t%.16G\n",raiz);
}
	
else if(n==3){
	x0= -0.048383776468198;
	x1= -0.096804954397038;
	x2= -0.142449370046012;
	x3= -0.185036033364387;

	double coef[n+1][n+1];
	coef[0][0]=2.5;
	coef[1][0]=2.6;
	coef[2][0]=2.7;
	coef[3][0]=2.8;
	coef[0][1]= (coef[1][0] - coef[0][0])/(x1 - x0);
	coef[1][1]= (coef[2][0] - coef[1][0])/(x2 - x1);
	coef[2][1]= (coef[3][0] - coef[2][0])/(x3 - x2);
	coef[0][2]= (coef[1][1] - coef[0][1])/(x2 - x0);
	coef[1][2]= (coef[2][1] - coef[1][1])/(x3 - x1);
	coef[0][3]= (coef[1][2] - coef[0][2])/(x3 - x0);

		for (i = 0; i <= n; ++i){
			j=0;
			printf("Componente f[x_%i]: %.16G, \t\t\t",i,coef[i][j]);
		}
		printf("\n\n");
		for ( i = 0; i <= n-1; ++i){
			 j=1;
			printf("Componente f[x_%ix_%i]: %.16G, \t\t",i,i+1,coef[i][j]);
		}
		printf("\n\n");
		for ( i = 0; i <= n-2; ++i){
			 j=2;
			printf("\tComponente f[x_%ix_%ix_%i]: %.16G, \t",i,i+1,i+2,coef[i][j]);
		}
		printf("\n\n");
		printf("\t\t Componente f[x_0x_1x_2x_3]: %.16G, \n",coef[0][3]);
		
		double raiz; //Cuando el polinomio interpolador se evalua en x=0
		raiz = coef[0][0] - coef[0][1]*x0 + coef[0][2]*x0*x1 - coef[0][3]*x0*x1*x2;
		printf("El valor de la raiz cuando el polinomio interpolador es de grado 3 es P(x=0)=\t%.16G\n",raiz);
}
else if(n==5){
	x0= -0.048383776468198;
	x1= -0.096804954397038;
	x2= -0.142449370046012;
	x3= -0.185036033364387;
	x4= -0.224311545791968;
	x5= -0.260051954901934;

	double coef[n+1][n+1];
	coef[0][0]=2.5;
	coef[1][0]=2.6;
	coef[2][0]=2.7;
	coef[3][0]=2.8;
	coef[4][0]=2.9;
	coef[5][0]=3.0;
	coef[0][1]= (coef[1][0] - coef[0][0])/(x1 - x0);
	coef[1][1]= (coef[2][0] - coef[1][0])/(x2 - x1);
	coef[2][1]= (coef[3][0] - coef[2][0])/(x3 - x2);
	coef[3][1]= (coef[4][0] - coef[3][0])/(x4 - x3);
	coef[4][1]= (coef[5][0] - coef[4][0])/(x5 - x4);
	coef[0][2]= (coef[1][1] - coef[0][1])/(x2 - x0);
	coef[1][2]= (coef[2][1] - coef[1][1])/(x3 - x1);
	coef[2][2]= (coef[3][1] - coef[2][1])/(x4 - x2);
	coef[3][2]= (coef[4][1] - coef[3][1])/(x5 - x3);
	coef[0][3]= (coef[1][2] - coef[0][2])/(x3 - x0);
	coef[1][3]= (coef[2][2] - coef[1][2])/(x4 - x1);
	coef[2][3]= (coef[3][2] - coef[2][2])/(x5 - x2);
	coef[0][4]= (coef[1][3] - coef[0][3])/(x4 - x0);
	coef[1][4]= (coef[2][3] - coef[1][3])/(x5 - x1);
	coef[0][5]= (coef[1][4] - coef[0][4])/(x5 - x0);

		for ( i = 0; i <= n; ++i){
			 j=0;
			printf("Componente f[x_%i]: %.16G, \t",i,coef[i][j]);
		}
		printf("\n\n");
		for ( i = 0; i <= n-1; ++i){
			 j=1;
			printf("Componente f[x_%ix_%i]: %.16G, \t",i,i+1,coef[i][j]);
		}
		printf("\n\n");
		for ( i = 0; i <= n-2; ++i){
			 j=2;
			printf("Componente f[x_%ix_%ix_%i]: %.16G, \t",i,i+1,i+2,coef[i][j]);
		}
		printf("\n\n");
		for ( i = 0; i <= n-3; ++i){
			 j=3;
			printf("Componente f[x_%ix_%ix_%ix_%i]: %.16G, \t",i,i+1,i+2,i+3,coef[i][j]);
		}
		printf("\n\n");
		for ( i = 0; i <= n-4; ++i){
			 j=4;
			printf("Componente f[x_%ix_%ix_%ix_%ix_%i]: %.16G, \t",i,i+1,i+2,i+3,i+4,coef[i][j]);
		}
		printf("\n\n");
		printf("Componente f[x_0x_1x_2x_3x_4x_5]: %.16G \n",coef[0][5]);
		
		double raiz; //Cuando el polinomio interpolador se evalua en x=0
		raiz = coef[0][0] - coef[0][1]*x0 + coef[0][2]*x0*x1 - coef[0][3]*x0*x1*x2 + coef[0][4]*x0*x1*x2*x3 - coef[0][5]*x0*x1*x2*x3*x4;
		printf("El valor de la raiz cuando el polinomio interpolador es de grado 5 es P(x=0)=\t%.16G\n",raiz);
}

  else{
	printf("No es un grado posible\n");
	return 0;
  }
  
	return 0;
}