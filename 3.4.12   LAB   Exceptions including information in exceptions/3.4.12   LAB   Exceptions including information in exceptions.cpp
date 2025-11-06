#include <iostream>
using namespace std;

class IPHeader {
private:
    string sourceIP;
    string destIP;

    bool isValidIP(string ip) {
        int count = 0;
        int num = 0;

        for (int i = 0; i <= ip.length(); i++) {
            if (i == ip.length() || ip[i] == '.') {
                if (num > 255) {
                    return false;
                }
                count++;
                num = 0;
            }
            else if (ip[i] >= '0' && ip[i] <= '9') {
                num = num * 10 + (ip[i] - '0');
            }
            else {
                return false;
            }
        }

        return count == 4;
    }

    void checkIPs() {
        bool srcValid = isValidIP(sourceIP);
        bool dstValid = isValidIP(destIP);

        if (!srcValid && !dstValid) {
            throw "Invalid IP Header - Source IP Address and Destination IP Address are invalid.";
        }
        else if (!srcValid) {
            throw "Invalid IP Header - Source IP Address is invalid.";
        }
        else if (!dstValid) {
            throw "Invalid IP Header - Destination IP Address is invalid.";
        }
    }

public:
    IPHeader(string src, string dst) {
        sourceIP = src;
        destIP = dst;
        checkIPs();
    }

    void display() {
        cout << "Valid IP Header." << endl;
    }
};

int main() {
    string src, dst;


    while (cin >> src >> dst) {
        try {
            IPHeader header(src, dst);
            header.display();
        }
        catch (const char* e) {
            cout << e << endl;
        }
    }

    return 0;
}