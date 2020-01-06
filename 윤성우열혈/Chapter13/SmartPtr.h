template<typename T>
class SmartPtr
{
private:
	T *ptr;
public:
	SmartPtr(T *_ptr):ptr(_ptr) {}
	T& operator*() const { return *ptr;}
	T* operator->() const {return ptr; }
	~SmartPtr() { delete ptr; }
};
