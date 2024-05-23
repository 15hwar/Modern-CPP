#include "../include/kmeans.hpp"
#include <random>
#include "kmeans.hpp"

float ipb::euclideanDistance(const cv::Mat &a, const cv::Mat &b) {
    return cv::norm(a , b, cv::NORM_L2);
}

std::vector<cv::Mat> ipb::getInitialClusterCenters(const std::vector<cv::Mat> &descriptors, const int &k) {
    std::vector<cv::Mat> centroids;
    centroids.reserve(k);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(0, descriptors.size() - 1);

    for(int i = 0; i < k; i++){
        int index = distribution(gen);
        centroids.emplace_back(descriptors[index].clone());
    }

    return centroids;
}

void ipb::assignToClusters(const std::vector<cv::Mat> &descriptors, const std::vector<cv::Mat> &centroids, std::map<int, std::vector<cv::Mat>> clusters)
{
    for(const auto &descriptor : descriptors) {
        float min_distance = std::numeric_limits<float>::max();
        int centroid_id = -1;
        for(int i = 0; i < centroids.size(); i++){
            float dist_from_centroid = euclideanDistance(centroids[i], descriptor);
            if(dist_from_centroid < min_distance) {
                centroid_id = i;
                min_distance = dist_from_centroid;
            }
        }
        clusters[centroid_id].emplace_back(descriptor);
    }
}
std::vector<cv::Mat> ipb::recomputeCenters(int k, const std::map<int, std::vector<cv::Mat>> clusters, const std::vector<cv::Mat> &centroids, const std::vector<cv::Mat> &descriptors)
{
    std::vector<cv::Mat> centroids_ = ipb::getInitialClusterCenters(descriptors, k);
    for(const auto& clusterPair : clusters){
        cv::Mat centroid = cv::Mat::zeros(descriptors[0].rows, descriptors[0].cols, descriptors[0].type());

        for(const auto &dataPoint : clusterPair.second)
            centroid += dataPoint;
        
        centroids_[clusterPair.first] = centroid / static_cast<float>(clusterPair.second.size());
    }

    return centroids_;
}

cv::Mat ipb::kmeans(const std::vector<cv::Mat> &descriptors, const int &max_iters, const int &k)
{
    std::vector<cv::Mat> desciptors_d;
    for(const auto &descriptor : descriptors) {
        cv::Mat desc;
        descriptor.convertTo(desc, CV_32FC1);
        desciptors_d.emplace_back(desc);
    }
    std::vector<cv::Mat> centroids = ipb::getInitialClusterCenters(desciptors_d, k);
    std::map<int, std::vector<cv::Mat>> clusters;
    for(int i = 0; i < max_iters; i++) {
        ipb::assignToClusters(desciptors_d, centroids, clusters);
        centroids = ipb::recomputeCenters(k, clusters, centroids, desciptors_d);
    }

    cv::Mat out;
    for(const auto &centroid : centroids)
        out.push_back(centroid);
    return out;
}
