#include <bits/stdc++.h>

using namespace std;

string simplifyPath(string path)
{
    // The path starts with a single slash '/'.
    // Any two directories are separated by a single slash '/'.
    // The path does not end with a trailing '/'.The path only contains the directories on the path from the root directory to the target file or directory(i.e., no period '.' or double period '..')

    string ans = "",
           str = "";
    vector<string> st;
    for (int i = 0; i < path.length(); i++)
    {
        if (path[i] == '/')
        {
            if (str == "" || str == ".")
            {
                str = "";
                continue;
            }
            else if (str == "..")
            {
                if (st.size())
                    st.pop_back();
            }
            else
                st.push_back(str);
            str = "";
        }
        else
            str += path[i];
    }
    if (str == "" || str == ".")
    {
        str = "";
    }
    else if (str == "..")
    {
        if (st.size())
            st.pop_back();
    }
    else
        st.push_back(str);
    for (int i = 0; i < st.size(); i++)
    {
        ans += '/';
        ans += st[i];
    }
    if (ans == "")
        ans += '/';
    return ans;
}

int main()
{

    // a period '.' refers to the current directory,
    // a double period '..' refers to the directory up a level,
    //  and any multiple consecutive slashes(i.e.'//') are treated as a single slash '/'.For this problem,
    // any other format of periods such as '...' are treated as file / directory names.
    string path = "/..hidden ";
    cout << path << " " << endl;
    cout << "simplified version : " << simplifyPath(path) << endl
         << endl;

    path = "/... ";
    cout << path << " " << endl;
    cout << "simplified version : " << simplifyPath(path) << endl
         << endl;

    path = "/ a // b////c/d//././/..";
    cout << path << " " << endl;
    cout << "simplified version : " << simplifyPath(path) << endl
         << endl;

    path = "/a/./b/../../c/";
    cout << path << " " << endl;
    cout << "simplified version : " << simplifyPath(path) << endl
         << endl;
    return 0;
}
