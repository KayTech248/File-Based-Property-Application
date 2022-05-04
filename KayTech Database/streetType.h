#pragma once
#include "entityType.h"

#include <iostream>
#include <fstream>
#include <string>
#include "neighborHoodType.h"

using namespace std;

struct strObj
{
	string ID;
	string name;
	string neighID;
	int houseNo;
};

class streetType : public entityType
{
public:
	streetType();
	void setRecords();
	string getID(int p);
	string getName( int p);
	string getNeighID(int p);
	int getHouseNo(int p);
	void SelectAll(string pk);
	void Insert(string pk);
	void Delete(string pk);
	~streetType();
private:
	strObj * list;
	neighborHoodType hood;
};

streetType :: streetType()
{
	tname = "Street_Table ";
	size = 5;
	list = new strObj[size];
	hood.setRecords();

	ofstream outData;
	  
	outData.open("streetData.txt");
	if(outData.is_open() == false)
		cout <<"file not found"<<endl;
	else 
	{
		  outData<<"ST001"<<" "<<"Alsatian_Str" <<" "<< hood.getID(0) <<" "<<30<<endl;
		  outData<<"ST002"<<" "<<"Glen_Austin" <<" "<< hood.getID(0) <<" "<<35<<endl;
		  outData<<"ST003"<<" "<<"Nelson_Mandela" <<" "<< hood.getID(1) <<" "<<34<<endl;
		  outData<<"ST004"<<" "<<"congo_Street" <<" "<< hood.getID(6) <<" "<<40<< endl;
		  outData<<"ST005"<<" "<<"BelAir_Drive" << " " <<hood.getID(7) <<" "<< 42 <<endl;
		    outData.close();
	}	
}

void streetType:: setRecords()
{
	ifstream in;
	in.open("streetData.txt");
	for (int i = 0; i < size; i++)
	{
		in >> list[i].ID;
		in >> list[i].name;
		in >> list[i].neighID;
		in >> list[i].houseNo;
	}
	in.close();
}



string streetType:: getName( int no)
{
		return list[no].name;

}
string streetType:: getID(int no)
{
	return list[no].ID;
}

int streetType :: getHouseNo(int no)
{
	return list[no].houseNo;
}

streetType::~streetType()
{
	delete [] list;
}


void streetType :: SelectAll(string pk)
{
	bool found = false;
	for(int i = 0; i < size; i++)
	{
		if(pk == list[i].ID)
		{
			cout << list[i].ID << " ";
			cout << list[i].name<< " ";
			cout << list[i].neighID<<  " ";
			cout << list[i].houseNo << " ";
			cout << endl;
		}

	}
	if(found == false)
		cout << "No results" << endl;
	
}

void streetType :: Insert( string pk)
{
	ofstream addData;
	string n;
	int no;
	string p;
	cout << "Enter new street name(eg congo Street): ";
	cin >> n;
	cout << "Enter The hood id : ";
	cin >> p;
	cout << "Enter The no of houses: ";
	cin >> no;
	addData.open("NewHood.txt",ios :: app);													

	addData << pk << " " << n << " " << p << " " << no << endl;
	addData.close();
}

void streetType :: Delete( string pk)
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

