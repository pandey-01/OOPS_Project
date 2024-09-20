#include<iostream>
#include<fstream>
using namespace std;
class Employee
{
    string name;
    int id;
    double salary;
    public:
    void accept()
    {
        cout<<"Enter Name: ";
        cin.ignore();
        getline(cin,name);
        // cout<<endl;
        cout<<"Enter ID: ";
        cin>>id;
        // cout<<endl;
        cout<<"Enter Salary: ";
        cin>>salary;
        // cout<<endl;

    }
    void display()
    {
        cout<<"\nName : "<<name;
        cout<<"\nId : "<<id;
        cout<<"\nSalary : "<<salary<<endl;
    }
};
int main()
    {
        Employee o[10];
        fstream f;
        int i,n;
        f.open("demo.txt",ios::out);
        cout<<"\n Enter the number of employees you want to store : ";
        cin>>n;
        for(i=0;i<n;i++)
        {
        cout<<"\nEnter information of Employee "<<i+1<<"\n";
        o[i].accept();
        f.write((char*)&o[i],sizeof o[i]);
        }
        f.close();

        f.open("demo.txt",ios::in);
        cout<<endl;
        cout<<"Information of Employees is as follows"<<endl;
        for(i=0;i<n;i++)
        {
           cout<<"\nEmployee "<<i+1<<" : "; 
           f.write((char*)&o[i],sizeof(o[i]));
           o[i].display(); 
        }
        f.close();
        return 0;
    }