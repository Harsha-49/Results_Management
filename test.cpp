#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
#include<fstraem>
#include<iterator>
using namespace std;
class Student
{
    protected:
    string roll_number;
    string name;
    string father_name;
    string mother_name;
    string contact_number;
    string address;
};
class Test : protected Student
{
    protected:
    string class_name;
    string academic_year;
    string name_of_test;
    map<string,float> marks;
    map<string,float> max_marks;
    
};
class Result : protected Test
{
    
    public:
    Result(){};
    Result()
    {
        cout<<"Enter Name of Student: "<<endl;
        cin>>name;
        cout<<"Enter Roll number of Student: "<<endl;
        cin>>roll_number;
        cout<<"Enter Father Name of Student: "<<endl;
        cin>>father_name;
        cout<<"Enter Mother Name of Student: "<<endl;
        cin>>mother_name;
        cout<<"Enter Contact Number of Student: "<<endl;
        cin>>contact_number;
        cout<<"Enter Address of Student: "<<endl;
        cin>>address;
        cout<<"Enter Class Name of Student: "<<endl;
        cin>>class_name;
        cout<<"Enter Academic Year of Student: "<<endl;
        cin>>academic_year;
        cout<<"Enter name of test of which marks will be entered: "<<endl;
        cin>>name_of_test;

        for(int i=0;i<5;i++)
        {
            string subj;
            float tempmarks;
            float tempmax_marks;
            cout<<"Enter Subject Name:"<<endl;
            cin>>subj;
            cout<<"Enter Max Marks of subject:"<<endl;
            cin>>tempmax_marks;
            cout<<"Enter Marks obtained: "<<endl;
            cin>>tempmarks;
            marks[subj]=tempmarks;
            max_marks[subj]=tempmax_marks;
        }
    }
    Result calculateResult(Result &ct1, Result ct2, Result end)
    {
        Result r;
        r.roll_number=ct1.roll_number;
        r.name=ct1.name;
        r.father_name=ct1.father_name;
        r.mother_name=ct1.mother_name;
        r.contact_number=ct1.contact_number;
        r.address=ct1.address;
        r.class_name=ct1.class_name;
        r.academic_year=ct1.academic_year;
        r.name_of_test=ct1.name_of_test;
        for(auto it: ct1.marks)
        {
            r.
        }
    }
};

class Storage
{
    public :

    void insertToBinaryFile(const Result &obj)
    {
        ofstream file("student.dat", ios::out | ios::binary);
        file.write((char *) &obj,sizeof(Result));
        
    }


}

int main()
{
    Result obj1;
    // obj1.calculateResult();
    return 0;
}