#include <homework_7.h>
#include <map>
#include <opencv2/core/base.hpp>
#include <random>

std::vector<cv::Mat> ipb::getInitialCentroids(const std::vector<cv::Mat> &descriptors,
                                              int k) {
  std::vector<cv::Mat> centroids;
  centroids.reserve(k);
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<int> distribution(0, descriptors.size() - 1);

  for (int i = 0; i < k; i++) {
    int index = distribution(gen);
    centroids.emplace_back(descriptors[index].clone());
  }

  return centroids;
}

void ipb::assignToClusters(const std::vector<cv::Mat> &descriptors,
                           const std::vector<cv::Mat> &centroids,
                           std::map<int, std::vector<cv::Mat>> &clusters) {
  for (const auto &descriptor : descriptors) {
    float distance_min = std::numeric_limits<float>::max();
    int centroid_id = -1;
    for (int j = 0; j < centroids.size(); j++) {
      auto centroid = centroids[j];
      float current_distance = ipb::euclideanDistance(descriptor, centroid);
      if (current_distance < distance_min) {
        distance_min = current_distance;
        centroid_id = j;
      }
    }
    clusters[centroid_id].emplace_back(descriptor);
  }
}

float ipb::euclideanDistance(const cv::Mat &a, const cv::Mat &b) {
  return cv::norm(a, b, cv::NORM_L2);
}

std::vector<cv::Mat>
ipb::recomputeCenters(const std::map<int, std::vector<cv::Mat>> &clusters,
                      const std::vector<cv::Mat> &centroids,
                      const std::vector<cv::Mat> &descriptors, int k) {
  std::vector<cv::Mat> centroids_ = ipb::getInitialCentroids(descriptors, k);
  for (const auto &[clusterId, cluster] : clusters) {
    cv::Mat centroid = cv::Mat::zeros(descriptors[0].rows, descriptors[0].cols,
                                      descriptors[0].type());
    for (const auto &dataPoint : cluster)
      centroid += dataPoint;

    centroid /= static_cast<float>(cluster.size());
    centroids_[clusterId] = centroid;
  }

  return centroids_;
}

cv::Mat ipb::kMeans(const std::vector<cv::Mat>& descriptors, int k,
                    int max_iter) {
  std::vector<cv::Mat> descriptors_d;
  for (const auto &descriptor : descriptors) {
    cv::Mat desc;
    descriptor.convertTo(desc, CV_32FC1);
    descriptors_d.emplace_back(desc);
  }
  std::vector<cv::Mat> centroids;
  const auto centroids_init = ipb::getInitialCentroids(descriptors_d, k);
  centroids = centroids_init;

  for (int i = 0; i < max_iter; i++) {
    std::map<int, std::vector<cv::Mat>> clusters;
    assignToClusters(descriptors_d, centroids, clusters);
    centroids = std::move(recomputeCenters(clusters, centroids, descriptors_d, k));
  }

  cv::Mat out;
  for (const auto &centroid : centroids) {
    out.push_back(centroid);
  }
  return out;
}