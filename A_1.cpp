#include<iostream>
#include<vector>
#include<ctime>
#include<algorithm>
#include<iomanip>
#include<cmath>

using namespace std;

string GetBinaryValue(long long int decimal)
{
    string binary="";
    while (decimal!=0)
    {
        long long int temp=decimal%2;
        decimal/=2;
        binary+=(temp+'0');
    }
    reverse(binary.begin(),binary.end());
    return binary;
}

class Universal
{
protected:
    long long int i;
    long long int n;
    vector<long long> U_int;
public:
    void setn(long long int);
    void createSetU();
    void getSetU();
    void getBinarySetU();
};
void Universal::setn(long long int N)
{
    n=N;
}
void Universal::createSetU()
{
    for(i=1; i<=n; i++)
    {
        U_int.push_back(i);
    }
}

void Universal::getSetU()
{
    cout<<endl;

    cout<<"Universal set U=  { ";
    for(i=0; i<n; i++)
    {
        cout<<U_int[i]<<" ";
    }
    cout<<"}"<<endl;
}

void Universal::getBinarySetU()
{
    cout<<"Universal set U in Binary=  { ";
    for(i=0; i<n; i++)
    {
        cout<<GetBinaryValue(U_int[i])<<" ";
    }
    cout<<"}"<<endl;
}
int main(void)
{
    long long int n;
    cout<<"Number of Universal set U: ";
    cin>>n;
    cout<<endl;
    Universal Set;
    Set.setn(n);
    Set.createSetU();
    Set.getSetU();
    Set.getBinarySetU();
    cout<<endl;
    return 0;
}
