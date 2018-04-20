#include <iostream>
#include <fstream>
#define MAX 50
using namespace std;

int getPositiveInt()
{
	int x;
	do
	{
		cin >> x;
		if (x < 1)
			cout << "Please enter a positive integer.\n";
	}
	while (x < 1);
	return x;
}

class employee
{
	char name[MAX];
	int id;
	int chain;
public:
	employee()
	{
		name[0] = '-';
		name[1] = '\0';
		id = chain = -1;
	}
	void readData();
	void display();
	int getID() { return id; }
	int getChain() { return chain; }
	void setChain(int x) { chain = x; }
	void setID(int x) { id = x; }
	void changeName() { cin.ignore(); cin.getline(name, MAX); }
};

void employee::readData()
{
	cout << "Name - ";
	cin.ignore();
	cin.getline(name, MAX);
	cout << "ID - ";
	id = getPositiveInt();
}

void employee::display()
{
	cout << id << "\t" << name << "\t" << chain << endl;
}

class DAFile
{
	int maxCount, recordCount;
	public:
	DAFile();
	void insert();
	void displayAll();
	int hash(int key) { return (key % maxCount); }
	int search(int key);
	void modify();
};

DAFile::DAFile()
{
	recordCount = maxCount= 0;
	bool flag = false;
	fstream myF;
	employee emp;
	//created file
	myF.open("Employee Database.txt", ios::app);
	myF.close();
	myF.open("Employee Database.txt", ios::in);//read
	while (myF.read((char*)&emp, sizeof(emp)))
	{
		flag = true;
		maxCount++;
		if (emp.getID() != -1)
			recordCount++;
	}
	cout << recordCount << endl << maxCount << endl;
	myF.close();
	
	if (flag == false)
	{
		cout << "Enter the number of records you wish to store in the file- ";
		cin >> maxCount;
		bool primeFlag;
		do
		{
			primeFlag = true;
			for (int i = 2; i < maxCount; i++)
				if (maxCount % i == 0)
				{
					primeFlag = false;
					break;
				}
			if (primeFlag == false)
				maxCount++;
		}
		while(primeFlag == false);
		cout << maxCount << endl;
		myF.open("Employee Database.txt", ios::in | ios::out);
		for (int i = 0; i < maxCount; i++)
			myF.write((char*)&emp, sizeof(emp));
		myF.close();
	}
}

void DAFile::insert()
{
	if (recordCount == maxCount)
	{
		cout << "Table is full. Cannot add more records." << endl;
		return;
	}
	int location, oldLocation;
	fstream myF;
	employee newEmp, oldEmp, temp;
	cout << "Enter the details of the new employee - " << endl;
	newEmp.readData();
	location = hash(newEmp.getID()); // Calculate location from id using hash function
	myF.open("Employee Database.txt", ios::in | ios::out); 
	myF.seekg(location * sizeof(newEmp)); // Move pointer to location
	myF.read((char*)&oldEmp, sizeof(oldEmp)); // Read the record present at location
	if (oldEmp.getID() != -1) // If it is not blank
	{
		while (oldEmp.getChain() != -1) // While we haven't reached the end of the chain
		{
			location = oldEmp.getChain(); // Change location to chain of current record
			myF.seekg(location * sizeof(oldEmp)); // Move pointer to updated location
			myF.read((char*)&oldEmp, sizeof(oldEmp)); // Read the record present there
		}
		oldLocation = location;
		temp = oldEmp;
		while (temp.getID() != -1)
		{
			location = (location + 1) % maxCount;
			myF.seekg(location * sizeof(temp));
			myF.read((char*)&temp, sizeof(temp));
		}
		oldEmp.setChain(location);
		myF.seekp(oldLocation * sizeof(oldEmp));
		myF.write((char*)&oldEmp, sizeof(oldEmp));
	}
	myF.seekp(location * sizeof(newEmp));
	myF.write((char*)&newEmp, sizeof(newEmp));
	myF.close();
	recordCount++;
}

void DAFile::displayAll()
{
	fstream myF;
	employee emp;
	myF.open("Employee Database.txt", ios::in);
	cout << "ID\tName\tChain" << endl;
	while (myF.read((char*)&emp, sizeof(emp)))
		emp.display();
	cout << endl;
	myF.close();
}

int DAFile::search(int key)
{
	int location = hash(key);
	fstream myF;
	bool flag = false;
	employee emp;
	myF.open("Employee Database.txt", ios::in);
	myF.seekg(location * sizeof(emp));
	myF.read((char*)&emp, sizeof(emp));
	if (emp.getID() != key)
	{
		while (emp.getChain() != -1 && emp.getID() != key)
		{
			location = emp.getChain();
			myF.seekg(location * sizeof(emp));
			myF.read((char*)&emp, sizeof(emp));
		}
	}
	
	if (emp.getID() == key)
		flag = true;
	
	if (flag == true)
	{
		cout << "Record found!" << endl;
		cout << "\nID\tName\tChain" << endl;
		emp.display();
		myF.close();
		return location;
	}
	else
	{
		cout << "Record not found." << endl;
		myF.close();
		return -1;
	}
}

void DAFile::modify()
{
	fstream myF;
	employee emp;
	int key;
	cout << "ID = ";
	key = getPositiveInt();
	int location = search(key);
	if (location == -1)
		return;
	myF.open("Employee Database.txt", ios::in | ios::out);
	myF.seekp(location * sizeof(emp));
	myF.seekg(location * sizeof(emp));
	myF.read((char*)&emp, sizeof(emp));
	cout << "Enter the modified name - ";
	emp.changeName();
	myF.seekp(location * sizeof(emp));
	myF.seekg(location * sizeof(emp));
	myF.write((char*)&emp, sizeof(emp));

}

int main()
{
	int choice, key;
	DAFile obj;
	for (;;)
	{
		cout << "1. Insert a record\n"
			 << "2. Display all records\n"
			 << "3. Search for a record\n"
			 << "4. Modify a record (name only)\n"
			 << "5. Exit\n\n"
			 << "Enter your choice - ";
		cin >> choice;
		cout << endl;
		
		if (choice == 5)
			break;
		
		switch (choice)
		{
			case 1:
				obj.insert();
				break;
			
			case 2:
				obj.displayAll();
				break;
				
			case 3:
				cout << "ID = ";
				key = getPositiveInt();
				obj.search(key);
				break;
			
			case 4:
				obj.modify();
				break;
			
			default:
				cout << "Invalid choice!" << endl;
				break;
		}
		cout << endl;
	}
	return 0;
}
