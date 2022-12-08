#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;
class Student{
    protected :
        long rollno;
        long long phno;
        string student_name, father_name, mother_name, address;
        void accept()
        {
            cout << "Enter the name of the student : ";
            cin >> student_name;
            cout << "Enter the roll no : ";
            cin >> rollno;
            cout << "Enter father's name : ";
            cin >> father_name;
            cout << "Enter mother's name : ";
            cin >> mother_name;
            cout << "Enter the contact number : ";
            cin >> phno;
            cout << "Enter the residential address : ";
            getline(cin, address, '.');
        }
};
class Test : protected Student{
    protected :
        string class_name,subj_name,test_name,ac_year;
        string subj_name_arr[5]={"CS201","CS202","CS203","CS204","CS205"};
        string test_name_arr[3]={"ct1database.txt","ct2database.txt","endsemdatabase.txt"};
        string ac_year_arr[4]={"2019-23","2020-24","2021-25","2022-26"};
        string class_name_arr[2]={"CSE","ECE"};
        int subj_marks[5];
        int max;
        double avg;
        int validSubject(string subj)
        {
            for(int i=0;i<5;i++)
            {
                if(subj==subj_name_arr[i])
                return i;
            }
            return -1;
        }
        int validClassname(string c_name)
        {
            if(!(c_name=="CSE" || c_name=="ECE"))
            {
                cout << "The class name entered is invalid\n";
                return 0;
            }
            else
            return 1;
        }
        int validAcyear(string ac_y)
        {
            if(!(ac_y=="2019-23" || ac_y=="2020-24" || ac_y=="2021-25" || ac_y=="2022-26"))
            {
                cout << "The academic year entered is invalid\n";
                return 0;
            }
            else
            return 1;
        }
        int validTestname(string t_name)
        {
            if(t_name=="CT1" || t_name=="CT2")
            return 20;
            else if(t_name=="EndSem")
            return 50;
            else
            {
                cout << "The exam name entered is invalid\n";
                return 0;
            }
        }
        void accept()
        {
            int f,mark;
            cout << "Enter the class name : ";
            cin >> class_name;
            if(!validClassname(class_name))
            return;
            cout << "Enter the academic year of study : ";
            cin >> ac_year;
            if(!validAcyear(ac_year))
            return;
            cout << "Enter the name of examination : ";
            cin >> test_name;
            if((max=validTestname(test_name))==0)
            return;
            for(int i=0;i<5;i++)
            {
                cout << "Enter the name of subject : ";
                cin >> subj_name;
                f=validSubject(subj_name);
                if(f!=-1)
                {
                    cout << "Enter the marks scored in " << subj_name << " out of " << max << " : ";
                    cin >> mark;
                    if(mark<=max && mark>=0)
                    subj_marks[i]=mark;
                    else
                    {
                        cout << "The entered subject mark is invalid\n";
                        i--;
                    }
                }
                else
                {
                    cout << "The entered subject name is invalid\n";
                    i--;
                }
            }
        }
};
class Result : protected Test{
    protected :
        double pc;
        string result;
        int div_no;
        int max_marks[5];
        void resEvaluate()
        {
            avg=0;
            for(int i=0;i<5;i++)
            avg+=subj_marks[i];
            avg/=5.0;
            pc=avg*100.0/max;
            if(pc>=35)
            {
                result="Pass";
                if(pc>=80)
                div_no=1;
                else if(pc>=60 && pc<80)
                div_no=2;
                else if(pc>=35 && pc<60)
                div_no=3;
            }
            else
            result="Fail";
        }
        void printResult()
        {
            string stu_key,ac_year_key,test_name_key,class_name_key,line,stu_check;
            int present_flag=0;
            cout << "Enter the name of the student : ";
            cin >> stu_key;
            cout << "Enter the academic year of study : ";
            cin >> ac_year_key;
            if(!validAcyear(ac_year_key))
            return;
            cout << "Enter the class name : ";
            cin >> class_name_key;
            if(!validClassname(class_name_key))
            return;
            cout << "Enter the name of examination : ";
            cin >> test_name_key;
            if(validTestname(test_name_key)==0)
            return;
            ifstream RDBMS((ac_year_key+""+class_name_key+""+test_name_key+".txt").c_str());
            if(RDBMS.is_open())
            {
                while(RDBMS)
                {
                    present_flag=0;
                    getline(RDBMS, line);
                    for(int i=0;i<line.length();i++)
                    {
                        if(line[i]==':')
                        {
                            stu_check=line.substr(i+2);
                            if(stu_check==stu_key)
                            present_flag=1;
                        }
                    }
                    for(int i=0;i<8;i++)
                    {
                        if(RDBMS)
                        {
                            if(present_flag)
                            cout << line << "\n";
                            getline(RDBMS, line);
                        }
                        else
                        break;
                    }
                    if(present_flag)
                    {
                        cout << line << "\n";break;
                    }
                }
                if(present_flag==0)
                cout << "The entered student name is not present in the roll of this class\n";
                RDBMS.close();
            }
        }
        void topperCalc()
        {
            string ac_year_top,class_name_top,test_name_top;
            int top_index,index=0;
            double stu_mark, topper=0.0;
            string stu_top,line,info="";
            vector<string>tot_info;
            cout << "\nEnter the academic year of study : ";
            cin >> ac_year_top;
            if(!validAcyear(ac_year_top))
            return;
            cout << "Enter the class name : ";
            cin >> class_name_top;
            if(!validClassname(class_name_top))
            return;
            cout << "Enter the name of examination : ";
            cin >> test_name_top;
            if(validTestname(test_name_top)==0)
            return;
            ifstream RDBMS((ac_year_top+""+class_name_top+""+test_name_top+".txt").c_str());
            if(RDBMS.is_open())
            {
                while(RDBMS)
                {
                    getline(RDBMS, line);
                    info="";
                    for(int i=0;i<8;i++)
                    {
                        info+=line+"\n";
                        if(RDBMS)
                        {
                            for(int i=0;i<line.length();i++)
                            {
                                if(line[i]==':' && line.substr(0,i-1)=="Aggregate Percentage")
                                {
                                    stu_mark=stod(line.substr(i+2));
                                    if(stu_mark>topper)
                                    {
                                        topper=stu_mark;
                                        top_index=index;
                                    }
                                }
                            }
                            getline(RDBMS, line);
                        }
                        else
                        break;
                    }
                    tot_info.push_back(info);
                    index++;
                }
                cout << "Topper of the class is : \n";
                cout << tot_info[top_index];
                RDBMS.close();
            }
        }
        void failureCalc()
        {
            string ac_year_f,class_name_f,test_name_f;
            int index=0;
            vector<int>f_index;
            double stu_mark;
            string stu_f,line,info;
            vector<string>tot_info;
            cout << "\nEnter the academic year of study : ";
            cin >> ac_year_f;
            if(!validAcyear(ac_year_f))
            return;
            cout << "Enter the class name : ";
            cin >> class_name_f;
            if(!validClassname(class_name_f))
            return;
            cout << "Enter the name of examination : ";
            cin >> test_name_f;
            if(validTestname(test_name_f)==0)
            return;
            ifstream RDBMS((ac_year_f+""+class_name_f+""+test_name_f+".txt").c_str());
            if(RDBMS.is_open())
            {
                while(RDBMS)
                {
                    getline(RDBMS, line);
                    info="";
                    for(int i=0;i<8;i++)
                    {
                        info+=line+"\n";
                        if(RDBMS)
                        {
                            for(int i=0;i<line.length();i++)
                            {
                                if(line[i]==':' && line.substr(0,i-1)=="Aggregate Percentage")
                                {
                                    stu_mark=stod(line.substr(i+2));
                                    if(stu_mark<35)
                                    f_index.push_back(index);
                                }
                            }
                            getline(RDBMS, line);
                        }
                        else
                        break;
                    }
                    tot_info.push_back(info);
                    index++;
                }
                cout << "Failures of the class are : \n";
                for(int i=0;i<f_index.size();i++)
                {
                    cout << tot_info[f_index[i]];
                }
                RDBMS.close();
            }
        }
};
class Storage : protected Result{
    protected :
        void storeData()
        {
            ofstream SDBMS("student_database.txt", fstream::app);
            SDBMS << "Student Name : " << student_name << "\n";
            SDBMS << "Roll No : " << rollno << "\n";
            SDBMS << "Father's Name : " << father_name << "\n";
            SDBMS << "Mother's Name : " << mother_name << "\n";
            SDBMS << "Contact No : " << phno << "\n";
            SDBMS << "Residential Address : " << address << "\n";
            SDBMS.close();
            ofstream RDBMS;
            RDBMS.open((ac_year+""+class_name+""+test_name+".txt").c_str() , fstream::app);
            RDBMS << "Student Name : " << student_name << "\n";
            RDBMS << "Roll No : " << rollno << "\n";
            for(int i=0;i<5;i++)
            RDBMS << subj_name_arr[i] << " : " << subj_marks[i] << "\n";
            resEvaluate();
            RDBMS << "Aggregate Percentage : " << pc << "\n";
            if(result=="Pass")
            RDBMS << "Passed by Division " << div_no << "\n";
            else
            RDBMS << "Fail\n";
        }
};
class Menu : protected Storage{
    public :
        void menuFunc()
        {
            int ch,stop_flag=0;
            while(1)
            {
                cout << "\n\nThe menu contains the following set of feasible operations that can be done :\n";
                cout << "1. Storing the data\n";
                cout << "2. Printing the data\n";
                cout << "3. Calculating the toppers from the data\n";
                cout << "4. Calculating the failures from the data\n";
                cout << "5. Exit\n\n";
                cin >> ch;
                switch(ch)
                {
                    case 1 :
                    Student :: accept();
                    Test :: accept();
                    Storage :: storeData();
                    break;
                    case 2 :
                    Result :: printResult();
                    break;
                    case 3 :
                    Result :: topperCalc();
                    break;
                    case 4 :
                    Result :: failureCalc();
                    break;
                    case 5 :
                    cout << "\n\t\t\t\t\tThank you !!!!\n";
                    stop_flag=1;
                    break;
                    default :
                    cout << "Enter any valid number between 1-5\n";
                }
                if(stop_flag)
                break;
            }
        }
};
int main()
{
    cout << "\n  Welcome to the IIIT Tiruchirappalli College Database Management System !!!!!\n"; 
    Menu m;
    m.menuFunc();
    return 0;
}