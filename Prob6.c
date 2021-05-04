#include<stdio.h>

#define NPUNTS 15

double trapezi(double a, double b, double fa, double fb);
double trapezi_composta(int n, double *t, double *v);

int main() {
	double t[NPUNTS] = {0,6,12,18,24,30,36,42,48,54,60,66,72,78,84};
	double v[NPUNTS] = {37.2,40.2,44.4,40.8,44.1,39.9,36.3,32.7,29.7,25.5,23.4,26.7,31.2,34.8,36.9};
	
	printf("Longitud de la pista: %.16Gm\n", trapezi_composta(NPUNTS, t, v));
	return 0;
}


double trapezi(double a,double b,double fa,double fb) {
	return (fa+fb)*(b-a)/2;
}

double trapezi_composta(int n, double *t, double *v) {
	int i;
	double total = 0;

	for (i=0; i<n-1; i++) {
		total += trapezi(t[i], t[i+1], v[i], v[i+1]);
	}
	return total;
}

