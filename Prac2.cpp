#include <iostream>
#include <string>
using namespace std;

class StudData;

class Student {
private:
    string name;
    int roll;
    int clas;
    char div;
    string dob;
    string bld_grp;
    static int cnt;

public:
    Student() : name(""), roll(0), clas(0), div(' '), dob("dd/mm/yyyy"), bld_grp("") {
        cnt++;
    }

    Student(string n, int r, int c, char d, string dob, string bg)
        : name(n), roll(r), clas(c), div(d), dob(dob), bld_grp(bg) {
        cnt++;
    }

    Student(const Student& other)
        : name(other.name), roll(other.roll), clas(other.clas),
          div(other.div), dob(other.dob), bld_grp(other.bld_grp) {
        cnt++;
    }

    ~Student() {
        cnt--;
    }

    static int getCount() {
        return cnt;
    }

    void getData(StudData* st);
    void dispData(StudData* st) const;
};

int Student::cnt = 0;

class StudData {
private:
    string caddr;
    long tele;
    long dl_no;

public:
    StudData() : caddr(""), tele(0), dl_no(0) {}

    void getStudData() {
        cout << "Enter Contact Address: ";
        cin.ignore();
        getline(cin, caddr);
        cout << "Enter Telephone Number: ";
        cin >> tele;
        cout << "Enter Driving License Number: ";
        cin >> dl_no;
    }

    void dispStudData() const {
        cout << "Contact Address: " << caddr << endl;
        cout << "Telephone Number: " << tele << endl;
        cout << "Driving License Number: " << dl_no << endl;
    }
};

inline void Student::getData(StudData* st) {
    cout << "Enter Student Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Roll Number: ";
    cin >> roll;
    cout << "Enter Class: ";
    cin >> clas;
    cout << "Enter Division: ";
    cin >> div;
    cout << "Enter Date of Birth: ";
    cin.ignore();
    getline(cin, dob);
    cout << "Enter Blood Group: ";
    cin >> bld_grp;
    st->getStudData();
}

inline void Student::dispData(StudData* st) const {
    cout << "Student Name: " << name << endl;
    cout << "Roll Number: " << roll << endl;
    cout << "Class: " << clas << endl;
    cout << "Division: " << div << endl;
    cout << "Date of Birth: " << dob << endl;
    cout << "Blood Group: " << bld_grp << endl;
    st->dispStudData();
}

int main() {
    const int MAX_STUDENTS = 100;
    Student* stud1[MAX_STUDENTS];
    StudData* stud2[MAX_STUDENTS];
    int n = 0;
    char ch;

    do {
        if (n >= MAX_STUDENTS) {
            cout << "Maximum number of students reached." << endl;
            break;
        }

        stud1[n] = new Student;
        stud2[n] = new StudData;

        stud1[n]->getData(stud2[n]);
        n++;

        cout << "Do you want to add another student (y/n): ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');

    for (int i = 0; i < n; i++) {
        cout << "---------------------------------------------------------------" << endl;
        stud1[i]->dispData(stud2[i]);
    }

    cout << "---------------------------------------------------------------" << endl;
    cout << "Total Students: " << Student::getCount() << endl;
    cout << "---------------------------------------------------------------" << endl;

    for (int i = 0; i < n; i++) {
        delete stud1[i];
        delete stud2[i];
    }

    return 0;
}