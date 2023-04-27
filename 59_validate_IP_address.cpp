#include <bits/stdc++.h>

using namespace std;
class IP
{
public:
    int isValid(string s)
    {
        int c = 0;
        string s1 = "", s2 = "", s3 = "", s4 = "";
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '.')
            {
                c++;
            }
            if (c == 0 && s[i] != '.')
            {
                s1 += s[i];
            }
            else if (c == 1 && s[i] != '.')
            {
                s2 += s[i];
            }
            else if (c == 2 && s[i] != '.')
            {
                s3 += s[i];
            }
            else if (c == 3 && s[i] != '.')
            {
                s4 += s[i];
            }
        }

        if (c < 3 || c > 3)
            return 0;

        if (s1.length() < 1 || s2.length() < 1 || s3.length() < 1 || s4.length() < 1)
            return 0;

        if ((s1[0] == '0' && s1.length() > 1) || (s2[0] == '0' && s2.length() != 1) || (s3[0] == '0' && s3.length() != 1) || (s4[0] == '0' && s4.length() != 1))
            return 0;

        // cout<<s1<<endl<<s2<<endl<<s3<<endl<<s4<<endl;
        for (int i = 0; i < s1.length(); i++)
        {
            if (s1[i] > 57)
                return 0;
        }
        for (int i = 0; i < s2.length(); i++)
        {
            if (s2[i] > 57)
                return 0;
        }
        for (int i = 0; i < s3.length(); i++)
        {
            if (s3[i] > 57)
                return 0;
        }
        for (int i = 0; i < s4.length(); i++)
        {
            if (s4[i] > 57)
                return 0;
        }
        int x1 = 0, x2 = 0, x3 = 0, x4 = 0;
        x1 = stoi(s1);
        x2 = stoi(s2);
        x3 = stoi(s3);
        x4 = stoi(s4);
        if (x1 <= 255 && x2 <= 255 && x3 <= 255 && x4 <= 255)
            return 1;
        return 0;
    }
};

int main()
{
    // A valid IPv4 Address is of the form x1.x2.x3.x4 where 0 <= (x1, x2, x3, x4) <= 255.
    // any additional leading zeroes will be considered invalid.
    string ip = "222.111.111.111";
    IP iP;
    if (iP.isValid(ip))
        cout << "Valid\n";
    else
        cout << "Not Valid\n";
    ip = "5555..555";
    if (iP.isValid(ip))
        cout << "Valid\n";
    else
        cout << "Not Valid\n";
    return 0;
}