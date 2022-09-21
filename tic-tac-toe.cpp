#include <iostream>
#include <time.h>

using namespace std;


class C_and_Z {
private:

    
    int arr[9];
public:
    int X = 0;
    int O = 1;
    int count = 0;

    int flag=1, zan=0;

    void CIN_X() {
        cout << "Введите крестик от 1 до 9" << endl;
        cin >> X;
    }
    void CIN_O() {
        cout << "Введите нолик от 1 до 9" << endl;
        cin >> O;
    }
    void AddX() {
            if (arr[X - 1] == -1) {
                arr[X - 1] = 1;
            }
            else { cout << "Поле занято" << endl; zan = 1; }
    }
    void AddO() {
            if (arr[O - 1] == -1) {
                arr[O - 1] = 0;
            }
            else { cout << "Поле занято" << endl; zan = 1; }
        
    }
    void Completion_one() {
        for (int i = 0; i <=8; i++) {
            arr[i] = -1;
        }
    }
    void check_win() {
        for (int i = 0; i < 9; i += 3) {
            if ((arr[i]==0) && (arr[i + 1]==0) && (arr[i + 2]==0)) {
                cout << "Нолики выйграли!!!" << endl;
                flag = 0;
            }
            if ((arr[i]==1) && (arr[i + 1]==1) && (arr[i + 2]==1)) {
                cout << "Крестики выйграли!!!" << endl;
                flag = 0;
            }
        }
        for (int i = 0; i < 3; i++) {
            if ((arr[i]==0 && arr[i + 3]==0 && arr[i + 6]==0)) {
                cout << "Нолики выйграли!!!" << endl;
                flag = 0;
            }
            if ((arr[i]==1 && arr[i + 3]==1 && arr[i + 6]==1)) {
                cout << "Крестики выйграли!!!" << endl; 
                flag = 0;
            }
        }
        if ((arr[0]==0 && arr[4]==0 && arr[8]==0)) {
            cout << "Нолики выйграли!!!" << endl;
            flag = 0;
        }
        if ((arr[0]==1 && arr[4]==1 && arr[8]==1) ) {
            cout << "Крестики выйграли!!!" << endl;
            flag = 0;
        }
        if ((arr[2]==0 && arr[4]==0 && arr[6]==0)) {
            cout << "Нолики выйграли!!!" << endl;
            flag = 0;
        }
        if ((arr[2]==1 && arr[4]==1 && arr[6]==1)) {
            cout << "Крестики выйграли!!!" << endl;
            flag = 0;
        }
    }
    void Print() {
        for (int i = 0; i < 9; i++) {
            
             if (arr[i] == -1) {
                cout << "| |" ;
            }
            if (arr[i] ==1) {
                cout << "|x|";
            }
            if (arr[i] == 0) {
                cout << "|0|";
            }
            if (i == 2 || i == 5 || i == 8) {
                cout << ""<<endl;
            }
        }
    }
    void Draw() {
        for (int i = 0; i < 9; i++) {
            if (arr[i] != -1) {
                count += 1;
            }
        }
    }
};

int main()
{
    setlocale(LC_ALL, "ru");
    int Rand;

    C_and_Z a;
    a.Completion_one();
    srand(time(0));
    Rand = 0 + rand() % 2;
    cout<<"|1|2|3|"<<endl<<"|4|5|6|"<<endl<<"|7|8|9|"<<endl;
    
    for (int i = 0; i <= 9; i++) {
        if (Rand == 1) {
            a.CIN_X();
            a.AddX();
            while (a.zan == 1) {
                a.CIN_X();
                a.AddX();

            }
            a.zan = 0;

            a.Print();
            a.check_win();
            Rand = 0;
        }
        if (a.flag == 0) {
            break;
        }
        if (Rand == 0) {
            a.CIN_O();
            a.AddO();
            while (a.zan == 1) {
                a.CIN_O();
                a.AddO();

            }
            a.zan = 0;
            a.Print();
            a.check_win();
            Rand = 1;
        }
        if (a.flag == 0) {
            break;
        }
        if (i == 4) {
            cout << "Ничья";
            break;
        }
    
        
    }
    return 0;
}

