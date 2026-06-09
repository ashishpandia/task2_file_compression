#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string compress(string str) {
    string result = "";
    int count;

    for(int i = 0; i < str.length(); i++) {
        count = 1;

        while(i < str.length()-1 && str[i] == str[i+1]) {
            count++;
            i++;
        }

        result += str[i];
        result += to_string(count);
    }

    return result;
}

int main() {
    ifstream inFile("input.txt");
    string data, line;

    while(getline(inFile, line))
        data += line;

    inFile.close();

    string compressed = compress(data);

    ofstream outFile("compressed.txt");
    outFile << compressed;
    outFile.close();

    cout << "Compression Successful!\n";
    cout << "Compressed Data: " << compressed << endl;

    return 0;
}
