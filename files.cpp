#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
class student
{
	int roll_no;
	
	char name[40],mob[20],div,addrs[40];
public:
	void getdata();
	void display();
	int getr(){return roll_no;}
	void assign(int s)
	{
	  roll_no=s;
	}
};
void student::getdata()
{
    	static int temp=100;
	 int temp2=temp;
	ifstream fin;
	student s;
	fin.open("DSF.txt");
	/*while(fin.read((char*)&s,sizeof(s)))
	{
	  if(s.getr()>temp2)
	  	temp2=s.getr();
	}*/
	if(fin) 
	{
		fin.seekg(-sizeof(s),ios::end);
		fin.read((char*)&s,sizeof(s))
		temp2=s.getr();
	}
	fin.close();
	roll_no=++temp2;
	cout<<"\nEnter the name of the student";
	cin.ignore();
	cin.getline(name,40);
	cout<<"\nEnter the division ";
	cin>>div;
	cout<<"\nEnter the address";
	cin.ignore();
	cin.getline(addrs,40);
	
	
	do{
		cout<<"\nEnter the mob number";
		cin>>mob;
		if(strlen(mob)!=10)
			cout<<"\n Enter proper 10 digit mobile Number ";
	}while(strlen(mob)!=10);
}
void student::display()
{
	cout<<"\n*****************************************";
	cout<<"\nroll NUmber  :"<<roll_no;
	cout<<"\n Name..:"<<name;
	cout<<"\n Division : "<<div;
	cout<<"\n Mobile number :  "<<mob;
	cout<<"\n Address : "<<addrs;
	cout<<"\n*****************************************\n\n";
}
class cfile
{
public:
	void add();
	void display();
	void modify();
	void Delete();
	void search();

};
void cfile::search()
{
	int qw,flag=0;
	cout<<"\n Enter the number to be Searched";
	cin>>qw;
	
	ifstream fin;
	
	fin.open("DSF.txt",ios::binary | ios::app);
	student s;
	while(fin.read((char*)&s,sizeof(s)))
	{
		if(qw==s.getr())
		{
			flag=1;
			break;
		}
		
	}
	if(flag==1)
		s.display();
	else
		cout<<"\nData not found";
	fin.close();

}



void cfile::Delete()
{
	int qw,flag=0;
	cout<<"\n Enter the number to be Deleted";
	cin>>qw;
	ofstream fout;
	ifstream fin;
	fout.open("Temp.txt",ios::binary | ios::app);
	fin.open("DSF.txt",ios::binary | ios::app);
	student s;
	while(fin.read((char*)&s,sizeof(s)))
	{
		if(qw==s.getr())
		{
			flag=1;
			continue;
		}
		else
			fout.write((char*)&s,sizeof(s));
	}
	fin.close();
	fout.close();
	remove("DSF.txt");
	rename("Temp.txt","DSF.txt");
	if(flag==1)
		cout<<"\n Data was Deleted successsfully ";
	else 
		cout<<"\n Data was not found for Deletion";
}
void cfile::modify()
{
	int qw,flag=0,rn;
	cout<<"\n Enter the number to be modified";
	cin>>qw;
	ofstream fout;
	ifstream fin;
	fout.open("Temp.txt",ios::binary|ios::app);
	fin.open("DSF.txt",ios::binary | ios::app);
	student s;
	while(fin.read((char*)&s,sizeof(s)))
	{
		if(qw==s.getr())
		{
			
			rn=s.getr();
			s.getdata();
			s.assign(rn);
			flag=1;
		}
		fout.write((char*)&s,sizeof(s));
	}
	fin.close();
	fout.close();
	remove("DSF.txt");
	rename("Temp.txt","DSF.txt");
	if(flag==1)
		cout<<"\n Data was modified successsfully ";
	else 
		cout<<"\n Data was not found for modification";
}
void cfile::add()
{
	ofstream fout;
	student s;
	fout.open("DSF.txt",ios::binary | ios::app);
	s.getdata();
	fout.write((char*)&s,sizeof(s));
	fout.close();
}
void cfile::display()
{
	ifstream fin;
	student s;
	fin.open("DSF.txt",ios::binary | ios::app);
	while(fin.read((char*)&s,sizeof(s)))
	{
		s.display();
	}
	fin.close();
}
int main()
{
	int ch;
	cfile f;
	do
	{
		cout<<"\n1.Add data\n2.display data\n3.Modify\n4.Delete\n5.Search \n Enter your choice";
		cin>>ch;
		switch(ch)
		{
		case 1:
			f.add();
			break;
		case 2:
			f.display();
			break;
		case 3:
			f.modify();
			break;
		case 4:
			f.Delete();
			break;
		case 5:
			f.search();
		}
	}while(ch!=0);
}
