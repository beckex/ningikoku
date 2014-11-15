#include <stdio.h>
#include <math.h>

#define PI (3.141592653589793)

const double calcDist(double lati1, double longi1, double lati2, double longi2){
	double r=6371*1000;
	double theta1=lati1/360*2*PI;
	double theta2=lati2/360*2*PI;
	double lambda=(longi1-longi2)/360*2*PI;
	double x=lambda*cos((theta1+theta2)/2);
	double y=theta1-theta2;
	return sqrt(pow(x,2)+pow(y,2))*r;
}

const char **checkMsg(const unsigned int userid, const double dist){
	
}


int main(){
	printf("%lf\n", calcDist(0,0,0,1));

}
