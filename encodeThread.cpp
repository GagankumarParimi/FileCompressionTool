#include <iostream>
#include "huffman.hpp"
#include <chrono>
#include <thread>

using namespace std;
using namespace std::chrono;



void compressFile(const char* inputFile, const char* outputFile) {
       huffman *f = new huffman(inputFile, outputFile);
       f->compress();

  
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        cout << "Enter the files in this format  <inputFile1> <inputFile2> <outputFile1> <outputFile2>" << endl;
        exit(1);
    }

    auto start = high_resolution_clock::now();

    // Launch two threads to compress files concurrently
    thread t1(compressFile, argv[1], argv[3]);
    thread t2(compressFile, argv[2], argv[4]);

    // Wait for both threads to finish
    t1.join();
    t2.join();

    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);

    cout << "Compressed successfully in " << duration.count() << " milliseconds" << endl;

    return 0;
}
