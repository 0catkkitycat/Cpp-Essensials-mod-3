#include <iostream>
using namespace std;

class IPNumber {
private:
    int octets[4];

    void parseIP(string ip_string) {
        int count = 0;
        int num = 0;

        for (int i = 0; i < ip_string.length(); i++) {
            if (ip_string[i] == '.') {
                if (num > 255) {
                    throw "Exception - invalid IP number.";
                }
                octets[count++] = num;
                num = 0;
            }
            else {
                num = num * 10 + (ip_string[i] - '0');
            }
        }

        if (num > 255) {
            throw "Exception - invalid IP number.";
        }
        octets[count++] = num;


        if (count != 4) {
            throw "Exception - invalid IP number.";
        }
    }

public:
    IPNumber(string ip_string) {
        parseIP(ip_string);
    }

    void print_subnet(int range_size) {

        if (range_size <= 0 || (range_size & (range_size - 1)) != 0) {
            throw "Exception - invalid range.";
        }


        long long ip_num = (long long)octets[0] * 256 * 256 * 256 +
            (long long)octets[1] * 256 * 256 +
            (long long)octets[2] * 256 +
            (long long)octets[3];


        for (int i = 1; i <= range_size; i++) {
            long long next_ip = ip_num + i;
            int o1 = (next_ip / (256 * 256 * 256)) % 256;
            int o2 = (next_ip / (256 * 256)) % 256;
            int o3 = (next_ip / 256) % 256;
            int o4 = next_ip % 256;
            cout << o1 << "." << o2 << "." << o3 << "." << o4 << endl;
        }
    }
};

int main() {
    try {
        IPNumber ip1("212.111.212.128");
        ip1.print_subnet(2);
    }
    catch (const char* e) {
        cout << e << endl;
    }
    cout << endl;

    try {
        IPNumber ip2("212.112.212.128");
        ip2.print_subnet(4);
    }
    catch (const char* e) {
        cout << e << endl;
    }
    cout << endl;

    try {
        IPNumber ip3("212.113.212.128");
        ip3.print_subnet(6);
    }
    catch (const char* e) {
        cout << e << endl;
    }
    cout << endl;

    try {
        IPNumber ip4("212.114.212.328");
        ip4.print_subnet(4);
    }
    catch (const char* e) {
        cout << e << endl;
    }

    return 0;
}