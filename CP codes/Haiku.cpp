#include <iostream>
#include <string>
using namespace std;

int main() {
    string sentence;

    int haiku=0;
    for(int j=1;j<=3;j++)
    {
        int Vcount=0;
    getline(cin, sentence);
    for(int i=0;i<sentence.size();i++)
    {
        if(sentence[i]=='a'||sentence[i]=='e'||sentence[i]=='i'||sentence[i]=='o'||sentence[i]=='u')
        {
            Vcount++;
        }
    }
    if(Vcount==5 && j!=2)haiku++;
    else if(j==2 && Vcount==7)haiku++;
    }
    if(haiku==3)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
