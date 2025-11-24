#include <iostream>
#include <fstream>

struct IntArray{
    void add(int i);
    int get(size_t id) const noexcept;
    size_t get_size() const noexcept;
    int last() const noexcept;
    IntArray(int i);
    ~IntArray();
    IntArray(const IntArray & rhs);
    IntArray & operator =(const IntArray & rhs);
    
    
    int *a;
    size_t k;
    
    IntArray::~IntArray(){
        delete[] a;
    }
    IntArray::IntArray(int i)
        a(new int [1]),
        k(1)
    {
        *a=i;
    }
    int IntArray::get(size_t id) const noexcept{
        return a[id];
    }
    size_t IntArray::size() const noexcept{
        return k;
    }
    int IntArray::last() const noexcept {
        return get(size()-1);
    }
    void IntArray::add(int i){
        int * tmp=new int[size() + 1];
        for (size_t i=0;i<size();++i){
            tmp[i]=get(i);
        }
        delete [] a;
        a=tmp;
        ++k;
    }
    
    IntArray:: IntArray ( const IntArray & rhs):
        data(new int[rhs.get_size()]),
        size(rhs.get_size())
    {
        for (size_t i=0;i<get_size(); ++i){
            data[i]=rhs.get(i);
        }
    }
    
    IntArray & IntArray::operator = ( const  IntArray & rhs){
        int * tmp = new int [rhs.get_size()];
        for (size_t i=0;i<get_size(); ++i){
            tmp[i]=rhs.get(i);
        }
        delete [] data;
        data=tmp;
        size=rhs.get_size();
        return *this;
    }
};

int main(){
    int next=0;
    std::cin>>next;
    
    try{
        IntArray a(next);
        while (std::cin>>next){
            a.add(next);
        }
        if (std::cin.fail() && std::cin.eof()){
            return 1;
        }
        
        
        size_t count=1;
        for(size_t i=0;i<a.size()-1;++i){
            int d=a.get(i);
            count+=!(d % a.last())? 1 : 0;
        }
    }
    catch(const std::bad_alloc){
        return 2;
    }
    std::cout<<count<<"\n";
}
