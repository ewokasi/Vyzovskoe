

#include <iostream>
#include <string>
using namespace std;

string muta(string s, int len) {

    string res="_";
    for (int i = 0; i < len/2; i++) {
        res = res + '_';
    }
    res = res + s;

    for (int i = 0; i < len / 2+1; i++) {
        res = res + '_';
    }

    return res;
}

int main()
{
    string s;
    int len;
    cin >> s;
    cout << "You've entered: " << s << endl;
    cout << "Enter len\n";
    cin >> len;
    cout<<muta(s, len);

}
