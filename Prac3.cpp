/*
Imagine a publishing company which does marketing for book
and audiocassette versions.
 Create a class publication that stores the title (a string)
and price (type float) of a
 publication.From this class derive two classes: book, which
adds a page count(type int),
 and tape, which adds a playing time in minutes(type float).
 Write a program that instantiates the book and tape classes,
allows user to enter data and
 displays the data members.If an exception is caught, replace
all the data member values
 with zero values.
*/

#include<iostream>
#include<stdio.h>
using namespace std;
class publication{
    string title;
    float price;
    public:
        void addit(){
            cout<<"Enter Details : "<<endl;
            cout<<"Enter title of publication : ";
            cin.ignore();
            getline(cin,title);
            cout<<"Enter price of publication : ";
            cin>>price;
        }
        void dispdata(){
            cout<<"Title : "<<title<<endl;
            cout<<"Price : "<<price<<endl;
        }
};
class book:public publication{
    int pg_cnt;
    public:
        void add(){
            addit();
            cout<<"Enter Page count : ";
            cin>>pg_cnt;
            if(pg_cnt<=0){
                cout<<"Invalid Input...\n";
                pg_cnt=0;
            }
        }
        void disp(){
            dispdata();
            cout<<"Page Count : "<<pg_cnt<<endl;
        }
};
class tape:public publication{
    float pl_time;
    public:
        void add(){
            addit();
            cout<<"Enter Play time : ";
            cin>>pl_time;
            if(pl_time<=0){
                cout<<"Invalid Input...\n";
                pl_time=0;
            }
        }
        void disp(){
            dispdata();
            cout<<"Play Time : "<<pl_time<<endl;
        }
};
int main(){
    book b;
    tape t;
    while(true){
        cout<<"\n\n1.Add Books\n2.Add Tape\n3.Display Books\n4.Display Tapes\n5.Exit\n";
        cout<<"\nEnter Your choice : ";
        int y;
        cin>>y;
        if(y==1){
            b.add();
        }
        else if(y==2){
            t.add();
        }
        else if(y==3){
            b.disp();
        }
        else if(y==4){
            t.disp();
        }
        else{
            break;
        }
    }
}