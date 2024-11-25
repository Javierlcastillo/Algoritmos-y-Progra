#include <iostream>
#include <string>

using namespace std;

const string CHARSET = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

void generatePasswords(const string& current, int length) {
    if (current.size() == length) {
        cout << current << endl;
        return;
    }

    for (char c : CHARSET) {
        generatePasswords(current + c, length);
    }
}

void generatePasswordsRange(int minLen, int maxLen) {
    for (int len = minLen; len <= maxLen; ++len) {
        generatePasswords("", len);
    }
}

int main() {
    int minLength = 6, maxLength = 9;

    generatePasswordsRange(minLength, maxLength);

    return 0;
}