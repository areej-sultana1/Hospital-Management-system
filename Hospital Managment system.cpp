#include<iostream>
#include<windows.h>
#include<conio.h>
#include<fstream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<iomanip>
using namespace std;
//global variable declaration
int k=7,r=0,flag=0;
COORD coord = {0, 0};

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
struct date
{
    int mm,dd,yy;
};

ofstream fout;
ifstream fin;

class patient
{
    int fileno;
    char name[25];
    date d;
public:
	int paymenttype()
    {
    		int num;
    		char grade;
    	cout<<"\n\n\tDo You have medical insurance card?  <1> YES\n <2>NO ";
    	cin>>num;
    	return num;
    }
    void add()
    {
        cout<<"\n\n\tFile No: ";
        cin>>fileno;
        cout<<"\n\n\tName of the patient: ";
        cin>>name;
//gets(name);
        cout<<"\n\n\tEnter Date(dd-mm-yy): ";
        cin>>d.mm>>d.dd>>d.yy;
    }
    void show()
    {
        cout<<"\n\tFile No: ";
        cout<<fileno;
        cout<<"\n\n\tName of the Patient: ";
        cout<<name;
        cout<<"\n\n\tDate : ";
        cout<<d.mm<<"-"<<d.dd<<"-"<<d.yy;
    }
    void report()
    {
        gotoxy(3,k);
        cout<<fileno;
        gotoxy(13,k);
        puts(name);
    }
    int retno()
    {
        return(fileno);

    }

};

class information: public patient
{
    float const oprice=200;
	float discountp,paidprice;
    char symp[25];
    char diag[25];
    char bloodgp;
    int age;
public:
    void add();
    void show();
    void report();
    void calculate();
    void payment();
    int department();

} info;

void information :: calculate()
{
	int x = patient::paymenttype();
	if(x==1) //medical
	{
		char grade;
		 cout<<"\n\n\tWhich grade card do you have? <1>A\n<2>B\n<3>C: ";
         cin>>grade;
         if((grade=='A') || (grade=='a'))
         {

         	 discountp=200;
         	 paidprice=0;



		 }
		 if((grade=='B') || (grade=='b'))
		 {
		 	float aprice;

		 	aprice =((25*oprice)/100);
		 	 discountp=oprice-aprice;
		 	 paidprice=oprice-discountp;

		 }
		 if((grade=='C') || (grade=='c'))
		 {
		 	float aprice;

		 	aprice =((50*oprice)/100);
		 	discountp=oprice-aprice;
		 	paidprice=oprice-discountp;
		 }} // end if

		 if(x==2)
		 {

		 	 discountp=0;
		 	 paidprice=200;
		 }

	}
void information::add()
{
    patient::add();
    cout<<"\n\n\tSymptoms: ";
    cin>>symp;
    cout<<"\n\n\tDiagnosis: ";
    cin>>diag;
    cout<<"\n\n\tBlood group: ";
    cin>>bloodgp;
    cout<<"\n\n\tAge: ";
    cin>>age;
    information::calculate();

    fout.write((char *)&info,sizeof(info));
    fout.close();
}
//void payment add

void information::show() //for payment
{
    fin.open("record.dat",ios::binary);
    fin.read((char*)&info,sizeof(info));
    patient::show();
    cout<<"\n\n\tAmount to be paid is: ";
    cout<<paidprice;
    fin.close();
}

void information::report()
{
    patient::report();
    gotoxy(23,k);
    cout<<symp;
    gotoxy(33,k);
    cout<<diag;
    gotoxy(44,k);
    cout<<bloodgp;
    gotoxy(54,k);
    cout<<age;
   // gotoxy(66,k);
    //cout<<paidprice;
    k=k+1;
    if(k==50)
    {
        gotoxy(25,50);
        cout<<"PRESS ANY KEY TO CONTINUE...";
        getch();
        k=7;
        system("cls");
        gotoxy(30,3);
        cout<<" PATIENT DETAILS ";
        gotoxy(3,5);
        cout<<"NUMBER";
        gotoxy(13,5);
        cout<<"NAME";
        gotoxy(23,5);
        cout<<"SYMPTOMS";
        gotoxy(33,5);
        cout<<"DIAGNOSIS";
        gotoxy(44,5);
        cout<<"BLOOD GRP";
        gotoxy(54,5);
        cout<<"AGE";
        //gotoxy(66,5);
        //cout<<"PAID AMOUNT";
    }
}
int information::department()
{
   int choice;
   system("cls");
  cout<<"\n\n\n\t\t\t\tDEPARTMENTS AVAILABLE:"<<endl;
  cout<<"\t\t\t\t----------------------------"<<endl;
  cout<<"\t\t\t\t1-Emergency case            "<<endl;
  cout<<"\t\t\t\t2-General Clinic            "<<endl;
  cout<<"\t\t\t\t3-Dentist                   "<<endl;
  cout<<"\t\t\t\t4-Skin specialist           "<<endl;
  cout<<"\t\t\t\t----------------------------"<<endl;
  cout<<"\n\t\t\t\tENTER YOUR CHOICE:   ";
  cin>>choice;
    int timing;
    switch(choice)
    {
    	case 1:
    		int cho;

    		cout<<"\nEMERGENCY CASE:     "<<endl;
    		cout<<"********************************\n               "<<endl;
    		cout<<"TWO doctors are available in emergency ward:     "<<endl;
    		cout<<"1- BURNT CASE          :DR SHAHZAD(9:00 t0 12:00)"<<endl;
    		cout<<"2- ACCIDENTAL INJURY   :DR FAROOQ (9:00 t0 12:00)"<<endl;
    		cout<<"Enter you choice:";
    		cin>>cho;
    		if(choice==1)
    		{
    			cout<<"\n\n\nYOUR APPOINTMENT IS SCHEDULED WITH DR SHAHZAD.";
    						return 0;

    			getch();
			}
			if(choice==2)
    		{
    			cout<<"\n\n\nYOUR APPOINTMENT IS SCHEDULED WITH DR FAROOQ.";
    						return 1;

			}
			break;
    		case 2:

    			system("cls");
    			cout<<"\n\n\nDR SAAD is for general clinic:"<<endl;
    			cout<<"TIMING: 9:00 am to 12:00 pm:"<<endl;
    			cout<<"Enter your timing:";
    			cin>>timing;

    			cout<<"YOUR APPOINTMENT IS SCHEDULED WITH DR FAROOQ.";
    		    system("cls");
    		    return 2;
    			break;
    		case 3:
    			cout<<"DOCTORS: DR NISHA\nTIMINGS:9:00 to 12:00"<<endl;
    			cout<<"Enter your timing:"<<endl;
    			cin>>timing;
    			cout<<"YOUR APPOINTMENT IS SCHEDULED WITH DR NISHA";
    			return 3;
    			break;
    		case 4:
    			cout<<"DR SANIA is skin specialist:"<<endl;
    			cout<<"Timings: 3:00pm to 9:00pm";
    			cout<<"ENTER YOUR Timings:";
    			cin>>timing;
    			{
    			    return 4;
    			}

    			cout<<"YOUR APPOINTMENT IS SCHEDULE:";
	     }
}

void information::payment()
{
    show();
    cout<<"\n\n\n\t\t*********************************************";
    cout<<"\n\t\t                 DETAILS                  ";
    cout<<"\n\t\t*********************************************";
    cout<<"\n\n\t\tPRICE                     Rs:"<<oprice;
    cout<<"\n\n\t\tINSURANCE COVERED         Rs:"<<discountp;
    cout<<"\n\t\tPAID AMOUNT                 Rs:"<<paidprice;
    cout<<"\n\t\t*********************************************";
}
void display()
{
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout<<"\t\t\t\t\t\t\t*********************@@@@@@@@@@@@@@@@@@@@@@@@@@@@**********************"<<endl;
	cout<<"\t\t\t\t\t\t\t|                                                                     |"<<endl;
	cout<<"\t\t\t\t\t\t\t|                                                                     |"<<endl;
	cout<<"\t\t\t\t\t\t\t|                                                                     |"<<endl;
	cout<<"\t\t\t\t\t\t\t|                !!!!WELCOME TO SAM HOPSITAL!!!                       |"<<endl;
	cout<<"\t\t\t\t\t\t\t|                                                                     |"<<endl;
	cout<<"\t\t\t\t\t\t\t|                                                                     |"<<endl;
	cout<<"\t\t\t\t\t\t\t|                                                                     |"<<endl;
	cout<<"\t\t\t\t\t\t\t*********************@@@@@@@@@@@@@@@@@@@@@@@@@@@@**********************"<<endl;
	cout<<"\npress anykey to continue...";
	getch();

}
/*int login()
{
	system("cls");
	string pass ="";
   char ch;
   cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t  HOSPITAL MANAGEMENT SYSTEM \n\n"<<endl;
   cout<<"\t\t\t\t\t\t\t\t------------------------------"<<endl;
   cout<<"                                               "<<endl;
   cout<<"\n\t\t\t\t\t\t\t\t\t     login system           "<<endl;
   cout<<"                                               "<<endl;
   cout<<"\t\t\t\t\t\t\t\t------------------------------\n\n"<<endl;
   cout << "\t\t\t\t\t\t\t\tEnter Password: ";
   ch = _getch();
   while(ch != 13){//character 13 is enter
      pass.push_back(ch);
      cout << '*';
      ch = _getch();
   }
   if(pass == "fast"){
      cout << "\n\n\t\t\t\t\t\t\t\tAccess Granted! \n";
      system("PAUSE");
      system ("CLS");
   }
   else{
      cout << "\n\n\t\t\t\t\t\t\t\tAccess Aborted...\n\t\t\t\t\t\t\t\tPlease Try Again\n\n";
      system("PAUSE");
      system("CLS");
      login();
   }


}*/


void doctor()
{
            cout<<"TWO doctors for emergency ward:     "<<endl;
    		cout<<"1- BURNT CASE          :DR SHAHZAD(9:00 t0 12:00)"<<endl;
    		cout<<"2- ACCIDENTAL INJURY   :DR FAROOQ (9:00 t0 12:00)"<<endl;
    		cout<<"\n\nDR SANIA is skin specialist:"<<endl;
            cout<<"Timings: 3:00pm to 9:00pm";
            cout<<"\n\nDENTIST: DR NISHA\nTIMINGS:9:00 to 12:00"<<endl;
            cout<<"\n\n\nDR SAAD is for general clinic:"<<endl;
            cout<<"TIMING: 9:00 am to 12:00 pm:"<<endl;


}
int main()
{
	system("COLOR b");
	//display();
    //login();
    //cout.setf(ios::fixed);
    //cout.setf(ios::showpoint);
    //cout<<setprecision(2);

    fstream tmp("temp.dat",ios::binary|ios::out);
menu:
	//system("COLOR 3E");
	//system("COLOR 5C");

    system("cls");
    system("COLOR 5C");

    system("COLOR 1E");
	system("cls");
    cout<<"\n\n\n\n\n\t\t\tHospital Management System  "<<endl;
    cout<<"\t\t\t===========================     \n\n"<<endl;
    cout<<"\t\t\t|   1.Patient File              |\n"<<endl;
    cout<<"\t\t\t|   2.Add/Remove/Edit File      |\n"<<endl;
    cout<<"\t\t\t|   3.Show Payment Slip         |\n"<<endl;
    cout<<"\t\t\t|   4.Back to menu              |\n"<<endl;
    cout<<"\t\t\t|   5.Take patient to doctor    |\n"<<endl;
    cout<<"\t\t\t|   6.View all doctor record    |\n"<<endl;
    cout<<"\t\t\tPlease Enter Required Option: ";
    int ch,ff;
    float gtotal;
    cin>>ch;
    switch(ch)
    {
    case 1:
ss:
        system("cls");
        gotoxy(25,2);
        cout<<"Patient Details";
        gotoxy(25,3);
        cout<<"================\n\n";
        cout<<"\n\t\t1.All Files\n\n";
        cout<<"\t\t2.Back to Main menu\n\n";
        cout<<"\t\tPlease Enter Required Option: ";
        int cho;
        cin>>cho;
        if(cho==1)
        {

            system("cls");
            gotoxy(30,3);
            cout<<" PATIENT DETAILS ";
            gotoxy(3,5);
            cout<<"FILE NO";
            gotoxy(13,5);
            cout<<"NAME";
            gotoxy(23,5);
            cout<<"SYMPTOMS";
            gotoxy(33,5);
            cout<<"DIAGNOSIS";
            gotoxy(44,5);
            cout<<"BLOOD GRP";
            gotoxy(54,5);
            cout<<"AGE";
            //gotoxy(66,5);
            //cout<<"PAID AMT";
            fin.open("record.dat",ios::binary);
            if(!fin)
            {
                cout<<"\n\nFile Not Found...";
                goto menu;
            }
            fin.seekg(0);

            while(!fin.eof())
            {
                fin.read((char*)&info,sizeof(info));
                if(!fin.eof())
                {
                    info.report();
				}

            }

            getch();
            fin.close();
        }
        if(cho==2)
        {
            goto menu;
        }
        goto ss;
    case 2:
db:
        system("cls");
        gotoxy(25,2);
        cout<<"File Editor";
        gotoxy(25,3);
        cout<<"=================\n\n";
        cout<<"\n\t\t1.Add File Details\n\n";
        cout<<"\t\t2.Edit File Details\n\n";
        cout<<"\t\t3.Delete File Details\n\n";
        cout<<"\t\t4.Back to Main Menu ";
        int apc;
        cin>>apc;
        switch(apc)
        {
        case 1:
        	system("cls");
        	cout<<"         PATIENTS' INFORMATION  ";
            fout.open("record.dat",ios::binary|ios::app);
            info.add();
            cout<<"\n\t\tFile Added Successfully!";
            getch();
            goto db;

        case 2:
            int ino;
            flag=0;
            cout<<"\n\n\tEnter File Number to be Edited :";
            cin>>ino;
            fin.open("record.dat",ios::binary);
            fout.open("record.dat",ios::binary|ios::app);
            if(!fin)
            {
                cout<<"\n\nFile Not Found...";
                goto menu;
            }
            fin.seekg(0);
            r=0;
            while(!fin.eof())
            {
                fin.read((char*)&info,sizeof(info));
                if(!fin.eof())
                {
                    int x=info.patient::retno();
                    if(x==ino)
                    {
                        flag=1;
                        fout.seekp(r*sizeof(info));
                        system("cls");
                        cout<<"\n\t\tCurrent Details are\n";
                        info.show();
                        cout<<"\n\n\t\tEnter New Details\n";
                        info.add();

                        cout<<"\n\t\tFile Details editted";
                    }
                }
                r++;
            }
            if(flag==0)
            {
                cout<<"\n\t\tFile No does not exist...Please Retry!";
                getch();
                goto db;
            }
            fin.close();
            fout.close();

            getch();
            goto db;

        case 3:
            flag=0;
            cout<<"\n\n\tEnter File Number to be deleted :";
            cin>>ino;
            fin.open("record.dat",ios::binary);
            if(!fin)
            {
                cout<<"\n\nFile Not Found...";
                goto menu;
            }
//fstream tmp("temp.dat",ios::binary|ios::out);
            fin.seekg(0);
            while(fin.read((char*)&info, sizeof(info)))
            {
                int x=info.patient::retno();
                if(x!=ino)
                    tmp.write((char*)&info,sizeof(info));
                else
                {
                    flag=1;
                }
            }
            fin.close();
            tmp.close();
            fout.open("record.dat",ios::trunc|ios::binary);
            fout.seekp(0);
            tmp.open("temp.dat",ios::binary|ios::in);
            if(!tmp)
            {
                cout<<"Error in File";
                goto db;
            }
            while(tmp.read((char*)&info,sizeof(info)))
                fout.write((char*)&info,sizeof(info));
            tmp.close();
            fout.close();
            if(flag==1)
                cout<<"\n\t\tFile Succesfully Deleted";
            else if (flag==0)
                cout<<"\n\t\tFile does not Exist! Please Retry";
            getch();
            goto db;
        case 4:
            goto menu;
        default:
            cout<<"\n\n\t\tWrong Choice!!! Retry";
            getch();
            goto db;
        }
    case 3:
        system("cls");
        flag=0;
        int ino;
        cout<<"\n\n\t\tEnter File Number :";
        cin>>ino;
        fin.open("record.dat",ios::binary);
        if(!fin)
        {
            cout<<"\n\nFile Not Found...\nProgram Terminated!";
            goto menu;
        }
        fin.seekg(0);
        while(fin.read((char*)&info,sizeof(info)))
        {
            int x=info.patient::retno();
            if(x==ino)
            {
                info.payment();
                flag=1;
                break;
            }
        }
        if(flag==0)
            cout<<"\n\t\tFILE does not exist....Please Retry!";
        getch();
        fin.close();
        goto menu;
    case 4:

        system("cls");
        gotoxy(20,20);
        cout<<"ARE YOU SURE, YOU WANT TO EXIT (Y/N)?";
        char yn;
        cin>>yn;
        if((yn=='Y')||(yn=='y'))
        {
            gotoxy(12,20);
            system("cls");
            cout<<"************************** THANKS **************************************";
            getch();
            exit(0);
        }
        else if((yn=='N')||(yn=='n'))
            goto menu;
        else
        {
            goto menu;
        }
        case 5:
         system("cls");
        flag=0;

        int sno;
        cout<<"\n\n\t\tEnter Patient file number  :";
        cin>>sno;
        fin.open("record.dat",ios::binary);
        if(!fin)
        {
            cout<<"\n\nFile Not Found...\nProgram Terminated!";
            goto menu;
        }
        fin.seekg(0);
        while(fin.read((char*)&info,sizeof(info)))
        {
            int x=info.patient::retno();
            if(x==sno)
            {
                 gotoxy(30,3);
            cout<<" PATIENT HISTORY ";
            gotoxy(3,5);
            cout<<"FILE NO";
            gotoxy(13,5);
            cout<<"NAME";
            gotoxy(23,5);
            cout<<"SYMPTOMS";
            gotoxy(33,5);
            cout<<"DIAGNOSIS";
            gotoxy(44,5);
            cout<<"BLOOD GRP";
            gotoxy(54,5);
            cout<<"AGE";
                info.report();
                getch();
                flag=1;
                cout<<"\n\n";
                int num=info.department();
              //  fout.write((char*)&info,sizeof(info));

                          if(num==0)
    {
        cout<<"APPOINTMENT BOOKED FOR  DR SHAHZAD. "<<endl;

    }
     if(num==1)
    {
        cout<<"APPOINTMENT BOOKED FOR DR FAROOQ. "<<endl;

    }
     if(num==2)
    {
        cout<<"APPOINTMENT BOOKED FOR  DR SANIA. "<<endl;

    }
     if(num==3)
    {
        cout<<"APPOINTMENT BOOKED FOR  DR NISHA. "<<endl;

    }
     if(num==4)
    {
        cout<<"APPOINTMENT BOOKED FOR  DR SAAD. "<<endl;

    }
                break;

            }
        }
        if(flag==0)
            cout<<"\n\t\tFILE does not exist....Please Retry!";
        getch();
        fout.close();
        fin.close();
        goto menu;

        case 6:
            system("cls");
            doctor();
            getch();
            goto menu;


    default:
        cout<<"\n\n\t\tWrong Choice....Please Retry!";
        getch();
        goto menu;
    }


    return 0;
}
