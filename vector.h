// vector class template

#ifndef Vector_Vector_h
#define Vector_Vector_h


#include <iostream>
#include <new>       // Needed for bad_alloc exception
#include <cstdlib>   // Needed for the exit function
#include <stdexcept>
namespace CIST2362 {

    template<class T>
    class vector {
    private:
        T *arrayPointer;          // To point to the allocated array
        unsigned long arraySize;    // Number of elements in the array
        unsigned long arrayCapacity; // number of memory locations available to the vector

        // increase capacity
        void increaseCapacity(unsigned long);

    public:
        // Default constructor
        vector();

        // Constructor declaration
        vector(unsigned long);

        // Resize the vector - changes the size attribute
        void resize(unsigned long newSize);

        // Resizes the vector and initializes the unused locations - updates the size attribute
        void resize(unsigned long newSize, const T &val);

        // Copy constructor declaration
        vector(const vector &);

        // Destructor declaration
        ~vector();

        // Accessor to return the array size
        unsigned long size() const { return arraySize; }

        // Accessor to return the array capacity
        unsigned long capacity() const { return arrayCapacity; }

        // Accessor to test empty status
        bool empty() const;

        // Accessor to return a specific element
        T &at(unsigned long index);

        // Overloaded [] operator declaration
        T &operator[](const unsigned long & index);

        // back element of the vector
        T &back();

        // front element of the vector
        T &front();

        void push_back(T);      // New push_back member
        T pop_back();           // New pop_back member

        // insert element at position
        int insert(unsigned long, const T &);

        // erase a range of values
        void erase(unsigned long, unsigned long);

        // erase one element at a position
        void erase(unsigned long);
    };

/* This is where your method definitions will be written. This default constructor
 * the first method you need to complete. To compile the program, you should create
 * empty stubs for each of the declared methods.
 */

    template<class T>
    inline void vector<T>::increaseCapacity(unsigned long value) {
        if (value <= arrayCapacity) return;
        T *tempPointer = new T[value];
        if (!tempPointer) throw std::bad_alloc();
        for (unsigned long i = 0; i < arraySize; ++i) {
            tempPointer[i] = arrayPointer[i];
        }
        delete[] arrayPointer;
        arrayPointer = tempPointer;
        arrayCapacity = value;
       
    }

    template<class T>
    vector<T>::vector() {
        try {
            arrayCapacity = 10;
            arraySize = 0;
            arrayPointer = new T[arrayCapacity];
        }
        catch (std::bad_alloc&) {
            std::cout << "ERROR: Cannot Allocate memory";
            exit(EXIT_FAILURE);
        }
    }
    template<class T>
    vector<T>::vector(unsigned long newCap){
        try{
        arrayCapacity = newCap;
        arraySize = newCap;
        arrayPointer = new T[arrayCapacity];
        }
        catch (std::bad_alloc&) {
            std::cout << "ERROR: Cannot Allocate memory\n";
            exit(EXIT_FAILURE);
        }
    }

    template<class T>
    void vector<T>::resize(unsigned long newSize){
        
        if (newSize > arraySize) {
            if (newSize >= arrayCapacity) {
                increaseCapacity(newSize);
            }
            
            T* tempPointer = new T[arrayCapacity];
            for (unsigned int i = 0; i < newSize; ++i) {
                tempPointer[i] = arrayPointer[i];
            }
            delete[] arrayPointer;
            arrayPointer = new T[arrayCapacity];
            for (unsigned int i = 0; i < arrayCapacity; ++i) {
                if (i < arraySize) {
                    arrayPointer[i] = tempPointer[i];
                }
                else {
                    arrayPointer[i] = 0;
                }
            }
            delete[] tempPointer;
        }
        else {
            T* tempPointer = new T[arrayCapacity];
            for (unsigned int i = 0; i < newSize; ++i) {
                tempPointer[i] = arrayPointer[i];
            }
            delete[] arrayPointer;
            arrayPointer = new T[arrayCapacity];
            for (unsigned int i = 0; i < newSize; ++i) {
                arrayPointer[i] = tempPointer[i];
            }
            delete[] tempPointer;

        }
        
        arraySize = newSize;
    }

    template<class T>
    void vector<T>::resize(unsigned long newSize, const T& value)
    {
        if (newSize > arraySize) {

            if (newSize >= arrayCapacity) {
                increaseCapacity(newSize);
            }
            
            T* tempPointer = new T[arrayCapacity];
            for (unsigned int i = 0; i < newSize; ++i) {
                tempPointer[i] = arrayPointer[i];
            }
            delete[] arrayPointer;
            arrayPointer = new T[arrayCapacity];
            for (unsigned int i = 0; i < arrayCapacity; ++i) {
                if (i < arraySize) {
                    arrayPointer[i] = tempPointer[i];
                }
                else {
                    arrayPointer[i] = value;
                }
            }
            delete[] tempPointer;
        }
        else {
            T* tempPointer = new T[arrayCapacity];
            for (unsigned int i = 0; i < newSize; ++i) {
                tempPointer[i] = arrayPointer[i];
            }
            delete[] arrayPointer;
            arrayPointer = new T[arrayCapacity];
            for (unsigned int i = 0; i < newSize; ++i) {
                arrayPointer[i] = tempPointer[i];
            }
            delete[] tempPointer;

        }
        
        arraySize = newSize;
    }

    template<class T>
    vector<T>::vector(const vector& origObject)
    {

        arrayPointer = new int[origObject.arrayCapacity];
        arrayCapacity = origObject.arrayCapacity;
        arraySize = origObject.arraySize;
        
        if (!empty()) {
            for (int i = 0; i < arrayCapacity; ++i) {
                arrayPointer[i] = origObject.arrayPointer[i];
            }
        }
    }

    template<class T>
    inline vector<T>::~vector()
    {
        delete[] arrayPointer;
    }
 

    template<class T>
    inline bool vector<T>::empty() const
    {
        if (arraySize <= 0) {
            return true;
        }
        return false;
    }

    template<class T>
    inline T& vector<T>::at(unsigned long index)
    {
        if (index >= arraySize) {
            throw std::out_of_range("");
            exit(EXIT_FAILURE);
            
        }
        return arrayPointer[index];
            
    
    }

    template<class T>
    inline T& vector<T>::operator[](const unsigned long& index)
    {
        // TODO: insert return statement here
        return arrayPointer[index];
    }

    template<class T>
    inline T& vector<T>::back()
    {
            if (arraySize == 0) {
                throw std::out_of_range ("ERROR: Empty Vector\n");
            }
            return arrayPointer[arraySize - 1];
        
        
        
    }

    template<class T>
    inline T& vector<T>::front()
    {
            if (arraySize == 0) {
                throw std::out_of_range("ERROR: Empty Vector\n");
            }
            return arrayPointer[0];

    }

    template<class T>
    inline void vector<T>::push_back(T value)
    {
        if (empty()) {
            arrayPointer[0] = value;
            ++arraySize;
        }
        else {

            if (arraySize == arrayCapacity) {
                increaseCapacity(arrayCapacity*=1.5);
            }
            T* tempPointer = new T [arrayCapacity];
            for (unsigned int i = 0; i < arraySize; ++i) {
                tempPointer[i] = arrayPointer[i];
            }
            delete[] arrayPointer;
            arrayPointer = new T [arrayCapacity];

            ++arraySize;
            for (unsigned int i = 0; i < arraySize; ++i) {
                arrayPointer[i] = tempPointer[i];
            }
            delete[] tempPointer;
            arrayPointer[arraySize - 1] = value;
            

        }


    }

    template<class T>
    inline T vector<T>::pop_back(){
        T returnedVal;

        returnedVal = arrayPointer[arraySize - 1]; 
        T* tempPointer = new T[arrayCapacity];
        for (unsigned int i = 0; i < arrayCapacity; ++i) {
            tempPointer[i] = arrayPointer[i];
        }
        delete[] arrayPointer;
        arrayPointer = new T[arrayCapacity];
         
        --arraySize;
        for (unsigned int i = 0; i < arrayCapacity; ++i) {
            arrayPointer[i] = tempPointer[i];
        }
        delete[] tempPointer;

        return returnedVal; 
    }

    template<class T>
    inline int vector<T>::insert(unsigned long index, const T& value)
    {
        ++arraySize;
        if (arraySize == arrayCapacity){
            ++arrayCapacity;
        }
        
        T* tempPointer = new T[arrayCapacity];
        for (unsigned int i = 0; i < arrayCapacity; ++i) {
            if (i < index) {
                tempPointer[i] = arrayPointer[i];

            }
            else if (i == index) {
                tempPointer[i] = value;
            }
            else {
                tempPointer[i] = arrayPointer[i - 1];

            }
        }
        delete[] arrayPointer;
        arrayPointer = new T[arrayCapacity];
        for (unsigned int i = 0; i < arrayCapacity; ++i) {
            arrayPointer[i] = tempPointer[i];
        }
        delete[] tempPointer;



        return index;
    }
    

    template<class T>
    inline void vector<T>::erase(unsigned long eraseBegin, unsigned long eraseEnd){
  
        int count = 0;
        T* tempPointer = new T[arrayCapacity];
        for (unsigned int i = 0; i < arrayCapacity; ++i) {
            if (i < eraseBegin || i >= eraseEnd) {
                tempPointer[i] = arrayPointer[i];
                
            }
            else {
                ++count;
            }
        }
        delete[] arrayPointer;
        for (unsigned int i = 0; i < arrayCapacity; ++i) {
            if (i >= eraseBegin) {
                tempPointer[i] = tempPointer[i + count];
            }
        }
        arraySize -=count;
        arrayPointer = new T[arrayCapacity];
        for (unsigned int i = 0; i < arrayCapacity; ++i) {
            arrayPointer[i] = tempPointer[i];
        }
        delete[] tempPointer;


    }

    template<class T>
    inline void vector<T>::erase(unsigned long eraseIndex)
    {
        T* tempPointer = new T[arrayCapacity];
        for (unsigned int i = 0; i < arrayCapacity; ++i) {
            if (i != eraseIndex) {
                tempPointer[i] = arrayPointer[i];
            }
        }
        delete[] arrayPointer;
        for (unsigned int i = 0; i < arrayCapacity; ++i) {
            if (i > eraseIndex) {
                tempPointer[i - 1] = tempPointer[i]; 
            }
        }
        --arraySize;       
        arrayPointer = new T[arrayCapacity];
        for (unsigned int i = 0; i < arrayCapacity; ++i) {
            arrayPointer[i] = tempPointer[i];
        }
        delete[] tempPointer;
    }
       
}
#endif
