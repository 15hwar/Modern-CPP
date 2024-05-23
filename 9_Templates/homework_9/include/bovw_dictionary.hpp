#ifndef BOVW_DICTIONARY_HPP_
#define BOVW_DICTIONARY_HPP_

#include <opencv2/core.hpp>

namespace ipb {

class BowDictionary {
private:
    cv::Mat vocabulary_;
    BowDictionary() = default;
    ~BowDictionary() = default;

public:
    BowDictionary(BowDictionary&) = delete;
    void operator=(BowDictionary&) = delete;
    static BowDictionary& GetInstance() {
        static BowDictionary bow_dict;
        return bow_dict;
    }
    void set_vocabulary(const cv::Mat &vocab_dict);
    int size() const;
    bool empty() const;
    void build(const int &iters, const int &size, const std::vector<cv::Mat> &descriptors);
    cv::Mat vocabulary() const;
};

}

#endif