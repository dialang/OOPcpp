

#include <iostream>
#include <sstream>
#include <cstring>
#include <stdlib.h>
#include "container.h"
#include "classes.h"
#include <time.h>

using namespace std;


Container <Shape*> Collection;

 //макросы это зло; или пишите везде rand()%101, или сделайте функцию.
//Заменила на функцию
int RAND(int n=100){ return   rand()%(n+1); }


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
		cout <<"Ошибочный выбор. Повторите ввод.(от 1 до "<< n <<"):"<<endl;
		cin.clear();
		
		while( cin.get()!='\n'){	}; 
		
		}
	}
	return item;
}

void ListAllFigures()
{
int n=Collection.lenght();

cout << endl << "Список фигур: "<<endl<<"---------------------------"<< endl;
if( n > 0 )
{

for(int i=0;i<n;i++)
{
	cout << *( Collection[i] )<< endl;;
}
cout<<"---------------------------"<<endl;
cout << "Общее число геометрических фигур: "<< Collection[0]->GetCount() <<endl;

}
else cout << "Список пуст"<< endl;

cout<<"---------------------------"<<endl;
}


void AddFigure(void )
{ 
 	int item;
 	Shape *pShape; 
  	float x,y,rad,w,h,n;
	Polyline *ppoly;
	Polygon *ppgn;
	
		cout << "Выберите тип добавляемой фигуры:"<< endl;
		cout << "1.Точка."<<endl;
		cout << "2.Окружность."<<endl;
		cout << "3.Прямоугольник."<<endl;
		cout << "4.Квадрат."<<endl;
		cout << "5.Ломаная."<<endl;
		cout << "6.Многоугольник."<<endl;
		
		item=SelectItem(6); 
	
		
		switch(item)
		{
			case 1: 
					x=RAND(); y=RAND();
					pShape = new Point(x,y); 
				
					break;
			case 2: 
					x=RAND(); y=RAND(); rad=RAND();
					pShape=new Circle(x,y,rad);  break;
			
			case 3:  
					x=RAND(); y=RAND(); w=RAND();h=RAND();
					pShape=new Rect(x,y,x+w,y+h);break;
			
			case 4: 
					x=RAND(); y=RAND(); w=RAND();
					 pShape=new Square(0,0,w);
					 break;
			
			case 5: 
					ppoly=new Polyline(); 
					n=2+rand()%10;
					for(int i=0 ; i < n ; i++ )
					{ x=RAND(); y=RAND(); ppoly->AddPoint(Point(x,y)); }
					pShape=ppoly; 
					break; 
					
			case 6: 
					ppgn = new Polygon();
					n=3+rand()%10;
					for(int i=0; i<n; i++ )
					{ x=RAND(); y=RAND(); ppgn->AddPoint(Point(x,y));}
					pShape=ppgn;
					break;
			default:cout << "Ошибка программы."<< endl; return;
		}
		
		cout << *pShape << endl;
		
		Collection.pushBack(pShape);
		
		cout <<"Объект успешно добавлен в хранилище."<< endl;
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
		
		cout <<"1.Добавить объект"<< endl;
		cout <<"2.Список всех объектов"<<endl;
		cout <<"3.Выход из программы"<< endl;
	
	
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
