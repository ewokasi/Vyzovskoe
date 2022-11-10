
#include <iostream>
#include <string>

int main()
{
    unsigned short x;
    std::cout << "enter x\n";
    std::cin >> std::hex >> x;
    short b, d, f, s;
    s = (x >> 13) & 0x7;
    d = (x >> 11) & 0x1;
    f = (x >> 9) & 0x1;
    b = (x >> 0) & 0xff;
    std::cout << std::dec << "\ns: " << s << "\nd: " << d << "\nf: " << f << "\nb: " << b << std::endl;
}
