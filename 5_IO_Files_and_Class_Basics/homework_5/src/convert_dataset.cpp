#include <homework_5.h>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/xfeatures2d.hpp>


void ipb::serialization::sifts::ConvertDataset(const std::filesystem::path &img_path)
{
    std::string bin_path = img_path.parent_path().parent_path().append("bin");
    if(!std::filesystem::exists(bin_path))
        std::filesystem::create_directory(bin_path);
        
    for(auto file : std::filesystem::directory_iterator(img_path)){
        if(file.path().extension() == ".png"){
            cv::Mat img_mat = cv::imread(file.path(), cv::IMREAD_GRAYSCALE);
            std::string img_stem = file.path().stem();
            ipb::serialization::Serialize(img_mat, bin_path + "/" + img_stem + ".bin");
        }
    }
}

cv::Mat GetSiftDescriptor(const cv::Mat& kInput) 
{
    // detect key points
    auto detector = cv::SiftFeatureDetector::create();
    std::vector<cv::KeyPoint> keypoints;
    detector->detect(kInput, keypoints);

    // present the keypoints on the image
    cv::Mat image_with_keypoints;
    drawKeypoints(kInput, keypoints, image_with_keypoints);

    // extract the SIFT descriptors
    cv::Mat descriptors;
    auto extractor = cv::SiftDescriptorExtractor::create();
    extractor->compute(kInput, keypoints, descriptors);

    return descriptors;
}

std::vector<cv::Mat> ipb::serialization::sifts::LoadDataset(const std::filesystem::path &bin_path)
{
    std::vector<cv::Mat> descriptors_list;
    for(auto& file : std::filesystem::directory_iterator(bin_path)) {
        if(file.path().extension() == ".bin"){
            cv::Mat img_mat = ipb::serialization::Deserialize(file.path());
            descriptors_list.emplace_back(GetSiftDescriptor(img_mat));
        }
    }
    return descriptors_list;
}
