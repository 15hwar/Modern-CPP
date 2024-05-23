#ifndef KMEANS_HPP_
#define KMEANS_HPP_

#include <opencv2/core.hpp>
#include <map>

namespace ipb {

float euclideanDistance(const cv::Mat &a, const cv::Mat &b);

std::vector<cv::Mat> getInitialClusterCenters(const std::vector<cv::Mat> &descriptors, const int &k);

void assignToClusters(const std::vector<cv::Mat> &descriptors, const std::vector<cv::Mat> &centroids, std::map<int, std::vector<cv::Mat>> clusters);

std::vector<cv::Mat> recomputeCenters(int k, const std::map<int, std::vector<cv::Mat>> clusters, const std::vector<cv::Mat> &centroids, const std::vector<cv::Mat> &descriptors);

cv::Mat kmeans(const std::vector<cv::Mat> &descriptors, const int &max_iters, const int &k);

}

#endif