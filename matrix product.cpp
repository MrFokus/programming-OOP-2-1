#include <iostream>#include <vector>#include <ctime>#include <locale>using namespace std;

class MatrixException{
public:
	string text;
	virtual string what()=0;
};
class MatrixParam:public MatrixException{
public:
	MatrixParam(){
		text="Ошибка компиляции";
	}
	MatrixParam(string _text){
		text=_text;
	}
	string what(){
		return text;
	}
};
class MartixSize final:public MatrixParam{
	public:
	MartixSize(): MatrixParam(){
		text="Ошибка. Число столбцов матрицы А равно числу строк матрицы Б";
	}
	MartixSize(string _text): MatrixParam(_text){
		
	}
	string what(){
		return text;
	}
};
class MatrixValue final: public MatrixParam{
public:
	MatrixValue(): MatrixParam(){
		text="Ошибка в синтаксисе ввода";
	}
	MatrixValue(string _text): MatrixParam(_text){
	}
	string what(){
		return text;
	}
};

class Size{
public:
	int m;
	int n;
	friend istream &operator>>(istream& in, Size& b){
		in>>b.m;
		in>>b.n;
		return in;
	}
};class laba {public:	int i, j,  m, n;
	
	friend istream &operator>>(istream& in, laba& b){
		for (int i = 0; i < b.m; i++) {			for (int j = 0; j < b.n; j++) {				in >>b.matrix[i][j];
			}
		}
		return in;
	}	vector<vector<int>> matrix;	friend laba operator *(laba& k, laba& b ) {		laba tmp(k.m,b.n);		for (int i = 0; i < k.m; i++) {			for (int j = 0; j < b.n; j++) {
				tmp.matrix[i][j]=0;				for (int l = 0; l < k.n; l++) {					tmp.matrix[i][j] += k.matrix[i][l] * b.matrix[l][j];				}			}		}		return tmp;	}	laba& operator =(const laba& h) {		for (int i = 0; i < m; i++) {			for (int j = 0; j < n; j++) {				matrix[i][j] = h.matrix[i][j];			}		}		return *this;	}	laba(int m, int n) {
		this->m=m;
		this->n=n;		for (i = 0; i < m; i++) {			matrix.push_back(vector<int>(n));		}
			}
	~laba(){
		for (i=0;i<m;i++){
			matrix[i].clear();
		}
		matrix.clear();
	}	friend ostream& operator<<(ostream& out, laba& c) {
		laba v{c};		for (int i = 0; i < v.m; i++) {			cout << endl;			for (int j = 0; j < v.n; j++) {				out <<"|"<< v.matrix[i][j] << "|";			}			cout << endl;		}
		cout<<"---------------------------------------------------------------------------------------"<<endl;		return out;	}	};
void Exception1(Size size_a, Size size_b){
	if (size_a.n==size_b.m){
		throw MartixSize();
	}
}
void Exception2(laba a, laba b){
	for(int i=0;i<a.m;i++){
		for(int j=0;j<a.n;j++){
			if((a.matrix[i][j]>-100000000)&&(a.matrix[i][j]<100000000)){
				continue;
			}
			else{
				throw MatrixValue();
			}
		}
	}
	for(int i=0;i<b.m;i++){
		for(int j=0;j<b.n;j++){
			if((b.matrix[i][j]>-100000000)&&(b.matrix[i][j]<100000000)){
				continue;
			}
			else{
				throw MatrixValue();
			}
		}
	}
}
int main() {	setlocale(LC_ALL, "ru");	srand(time(0));	int m_size_A, n_size_A, m_size_B, n_size_B;
	Size size_a, size_b;
	cout << "Введите размер для матрицы А" << endl;
	cin >> size_a;
	cout << "Введите размер для матрицы B" << endl;	cin >> size_b;

	for (;;){
		try{			Exception1(size_a, size_b);
			laba a(size_a.m, size_a.n);
			cout<<"Введите значения матрицы А"<<endl;
			cin>>a;
			cout<<"Матрица А";			cout<<a;			laba b(size_b.m,size_b.n);
			cout<<"Введите значения матрицы B"<<endl;
			cin>>b;
			cout<<"Матрица B";			cout<<b;			laba c(size_a.m, size_b.n);			c = a * b;
			cout<<"Матрица C";			cout<<c;
		}
		catch(MartixSize n) {
			cout<<n.what()<<endl;
		}
		catch(MatrixValue m){
			cout<<m.what()<<endl;
		}
		cout << "Введите размер для матрицы А" << endl;
		cin >> m_size_A >> n_size_A;
		cout << "Введите размер для матрицы B" << endl;		cin >> m_size_B >> n_size_B;
	}	
}