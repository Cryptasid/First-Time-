#include<iostream>
#include<string>
using namespace std;
int main()
{
    string word;
    cin>>word;
    string revers;
    cin>>revers;

    int n = word.length();
    for (int i = 0; i < n / 2; i++) {
        char temp=word[i];
        word[i]=word[n - i - 1];
        word[n - i - 1]= temp;
    }

    if(word==revers)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
