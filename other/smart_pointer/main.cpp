#include<iostream>
using namespace std;

template<typename T>
class Smartpointer
{
public:
	// the constructor taking a dynamic type as input, ptr becomes a smart pointer after this
	Smartpointer(T* ptr);
	// copy constructor, after this operation, there will be one more pinter pointing to the dynamic object on the heap
	Smartpointer(Smartpointer<T> &sptr); 
	// assignment operator, after this operation, the address in the pointer "sptr" is assigned to the calling object, the heap memory where the calling object originally pointing to, becomes a leak
	Smartpointer<T>& operator=(Smartpointer<T> &sptr);
	// destructor, decrease the refNum by one, and if no reference to heap memory, clear memory
	~Smartpointer();
	T getValue(){return *ref;}

private:
	//clean the memory in the heap, since not directly accessible by the user, make it private.
	void clear(); 
	T *ref; // the address of the object in the heap
	int *refNum; // the number of pointers pointing to this address
};


int main()
{
    	int *ip1 = new int(1);
    	int *ip2 = new int(2);
    	Smartpointer<int> sp1(ip1), sp2(ip2);
    	Smartpointer<int> spa1 = sp1;
    	sp2 = spa1; // memory clear, avoid memory leak

    	int *ip3 = new int(3);
    	int *ip4 = new int(4);
    	Smartpointer<int> sp3(ip3), sp4(ip4);
    	Smartpointer<int> spa2 = sp3;
   	return 0;
}


template<typename T>
Smartpointer<T>::Smartpointer(T *ptr)
{
	ref=ptr;
	refNum=new int(1); // allocate on the heap so that the refNum becomes global to all pointers refering to this object
}

template<typename T>
Smartpointer<T>::Smartpointer(Smartpointer<T> &sptr)
{
	ref=sptr.ref;
	(*(sptr.refNum))++;
	refNum=sptr.refNum;
}

template<typename T>
Smartpointer<T>& Smartpointer<T>::operator=(Smartpointer<T> &sptr)
{
	if (this!=&sptr)
	{
		if(--(*refNum)==0)
		{
			clear(); // delete the memory in the heap to avoid memory leak
			cout<<"Assignment operator= clear, avoid memory leak"<<endl;
		}
		
		ref=sptr.ref;
		(*(sptr.refNum))++;
		refNum=sptr.refNum;
	}
	return *this;
}

template<typename T>
Smartpointer<T>::~Smartpointer()
{
	if(--(*refNum)==0)
	{
		clear(); // delete memory in the heap to avoid memory leak
		cout<<"Destructor clear, avoid memory leak"<<endl;
	}
}

template<typename T>
void Smartpointer<T>::clear()
{
	delete ref;
	delete refNum;
	ref=nullptr; // avoid dangling pointer problem
	refNum=nullptr; // avoid dangling pointer problem
}
