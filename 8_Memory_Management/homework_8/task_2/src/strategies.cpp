#include "strategies.hpp"
#include <fstream>
#include <png++/png.hpp>

igg::ImageData igg::PpmIoStrategy::Read(const std::string &file) const
{
    std::ifstream in_file(file, std::ios_base::in);

    std::string type;
    int row = 0;
    int col = 0;
    int max_val = 0;
    in_file >> type >> row >> col >> max_val;

    std::vector<std::vector<int>> f_data;
    f_data.reserve(row * col);
    int red, green, blue;
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            in_file >> red >> green >> blue;
            std::vector<int> pix{red, green, blue};
            f_data.emplace_back(pix);
        }
    }

    return {row, col, max_val, f_data};
}

bool igg::PpmIoStrategy::Write(const std::string &file, const igg::ImageData &img_data) const
{
    std::ofstream out_file(file, std::ios_base::out | std::ios_base::binary);
    if(!out_file) return false;

    out_file << "P3" << std::endl;
    out_file << img_data.rows << " " << img_data.cols << std::endl;
    out_file << img_data.max_val << std::endl;
    for(int i = 0; i < img_data.rows; i++) {
        for(int j = 0; j < img_data.cols; j++) {
            out_file << img_data.data[i * img_data.cols + j][0] << " ";
            out_file << img_data.data[i * img_data.cols + j][1] << " ";
            out_file << img_data.data[i * img_data.cols + j][2] << " ";
        }
        out_file << std::endl;
    }
    return true;
}

igg::ImageData igg::PngIoStrategy::Read(const std::string &file) const
{
    png::image<png::rgb_pixel> image(file, png::require_color_space<png::rgb_pixel>());
    igg::ImageData image_out;
    image_out.rows = image.get_height();
    image_out.cols = image.get_width();
    image_out.max_val = 255;
    for(png::uint_32 i = 0; i < image_out.rows; i++) {
        for(png::uint_32 j = 0; j < image_out.cols; j++){
            std::vector<int> pix{image[i][j].red, image[i][j].green, image[i][j].blue};
            image_out.data.emplace_back(pix);
        }
    }
    return image_out;
}

bool igg::PngIoStrategy::Write(const std::string &file, const igg::ImageData &img_data) const
{
    png::image<png::rgb_pixel> image(img_data.rows, img_data.cols);
    for(png::uint_32 i = 0; i < img_data.rows; i++) {
        for(png::uint_32 j = 0; j < img_data.cols; j++){
            std::vector<int> pix = img_data.data[i * img_data.cols + j];
            image[i][j] = png::rgb_pixel(pix[0], pix[1], pix[2]);
        }
    }
    image.write(file);
    return true;
}
