#include <iostream>

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
};
	
	friend istream &operator>>(istream& in, laba& b){
		for (int i = 0; i < b.m; i++) {
			}
		}
		return in;
	}
				tmp.matrix[i][j]=0;
		this->m=m;
		this->n=n;
		
	~laba(){
		for (i=0;i<m;i++){
			matrix[i].clear();
		}
		matrix.clear();
	}
		laba v{c};
		cout<<"---------------------------------------------------------------------------------------"<<endl;
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

	Size size_a, size_b;
	cout << "Введите размер для матрицы А" << endl;
	cin >> size_a;
	cout << "Введите размер для матрицы B" << endl;

	for (;;){
		try{
			laba a(size_a.m, size_a.n);
			cout<<"Введите значения матрицы А"<<endl;
			cin>>a;
			cout<<"Матрица А";
			cout<<"Введите значения матрицы B"<<endl;
			cin>>b;
			cout<<"Матрица B";
			cout<<"Матрица C";
		}
		catch(MartixSize n) {
			cout<<n.what()<<endl;
		}
		catch(MatrixValue m){
			cout<<m.what()<<endl;
		}
		cout << "Введите размер для матрицы А" << endl;
		cin >> m_size_A >> n_size_A;
		cout << "Введите размер для матрицы B" << endl;
	}
}