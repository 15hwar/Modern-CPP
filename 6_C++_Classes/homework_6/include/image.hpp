#include <vector>
#include <string>

namespace igg {

class Image {
    int row_ = 0;
    int col_ = 0;
    std::vector<int> data_;

public:

    Image() = default;

    Image(int& row, int& col) {
        row_ = row;
        col_ = col;
        data_.resize(row * col, 0);
    }
    
    Image(Image &&var) = default;
    Image(const Image &var) = default;
    Image& operator=(Image&& var) = default;
    Image& operator=(Image& var) = default;

    int rows() const;

    int cols() const;

    const int& at(const int& row, const int& col) const;

    int& at(const int& row, const int& col);

    bool FillFromPgm(const std::string& file_name);

    void WriteToPgm(const std::string& file_name);

    std::vector<float> ComputeHistogram(int bins) const;

    void DownScale(int scale);
    
    void UpScale(int scale);

};

}