#include <iostream>
#include <sstream>
#include <cstring>



template <typename T> 
class Container
{
public:
	Container(); 				
	Container ( int ); 			
	Container( Container const & src); 
	~Container();				
	void pushBack(T); 			
	void popBack();       		
	T& operator[] ( int i );	
	int lenght();     			
	bool is_empty();  			
	void clear();				
protected:
	void allocate();			
protected:
	T  *m_data;    
	int m_last;    
	unsigned int m_size;
	int m_inc_sz;  

};




template <typename T> 
Container<T>::Container()
{  
	m_size=0; 		
	m_last=-1; 		
	m_data=NULL; 	
	m_inc_sz=10;	
}


template <typename T> 
Container<T>::Container( int c )
{
	//if( c < 0 ) c = 0; 
	
	m_data = new T[ c ](); 	
	m_last = c-1;			
	m_size = c;				
}


template <typename T> 
Container <T>::Container( Container const & src )
{
	m_size = src.m_size; 
	
	m_data = new T[ m_size ]; 
	
	
    for( int i=0 ; i < m_size ; i++ ) m_data[ i ] = src.m_data[ i ];
        
	m_last = m_size - 1; 
}


template <typename T> 
Container <T>::~Container()
{
	
	 if( m_size > 0 ) delete []m_data;
}


template <typename T> 
void Container <T>::pushBack( T const &data)
{
	
	if( ( m_last + 1 ) >= m_size )
	{
	
	  allocate(); 
	  
	}
	
	m_data[ ++m_last ] = data;
   
}


template <typename T> 
void Container <T>::popBack()
{
    
	if( m_last >= 0 )  m_last--;
}


template <typename T> 
T&  Container <T>::operator[] ( int index )
{
	
	if (index < 0 || index > m_last) throw std::runtime_error("Wrong index: " + std::to_string(index));
	
 return m_data[ index ];
}
	

template <typename T> 
void Container <T>::allocate()
{

 
 T *ptr=new T[ m_size + m_inc_sz ]; 

 
 for( int i=0 ; i < m_size ; i++ )  ptr[ i ] = m_data[ i ];

 delete []m_data; 

 m_size += m_inc_sz; 

 m_data =  ptr;
 
 	
}


template <typename T> 
int  Container <T>::lenght()
{
 return ( m_last + 1 );
}


template <typename T> 
bool Container <T>::is_empty()	
{
 return ( m_last < 0 );
}


template <typename T> 
void Container <T>::clear()
{
	m_last = -1; 
}


