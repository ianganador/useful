#include <stdio.h>
#include <math.h>
float mean(int n, float *x);
float variance(int n, float *x, float ave);
float standev(int n, float *x, float var);

int main(){
	float m,v,st;
	float x[]={0,1,2,3,4,5,6,7,8,9};
	int n=10;

	m=mean(n,x);
	v=variance(n,x,m);
	st=sqrt(v);
	printf("%f %f %f\n", m,v,st);
}

float mean(int n, float *x){
	float ave=0;
	int i;
	for(i=0;i<n;i++){
		ave+=x[i];
	}
	ave=ave/n;
	return ave;
}
  
float variance(int n, float *x, float ave){
	float diff=0;
	float var=0;
	int i;
	for(i=0;i<n;i++){
		diff=(x[i]-ave)*(x[i]-ave);
		var+=diff;
	}
	var=var/(n-1);
	return var;
}




