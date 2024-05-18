#ifndef NAMED_VECTOR_HPP_
#define NAMED_VECTOR_HPP_

#include <initializer_list>
#include <string>
#include <vector>
namespace ipb {

template <typename T>
class named_vector {
private:
    std::string container_name;
    std::vector<T> elements;

public:
    named_vector() {
        this->container_name = "";
        this->elements = {};
    }

    named_vector<T>(std::string type_name, std::vector<T> elems) {
        this->container_name=type_name;
        this->elements=elems;
    }
    
    named_vector<T>& operator=(std::initializer_list<T> name_elems) {
        this->container_name = name_elems.first;
        this->elements = name_elems.second;
        return *this;
    }

    ~named_vector() {}

    std::string name();

    int size();

    int capacity();

    bool empty();

    void reserve(int to_reserve);

    void resize(int to_resize);

    std::vector<T> vector();

};

}


template<typename T> std::string ipb::named_vector<T>::name(){
    return this->container_name;
}

template<typename T> bool ipb::named_vector<T>::empty(){
    if(container_name.empty()) return true;
    return elements.empty();
}

template<typename T> int ipb::named_vector<T>::size(){
    return elements.size() + container_name.size();
}

template<typename T> int ipb::named_vector<T>::capacity(){
    return elements.capacity();
}

template<typename T> void ipb::named_vector<T>::reserve(int to_reserve){
    return elements.reserve(to_reserve);
}

template<typename T> void ipb::named_vector<T>::resize(int to_resize){
    return elements.resize(to_resize);
}

template<typename T> std::vector<T> ipb::named_vector<T>::vector(){
    return elements;
}



#endif