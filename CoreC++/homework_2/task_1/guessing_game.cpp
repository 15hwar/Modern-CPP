#include <iostream>
#include <random>

using namespace std;

int get_random_number(){
    random_device rnd;
    static uniform_int_distribution<int> dist(0,99);
    return dist(rnd);
}

int main(){
    int inp;
    int rand_num = get_random_number();
    try{
        cout << "Enter the number" << endl;
        cin >> inp;
        while(rand_num != inp){
            if(cin.fail()) throw invalid_argument("Invalid Input");
            if(inp < 0 || inp > 99){
                cerr << "[WARNING] : Number must be between 0 and 99" << endl;
            }
            else if(inp > rand_num){
                cout << "choose a smaller number" << endl;
            }
            else{
                cout << "choose a larger number" << endl;
            }
            cin >> inp;
        }
    }catch(exception &exp){
        cerr << "Error encountered, exiting..." << endl;
        cout << rand_num << endl;
        exit(EXIT_FAILURE);
    }
    cout << "You won the game" << endl;
    cout << rand_num << endl;
    return 0;
}