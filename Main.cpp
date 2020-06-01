#include <iostream>
#include<stdio.h>		//standard input/output c
#include<stdlib.h>		//standard library
#include<conio.h>		//getch function
#include<dos.h>			//delay function
#include<windows.h>		//Sleep,gotoxy coordinate functions
#include<iomanip>		//output manipulatons
#include<fstream>		//file handling
#include<string.h>		//string abstract datatype
#include<math.h>		//mathematical operations
#include<time.h>
#include<cwchar>	
using namespace std;
char loc[20];
void gotoxy (int x, int y);	//handle output on screen
void frame ();			//frame for every dialog box
void frame_fix();
char *date_time ();
void scroll_note();		
void flow(char *ch);
COORD coord = {0, 0};
void menupage();
void login();

class date;
class date		//class current date and time of system
{		
	public:
		int aday,amonth,ayear,ahour,amin,asec;
	void date_times()
	{
		SYSTEMTIME t;		//pre defined in time.h header
 		GetLocalTime(&t);
		aday=t.wDay,amonth=t.wMonth,ayear=t.wYear,ahour=t.wHour,amin=t.wMinute,asec=t.wSecond;
		
	}
};
class Employee{
	public:
		string empid,emp_id;
		string name;
		string deptid;
		string emp_dob;
		string emp_mob;
		string city;
		string salary;
		int count;
		void main1();
		void read_data();
		void pack();
		void write_to_file();
		void unpack();
		int search1(string);
		void delete_item();
		void modify1(string);
		void display();
		int delete_from_file1(string);
		string buffer1;
};
class Project: public Employee{
	public:
		string project_id;
		string proj_name;
		string dept_id;
		string buffer2;
		string projid_list[100];
		string extract_projid2();
		int address_list[100];
		int count;
		int search_index2(string);
		void main2();
		void read_data2();
		void pack2();
		void write_to_file2();
		void unpack2();
		void create_index2();
		void remove2(string);
		void search2(string);
		void modify2();
		void sort_index2();
		void display_proj();
		void search_deptproj(string);
};
class Department: public Project{
	public:
		string dept_id;
		string dept_name;
		string manager_id;
		string buffer3;
		string dept_list[100];
		string extract_deptid3();
		int address_list[100];
		int count;
		int search_index3(string);
		void read_data3();
		void pack3();
		void unpack3();
		void write_to_file3();
		void create_index3();
		void remove3(string);
		void search3(string);
		void search_employees3(string);
		void sort_index3();
		void display_dept();
		void main3();
};
class mainp : public Project{
	public:
	void login();
	void menupage();
};

void gotoxy (int x, int y)	//defining/initializing to predefined objects
{
    coord.X = x;
    coord.Y = y; // X and Y coordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void frame()
{
	int i,j=117;
	for(i = 0;i<118,j>=0;i++,j--)
	{
		gotoxy(i,3);
		Sleep(0.9);
		cout<<"_";
		gotoxy(j,22);
		Sleep(0.9);
		cout<<"_";
	}
	gotoxy(90,2);
	char s[20];
	strcpy(s,date_time());
	cout<<s;		//every frame has date on the right top 
	
}
void frame1()	//instead of flow line fixing the frame
{
	int i;
	for(i = 0;i<118;i++)
	{
		gotoxy(i,3);
		cout<<"_";
		Sleep(0.5);
	}
	gotoxy(90,2);
	char s[20];
	strcpy(s,date_time());
	cout<<s;
}
char *date_time()
{
	time_t t;
	time(&t);
	char *loc=ctime(&t);
	return loc;	//returns local time and date
}
void scroll_note()	//welcome note
{
	system("color F4");
	int j,i,x,y;
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize=sizeof(cfi);
	cfi.nFont=0;
	cfi.dwFontSize.X=8;
	cfi.dwFontSize.Y=18;
	cfi.FontFamily=FF_DONTCARE;
	cfi.FontWeight=700;
	wcscpy(cfi.FaceName,L"Courier");
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE),FALSE,&cfi);
	gotoxy(30,8);cout << char(201);      for(int i=0; i<49; i++){cout << char(205);}      cout << char(187);
	gotoxy(30,9); cout << char(186) << "                  				" << char(186);
	gotoxy(30,10);cout << char(186) << "                     				" << char(186);
	gotoxy(30,11);cout << char(186) << "  		           					";gotoxy(80,11); cout<< char(186);
	gotoxy(30,12);cout << char(186) << "                  					" ;gotoxy(80,12); cout<< char(186);
	gotoxy(30,13);cout << char(186) << "                     				" << char(186);
	gotoxy(30,14);cout << char(186) << "                     				" << char(186);
	gotoxy(30,15);cout << char(186) << "                   				" << char(186);
	gotoxy(30,16);cout << char(200);      for(int i=0; i<49; i++){cout << char(205);}      cout << char(188) << endl;
	
	gotoxy(39,12);cout<<"HUMAN RESOURCE MANAGEMENT SYSTEM";
	for(int j=0,k=115;j<=115,k>=0;j++,k--)
	{
		
		gotoxy(j,4);cout<<"*";
		Sleep(1);
		gotoxy(k,20);cout<<"*";
		
		Sleep(1);
	}
	gotoxy(86,23);cout<<"CRISEL MATHIAS - 4SF17IS015";
	gotoxy(86,24);cout<<"DEEKSHA - 4SF17IS017\n";
	gotoxy(86,26);system("PAUSE");

}
void mainp::login(){
	system("color 5F");
	char addname[30],pass[30];
	char adname1[]="crisel";
	char password1[]="cris";
	char adname2[]="deeksha";
	char password2[]="deek";
	while(1)
	{
		system("cls");
		frame();
		gotoxy(48,2);
		cout<<"LOGIN PAGE ";
		gotoxy(29,10);
		cout<<"Enter name of the admin : ";
		
		cin>>addname;
			if(strcmp(adname1,addname)==0||strcmp(adname2,addname)==0)
			{
				gotoxy(29,13);
				cout<<"Enter password : ";
				cin>>pass;
				if(strcmp(password1,pass)==0,strcmp(password2,pass)==0)
				{
					
					menupage();					
						
				}
			}
	}
}
void mainp::menupage(){
	int op1;
	fstream file;
	while(1)
	{
		system("cls");
		system("COLOR 8F");
		frame();
		gotoxy(48,8);
		cout<<"1.EMPLOYEE ";
		gotoxy(48,10);
		cout<<"2.COMPANY";
		gotoxy(48,12);
		cout<<"3.DEPARTMENTS";
		gotoxy(48,14);
		cout<<"4.PROJECT\n";
		gotoxy(48,16);
		cout<<"5.EXIT\n";
		gotoxy(48,18);
		cout<<"Select your option : ";
		op1=getch();
		if(op1=='1')
		{
			Employee ap;
			ap.main1();
		}
		else if(op1=='2')		
		{
			system("cls");
			system("COLOR 90");
			frame();
			gotoxy(10,8);
			cout<<ifstream("About.txt").rdbuf();
			gotoxy(10,20);
			system("PAUSE");
	    }
		else if(op1=='3'){
			Department ae;
			ae.main3();
		}
		else if(op1=='4')		
		{
			Project ar;
			ar.main2();
		} 
		else if(op1=='5'){
			exit(0);
		}	
		else
		{
			gotoxy(48,24);cout<<"INVALID INPUT...TRY AGAIN!!!";
			Sleep(1000);			
			system("cls");						
		}
	}
}
//Employee
//----------------------------------------------------------------------

void Employee::main1(){
	int op1;
	Employee a;
	while(1)
	{
		system("cls");
		system("COLOR 8F");
		frame();
		gotoxy(48,8);
		cout<<"1.ADD NEW EMPLOYEE ";
		gotoxy(48,10);
		cout<<"2.DELETE AN EMPLOYEE";
		gotoxy(48,12);
		cout<<"3.UPDATE EMPLOYEE DETAILS";
		gotoxy(48,14);
		cout<<"4.SEARCH EMPLOYEE DETAILS";
		gotoxy(48,16);
		cout<<"5.DISPLAY ALL EMPLOYEE DETAILS";
		gotoxy(48,18);
		cout<<"6.BACK";
		gotoxy(48,20);
		cout<<"Select your option : ";
		op1=getch();
		if(op1=='1')
		{
			
			a.read_data();
			a.pack();
			a.write_to_file();
		}
		
		else if(op1=='2')		
		{
			int i;
			string key;
			system("cls");
			system("COLOR 8F");
			frame();
			gotoxy(40,8);
			cout<<"enter the employee id to be deleted:";
			cin>>key;
			gotoxy(40,9);
			i=a.delete_from_file1(key);
			gotoxy(40,12);
			if(i==1)
			    cout<<"record deleted\n";
			else
				cout<<"record not deleted\n";
			
			Sleep(5000);
		}
		else if(op1=='3'){
			string key;
			system("cls");
			system("COLOR 8F");
			frame();
			gotoxy(40,8);
			cout<<"enter the employee id to be modified:";
			cin>>key;
			gotoxy(40,9);
			a.modify1(key);
			Sleep(5000);
		}
		else if(op1=='4'){
			string key;
			system("cls");
			system("COLOR 8F");
			frame();
			gotoxy(40,8);
			cout<<"enter the employee id to be searched:";
			cin>>key;
			gotoxy(40,9);
			a.search1(key);
			gotoxy(40,21);
			system("PAUSE");
			
		}
		else if(op1=='5'){
			a.display();
			
		}	
		else if(op1=='6'){
			mainp p;
			p.menupage();
		}	
		else
		{
			gotoxy(48,24);cout<<"INVALID INPUT...TRY AGAIN!!!";
			Sleep(1000);			
			system("cls");						
		}
	}
}

void Employee::read_data(){
	ifstream file;
	int flag=0,pos=0,j=10,k=0;
	system("cls");
	system("COLOR 8F");
	frame();
	gotoxy(40,8);
	cout<<"Choose the department";
	file.open("Department.txt",ios::in);
	while(!file.eof())
	{
		buffer1.erase();
		getline(file,buffer1);
		unpack();
		gotoxy(40,j);
		size_t f=empid.find('*');
		if(buffer1.empty())
			break;
		if(f==string::npos)
		{
			cout<<empid<<"-"<<deptid;
			j=j+1;
	    }
    }
    file.close();
	gotoxy(40,j);
	cout<<"Department ID form the above list: ";
	cin>>deptid;
	top: system("cls");
	system("COLOR 90");
	frame();
	gotoxy(40,10);
	cout<<"Enter Employee ID:";
	cin>>empid;
	file.open("Employee.txt",ios::in);
	emp_id=empid;
	while(!file.eof())
	{
		buffer1.erase();
		getline(file,buffer1);
		unpack();
		if(emp_id==empid)
		{
			gotoxy(40,14); 
			cout<<"ID already exists !!";
			Sleep(30);file.close();
			goto top;
		}
	}
	file.close();
	gotoxy(40,12);
	cout<<"Enter the Employee name:";
	cin>>name;
	gotoxy(40,14);
	cout<<"Employee DOB:";
	cin>>emp_dob;
	gotoxy(40,16);
	cout<<"Mobile number:";
	cin>>emp_mob;
	gotoxy(40,18);
	cout<<"Enter the city:";
	cin>>city;
	gotoxy(40,20);
	cout<<"Enter the Salary:";
	cin>>salary;
}
void Employee::pack(){
	buffer1.erase();
	buffer1+=empid+"|"+deptid+"|"+name+"|"+emp_dob+"|"+emp_mob+"|"+city+"|"+salary+"$"+"\n";
}
void Employee::write_to_file(){
	fstream f1;
	f1.open("Employee.txt",ios::out|ios::app);
	f1<<buffer1;
	f1.close();
}
void Employee::unpack(){
	int ch=1,i=0;
	empid.erase();
	while(buffer1[i]!='|')
		empid+=buffer1[i++];
		
	deptid.erase();
	i++;
	while(buffer1[i]!='|')
		deptid+=buffer1[i++];
	
	name.erase();
	i++;
	while(buffer1[i]!='|')
		name+=buffer1[i++];
	
	emp_dob.erase();
	i++;
	while(buffer1[i]!='|')
		emp_dob+=buffer1[i++];
		
	emp_mob.erase();
	i++;
	while(buffer1[i]!='|')
		emp_mob+=buffer1[i++];
		
	city.erase();
	i++;
	while(buffer1[i]!='|')
		city+=buffer1[i++];
	
	salary.erase();
	i++;
	while(buffer1[i]!='$')
		salary+=buffer1[i++];
}
int Employee::search1(string key)
{
	ifstream file;
	int flag=0,pos=0;
	file.open("Employee.txt",ios::in);
	while(!file.eof())
	{
		buffer1.erase();
		getline(file,buffer1);
		unpack();
		if(key==empid)
		{
			gotoxy(40,10);
			cout<<"found the key .the record is..."<<endl;
			gotoxy(40,12);
			cout<<"empid: "<<empid<<endl;
			gotoxy(40,13);
			cout<<"dept_id: "<<deptid<<endl;
			gotoxy(40,14);
			cout<<"emp_name: "<<name<<endl;
			gotoxy(40,15);
			cout<<"emp_dob: "<<emp_dob<<endl;
			gotoxy(40,16);
			cout<<"Emp_mobile: "<<emp_mob<<endl;
			gotoxy(40,17);
			cout<<"city: "<<city<<endl;
			gotoxy(40,18);
			cout<<"Salary: "<<salary<<endl;
			flag=1;
			return pos;
		}
	}
	file.close();
	if(flag==0)
	{
		gotoxy(40,10);
		cout<<"not found..";
		return -1;
	}
}
int Employee::delete_from_file1(string key)
{
	fstream file;
	int pos,flag=0;
	pos=search1(key);
	if(pos>=0)
	{
		file.open("Employee.txt");
		file.seekp(pos,ios::beg);
		file.put('*');
		flag=1;
		file.close();
	}
	if(flag==1)
		return 1;
	else
		return 0;
}
void Employee::modify1(string key)
{
	int c;
	fstream file;
	if(delete_from_file1(key))
	{
		top: system("cls");
		system("COLOR 8F");
		frame();
		gotoxy(40,8);
		cout<<"\nwhat to modify \n 1:emp_id 2:dept_id  3:name  4:emp_dob  5:emp_mob  6:city:  7.Salary ---> ";
		
		cin>>c;
		switch(c)
		{
			case 1:gotoxy(40,13);
					cout<<"empid:\t";
			       cin>>empid;
			       file.open("Employee.txt",ios::in);
					emp_id=empid;
					while(!file.eof())
					{
						buffer1.erase();
						getline(file,buffer1);
						unpack();
						if(emp_id==empid)
						{
							gotoxy(40,13); 
							cout<<"ID already exists !!";
							Sleep(30);file.close();
							goto top;
						}
					}
					file.close();
			       gotoxy(40,15);
			       cout<<"Data updated";
			       Sleep(50);
			       break;
			case 2:gotoxy(40,13);
					cout<<"managerid:\t";
			       cin>>deptid;
			       gotoxy(40,15);
			       cout<<"Data updated";
			       Sleep(50);
			       break;
			case 3:gotoxy(40,13);
					cout<<"name:\t";
			       cin>>name;
			       gotoxy(40,15);
			       cout<<"Data updated";
			       Sleep(50);
			       break;
			case 4:gotoxy(40,13);
					cout<<"emp_dob:\t";
			       cin>>emp_dob;
			       gotoxy(40,15);
			       cout<<"Data updated";
			       Sleep(50);
			       break;
			case 5:gotoxy(40,13);
					cout<<"emp_mob:\t";
			       cin>>emp_mob;
			       gotoxy(40,15);
			       cout<<"Data updated";
			       break;
			case 6:gotoxy(40,13);
					cout<<"city:\t";
			       cin>>city;
			       gotoxy(40,15);
			       cout<<"Data updated";
			       Sleep(50);
			       break;
			case 7:gotoxy(40,13);
					cout<<"Salary:\t";
			       cin>>salary;
			       gotoxy(40,15);
			       cout<<"Data updated";
			       Sleep(50);
			       break;
			default:gotoxy(40,13);
					cout<<"wrong choice\t";
					Sleep(50);
		}
		buffer1.erase();
		pack();
		write_to_file();
	}
}

void Employee::display()
{
	ifstream file;
	int flag=0,pos=0,j=10,ce=0,k=0;
	system("cls");
	system("COLOR 8F");
	frame1();
	file.open("Employee.txt",ios::in);
	gotoxy(6,6);
	cout<<"Emp_id\t\tDept_id\t\tName\t\tDOB\t\tPhoneNo\t\tsalary\t\tcity\n";
	gotoxy(6,8);
	cout<<"--------------------------------------------------------------------------------------------------------\n";
	while(!file.eof())
	{
		buffer1.erase();
		getline(file,buffer1);
		unpack();
		gotoxy(6,j);
		if(buffer1.empty())
			break;
		size_t f=empid.find('*');
		if(f==string::npos)
		{
			cout<<empid<<"\t\t"<<deptid<<"\t\t"<<name<<"\t\t"<<emp_dob<<"\t"<<emp_mob<<"\t"<<salary<<"\t\t"<<city<<"\n";
			j=j+2;
	    }
    }
    file.close();
    system("PAUSE");
}
//Project
//-------------------------------------------------------------------------------------------------------------



void Project::main2(){
	int op1;
	string key;
	Project a;
	a.create_index2();
	while(1)
	{
		system("cls");
		system("COLOR E0");
		frame();
		frame();
		frame();
		gotoxy(48,8);
		cout<<"1.ADD NEW PROJECT ";
		gotoxy(48,10);
		cout<<"2.DELETE PROJECT";
		gotoxy(48,12);
		cout<<"3.SEARCH PROJECT DETAILS";
		gotoxy(48,14);
		cout<<"4.PROJECT LIST";
		gotoxy(48,16);
		cout<<"5.DEPARTEMNT'S PROJECT LIST";
		gotoxy(48,18);
		cout<<"6.BACK";
		gotoxy(48,20);
		cout<<"Select your option : ";
		op1=getch();
		if(op1=='1')
		{
			
			a.read_data2();
			a.pack2();
			a.write_to_file2();
			
		}
		
		else if(op1=='2')		
		{
			system("cls");
			system("COLOR  E0");
			frame();
			gotoxy(48,8);
			cout<<" enter the project id:";
			cin>>key;
			gotoxy(48,9);
			a.remove2(key);
			
		} 
		
		else if(op1=='3'){
			system("cls");
			system("COLOR  E0");
			frame();
			gotoxy(40,8);
		    cout<<"enter the project id:";
			cin>>key;
			a.search2(key);
			Sleep(5000);
		}
		else if(op1=='4'){
			a.display_proj();
		}
		else if(op1=='5'){
			system("cls");
			system("COLOR  E0");
			frame();
			gotoxy(40,8);
		    cout<<"enter the department id:";
			cin>>key;
			a.search_deptproj(key);
		}
		else if(op1=='6'){
			mainp p;
			p.menupage();
		}	
		else
		{
			gotoxy(48,24);cout<<"INVALID INPUT...TRY AGAIN!!!";
			Sleep(1000);			
			system("cls");						
		}
	}
}
void Project::read_data2()
{
	top: system("cls");
	int i=0,flag=0;
	system("COLOR  E0");
	frame();
	gotoxy(40,8);
	cout<<"Project id:";
	cin>>project_id;
	while(i<=count)
    {
        if(projid_list[i++]==project_id)
        flag=1;
	}
	if(flag==1){
		gotoxy(40,10);
		cout<<"Key already exists!!";
		Sleep(10);
		goto top;
	}
	gotoxy(40,9);
	cout<<"Project name:";
	cin>>proj_name;
	gotoxy(40,10);
	cout<<"Department_id: ";
	cin>>dept_id;
	
}
void Project::pack2()
{
	string temp;
	buffer2.erase();
	buffer2+=project_id+'|'+proj_name+'|'+dept_id+'$'+"\n";
}
void Project :: write_to_file2()
{
	int pos;
	fstream file;
	file.open("Project.txt",ios::out|ios::app);
	pos=file.tellp();
	file<<buffer2;
	file.close();
	projid_list[++count]=project_id;
	address_list[count]=pos;
	sort_index2();
}
void Project::unpack2()
{
	int ch=1,i=0;
	project_id.erase();
	while(buffer2[i]!='|')
	project_id+=buffer2[i++];
	proj_name.erase();
	i++;
	while(buffer2[i]!='|')
	proj_name+=buffer2[i++];
	dept_id.erase();
	i++;
	while(buffer2[i]!='$')
	dept_id+=buffer2[i++];
}
string Project::extract_projid2()
{
	string project_id;
	int i=0;
	project_id.erase();
	while(buffer2[i]!='|')
	project_id+=buffer2[i++];
	return project_id;
}
void Project:: create_index2()
{
	fstream file;
	int pos;
	string project_id;
	count=-1;
	file.open("Project.txt",ios::in);
	while(!file.eof())
	{
		pos=file.tellg();
		
		buffer2.erase();
		getline(file,buffer2);
		if(buffer2[0]!='*')
		{
			if(buffer2.empty())
			break;
			project_id=extract_projid2();
			projid_list[++count]=project_id;
			address_list[count]=pos;
		}
	}
	file.close();
	sort_index2();
	buffer2.erase();
	
}
void Project::sort_index2()
{
	int i,j,temp_address;
	string temp_aero;
	for(int i=0;i<=count;i++)
	{
		for(int j=i+1;j<count;j++)
		{
			if(projid_list[i]>projid_list[j])
			{	
				temp_aero=projid_list[i];
				projid_list[i]=projid_list[j];
				projid_list[j]=temp_aero;
				temp_address=address_list[i];
				address_list[i]=address_list[j];
				address_list[j]=temp_address;
			}
		}
	}
	for(i=0;i<=count;i++)
	{
		cout<<projid_list[i]<<"\t"<<address_list[i]<<"\n";
	}
}
int Project::search_index2(string key)
{
	int low=0,high=count,mid=0,flag=0,pos;
	while(low<=high)
	{
		
		mid=(low+high)/2;
		
		if(projid_list[mid]==key){
			flag=1;
			break;
			
		}
		
		if(projid_list[mid]>key)
			high=mid-1;
		if(projid_list[mid]<key)
			low=mid+1;
	}
		
	
	if(flag)
		return mid;
	else
		return -1;
	
}
void Project::display_proj()
{
	system("cls");
	system("COLOR  E0");
	frame1();
	gotoxy(40,8);
	int pos=0,add,j=10;
	fstream file;
	buffer2.erase();
	file.open("Project.txt");
	gotoxy(20,6);
	cout<<"Project id\t\tDept_id\t\tProject Name\n";
	gotoxy(20,8);
	cout<<"-------------------------------------------------------------\n";
	for(int i=0;i<=count;i++){	
		add=address_list[i];
		file.seekp(add,ios::beg);
		while(!file.eof())
		{
			buffer2.erase();
			getline(file,buffer2);
			unpack2();
			gotoxy(20,j);
			if(buffer2.empty())
			break;
			size_t f=project_id.find('*');
			if(f==string::npos)
			{
				cout<<project_id<<"\t\t\t"<<dept_id<<"\t\t\t"<<proj_name<<"\n";
				j=j+2;
			}
	    }
	    file.close();
	}
	system("PAUSE");
}
void Project::search2(string key)
{
	int pos=0,add;
	fstream file;
	buffer2.erase();
	
	pos=search_index2(key);
	gotoxy(40,10);
	if(pos==-1)
		cout<<endl<<"record NOT found"<<endl;
	else if(pos>=0)
	{
		file.open("Project.txt");
		add=address_list[pos];
		file.seekp(add,ios::beg);
		getline(file,buffer2);
		gotoxy(40,10);
		cout<<"record found....\n"<<buffer2;
		Sleep(5000);
		file.close();
	}
}

void Project::search_deptproj(string key)
{
	system("cls");
	system("COLOR  E0");
	frame1();
	gotoxy(40,8);
	int pos=0,add,j=10;
	fstream file;
	buffer2.erase();
	file.open("Project.txt");
	gotoxy(20,6);
	cout<<"Project id\t\tDept_ID\t\tProject name\n";
	gotoxy(20,8);
	cout<<"-------------------------------------------------------------\n";
	for(int i=0;i<=count;i++){	
		add=address_list[i];
		file.seekp(add,ios::beg);
		while(!file.eof())
		{
			buffer2.erase();
			getline(file,buffer2);
			unpack2();
			gotoxy(20,j);
			if(buffer2.empty())
			break;
			size_t f=project_id.find('*');
			if(f==string::npos && dept_id==key)
			{
				cout<<project_id<<"\t\t\t"<<dept_id<<"\t\t"<<proj_name<<"\n";
				j=j+2;
			}
	    }
	    file.close();
	}
	system("PAUSE");
}
void Project::remove2(string key)
{
	int pos=0,i,address;
	fstream file;
	pos=search_index2(key);
	if(pos>=0)
	{
		file.open("Project.txt",ios::out|ios::in);
		address=address_list[pos];
		file.seekp(address,ios::beg);
		file.put('*');
		file.close();
		cout<<"\n record deleted";
		for(i=pos;i<count;i++)
		{
			projid_list[i]=projid_list[i+1];
			address_list[i]=address_list[i+1];
		}
		count--;
	}
	else
	cout<<"record not found\n";
}



//--------------------------------------------------------------------------
//Department
//-----------------------------------------------------------------------------------------------------------
void Department::main3(){
	int op1;
	string key;
	Department a;
	a.create_index3();
	while(1)
	{
		system("cls");
		system("COLOR 1F");
		frame();
		gotoxy(48,8);
		cout<<"1.ADD NEW DEPARTMENT ";
		gotoxy(48,10);
		cout<<"2.DELETE DEPARTMENT";
		gotoxy(48,12);
		cout<<"3.SEARCH DEPARTMENT DETAILS";
		gotoxy(48,14);
		cout<<"4.DEPARTMENT EMPLOYEES";
		gotoxy(48,16);
		cout<<"5.DEPARTMENT LIST";
		gotoxy(48,18);
		cout<<"6.BACK";
		gotoxy(48,20);
		cout<<"Select your option : ";
		op1=getch();
		if(op1=='1')
		{
			
			a.read_data3();
			a.pack3();
			a.write_to_file3();
			
		}
		
		else if(op1=='2')		
		{
			system("cls");
			system("COLOR 1F");
			frame();
			gotoxy(48,8);
			cout<<" enter the department id:";
			cin>>key;
			gotoxy(48,9);
			a.remove3(key);
			
		} 
		
		else if(op1=='3'){
			system("cls");
			system("COLOR 1F");
			frame();
			gotoxy(40,8);
		    cout<<"enter the department id:";
			cin>>key;
			a.search3(key);
			Sleep(5000);
		}
		else if(op1=='4'){
			system("cls");
			system("COLOR 1F");
			frame();
			gotoxy(40,8);
		    cout<<"enter the department id:";
			cin>>key;
			a.search_employees3(key);
			Sleep(5000);
		}
		else if(op1=='5'){
			a.display_dept();
		}
		else if(op1=='6'){
			mainp p;
			p.menupage();
		}	
		else
		{
			gotoxy(48,24);cout<<"INVALID INPUT...TRY AGAIN!!!";
			Sleep(1000);			
			system("cls");						
		}
	}
}
void Department::read_data3()
{
	top: system("cls");
	int i=0,flag=0;
	system("COLOR 1F");
	frame();
	gotoxy(40,8);
	cout<<"Department id:";
	cin>>dept_id;
	while(i<=count)
    {
        if(dept_list[i++]==dept_id)
        flag=1;
	}
	if(flag==1){
		gotoxy(40,10);
		cout<<"Key already exists!!";
		Sleep(10);
		goto top;
	}
	gotoxy(40,9);
	cout<<"department name:";
	cin>>dept_name;
	gotoxy(40,10);
	cout<<"manager_id: ";
	cin>>manager_id;
	
}
void Department::pack3()
{
	string temp;
	buffer3.erase();
	buffer3+=dept_id+'|'+dept_name+'|'+manager_id+'$'+"\n";
}
void Department :: write_to_file3()
{
	int pos;
	fstream file;
	file.open("Department.txt",ios::out|ios::app);
	pos=file.tellp();
	file<<buffer3;
	file.close();
	dept_list[++count]=dept_id;
	address_list[count]=pos;
	sort_index3();
}
void Department::unpack3()
{
	int ch=1,i=0;
	dept_id.erase();
	while(buffer3[i]!='|')
	dept_id+=buffer3[i++];
	dept_name.erase();
	i++;
	while(buffer3[i]!='|')
	dept_name+=buffer3[i++];
	manager_id.erase();
	i++;
	while(buffer3[i]!='$')
	manager_id+=buffer3[i++];
}
string Department::extract_deptid3()
{
	string dept_id;
	int i=0;
	dept_id.erase();
	while(buffer3[i]!='|')
	dept_id+=buffer3[i++];
	return dept_id;
}
void Department:: create_index3()
{
	fstream file;
	int pos;
	string dept_id;
	count=-1;
	file.open("Department.txt",ios::in);
	while(!file.eof())
	{
		pos=file.tellg();
		
		buffer3.erase();
		getline(file,buffer3);
		if(buffer3[0]!='*')
		{
			if(buffer3.empty())
			break;
			dept_id=extract_deptid3();
			dept_list[++count]=dept_id;
			address_list[count]=pos;
		}
	}
	file.close();
	sort_index3();
	buffer3.erase();
	
}
void Department::sort_index3()
{
	int i,j,temp_address;
	string temp_aero;
	for(int i=0;i<=count;i++)
	{
		for(int j=i+1;j<count;j++)
		{
			if(dept_list[i]>dept_list[j])
			{	
				temp_aero=dept_list[i];
				dept_list[i]=dept_list[j];
				dept_list[j]=temp_aero;
				temp_address=address_list[i];
				address_list[i]=address_list[j];
				address_list[j]=temp_address;
			}
		}
	}
	for(i=0;i<=count;i++)
	{
		cout<<dept_list[i]<<"\t"<<address_list[i]<<"\n";
	}
}
int Department::search_index3(string key)
{
	int low=0,high=count,mid=0,flag=0,pos;
	while(low<=high)
	{
		
		mid=(low+high)/2;
		
		if(dept_list[mid]==key){
			flag=1;
			break;
			
		}
		
		if(dept_list[mid]>key)
			high=mid-1;
		if(dept_list[mid]<key)
			low=mid+1;
	}
		
	
	if(flag)
		return mid;
	else
		return -1;
	
}
void Department::display_dept()
{
	system("cls");
	system("COLOR 1F");
	frame1();
	gotoxy(40,8);
	int pos=0,add,j=10;
	fstream file;
	buffer3.erase();
	file.open("Department.txt");
	gotoxy(20,6);
	cout<<"Dept id\t\tDepartment Name\t\tManager ID\n";
	gotoxy(20,8);
	cout<<"-------------------------------------------------------------\n";
	for(int i=0;i<=count;i++){	
		add=address_list[i];
		file.seekp(add,ios::beg);
		while(!file.eof())
		{
			buffer3.erase();
			getline(file,buffer3);
			unpack3();
			gotoxy(20,j);
			if(buffer3.empty())
			break;
			size_t f=dept_id.find('*');
			if(f==string::npos)
			{
				cout<<dept_id<<"\t\t\t"<<dept_name<<"\t\t\t"<<manager_id<<"\n";
				j=j+2;
			}
	    }
	    file.close();
	}
	system("PAUSE");
}
void Department::search3(string key)
{
	int pos=0,add;
	fstream file;
	buffer3.erase();
	
	pos=search_index3(key);
	gotoxy(40,9);
		cout<<pos;
	
	gotoxy(40,10);
	if(pos==-1)
		cout<<endl<<"record NOT found"<<endl;
	else if(pos>=0)
	{
		file.open("Department.txt");
		add=address_list[pos];
		file.seekp(add,ios::beg);
		getline(file,buffer3);
		//gotoxy(40,10);
		cout<<"record found....\n"<<buffer3;
		Sleep(1000);
		file.close();
	}
}
void Department::search_employees3(string key)
{
	ifstream file;
	int flag=0,pos=0,j=10,ce=0,k=0;
	system("cls");
	system("COLOR 1F");
	frame1();
	file.open("Employee.txt",ios::in);
	gotoxy(6,6);
	cout<<"Emp_id\t\tDept_id\t\tName\t\tDOB\t\tPhoneNo\t\tsalary\t\tcity\n";
	gotoxy(6,8);
	cout<<"--------------------------------------------------------------------------------------------------------\n";
	while(!file.eof())
	{
		buffer1.erase();
		getline(file,buffer1);
		unpack();
		gotoxy(6,j);
		if(buffer1.empty())
			break;
		if(deptid==key){
			size_t f=empid.find('*');
			if(f==string::npos)
			{
				cout<<empid<<"\t\t"<<deptid<<"\t\t"<<name<<"\t\t"<<emp_dob<<"\t"<<emp_mob<<"\t"<<salary<<"\t\t"<<city<<"\n";
				j=j+2;
		    }
		}
    }
    file.close();
    Sleep(10000);
}
void Department::remove3(string key)
{
	int pos=0,i,address;
	fstream file;
	pos=search_index3(key);
	if(pos>=0)
	{
		file.open("Department.txt",ios::out|ios::in);
		address=address_list[pos];
		file.seekp(address,ios::beg);
		file.put('*');
		file.close();
		cout<<"\n record deleted";
		for(i=pos;i<count;i++)
		{
			dept_list[i]=dept_list[i+1];
			address_list[i]=address_list[i+1];
		}
		count--;
	}
	else
	cout<<"record not found\n";
}

//----------------------------------------------------------------------------------------------------------------------------------------------------
//main page
//---------------------------------------------------------------------------------------------------------------------------------------------------

int main() {//int argc, char** argv
	mainp q;
	scroll_note();
	Sleep(10);
    q.login();
	
	return 0;
}
