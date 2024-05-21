#ifndef BOW_DICTIONARY_
#define BOW_DICTIONARY_

#include <opencv2/core.hpp>
#include <vector>

namespace ipb {

class BowDictionary {
private:
    int max_iters;
    int bow_size;
    std::vector<cv::Mat> inp_descriptors;
    cv::Mat vocab;
    BowDictionary() = default;
    ~BowDictionary() = default;
public: 
    BowDictionary(const BowDictionary&) = delete;
    void operator=(const BowDictionary&) = delete;
    static BowDictionary& GetInstance() {
        static BowDictionary bow_dict;
        return bow_dict;
    }

    void set_params(const int &iters, const int &size, const std::vector<cv::Mat> descriptors);

    int max_iterations() const;
    int size() const;
    std::vector<cv::Mat> descriptors() const;
    cv::Mat vocabulary() const;
    int total_features() const;
    int empty() const;

    void set_max_iterations(const int &iters);
    void set_size(const int &size);
    void set_descriptors(std::vector<cv::Mat> &descriptors);
};

}

#endif