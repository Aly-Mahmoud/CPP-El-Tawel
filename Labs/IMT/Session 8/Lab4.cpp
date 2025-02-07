#include <iostream>

template <typename T>
class PointerUtility 
{
private:
    T* ptr;
public:
    // Constructor taking a pointer to an object of type T
    PointerUtility(T* pointer) : ptr(pointer) {}

    // Function to get the value the pointer points at
    T getValue() const 
    {
        return *ptr;
    }

    // Function to check if the stored pointer is null
    bool isNull() const {
        return (ptr == nullptr);
    }

    // Overloading insertion operator for printing
    friend std::ostream& operator<<(std::ostream& os, const PointerUtility<T>& pu) {
        if (pu.isNull()) {
            os << "Null Pointer";
        } else {
            os << "Value: " << pu.getValue();
        }
        return os;
    }
};

// Specialization if T is a pointer type
template <typename T>
class PointerUtility<T*> 
{
private:
    T* ptr;
public:
    // Constructor taking a pointer to an object of type T
    PointerUtility(T* pointer) : ptr(pointer) {}

    // Function to get the value the pointer points at
    typename std::remove_pointer<T>::type getValue() const 
    {
        return *ptr;
    }

    // Function to check if the stored pointer is null
    bool isNull() const 
    {
        return (ptr == nullptr);
    }

    // Overloading insertion operator for printing
    friend std::ostream& operator<<(std::ostream& os, const PointerUtility<T*>& pu) 
    {
        if (pu.isNull()) 
        {
            os << "Null Pointer";
        } else 
        {
            os << "Value: " << pu.getValue();
        }
        return os;
    }
};

int main() 
{
    int x = 5;
    int* ptr = &x;

    // Using PointerUtility with int pointer
    PointerUtility<int*> intPointer(ptr);
    std::cout << "Int Pointer: " << intPointer << std::endl;

    // Using PointerUtility with int
    PointerUtility<int> intValue(&x);
    std::cout << "Int Value: " << intValue << std::endl;

    return 0;
}
