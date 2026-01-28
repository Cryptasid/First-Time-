#include <iostream>
#include <string>
using namespace std;

int main() {
    string word;

    cin>>word;
    int upcount=0,lowcount=0;
    for(int i=word.size()-1;i>=0;i--)
    {
        if(word[i]>='A' && word[i]<='Z')
        {
            upcount++;
        }

        else if(word[i]>='a' && word[i]<='z')
        {
            lowcount++;
        }
    }
    for(int i=0;i<word.size();i++)
    {
        if(upcount>lowcount)
        {
            if(word[i]>='a' && word[i]<='z')word[i]=word[i]-32;
        }
        else if(word[i]>='A' && word[i]<='Z')word[i]=word[i]+32;
    }
    cout<<word<<endl;
    return 0;
}

