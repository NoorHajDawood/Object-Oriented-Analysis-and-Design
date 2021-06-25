#pragma once

/*********************************************************************************/
/*****************************<UNIQUE POINTER>************************************/
template <class T>
class UniquePointer
{
public:
	UniquePointer(T* p) : _ptr(p) {}
	~UniquePointer() { delete _ptr; }
	UniquePointer(const UniquePointer<T>& p) = delete;//Disable copy constructor
	const UniquePointer<T>& operator = (const UniquePointer<T>& p) = delete;//disable = operator
	UniquePointer(UniquePointer<T> &&p)//Create move semantics for rvalue referance
	{
		_ptr = p._ptr;
		p._ptr = nullptr;
	}


	const T& operator *() const { return *_ptr; }
	T* operator -> () const { return _ptr; }

private:
	T * _ptr;
};

/*********************************************************************************/
/*****************************<SHARED POINTER>************************************/
template <class T>
class SharedPointer
{
public:
	SharedPointer(T* p) : _ptr(p), _counter(new int(1)) {}
	~SharedPointer()
	{
		deleteShared();
	}
	SharedPointer(const SharedPointer<T>& p)
	{
		_counter = nullptr;
		*this = p; //Call = operator
	}
	const SharedPointer<T>& operator = (const SharedPointer<T>& p)
	{
		deleteShared();
		_counter = p._counter;
		_ptr = p._ptr;
		++(*_counter);
		return *this;
	}
	
private:
	void deleteShared()
	{
		if (nullptr == _counter)
			return;

		--(*_counter);//Decrement the reference counter
		if (0 == *_counter)
			delete _ptr;
	}

	const T& operator *() const { return *_ptr; }
	T* operator -> () const { return _ptr; }

private:
	T * _ptr;
	int * _counter;
};
