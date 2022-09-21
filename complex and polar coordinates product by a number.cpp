#include <iostream>
#include <ctime>
using namespace std;

class Complex{
public:

	double x,y;
	static Complex rand_c(){
		Complex c;
		c.x=(rand()%20)/10.0+5;
		c.y=(rand()%20)/10.0+5;
		return c;
	}
	void to_str(char* bufer){
		if (y>=0){
			sprintf(bufer, "%.2lf+%2.lfi", x, y);
		}
		else{
			sprintf(bufer, "%.2lf %2.lfi", x, y);
		}
	}
	friend Complex operator*(Complex c, int u)
	{
		return {c.x*u, c.y*u};
	}
};
class Polar{
public:
	double x;
	int y;
	static Polar rand_c(){
		Polar c;
		c.x=(rand()%20)/10.0;
		c.y=(rand()%20);
		return c;
	}
	void to_str(char* bufer){
			sprintf(bufer, "%.2lf %d", x, y);
	}
	friend Polar operator*(Polar c, int u)
	{
		return {c.x*u, c.y};
	}
};
template <typename T>
class Matrix{
public:
	int n,i,j,m;
	T**arr;
	Matrix(int n,int m){
		this->n=n;
		this->m=m;
		arr=new T* [n];
		for (i=0; i<n; i++){
			arr[i]=new T[m];
		}
}
	void Zap(){
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				arr[i][j]=T::rand_c();
			}
		}
	}

	friend Matrix operator *(const Matrix& a, int u){
		Matrix t{a};
		for(int i=0;i<t.n;i++){
			for(int j=0;j<t.m;j++){
				t.arr[i][j] = t.arr[i][j] * u;
			}
		}
		return t;
	}
	Matrix operator=(const Matrix<T>& b){
		for(int i=0;i<b.n;i++){
			for(int j=0;j<b.m;j++){
				arr[i][j].x=b.arr[i][j].x;
				arr[i][j].y=b.arr[i][j].y;
			}
			
		}
		return *this;
	}
	void print(){
		char* bufer=new char[100];
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				arr[i][j].to_str(bufer);
				printf("|%s|\t",bufer);
			}
			printf("\n");
		}
		printf("\n");
	}
};
int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "ru");
	int n,m,flag,v=3;
	
	for(;;){
		cout<<"1-работать с комплексными числами \n 2-работать с координатами в полярной системе\n 0-выйти из программы ";
		cin>>flag;
		if(flag==1){
			cout<<"Введите размер матрицы\n";
			cin>>n>>m;
			cout<<"Введите число на которое хотите умножить\n";
			cin>>v;
			Matrix<Complex> a(n,m);
			Matrix<Complex> b(n,m);
			b.Zap();
			a=b*v;
			a.print();
		}
		if(flag==2){
			cout<<"Введите размер матрицы\n";
			cin>>n>>m;
			cout<<"Введите число на которое хотите умножить\n";
			cin>>v;
			Matrix<Polar> a(n,m);
			Matrix<Polar> b(n,m);
			b.Zap();
			a=b*v;
			a.print();
		}
		if(flag==0){
			break;
		}
	}
}