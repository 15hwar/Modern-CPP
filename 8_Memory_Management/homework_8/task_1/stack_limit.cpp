#include <iostream>
#include <vector>

int main()
{
    double arr[81 * 102400 / 8];
    int j = 0;
    while(true) {
        for(int i = j * 102400 / 8; i < (j + 1) * 102400 / 8; ++i) {
            arr[i] = 1.;
        }
        j++;
        std::cerr << j * 102400 / 1024 << "[KiB] Allocated in the stack" << std::endl;
    }
    return 0;
}