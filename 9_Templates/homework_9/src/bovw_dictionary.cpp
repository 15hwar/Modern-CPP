#include "bovw_dictionary.hpp"
#include "kmeans.hpp"

void ipb::BowDictionary::set_vocabulary(const cv::Mat &vocab_dict) {
    vocabulary_ = vocab_dict;
}

bool ipb::BowDictionary::empty() const {
    cv::Size s = vocabulary_.size();
    return s.height == 0;
}

void ipb::BowDictionary::build(const int &iters, const int &size, const std::vector<cv::Mat> &descriptors)
{
    vocabulary_ = ipb::kmeans(descriptors, iters, size);
}

cv::Mat ipb::BowDictionary::vocabulary() const {
    return vocabulary_;
}

int ipb::BowDictionary::size() const {
    cv::Size s = vocabulary_.size();
    return s.height;
}