#include <cstring>
#include <iostream>
#include <math.h>

using namespace std;


class Printable
{
public:
	Printable(){}
	virtual std::string ToString()=0; 
	friend std::ostream& operator<<(std::ostream &output, Printable const &obj);
};

std::ostream& operator<<(std::ostream &output,   Printable  &obj)
{
	std::string strout=obj.ToString();
	
    output<<strout;
        
    return output;
}

class Named: public virtual Printable
{
public:
	Named();
	Named(std::string const &name){m_name=name;} // Вопрос: а почему параметр -- С-строка?
protected:                                      // Исправила на std::string
	std::string m_name;

};



class Shape : public virtual Printable
{
public:
	Shape()  { sm_Counter++; }
	~Shape() { sm_Counter--; }
	int GetCount(); // Ворос: вы в конце программы GetCount() выводили? Чё там было написано?
		       // Число соданных экземпляров класса Shape в текущий момент времени
protected:
	static int sm_Counter;
};


int Shape::GetCount(){	return sm_Counter;}

int Shape::sm_Counter=0;

class Point : public Shape,public Named
{
 static std::string sm_stat_name;

public:
	Point():Named(sm_stat_name + std::to_string(GetCount())){X=Y=0;}
//	Point(float x,float y):Named("POINT"),Shape(){X=x;Y=y;}
	Point(float x,float y):Named(sm_stat_name + std::to_string(GetCount())){X=x;Y=y;}
   
   //Вопрос: Shape() писать разве обязательно? а можно сделать так,чтобы у каждого экземпляра точки было своё персональное имя? 
  //добавляем уникальный номер экземпляра класса Shape
  
 	virtual std::string ToString(); 
 	float x(){	return X;	 }
 	float y(){	return Y;	}
 	float distance(Point &p); //"distance" please - исправлено
	friend Point operator-(Point const &p1, Point  const &p2);
protected:
	float X,Y;
};

 std::string Point::sm_stat_name="POINT";// стандартный префикс имени точки
 
std::string Point::ToString()
{ 
   std::stringstream ss;
   ss << m_name <<'('<<X<<','<<Y<<')';
   return ss.str();
}

float Point::distance(Point  &p)
{
   float dx,dy;	
   dx=X-p.x();
   dy=Y-p.y();
   return sqrt( dx * dx + dy * dy );
}

Point operator-(Point  const &p1, Point   const &p2)
{
	return Point( p1.X - p2.X, p1.Y - p2.Y );
}
 
class Circle : public Shape,Named
{
	Point center;
	double rad;
 public:
	Circle():Named("CIRCLE"),Shape(){}
 	Circle(float x,float y,float r):Named("CIRCLE"),Shape(){center=Point(x,y); rad=r; }
 	virtual std::string ToString(); 
	float Area(){return rad*rad*3.1415926535;} 
};

std::string Circle::ToString()
{ 
   std::stringstream ss;
   ss << m_name <<'('<< '(' <<center.x()<<','<<center.y()<<')'<<",Rad:"<<rad<<",Area:"<<Area()<<')';
   return ss.str();
}


class Rect : public Shape,Named
{
 public:
 Rect():Named("RECT"),Shape(){}
 Rect(float left,float bottom,float width,float height):Named("RECT"),Shape(){ leftbottom=Point(left,bottom); righttop=Point(left+width,bottom+height); }
 virtual std::string ToString(); 
 float Area(); 
 float Perimetr();
protected:
 Point leftbottom;
 Point righttop;
 
};

std::string Rect::ToString()
{
   std::stringstream ss;
   ss << m_name <<'('<<'('<<leftbottom.x()<<','<<leftbottom.y()<<')'<<','<< '('<<righttop.x()<< ','<< righttop.y()<<')'<< ",Perimetr:"<<Perimetr()<<",Area:"<<Area()<<')';
   return ss.str();
}

 float Rect::Area()
{ 
  Point d = righttop - leftbottom; 

  return d.x() * d.y();

} 

float Rect::Perimetr()
{
  Point d = righttop - leftbottom; 

  return 2 * d.x() + 2 * d.y();

}

class Square :public Shape,Named
{
 public:
 	Square():Named("SQUARE"),Shape(){}
 	Square(float left,float bottom,float w):Named("SQUARE"),Shape(){ leftbottom=Point(left,bottom); width=w;  }
	virtual std::string ToString(); 
protected:
	Point leftbottom;
	float width; 	
        float Area(){ return width*width; }
	float Perimetr(){ return 4*width; }
};

std::string Square::ToString()
{
	std::stringstream ss;
   	ss << m_name <<'('<<'('<<leftbottom.x()<<','<<leftbottom.y()<<')';
        ss << ','<< width <<",Perimetr:"<<Perimetr()<< ",Area:"<< Area() << ')'; 
//плохо делать длинные строки - исправлено
   	return ss.str();
}


class Polyline : public Shape,Named
{
 public:
 Polyline():Named("POLYLINE"),Shape() {}
 void AddPoint(Point const &point);
 virtual std::string ToString(); 
 float Length(); 
protected:
 Container <Point> line; 
};


float Polyline::Length()
{
 	float d=0;
 	Point p1,p2;
 	if( line.lenght() > 1 )
 	{
	 for( int i=0; i < (line.lenght()-1) ; i++ )
	 {
	 	p1=line[i];
	 	p2=line[i+1];
	        d += p1.distance(p2);
	 }
	 
	 }
	 
	 return d;
 }

 void Polyline::AddPoint(Point const &point)
 {
 	line.pushBack(point);
 }
 
std::string Polyline::ToString()
{
	std::stringstream ss;
	Point p;
	ss << m_name << '(';
	for(int i=0; i< line.lenght(); i++)
	{
		p=line[i];
	    ss << p.ToString();	
	}
	ss << "Length:"<< Length() << ')';
	
   	
   	return ss.str();
}
 

class Polygon : public Shape,Named
{
 public:
 	Polygon():Named("POLYGON"),Shape(){}
 	void AddPoint(Point const &point);
 	virtual std::string ToString(); 
	float Perimetr();
protected:
	Container <Point> verts;
};

 void Polygon::AddPoint(Point const &point)
 {
 	verts.pushBack(point);
 }
 
std::string Polygon::ToString()
{
	std::stringstream ss;
	Point p;
	ss << m_name << '(';
	for(int i=0; i< verts.lenght(); i++)
	{
	    p=verts[i];
	    ss << p.ToString();	
	}
	ss <<"Perimetr:"<<Perimetr()<<')';
	
   	
   	return ss.str();
}

float Polygon::Perimetr()
{
 	float p=0;
 	Point p1,p2;
 	int num = verts.lenght();
 	
 	if( num > 2 )
 	{
	 for( int i=0; i < num ; i++ )
	 {
	 	p1=verts[i];
	 	p2=verts[(i+1)%num];
	    p += p1.distance(p2);
	 }
	 
	 }
	 
	 return p;

}
