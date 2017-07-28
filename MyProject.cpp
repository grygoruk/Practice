#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

struct date {
    short day;
    short month;
    short year;
        };

struct bio {
    string name;
    char sex;
    date BirthDate;
};

struct date SetBirthDate () {
    struct date BD;
    cout << "Born on: ";
    cin >> BD.day >> BD.month >> BD.year;
    return BD;
    }

class Human {
    
    private:
    bio b;
    string n;
    char s;
    struct date d;
    
    public:
    
    Human () {
        cout << "Name: ";
        cin >> b.name;
        cout << "Enter sex: ";
        cin >> b.sex;
        b.BirthDate = SetBirthDate ();
    }
    
    ~Human () {
        cout << "R.I.P., " << b.name << endl;
    }
    struct bio GetBio () {
        return b;}
    friend struct date SetBirthDate ();
};

int main (){
    ofstream reg;
    reg.open ("/storage/emulated/CppDroid/projects/MyProject/register.txt", ios::app);
    
    char ans;
    int cnt = 0;
    
    do {
    M1:
    cout << "Create human? y/n: ";
    cin >> ans;
    switch (ans){
        case 'y': goto M2;
        case 'Y': goto M2;
        case 'n': goto M3;
        case 'N': goto M3;
        default: cout << "Wrong value!" << endl; goto M1;
    };
    M2: {
    Human h1;
    bio b1 = h1.GetBio ();
    reg << ++cnt << ' ' << b1.name << ' ' << b1.sex << ' ' << endl;;
    }
    } while ((ans != 'n') || (ans != 'N'));
    M3:
    cout << "Goodbuy";
    reg.close ();
return 0;
}