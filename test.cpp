#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
#include<fstream>
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
class Test : public Student
{
    protected:
    string class_name;
    string academic_year;
    string name_of_test;
    map<string,float> marks;
    map<string,float> max_marks;
    
};
class Result : public Test
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

        if(name_of_test=="End")
        {
            find(obj,roll_number);
        }
    }
    void calculateResult(Result &ct1, Result &ct2, Result &end)
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
        for(auto i : ct1.marks)
        {
            r.marks[i.first]=i.second+ct2.marks[i.first]+end.marks[i.first];
        }
        
    }


    void find(const Storage &obj ,string roll_number)
    {
        vector<Result>v2;
        for(auto i : obj.v1)
        {
            if(roll_number==i.roll_number)
            {
                v2.push_back(i);
            }
        }

        calculateResult(v2[0],v2[1],v2[2]);
    }
};

class Storage
{
    public :
    vector<Result>v1;

    void insertToBinaryFile(const Result &obj)
    {
        ofstream file("binaryFile", ios::app | ios::binary);
        file.write((char *) &obj,sizeof(Result));
    }

    void readFromBinaryFile()
    {
        Result object;
        ifstream file("binaryFile",ios::in | ios::binary);
        while(!file.eof())
        {
            file.read((char *)&object,sizeof(Result));
            v1.push_back(object);

            if(file.gcount()==0)
            {
                break;
            }
        }
    }

    friend class Result;


}obj;

int main()
{
    Result obj1;
    // obj1.calculateResult();
    return 0;
}