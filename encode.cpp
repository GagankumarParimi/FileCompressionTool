#include <iostream>
#include "huffman.hpp"
#include <chrono>
using namespace std;
using namespace std::chrono;

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        cout << "Failed to detect Files";
        exit(1);
    }
    auto start = high_resolution_clock::now();
    huffman f1(argv[1], argv[3]);
    f1.compress();
    huffman f2(argv[2], argv[4]);
    f2.compress();
    cout << "Compressed successfully in " ;
    auto end = high_resolution_clock::now();

    auto duration = duration_cast<milliseconds>(end - start);

    cout<<duration.count() << "milliseconds"<<endl;
    return 0;
}