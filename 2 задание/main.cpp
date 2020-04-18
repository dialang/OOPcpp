

#include <iostream>
#include <cstring>
#include <stdlib.h>
#include "container.h"
#include "classes.h"
#include <time.h>

using namespace std;


Container <Shape*> Collection;

#define RAND100  rand()%101

int SelectItem(int n)
{
	int item;
	while( true ) 
	{
		cin >> item;
		if( (item > 0 && item <= n  ) && (cin.peek()=='\n')) 
		{ cin.get();
		  break; 
		}
		else
		{
		cout <<"��������� �����. ��������� ����.(�� 1 �� "<< n <<"):"<<endl;
		cin.clear();
		
		while( cin.get()!='\n'){	}; 
		
		}
	}
	return item;
}

void ListAllFigures()
{
int n=Collection.lenght();

cout << endl << "������ �����: "<<endl<<"---------------------------"<< endl;
if( n > 0 )
{

for(int i=0;i<n;i++)
{
	cout << *( Collection[i] )<< endl;;
}
cout<<"---------------------------"<<endl;
cout << "����� ����� �������������� �����: "<< Collection[0]->GetCount() <<endl;

}
else cout << "������ ����"<< endl;

cout<<"---------------------------"<<endl;
}


void AddFigure(void )
{ 
 	int item;
 	Shape *pShape; 
  	float x,y,rad,w,h,n;
	Polyline *ppoly;
	Polygon *ppgn;
	
		cout << "�������� ��� ����������� ������:"<< endl;
		cout << "1.�����."<<endl;
		cout << "2.����������."<<endl;
		cout << "3.�������������."<<endl;
		cout << "4.�������."<<endl;
		cout << "5.�������."<<endl;
		cout << "6.�������������."<<endl;
		
		item=SelectItem(6); 
	
		
		switch(item)
		{
			case 1: 
					x=RAND100; y=RAND100;
					pShape = new Point(x,y); 
					cout << *pShape;
					break;
			case 2: 
					x=RAND100; y=RAND100; rad=RAND100;
					pShape=new Circle(x,y,rad);  break;
			
			case 3:  
					x=RAND100; y=RAND100; w=RAND100;h=RAND100;
					pShape=new Rect(x,y,x+w,y+h);break;
			
			case 4: 
					x=RAND100; y=RAND100; w=RAND100;
					 pShape=new Square(0,0,w);
					 break;
			
			case 5: 
					ppoly=new Polyline(); 
					n=2+rand()%10;
					for(int i=0 ; i < n ; i++ )
					{ x=RAND100; y=RAND100; ppoly->AddPoint(Point(x,y)); }
					pShape=ppoly; 
					break; 
					
			case 6: 
					ppgn = new Polygon();
					n=3+rand()%10;
					for(int i=0; i<n; i++ )
					{ x=RAND100; y=RAND100; ppgn->AddPoint(Point(x,y));}
					pShape=ppgn;
					break;
			default:cout << "������ ���������."<< endl; return;
		}
		
		cout << *pShape << endl;
		
		Collection.pushBack(pShape);
		
		cout <<"������ ������� �������� � ���������."<< endl;
}


int main()
{
	
	setlocale(0,"Russian");
	
	bool bQuit;
	int k;
	
	system("cls");
	
	bQuit=false;
	
	srand(time(0)); 
		
	
	while( !bQuit )
	{
		
		cout <<"1.�������� ������"<< endl;
		cout <<"2.������ ���� ��������"<<endl;
		cout <<"3.����� �� ���������"<< endl;
	
	
		k=SelectItem(5);
	
		switch(k)
		{
			case 1: AddFigure(); break;
			case 2: ListAllFigures(); break;
			case 3: bQuit=true; break;
		
		}
	
	}

return 0;
}
