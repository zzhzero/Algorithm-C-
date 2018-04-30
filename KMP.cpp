#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void PrintVectorInt(int i) {
    cout << i << " ";
}

bool KMP(string bigstr, string cstr) {
    int len_bigstr = bigstr.length();
    int len_cstr = cstr.length();
    if (len_bigstr < len_cstr)return false;
    if (len_cstr == 0)return true;
    int next[len_cstr];
    int j = 0;
    int i = 1;
    next[0] = 0;
    while (len_cstr > i) {
        if (cstr[j] == cstr[i]) {
            next[i++] = ++j;
        } else {
            if (j == 0) {
                next[i++] = 0;
            } else {
                j = next[j - 1];
            }
        }
    }
    i = 0, j = 0;
    for_each(next, next + len_cstr, PrintVectorInt);
    cout << endl;
    while (i < len_bigstr) {
        if (bigstr[i] == cstr[j]) {
            i++;
            j++;
        } else {
            if (j == 0) {
                i++;
            } else {
                j = next[j - 1];
            }
        }
        if (j == len_cstr)return true;
    }
    return false;
}

int main() {
    cout << KMP("abxabcabcaby", "abcaby");
    return 0;
}
