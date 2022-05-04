#pragma once
#include "entityType.h"
#include <iostream>
#include "clientType.h"
#include "streetType.h"
#include <fstream>
#include <string>

using namespace std;

struct hrow
{
	string clientID;
	string streetID;
	string ID;
	string Address;
};

class houseType : public entityType
{
public:
	houseType();
	~houseType();
	void Delete(string pk);
	void Insert(string pk);
	void createFile(int p);
	void setRecords();
	string getID(int p);
	string getAddress(int p);
	string getclientID(int p);
	void displayProperty(string pk);
	void displayClients();
	string getStreetID(int p);
	void print();
	void SelectAll(string pk); 
	void locateClient(string pk);
	void changeClient(string pk);
	void addClient(string pk);
private:
	hrow * list;
	clientType client;
	streetType streetObj;

	
};


houseType :: houseType()
{
	tname = "houseType_Table";
	size = 10;
	list = new hrow[size];
	streetObj.setRecords();
	client.setRecords();

	ofstream outData;
	  
	outData.open("houseData.txt");
	if(outData.is_open()==false)
		cout <<"file found"<<endl;
	else
	{
		outData<<"HN001"<<" "<<"10A" <<" "<< streetObj.getID(3) <<" "<<client.getID(0)<<endl;
		outData<<"HN002"<<" "<<"9C" <<" "<< streetObj.getID(3) <<" "<<client.getID(0)<<endl;
		outData<<"HN003"<<" "<<"44D" <<" "<< streetObj.getID(2) <<" "<< client.getID(3)<<endl;
		outData<<"HN004"<<" "<<"101F" <<" "<< streetObj.getID(1) <<" "<<client.getID(3)<< endl;
		outData<<"HN005"<<" "<<"G45" << " " <<streetObj.getID(1) <<" "<< client.getID(4) <<endl;
		outData<<"HN006"<<" "<<"H67" << " " <<streetObj.getID(0)<<" "<< client.getID(5) <<endl;
		outData<<"HN007"<<" "<<"HG6" << " " <<streetObj.getID(0) <<" "<< client.getID(3) <<endl;
		outData<<"HN008"<<" "<<"B44" << " " <<streetObj.getID(4)<<" "<< client.getID(2) <<endl;
		outData<<"HN009"<<" "<<"PM9" << " " <<streetObj.getID(0) <<" "<< client.getID(2) <<endl;
		outData<<"HN0010"<<" "<<"GM2" << " " <<streetObj.getID(2)<<" "<< client.getID(9) <<endl;
		outData.close();
	}
}

void houseType ::setRecords()
{
	ifstream inData;
	inData.open("houseData.txt");
	for (int i = 0; i < size; i++)
	{

		inData >> list[i].ID;
		inData >> list[i].Address;
		inData >> list[i].streetID;
		inData >> list[i].clientID;
	}
	inData.close();

}


houseType::~houseType()
{
	delete [] list;
}

void houseType::print()
{
	for(int i = 0; i < size; i++)
	{
			cout << list[i].ID << " ";
			cout << list[i].Address<< " ";
			cout << list[i].streetID <<  " ";
			cout << list[i].clientID<< " ";
			cout << endl;
	}
}


void houseType :: SelectAll(string k)
{
	bool found = false;
	for(int i = 0; i < size; i++)
	{
		if(k == list[i].ID)
		{
			found = true;
			cout << "houseTypeID: " <<list[i].ID << endl;
			cout << "Address: " << list[i].Address<< endl;
			cout << "Street ID: " << list[i].streetID <<  endl;
			cout << "client ID: " << list[i].streetID <<  endl;
			cout << endl;
		}

	}
	if(found == false)
		cout << "No records" << endl;
	
}

void houseType ::locateClient(string pk)
{
	client.SelectAll(pk);
}

void houseType ::changeClient(string pk)
{
	bool found = false;
	for(int i = 0; i < size; i++)
	{
		if(pk == list[i].ID)
		{
			found = true;
			cout << "Enter New clients ID: ";
			cin >> list[i].clientID;
			client.Insert(list[i].clientID);
			cout <<"NEW CLIENT LIST" <<endl;
			client.print();
			createFile(i);										
	
		}

	}
	if(found == false)
		cout << "No results" << endl;
}
void houseType :: Insert( string pk)
{
	ofstream addData;

	string address, strid, clientid;

	int i =0;
	while(i < size)							
	{
		bool found = false;
		if (pk == list[i].ID)
		{
			found = true;
			cout << "ID exits. enter another: ";
			cin >> pk;
		}
		if(found)
			i = 0;
		else
			i++;

	}
	cout << "Enter new houseType Address: ";
	cin >>address;
	cout << "Enter The street ID: ";
	cin >> strid;
	cout << "Enter the client ID ";
	cin >> clientid;
	client.Insert(clientid);
	//deep copy //
	hrow * list2 = new hrow[size+1];
	for (int i = 0; i < size; i++)
	{
		list2[i] = list[i];
	}
	delete [] list;
	size = size+1;
	hrow * list = new hrow[size];
	for (int i = 0; i < size; i++)
	{
		list[i] = list2[i];
	}
	delete [] list2;
	list[size-1].ID = pk;
	list[size-1].Address = address;
	list[size-1].streetID = strid;
	list[size-1].clientID = clientid;

	addData.open("houseData.txt",ios :: app);													
	addData << pk << " " << address << " " << strid << " " << clientid << endl;
	addData.close();

	addData.open("newHouseInfo.txt",ios :: app);													
	addData << pk << " " << address << " " << strid << " " << clientid << endl;
	addData.close();
	//delete [] list;
	//size++;
	//list = new hrow[size];
	//setRecords();
	
}

void houseType :: Delete( string pk)
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

void houseType ::createFile( int p)
{
	ofstream addData;
	addData.open("NewHouseInfo.txt",ios :: app);
	addData << list[p].ID << " " << list[p].Address << " " << list[p].streetID << " " << list[p].clientID << endl;
	addData.close();
	

	//client.createFile();
}

void houseType :: displayProperty(string pk)
{
	client.SelectAll(pk);
	cout << endl;
	bool found = false;
	for(int i = 0; i < size; i++)
	{
		if(pk == list[i].clientID)
		{
			found = true;
			cout << "houseType ID: " <<list[i].ID << endl;
			cout << "Address: " << list[i].Address<< endl;
			cout << "Street ID: " << list[i].streetID <<  endl;
			cout << "client ID: " << list[i].streetID <<  endl;
			cout << endl;
		}

	}
	if(found == false)
		cout << "No results" << endl;
}
string houseType::getID(int p)
{
	return list[p].ID;
}

string houseType::getAddress(int p)
{
	return list[p].Address;
}

string houseType::getclientID(int p)
{
	return list[p].clientID;
}

string houseType::getStreetID(int p)
{
	return list[p].streetID;
}


void houseType :: displayClients()
{
		client.print();
}

void houseType :: addClient(string pk)
{
	client.Insert(pk);
}