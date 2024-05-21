#ifndef KMEANS_HPP_
#define KMEANS_HPP_

#include <map>
#include <opencv2/core.hpp>

namespace ipb {

cv::Mat kMeans(const std::vector<cv::Mat> &descriptors, int k, int max_iter);

std::vector<cv::Mat> getInitialCentroids(const std::vector<cv::Mat> &descriptors,
                                         int k);

void assignToClusters(const std::vector<cv::Mat> &descriptors,
                      const std::vector<cv::Mat> &centroids,
                      std::map<int, std::vector<cv::Mat>> &clusters);

float euclideanDistance(const cv::Mat &a, const cv::Mat &b);

std::vector<cv::Mat>
recomputeCenters(const std::map<int, std::vector<cv::Mat>> &clusters,
                 const std::vector<cv::Mat> &centroids,
                 const std::vector<cv::Mat> &descriptors, int k);

} // namespace ipb

#endif