#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164

double f(double x){
    return 1./(1+25*x*x);
}

void equidistants (int n, double *eqs){
    int i;
    
    for (i=0; i<=n; i++){
        eqs[i] = -1 + i*2./n;
//	printf("eqs[%d] = %.16G\n", i, eqs[i]);
    }
}

void chebyshev(int n, double *che){
    int i;
    
    
    for (i=0; i<=n; i++){
        che[i] = cos((2*i+1)*PI/(2*(n+1)));
// 	printf("che[%d] = %.16G\n", i, che[i]);
    }
}

void coeficients(int n, double *suports, double **coefs){
    int i,j;
    
    for (j=0; j<=n; j++){
        coefs[0][j] = f(suports[j]);
//	printf("coefs[0][%d] = %.16G\n", j, coefs[0][j]);
// 	printf("punts[%d] = %.16G\n", j, punts[j]);
    }
    for(i=1; i<=n; i++){
        for (j=0; j<=(n-i); j++){
            coefs[i][j] = (coefs[i-1][j+1]-coefs[i-1][j])/(suports[j+i]-suports[j]);
//	    printf("coefs[%d][%d] = %.16G\n", i, j, coefs[i][j]);
        }
    }
}


void polinomi(int n, int npunts, double *suports, double **coefs, double **sort){
    int i, j, punt;
    for (i=0; i<npunts; i++){
        sort[i][0] = -0.989 + i*0.011;
//         printf("sort[%d][0] = %.16G\n", i, sort[i][0]);
    }    
    
    double terme;
    for(punt=0; punt<npunts; punt++){
        sort[punt][1] = coefs[0][0];
        for (i=1; i<=n; i++){
            terme = coefs[i][0];
            for (j=0; j<i; j++){
                terme *= sort[punt][0]-suports[j];
//                 printf("%.16G\n", terme);
            }
            sort[punt][1] += terme;
//             printf("%.16G\n", sort[punt][1]);
        }
	// error en lugar de el polinomio
	sort[punt][1] = fabs(f(sort[punt][0])-sort[punt][1]);
    }

}
                
        
        
int main() {
    int i,n, npunts=180, opcio;
    double *suports, **coefs, **sort;

    printf("Introducid el numero de puntos de soporte: ");
    if(scanf("%d", &n)==0);
    printf("\n");
    
    
    suports = (double*)malloc((n+1)*sizeof(double));
    coefs = (double**)malloc((n+1)*sizeof(double*));
    sort = (double**)malloc(npunts*sizeof(double*));
    
    for (i=0; i<=n; i++){
      coefs[i] = (double*)malloc((n+1)*sizeof(double));
    }
    for(i=0; i<npunts; i++){
	sort[i] = (double*)malloc(2*sizeof(double));
    }
    
    
    printf("Para utilizar una distribucion de puntos equidistantes pulsar 0.\n");
    printf("Para utilizar la distribucion de Chebyshev pulsar 1.\n");
    if(scanf("%d", &opcio)==0);
    
    switch(opcio){
      case(0):
	equidistants(n, suports);
	break;
      case(1):
	chebyshev(n, suports);
	break;
    }
	
    coeficients(n, suports, coefs);
    polinomi(n, npunts, suports, coefs, sort);

    FILE *fitxer;
    fitxer = fopen("puntos.txt", "w");
    
    for(i=0; i<npunts; i++){
        fprintf(fitxer, "%.16G %.16G\n", sort[i][0], sort[i][1]);
    }
           
    printf("Puntos escritos en el fichero \"puntos.txt\"\n");                                                                                        
    return 0;
}
