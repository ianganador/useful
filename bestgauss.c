#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float boxy(float stdv, float mean){  
	float x, y, r, G1, G2;
	do{
		x=2.*drand48()-1.; //random number 0-1.
		y=2.*drand48()-1.; //random number 0-1.
		r=x*x+y*y; 
	}
	while(r>=1.);
	r=sqrt((-2.*log(r))/r);
	G1=x*r;
	G2=y*r;
	return(mean+G1*stdv);
}

float exporand(float tau){
	float x;
	x = drand48();
	return -log(1-x)/tau;
}

float unirand(float ul, float ll){
	float stretch, x;
	stretch=ul-ll;
	x=(stretch*drand48())+ll;
	return x;
	}

int main(){
	FILE *fp;

	int i, N, randtype, seed;//randtype sets number generator type, 0=uniform, 1=gaussian, 2=exponential
	float mean, stdev, x, ul, ll, expnt;

	N=10000;		//;set number of samples
	seed=1;
	srand(seed); 	// set seed
	mean=0.;	//set gauss parameters
	stdev=1.;
	ul=1.;		//set uniform rand parameters
	ll=0;
	expnt=1. ;	//set exponential parameters
	randtype=1;

	char data[20];  //file writing
	sprintf(data, "%d_%d.dat", randtype, N );  
	fp=fopen(data,"w");

	if (randtype==0){
		for(i=0; i<N; i++){
			x=unirand(ul, ll);
			fprintf(fp,"%f\n",x);
		}
	}
	else if (randtype==1){
		for(i=0; i<N; i++){
			x=boxy(stdev,mean);
			fprintf(fp,"%f\n",x);
		}
	}
	else if (randtype==2){
		for (i=0; i<N; i++){
			x=exporand(expnt);
			fprintf(fp,"%f\n", x);
		}	
	}
	fclose(fp);
}
