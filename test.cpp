/* 1) Create a class student. The student class has data members such as roll number, name of student, father name, mother name, contact number and address. Create the derived class test which contains data members representing class (the class in which the student is studying) name, academic year, name of the test (ct1, ct2, end sem etc), name of subject, and test marks of 5 subjects, maximum marks for each subject. Another derived class Result, may be used to calculate the results, including pass/fail criteria and division allocation. There can be another class called storage, which will store and retrieve the data from binary files, such as adding data, storing sorted data, including student, test and result. Create a menu driver program that can be used by a school, for storing, processing, printing results, finding the toppers of each class, failures in a class. */

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
    bool status_of_result=false;
    
    public:
    Result(const Result& obj1)
    {
        roll_number=obj1.roll_number;
        name=obj1.name;
        father_name=obj1.father_name;
        mother_name=obj1.mother_name;
        contact_number=obj1.contact_number;
        address=obj1.address;
        class_name=obj1.class_name;
        academic_year=obj1.academic_year;
    }
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
            float temp_marks;
            float temp_max_marks;
            cout<<"Enter Subject Name:"<<endl;
            cin>>subj;
            cout<<"Enter Max Marks of subject:"<<endl;
            cin>>temp_max_marks;
            cout<<"Enter Marks obtained: "<<endl;
            cin>>temp_marks;
            marks[subj]=temp_marks;
            max_marks[subj]=temp_max_marks;
        }

        if(name_of_test=="End")
        {
            find(obj,roll_number);
        }
    }
    void calculateResult(Result &ct1, Result &ct2)
    {
        Result r(ct1);
        /* r.roll_number=ct1.roll_number;
        r.name=ct1.name;
        r.father_name=ct1.father_name;
        r.mother_name=ct1.mother_name;
        r.contact_number=ct1.contact_number;
        r.address=ct1.address;
        r.class_name=ct1.class_name;
        r.academic_year=ct1.academic_year; */
        for(auto i : ct1.marks)
        {
            r.marks[i.first]=i.second+ct2.marks[i.first]+this->marks[i.first];
        }
        
    }
    void decideResult(Result r)
    {
        for(auto it:r.marks)
        {
            if(r.marks[it.first]<35)
            {
                r.status_of_result=true;
            }
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

        calculateResult(v2[0],v2[1]);
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