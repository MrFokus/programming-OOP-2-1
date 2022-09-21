#include <iostream>
#include <cmath>
#include <vector>
#include <locale>

using namespace std;

class Vector{
public:
	virtual double Prim(double a,double b,double x,double c)=0;

};
class Vir1:public Vector
{
	
	double Prim(double a,double b,double x,double c) override{
		double rez;
		rez=a*sin(x*b);
		return rez;
		
	}
};
class Vir2:public Vector
{
	double Prim(double a,double b,double x,double c) override{
		double rez;
		rez=a*log10(x*b)+c;
		return rez;
		
	} 
};
class User{
public:
	double x, a, b, c;
	int N;
	vector<double> skal;
	void Zap(Vector *one){
		double cout;
		cout=one->Prim(a,b,x,c);
		skal.push_back(cout);
	}
	void Print(){
		for(int i=0; i<N; i++){
			printf("y%d=%f\n", i+1, skal[i]);
		}
	}
	User(){
		cout<<"Введите размер вектора"<<endl;
		cin>>N;
		skal.reserve(N);
		cout<<"Введите x "<<endl;
		cin>>x;
	}
	void Dob(int flag){
		if (flag==1){
			
			cout<<"Введите a "<<endl;
			cin>>a;
			cout<<"Введите b "<<endl;
			cin>>b;
		}
		if(flag==2){
			cout<<"Введите a "<<endl;
			cin>>a;
			cout<<"Введите b "<<endl;
			cin>>b;
			cout<<"Введите c"<<endl;
			cin>>c;
		}
	}

	
};
int main() {
	setlocale(LC_ALL, "ru");
	int flag;
	Vir1 vir1;
	Vir2 vir2; 
	User user;
	for(int i=0; i<user.N;i++){
		cout<<" Если вы хотите посчитать первым способом (a*sin(x*b)), то введите 1, если вы хотите посчитать вторым способом (a*lg(x*b)+c), то введите 2"<<endl; 
		cin>>flag;
		if ((flag!=1)&&(flag!=2)){
			cout<<"Введи 1 или 2!"<<endl;
			i--;
		}
		if (flag==1){
			user.Dob(flag);
			user. Zap(&vir1);
			
		}
		if (flag==2){
			user.Dob(flag);
			user. Zap(&vir2);
		}
		
	}
	user.Print();
}