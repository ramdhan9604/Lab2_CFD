#include<iostream>
#include<iomanip>
#include<cmath>

#define X 5
#define T 3

using namespace std;

float f(float x){
    float pi=3.14;
	return (sin(pi*x));
}
//using namespace std;


int main(){
	float u[X+1][T+1],h=0.2,k=0.02,csqr,alpha,ust,uet;
	int i,j;
	cout<<"Enter the  square  of 'c'"<<endl;
	cin>>csqr;
	alpha=(csqr*k)/(h*h);
	cout<<"Enter the value of u[0,t]:"<<endl;
	cin>>ust;
	cout<<"Enter the value of u["<<1<<",t]:"<<endl;
	cin>>uet;
	cout<<fixed;
	for(j=0;j<=T;j++){
		u[0][j]=u[X][j]=ust;
	}
	for(i=1;i<=X-1;i++){
		u[i][0]=f(i*h);
	}
	for(j=0;j<=T-1;j++){
		for(i=1;i<=X-1;i++){
			u[i][j+1]=alpha*u[i-1][j]+(1-2*alpha)*u[i][j]+alpha*u[i+1][j];
		}
	}
	cout<<"The value of alpha is"<<setw(4)<<setprecision(2)<<alpha<<endl;
	cout<<"The values of u[i,j] are:-"<<endl;
	
	for(j=0;j<=T;j++){
		for(i=0;i<=X;i++){
			cout<<setw(7)<<setprecision(2)<<u[i][j];
		}
		cout<<endl;
	}
	return 0;
	
}
