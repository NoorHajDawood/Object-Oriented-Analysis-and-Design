#pragma once

/*********************************************************************************/
/*****************************<UNIQUE POINTER>************************************/
template <class T>
class UniquePointer
{
public:
	UniquePointer(T *p) : _ptr(p) {}
	~UniquePointer() { delete _ptr; }
	UniquePointer(const UniquePointer<T> &p) = delete;					   //Disable copy constructor
	const UniquePointer<T> &operator=(const UniquePointer<T> &p) = delete; //disable = operator
	UniquePointer(UniquePointer<T> &&p) : _ptr(std::move(p._ptr))		   //Create move semantics for rvalue referance
	{
		p._ptr = 0;
	}

	const T &operator*() const
	{
		if (nullptr != _ptr)
			return *_ptr;

		return NULL;
	}

	T *operator->() const
	{
		if (nullptr != _ptr)
			return _ptr;

		return NULL;
	}

	operator void *() const { return _ptr; }

private:
	T *_ptr;
};

/*********************************************************************************/
/*****************************<SHARED POINTER>************************************/
class Counter
{
public:
	Counter() : _useCount(0), _weakCount(0) {}
	Counter(int use, int weak) : _useCount(use), _weakCount(weak) {}

public:
	void incUse() { ++_useCount; }
	void incWeak() { ++_weakCount; }
	void decUse() { --_useCount; }
	void decWeak() { --_weakCount; }
	int getUse() const { return _useCount; }
	int getWeak() const { return _weakCount; }

private:
	int _useCount;
	int _weakCount;
};

template <class T>
class SharedPointer
{
public:
	SharedPointer(T *p) : _ptr(p), _counter(new Counter(p != 0, 0)) {}

	~SharedPointer()
	{
		decrementRef();
	}

	SharedPointer(const SharedPointer<T> &p) : _counter(0), _ptr(0)
	{
		*this = p; //Call = operator
	}

	const SharedPointer<T> &operator=(const SharedPointer<T> &p)
	{
		if (this != &p)
		{
			decrementRef();
			_ptr = p._ptr;
			_counter = p._counter;
			if (_ptr)
				_counter->incUse();
		}
		return *this;
	}

	T *get() { return _ptr; }
	const T &operator*() const { return *_ptr; }
	T *operator->() const { return _ptr; }
	int use_count() const { return _counter->getUse(); }

	template <class U>
	friend class WeakPointer;

	operator void *() const { return _ptr; }

private:
	void decrementRef()
	{
		if (_counter == nullptr)
			return;

		_counter->decUse(); //Decrement the reference counter

		if (_counter->getUse() == 0)
		{
			delete _ptr;
			if (_counter->getWeak() == 0)
				delete _counter;
		}
	}

private:
	T *_ptr;
	Counter *_counter;
};

/*********************************************************************************/
/******************************<WEAK POINTER>************************************/

template <class T>
class WeakPointer
{
public:
	WeakPointer() : _shared(nullptr), _counter(nullptr) {}

	WeakPointer(SharedPointer<T> &p) : _shared(&p), _counter(p._counter)
	{
		_counter->incWeak();
	}

	~WeakPointer()
	{
		decrementRef();
	}

	WeakPointer(const WeakPointer<T> &wp) : _counter(0), _shared(0)
	{
		*this = wp;
	}

	const WeakPointer<T> &operator=(const WeakPointer<T> &WeakPointer)
	{
		if (this != &WeakPointer)
		{
			decrementRef();
			_counter = WeakPointer._counter;
			_shared = WeakPointer._shared;
			_counter->incWeak();
		}
		return *this;
	}

	bool expired() const { return _counter->getUse() == 0; }

	T *operator->() const
	{
		if (expired())
			throw "Pointer is not longer valid.";
		return _shared->get();
	}

	const T &operator*() const
	{
		if (expired())
			throw "Pointer is not longer valid.";
		return *_shared->get();
	}

	int use_count() const { return _counter->getUse(); }

private:
	void decrementRef(void)
	{
		if (_counter == nullptr)
			return;

		_counter->decWeak();
		if (_counter->getWeak() == 0 && _counter->getUse() == 0)
			delete _counter;
	}

private:
	SharedPointer<T> *_shared;
	Counter *_counter;
};