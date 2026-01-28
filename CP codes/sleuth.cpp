#include <iostream>
#include <string>
using namespace std;

int main() {
    string sentence;

    getline(cin, sentence);
    for(int i=sentence.size()-1;i>=0;i--)
    {
        if(sentence[i]>='A' && sentence[i]<='Z' || sentence[i]>='a' && sentence[i]<='z')
        {
            if(sentence[i]=='A' || sentence[i]=='E'||sentence[i]=='I'||sentence[i]=='O'||sentence[i]=='U'||sentence[i]=='a'||sentence[i]=='e'||sentence[i]=='i'||sentence[i]=='o'||sentence[i]=='u'|| sentence[i]=='Y' || sentence[i]=='y')
            {
                cout<<"YES"<<endl;
            }
            else cout<<"NO"<<endl;

            break;
        }
    }
    return 0;
}
