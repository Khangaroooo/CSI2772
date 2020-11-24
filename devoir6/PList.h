//Khang Nguyen 300007277
#ifndef PList_HPP
#define PList_HPP

#include <stdexcept>
#include <iostream>


template <class T>
class PList {
    
    int capacity;
    int size = 0;
    mutable int current = 0;
    T** tablePtr;
    
    T* get() const {
        return *(tablePtr + current);
    }
    
    T* start() const {
        current = 0;
        return *tablePtr;
    }
    
    void next() const {
        current++;
    }
    
    bool isLast() const {
        return current == size-1;
    }
    
    int getCurrent() const {
        return current;
    }
    
    public:
    
        PList(int _capacity){
            capacity = _capacity;
            tablePtr = new T * [capacity];
        }

    
        ~PList(){
            delete [] tablePtr;
        }
    
        void add(T* item){
            if(size >= capacity){
               throw std::out_of_range("already has 5 orgs");
            }else{
                tablePtr[size] = item;
                size++;
            }
        }
        
        bool remove(T* item){
            start();
            while(!isLast()){
                if(get() == item){
                    size--;
                    while(!isLast()){
                        T* temp = get();
                        next();
                        temp = get();
                    }
                    return true;
                }
                next();
            }
            return false;
        }
        
        T* getItem(int i) const {
            return tablePtr[i];
        }
        
        bool isFull() const {
            return (size == capacity);
        }
        
        int getSize() const {
            return size;
        }
        
        int getCapacity() const {
            return capacity;
        }
};


#endif 