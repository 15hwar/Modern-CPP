#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main(int argc, char* argv[]){
    if(argc != 3){
        cerr << "Mismatch in number of outputs";
        exit(EXIT_FAILURE);
    }
    stringstream file1(argv[1]);
    stringstream file2(argv[2]);
    int num1, num2;
    string str1, str2;
    file1 >> num1 >> str1;
    file2 >> num2 >> str2;
    string txt=".txt", png=".png";
    if (str1 == txt && str2 == txt) {
        cout << (num1 + num2)/2 << endl;
    } else if (str1 == png && str2 == png) {
        cout << num1 + num2 << endl;
    } else if (str1 == txt && str2 == png) {
        cout << num1 % num2 << endl;
    } else {
        cerr << "Pattern doesn't matches." << endl;
        exit(EXIT_FAILURE);
    }
    return EXIT_SUCCESS;
}