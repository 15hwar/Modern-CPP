#include <iostream>
#include "../include/html_writer.hpp"
#include "../include/image_browser.hpp"

using namespace std;
using image_browser::ImageRow;

void image_browser::AddFullRow(const ImageRow& row, bool first_row) {
    html_writer::OpenRow();
    for(int i=0;i<row.size();i++){
        html_writer::AddImage(get<0>(row[i]), get<1>(row[i]), first_row && (i==0));
    }
    html_writer::CloseRow();
}

void CreateImageBrowser(const std::string& title, const std::string& stylesheet, const std::vector<ImageRow>& rows) {
    html_writer::OpenDocument();
    html_writer::AddTitle(title);
    html_writer::AddCSSStyle(stylesheet);
    html_writer::OpenBody();
    for(int i=0;i<rows.size();i++){
        html_writer::OpenRow();
        image_browser::AddFullRow(rows[i],i==0);
        html_writer::CloseRow();
    }
    html_writer::CloseBody();
    html_writer::CloseDocument();
}