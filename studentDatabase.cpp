#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <fstream>
#include <string.h>

using namespace std;

class marks {private:
                                 char name[20];
                                 char claSec[10];
                                 char house[10];
                                 char admno[10];
                                 int rollno;
                                 int english;
                                 int maths;
                                 int physics;
                                 int chemistry;
                                 int cs;
                                 float percent;
                                 public:
                                 int getRoll();
                                 void dataMenu();
                                 void insertData();
                                 void inputData();
                                 void viewData();
                                 void displayAll();
                                 void searchData();
                                 void addData();
                                 void modifyData();
                                 void deleteData();
                                }m,m1,m2;


int marks :: getRoll(){
    return rollno;
}

void marks :: dataMenu(){

    marks s;
    char ch='y';
    int choice;

            do{
        cout<<setw(50)<<"DELHI PUBLIC SCHOOL BHILAI"<<endl;
        cout<<"--------------------------------------------------------------------------------"<<endl;
        cout<<"1. Add Data "<<endl;
        cout<<"2. Search "<<endl;
        cout<<"3. Modify Data "<<endl;
        cout<<"4. Delete Data "<<endl;
        cout<<"5. View Data "<<endl;
        cout<<"6. Exit "<<endl;
        cout<<"--------------------------------------------------------------------------------"<<endl;
        cin>>choice;
        switch (choice) {

            case 1 : s.addData();
                     break;
            case 2 : s.searchData();
                      break;
            case 3 : s.modifyData();
                     break;
            case 4 : s.deleteData();
                     break;
            case 5 : s.displayAll();
                     break;
            case 6: cout<<"THANK YOU";
                    exit(0);
            default:cout<<"Invalid choice: "<<endl;

        }
            cout<<"Continue Editing?  (Y/N)"<<endl;
            cin>>ch;
            system("cls");
        } while(ch == 'y' || ch == 'Y');
}

void marks :: addData(){
   char ans = 'y';
    fstream fout("STU.dat",ios::app|ios::binary);
    while(ans=='y'||ans=='Y'){
        m.inputData();
        cout<<endl;
        fout.write((char*)&m,sizeof(m));

        cout<<"Records Added: "<<endl;
        cout<<"Want to Add more [Y/N]:";
        cin>>ans;
        cout<<endl;
    }
    fout.close();
    system("cls");
    m.dataMenu();
}





void marks :: modifyData(){
    char f='n',nm[20],clSc[10],hs[10],admn[10];
    marks s1;
    int r,rn,eng,mths,phy,compsc,chem;
    long pos;
    fstream fk("STU.dat",ios::in|ios::out|ios::binary);
    cout<<"Enter the Roll No. whose data has to modified: ";
    cin>>rn;
    while(!fk.eof())
    {pos=fk.tellg();
    fk.read((char*)&s1,sizeof(s1));
    if(s1.getRoll()==rn)
    { f='y';
    s1.viewData();
        cout<<"Enter New Data:"<<endl;

            cout<<"Enter Roll No. : "; '\n';
            cin>>r; '\n';
            s1.rollno=r;
            cin.get();
            cout<<"Enter Name of Student : ";
            gets(nm); '\n';
            strcpy(s1.name,nm) ;
            cout<<"Enter Class/Sec : ";
            gets(clSc); '\n'; strcpy(s1.claSec,clSc);
            cout<<"Enter House : "; '\n';
            gets(hs);     strcpy(s1.house,hs);
            cout<<"Enter Admission No. : "; '\n';
            gets(admn);   strcpy(s1.admno,admn);
            cout<<"Enter Marks in English : ";
            cin>>eng;  s1.english=eng;
            cout<<"Enter Marks in Maths : ";
            cin>>mths;    s1.maths=mths;
            cout<<"Enter Marks in Physics : ";
            cin>>phy;       s1.physics=phy;
            cout<<"Enter Marks in Chemistry : ";
            cin>>chem;     s1.chemistry=chem;
            cout<<"Enter Marks in Computer Science : ";
            cin>>compsc; s1.cs=compsc;
            fk.seekg(pos);
            fk.write((char*)&s1,sizeof(s1));
            cout<<endl;
cout<<"Your data after modification: "<<endl;

s1.viewData();
break;
}

}
if(f=='n')
    cout<<"Record not found\n";
fk.seekg(0);

fk.close();

 m.dataMenu();
}

void marks :: deleteData(){
  ifstream fio("STU.dat",ios::in);
  ofstream file("TEMP.dat",ios::out);
  int rno; char found='n';
  cout<<"Enter the Roll No. of Student whose Record is to be Deleted:\n";
  cin>>rno;
  while(!fio.eof())
 {fio.read((char*)&m1,sizeof(m1));
  if(m1.getRoll()==rno)
   {
      found='y';

    }
    else{
        file.write((char*)&m1,sizeof(m1));
    }

   }
 if(found=='n')
    cout<<"record not found\n";
    fio.close();
    file.close();
    cout<<"Record Deleted!"<<endl;
    remove("STU.dat");
    rename("TEMP.dat","STU.dat");
}

void marks :: searchData(){
    fstream fin("STU.dat",ios::in|ios::binary);
    int rno,i=0;
    char found='n';
    cout<<"Enter Roll No. to be searched :";
    cin>>rno;
     while(fin.read((char*)&m,sizeof(m)))
     {
         if(m.getRoll()==rno)
         {
             m.viewData();
             found='y';
         }i++;
     }
     if (found=='n'){
            cout<<"No Record Found!"<<endl;
         }
 fin.close();
 m.dataMenu();
}

void marks :: inputData(){
        cin.get();
        cout<<"Enter Roll No. : ";
        cin>>rollno;
        cin.get();
        cout<<"Enter Name of Student : ";
        gets(name);
        cout<<"Enter Class/Sec : ";
        gets(claSec);
        cout<<"Enter House : ";
        gets(house);
        cout<<"Enter Admission No. : ";
        gets(admno);
        cout<<"Enter Marks in English : ";
        cin>>english;
        cout<<"Enter Marks in Maths : ";
        cin>>maths;
        cout<<"Enter Marks in Physics : ";
        cin>>physics;
        cout<<"Enter Marks in Chemistry : ";
        cin>>chemistry;
        cout<<"Enter Marks in Computer Science : ";
        cin>>cs;
        cout<<endl;
}


void marks :: viewData(){

        cout<<"Roll No. : ";
        cout<<rollno<<endl;
        cout<<"Name of Student : ";
        cout<<name<<endl;
        cout<<"Class/Sec : ";
        cout<<claSec<<endl;
        cout<<"House : ";
        cout<<house<<endl;
        cout<<"Admission No. : ";
        cout<<admno<<endl;
        cout<<"Marks in English : ";
        cout<<english<<endl;
        cout<<"Marks in Maths : ";
        cout<<maths<<endl;
        cout<<"Marks in Physics : ";
        cout<<physics<<endl;
        cout<<"Marks in Chemistry : ";
        cout<<chemistry<<endl;
        cout<<"Marks in Computer Science : ";
        cout<<cs<<endl;
        cout<<endl;

}

void marks :: displayAll(){
    ifstream fin("STU.dat",ios::in|ios::binary);
    while(fin.read((char*)&m,sizeof(m)))
    {
       m.viewData();
    }
 fin.close();
}
int main()
{
    marks l;

         fstream fm("STU.dat",ios::in);
         if(fm){
                l.dataMenu();
            }else{
             cout<<"No records Entered Press Enter key to Enter data:";
            l.addData();
          }

    cout<<"THANK YOU";
    return 0;
}
