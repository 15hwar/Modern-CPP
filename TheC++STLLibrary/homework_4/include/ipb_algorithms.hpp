#ifndef IPB_ALGORITHMS_HPP_
#define IPB_ALGORITHMS_HPP_

#include "named_vector.hpp"

namespace ipb {

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

#endif