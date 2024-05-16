#ifndef NAMED_VECTOR_HPP_
#define NAMED_VECTOR_HPP_

#include <initializer_list>

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

    int size();

    int capacity();

    bool empty();

    void reserve(int to_reserve);

    void resize(int to_resize);

};

}

#endif