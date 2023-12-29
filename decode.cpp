#include <iostream>
#include "huffman.hpp"
using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 3) {
        cout << "Failed to detect Files";
		exit(1);
	}

    huffman f1(argv[1], argv[3]);
    f1.decompress();
    huffman f2(argv[2], argv[4]);
    f2.decompress();
    cout << "Decompressed successfully" << endl;

    return 0;
}