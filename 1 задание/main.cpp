using namespace std;

#include <iostream>
#include <cstring>
#include <stdlib.h>
#include "container.h"



int main()
{
Container <double> vectDouble(5); 	
Container <int> vectInteger;		
Container <string> vectStr; 		
system("chcp 1251");


vectStr.pushBack(std::string("123"));
vectStr.pushBack(std::string("456"));
vectStr.pushBack(std::string("789"));


try
{

cout <<"��������� �����:";

for( int i = 0 ; i < vectStr.lenght() ; i++ )cout << vectStr[i]<<',';
cout << endl;


double a=0.1;
	
	
	for(int i = 0 ; i < vectDouble.lenght() ; i++)
	{
	  vectDouble[i] = a; a+=a;
	}
	
	cout <<"��������� ���. �����:";
	
	for(int i=0;i< vectDouble.lenght(); i++) cout << vectDouble[i] << ' ';
 
 	cout << std::endl;

  
	vectInteger.pushBack(3);
	vectInteger.pushBack(4);
	vectInteger.pushBack(5);
	vectInteger.pushBack(7);
	vectInteger.pushBack(8);
	vectInteger.pushBack(9);
	vectInteger.pushBack(10);
	vectInteger.pushBack(11);
	vectInteger.pushBack(-2);
	vectInteger.pushBack(-3);
	vectInteger.pushBack(-4);

	cout <<"��������� ����� �����:";
    
   	for(int i=0;i< vectInteger.lenght(); i++)  std::cout << vectInteger[i] << ' ';
	cout << endl;
 
 	
	Container <int> vectInteger2=vectInteger;
 
    cout <<"������ ��������� ���. �����" << endl;
    
 	vectDouble.clear();
 
 	
 	cout << "������ ���. ����������: " << vectDouble.lenght() << endl;
 	
 	cout << "������ ������ ����������: " << vectInteger.lenght() << endl;
 
 	cout << vectDouble[5] << endl; 
 
}
catch(const std::string &msg)
{
  
	std::cerr << msg << endl;
}
 
cout << endl;

system("pause");

return 0;
}
