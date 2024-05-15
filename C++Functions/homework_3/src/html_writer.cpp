#include <iostream>
#include <iomanip>

#include "../include/html_writer.hpp"
#include "../include/image_browser.hpp"

using namespace std;

void html_writer::OpenDocument() {
    cout << "<!DOCTYPE html>" << endl;
    cout << "<html>" << endl;
}

void html_writer::CloseDocument() {
    cout << "</html>" << endl;
}

void html_writer::AddCSSStyle(const std::string& stylesheet) {
    cout << "<head>" << endl;
    cout << "<link rel=\"stylesheet\" type=\"text/css\" href=\"" + stylesheet + "\" />" << endl;
    cout << "</head>" << endl;
}

void html_writer::AddTitle(const std::string& title) {
    cout << "<title>" + title + "</title>" << endl;
}

void html_writer::OpenBody() {
    cout << "<body>" << endl;
}

void html_writer::CloseBody() {
    cout << "</body>" << endl;
}
void html_writer::OpenRow() {
    cout << "<div class=\"row\">" << endl;
}

void html_writer::CloseRow() {
    cout << "</div>" << endl;
}

void html_writer::AddImage(const std::string& img_path, float score, bool highlight) {
    if(highlight)
        cout << "<div class=\"column\" style=\"border: 5px solid green;\">" << endl;
    else
        cout << "<div class=\"column\">" << endl;
    cout << "<h2>" + img_path.substr(img_path.find_last_of('/')) + "</h2>" << endl;
    cout << "<img src=\"" + img_path + "\" />" << endl;
    cout << "<p>score = " << setprecision(2) << std::fixed << score << "</p>" << endl;
    cout << "</div" << endl;
}