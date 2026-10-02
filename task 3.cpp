#include <iostream>
#include <string>

using namespace std;

bool isPalindromeHelper(const string& str, int start, int end) {
    if (start >= end) return true;
    if (str[start] != str[end]) return false;
    return isPalindromeHelper(str, start + 1, end - 1);
}

bool isPalindrome(const string& str) {
    if (str.empty()) return true;
    return isPalindromeHelper(str, 0, str.length() - 1);
}

int main() {
    string str1 = "racecar";
    string str2 = "hello";
    
    cout << "isPalindrome(\"" << str1 << "\"): " << (isPalindrome(str1) ? "true" : "false") << endl;
    cout << "isPalindrome(\"" << str2 << "\"): " << (isPalindrome(str2) ? "true" : "false") << endl;
    
    return 0;
}
