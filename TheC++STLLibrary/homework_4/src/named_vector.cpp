#include <homework_4.h>
#include "named_vector.hpp"

template<typename T> bool ipb::named_vector<T>::empty(){
    return ipb::named_vector::elements.empty();
}

template<typename T> int ipb::named_vector<T>::size(){
    return ipb::named_vector::elements.size();
}

template<typename T> int ipb::named_vector<T>::capacity(){
    return ipb::named_vector::elements.capacity();
}

template<typename T> void ipb::named_vector<T>::reserve(int to_reserve){
    return ipb::named_vector::elements.reserve(to_reserve);
}

template<typename T> void ipb::named_vector<T>::resize(int to_resize){
    return ipb::named_vector::elements.resize(to_resize);
}

