#include "bow_dictionary.hpp"

void ipb::BowDictionary::set_params(const int &iters, const int &size, const std::vector<cv::Mat> descriptors)
{
    max_iters = iters;
    bow_size = size;
    inp_descriptors = descriptors;
}

int ipb::BowDictionary::max_iterations() const
{
    return max_iters;
}

int ipb::BowDictionary::size() const
{
    return bow_size;
}

std::vector<cv::Mat> ipb::BowDictionary::descriptors() const
{
    return inp_descriptors;
}

cv::Mat ipb::BowDictionary::vocabulary() const
{
    return vocab;
}

int ipb::BowDictionary::total_features() const
{
    return bow_size;
}

int ipb::BowDictionary::empty() const
{
    return bow_size == 0;
}

void ipb::BowDictionary::set_max_iterations(const int &iters)
{
    max_iters = iters;
}

void ipb::BowDictionary::set_size(const int &size)
{
    bow_size = size;
    vocab.resize(bow_size);
}

void ipb::BowDictionary::set_descriptors(std::vector<cv::Mat> &descriptors)
{
    inp_descriptors = descriptors;
}