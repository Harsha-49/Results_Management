#include<bits/stdc++.h>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
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
    map<string,int> marks;
    map<string,int> max_marks;
    
};
class Result : protected Test
{
    
    public:
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
            float marks;
            float max_marks;
            cout<<"Enter Subject Name:"<<endl;
            cin>>subj;
            cout<<"Enter Max Marks of subject:"<<endl;
            cin>>max_marks;
            cout<<"Enter Marks obtained: "<<endl;
            cin>>marks;
            marks[subj]=marks;
            marks[subj]=max_marks;
        }
        
        cout<<"Enter Address of Student: "<<endl;
        cin>>address;
    }
    Result calculateResult(Result ct1, Result ct2, Result end)
    {
        Result r;
        r.
    }
};
int main()
{
    Result obj1;
    obj1.calculateResult;
    return 0;
}s