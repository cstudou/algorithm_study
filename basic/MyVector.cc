 ///
 /// @file    MyVector.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-08-10 09:56:47
 ///
 
#include <iostream>
#include <memory>
#include <algorithm>
using std::cout;
using std::endl;


template <typename T>
class Vector
{
public:
	Vector()
	: _start(NULL)
	, _finish(NULL)
	, _end_of_storage(NULL)
	{}

	~Vector()
	{
		if(_start) {
			while(_start != _finish) {
				_alloc.destroy(--_finish);
			}

			_alloc.deallocate(_start, capacity());
		}
	}

	void push_back(const T & value);

	void pop_back();

	T * begin() {	return _start;	}
	T * end() {	return _finish;	}

	T & operator[](size_t idx) {	return _start[idx];	}

	size_t size() const {	return _finish - _start;	}
	size_t capacity() const {	return _end_of_storage - _start;	}

private:
	void reallocate();

private:
	//static std::allocator<T> _alloc;
	std::allocator<T> _alloc;

	T * _start;
	T * _finish;
	T * _end_of_storage;
};

//template <typename T>
//std::allocator<T> Vector<T>::_alloc;

template <typename T>
void Vector<T>::push_back(const T & value)
{
	if(size() == capacity()) {
		reallocate();//重新申请空间
	}	

	_alloc.construct(_finish++, value);
}

template <typename T>
void Vector<T>::reallocate()
{
	int oldCapacity = capacity();
	int newCapacity = oldCapacity > 0 ? 2 * oldCapacity : 1;

	T * ptmp = _alloc.allocate(newCapacity);//没有元素 --> 未类型化
    //如果目标空间未初始化用uninitialized_copy,其调用的是拷贝构造函数
    //std::copy(_start, _finish, ptmp);//不合理，调用相应类型的赋值运算符
	if(_start) {
		std::uninitialized_copy(_start, _finish, ptmp);//拷贝原来空间的数据
		//析构原来空间的对象
		while(_start != _finish) {
			_alloc.destroy(--_finish);
		}
		//回收原来的空间
		_alloc.deallocate(_start, oldCapacity);
	}

	_start = ptmp;
	_finish = _start + oldCapacity;
	_end_of_storage = _start + newCapacity;
}

template <typename T>
void Vector<T>::pop_back()
{
	if(size() > 0) {
		_alloc.destroy(--_finish);
	}
}

template <typename Container>
void display(Container & vec)
{
	cout << "vec's size = " << vec.size() << endl;
	cout << "vec's capacity = " << vec.capacity() << endl;
}
 
int test0(void)
{
	Vector<int> numbers;
	display(numbers);

	numbers.push_back(1);
	display(numbers);

	numbers.push_back(2);
	display(numbers);

	numbers.push_back(3);
	display(numbers);
	numbers.push_back(4);
	display(numbers);
	numbers.push_back(5);
	display(numbers);

	for(auto & elem : numbers)
	{
		cout << elem << " ";
	}
	cout << endl;

	for(auto it = numbers.begin(); it != numbers.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	for(size_t idx = 0; idx != numbers.size(); ++idx)
	{
		cout << numbers[idx] << " ";
	}
	cout << endl;
	return 0;
}

class Point
{
public:
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{	cout << "Point(int,int)" << endl; }
	
	Point(const Point & rhs)
	: _ix(rhs._ix)
	, _iy(rhs._iy)
	{
		cout << "Point(const Point &)" << endl;
	}

	~Point()
	{	cout << "~Point()" << endl;	}

	friend std::ostream & operator<<(std::ostream & os, const Point & );
private:
	int _ix;
	int _iy;
};

std::ostream & operator<<(std::ostream & os, const Point & rhs)
{
	os << "(" << rhs._ix
	   << "," << rhs._iy
	   << ")";
	return os;
}
int test1(void)
{
	Vector<Point> numbers;
	display(numbers);

	numbers.push_back(Point(1, 2));
	display(numbers);

	numbers.push_back(Point(3, 4));
	display(numbers);

	numbers.push_back(Point(5, 6));
	display(numbers);
	numbers.push_back(Point(7, 8));
	display(numbers);
	numbers.push_back(Point(9, 10));
	display(numbers);

	for(auto & elem : numbers)
	{
		cout << elem << " ";
	}
	cout << endl;

	for(auto it = numbers.begin(); it != numbers.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;

	for(size_t idx = 0; idx != numbers.size(); ++idx)
	{
		cout << numbers[idx] << " ";
	}
	cout << endl;
	return 0;
}

int main(void)
{
	test1();
	return 0;
}
