#define MemSize 100

template <class TypeVal>
class Stack
{
private: TypeVal* pMem;
	   int size;   
	   int top;    
public:
	Stack(const int n = MemSize);             
	~Stack();								

	bool empty();           
	bool full();            
	void push(TypeVal Elem);
	TypeVal pop();
	TypeVal watch_top_stek();

	int GetSize() const { return size; }   
};

template <class TypeVal>
Stack<TypeVal>::Stack(const int n)
{
	if ((n < 0) || (n > MemSize)) throw 'Neg';
	pMem = new TypeVal[n];
	size = n;
	top = -1;
}

template <class TypeVal>
Stack<TypeVal>::~Stack()
{
	delete[]pMem;
}

template <class TypeVal>
bool Stack<TypeVal>::empty()
{
	if (top == -1)
		return true;
	else
		return false;
}

template <class TypeVal>
bool Stack<TypeVal>::full()
{
	if (top == (size - 1))
		return true;
	else
		return false;
}

template<class TypeVal>
void Stack<TypeVal>::push(TypeVal elem)
{
	if (IsFull() == true) throw 'Full';
	else
		pMem[++top] = elem;
}

template <class TypeVal>
TypeVal Stack<TypeVal>::pop()
{
	if (IsEmpty()) throw 'Emp';
	else
		return pMem[top--];
}

template <class TypeVal>
TypeVal Stack<TypeVal>::watchtop()
{
	return pMem[top];
}