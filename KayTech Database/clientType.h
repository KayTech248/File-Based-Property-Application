#pragma once
#include "entityType.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct record
{
	string ID;
	string name;
	int HouseNo;
	

};

class clientType : public entityType
{
public:
	clientType();
	~clientType();
	void setRecords();
	string getID(int p);
	string getName(int p);
	int getHouseNo(int p);
	void print();
	void SelectAll(string pk);
	void Delete(string pk);
	void Insert(string pk);
	void createFile( int p);

private:
	record *list;
};

clientType :: clientType()
{
	tname = "clientType_Table";
	size = 10;
	list = new record[size];

	ofstream outData;
	  
	outData.open("clientData.txt");
	if(outData.is_open() == false)
		cout <<"file not found"<<endl;
	else 
	{
		  outData<<"CL001"<<" "<<"Christella" <<" " << 2 <<endl;
		  outData<<"CL002"<<" "<<"Elodie" << " "<<1<<endl;
		  outData<<"CL003"<<" "<<"Daniel" << " " <<1 << endl;
		  outData<<"CL004"<<" "<<"Ketsya"  << " " << 4 << endl;
		  outData<<"CL005"<<" "<<"James" << " " << 2 << endl;
		  outData<<"CL006"<<" "<<"Nathan" <<" "<< 1 <<endl;
		  outData<<"CL007"<<" "<<"Paul" <<" "<< 5 <<endl;
		  outData<<"CL008"<<" "<<"Gary" << " "<< 2 <<endl;
		  outData<<"CL009"<<" "<<"Candice" <<" "<< 1 <<endl;
		  outData<<"CL0010"<<" "<<"Bernadette" << " "<< 2 <<endl;
		  outData.close();
	}
}

void clientType :: setRecords()
{
	ifstream inData;
	inData.open("clientData.txt");
	for (int i = 0; i < size; i++)
	{

		inData >> list[i].ID;
		inData >> list[i].name;
		inData >> list[i].HouseNo;
	}
	inData.close();
}
string clientType :: getName(int p)
{
	return list[p].name;
}

string clientType :: getID(int p)
{
	return list[p].ID;
}

int clientType :: getHouseNo(int p)
{
	return list[p].HouseNo;
}

clientType :: ~clientType()
{
	delete [] list;
}

void clientType :: Insert( string pk)
{
	ofstream addData;
	string name;
	int no;
	int i = 0;
	while(i < size)							
	{
		bool found = false;
		if (pk == list[i].ID)
		{
			found = true;
			cout << "ID exists. enter another: ";
			cin >> pk;
		}
		if(found)
			i = 0;
		else
			i++;

	}
	cout << "Enter new owners name(eg Jane): ";
	cin >> name;
	cout << "Enter The number of houses owned(eg 2): ";
	cin >> no;
	//deep copy //
	record * list2 = new record[size+1];
	for (int i = 0; i < size; i++)
	{
		list2[i] = list[i];
	}
	delete [] list;
	size = size+1;
	record * list = new record[size];
	for (int i = 0; i < size; i++)
	{
		list[i] = list2[i];
	}
	delete [] list2;
	list[size-1].ID = pk;
	list[size-1].name = name;
	list[size-1].HouseNo = no;


	addData.open("clientData.txt",ios :: app);													
	addData << pk << " " << name<< " " << no << endl;											
	addData.close();
	addData.open("NewclientInfo.txt",ios :: app);													
	addData << pk << " " << name << " " << no << endl;											
	addData.close();
}

void clientType::print()
{

	for(int i = 0; i < size; i++)
	{
			cout << list[i].ID << " ";
			cout << list[i].name<< " ";
			cout << list[i].HouseNo <<  " ";
			cout << endl;
	}
}

void clientType :: Delete( string pk)
{
	bool found = false;
	for(int i = 0; i < size; i++)
		if(pk == list[i].ID)
		{
			found = true;
			if(i < size)
			{
				size = size - 1;
				for(int j = i; j < size;j++)
				{
						list[j] = list[j+1];
				
				}
			
			}
		}

	if(found == false)
		cout << "No results" << endl;
}


void clientType ::createFile( int p)
{
	ofstream addData;
	addData.open("clientType_Query.txt",ios :: out);

		addData << list[p].ID << " " << list[p].name << " " << list[p].HouseNo << endl;
	addData.close();
}
void clientType :: SelectAll(string pk)
{
	bool found = false;
	for(int i = 0; i < size; i++)
	{
		if(pk == list[i].ID)
		{
			found = true;
			cout << "ID: " <<list[i].ID << endl;
			cout << "Client Name: " << list[i].name<< endl;
			cout << "No_of_Houses owned: " << list[i].HouseNo <<  endl;
			cout << endl;
			createFile(i);
		}

	}
	if(found == false)
		cout << "No results" << endl;
	
}