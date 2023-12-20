#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<vector>
#include<iomanip>
// You can add more libraries here (if needed)
using namespace std;
// Define the classes and member functions here

struct Student {
	int id;
	string name;
	Student() {
		id = 0;
		name = "invalid";
	};
	Student(int inputid, string inputname) {
		id = inputid;
		name = inputname;
	};
};

class Table {
public:
	void InsertStudent(Student x, int y);
	void SearchbyID(int x);
	void SearchbyGrade(int y);
	void Statistics();
	void PrintAll();
	// You can add more member functions to help your implementation.
	map<struct Student, int>book;//create the map
	map<struct Student, int>::iterator itr;//create the corresponding iterator
private:
	/* The data type is decided by you records; */
};

bool operator<(const Student& a, const Student& b) {
	return a.id < b.id;
}

//insert one record in to the map
void Table::InsertStudent(Student x, int y) {
	book[x] = y;
}

//return the name and grade of the student with id x
void Table::SearchbyID(int x) {
	for (itr = book.begin(); itr != book.end(); itr++)
	{
		if ((*itr).first.id == x)//(*itr).first is key, (*itr).second is value
		{
			cout << (*itr).first.name << endl;
			cout << (*itr).second << endl;
			return;
		}
	}
	cout << "No such student." << endl;
}

//return the id and name of the student with grade y
void Table::SearchbyGrade(int y) {
	int flag = 0;
	for (itr = book.begin(); itr != book.end(); itr++)
	{
		if ((*itr).second == y)
		{
			cout << (*itr).first.id << " " << (*itr).first.name << endl;
			flag = 1;
		}
	}
	if (flag == 0)
	{
		cout << "No such record." << endl;
	}
	return;
}

void Table::Statistics() {
	int max = 0;
	int min = 10000;

	for (itr = book.begin(); itr != book.end(); itr++)
	{
		if ((*itr).second > max)
		{
			max = (*itr).second;
		}
	}
	cout << "Maximum " << max << endl;//get the maximum

	//to get the median by using dynamic memory
	int size = book.size();
	int* gradesArray = new int[size];
	int index=0;
	for (itr = book.begin(); itr != book.end(); itr++)
	{
		gradesArray[index] = (*itr).second;
		index++;
	}
	sort(gradesArray, gradesArray + size);//sort the array

	if (size % 2 == 0)
	{
		//it is even
		int mid = size/2;
		double first = gradesArray[mid];
		double second = gradesArray[mid-1];
		double median = (first + second)/2;
		cout<<"Median "<<median<<endl;
	}
	else if (size % 2 != 0)
	{
		//it is odd
		int mid = size/2;
		int median = gradesArray[mid];
		cout<<"Median: "<<median<<endl;
	}
	delete [] gradesArray;

	for (itr = book.begin(); itr != book.end(); itr++)
	{
		if ((*itr).second < min)
		{
			min = (*itr).second;
		}
	}
	cout << "Minimum " << min << endl;//get the minimum

	return;
}

//Print all records in the accending order of id
void Table::PrintAll() {
	for (itr = book.begin(); itr != book.end(); itr++)
	{
		cout << (*itr).first.id << " " << (*itr).first.name << " " << (*itr).second << endl;
	}
	return;
}


int main() {
	Table t;
	string command;
	int id;
	string name;
	int grade;


	while (cin >> command) {
		if (command == "InsertStudent") {
			cin >> id >> name >> grade;
			Student s = { id, name };
			t.InsertStudent(s, grade);
		}
		else if (command == "SearchbyID") {
			cin >> id;
			t.SearchbyID(id);
		}
		else if (command == "SearchbyGrade") {
			cin >> grade;
			t.SearchbyGrade(grade);
		}
		else if (command == "PrintAll") {
			t.PrintAll();
		}
		else if (command == "Statistics") {
			t.Statistics();
		}
		else if (command == "exit") {
			break;
		}
	}

	return 0;
}
