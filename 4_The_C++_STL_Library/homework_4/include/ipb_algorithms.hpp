#ifndef IPB_ALGORITHMS_HPP_
#define IPB_ALGORITHMS_HPP_

#include "named_vector.hpp"
#include <numeric>
#include <algorithm>

namespace ipb {

    void hello_you();

    template<typename T> int accumulate(const ipb::named_vector<T>& vec);

    template<typename T> int count(const ipb::named_vector<T>& vec, int num);

    template<typename T> bool all_even(const ipb::named_vector<T>& vec);

    template<typename T> void clamp(ipb::named_vector<T>& vec, int min_val, int max_val);

    template<typename T> void fill(ipb::named_vector<T>& vec, int num);

    template<typename T> bool find(const ipb::named_vector<T>& vec, int num);

    template<typename T> void print(const ipb::named_vector<T>& vec);

    template<typename T> int toupper(ipb::named_vector<T>& vec);

    template<typename T> void sort(ipb::named_vector<T>& vec);

    template<typename T> void rotate(ipb::named_vector<T>& vec, int rotate_by);

    template<typename T> void reverse(ipb::named_vector<T>& vec);

}

template<typename T> int ipb::accumulate(const ipb::named_vector<T>& vec) {
    std::vector<T> inp_vec = vec.vector();
    return std::accumulate(inp_vec.begin(), inp_vec.end());
}

template<typename T> int ipb::count(const ipb::named_vector<T>& vec, int num) {
    std::vector<T> inp_vec = vec.vector();
    return std::count(inp_vec.begin(), inp_vec.end(), num);
}

inline bool even(int i){
    return i % 2 == 0;
}

template<typename T> bool ipb::all_even(const ipb::named_vector<T>& vec) {
    std::vector<T> inp_vec = vec.vector();
    return std::all_of(inp_vec.begin(), inp_vec.end(), even);
}

#endif