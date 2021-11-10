#include<iostream>
#include<vector>
#include<ctime>
#include<algorithm>
#include<iomanip>
#include<cmath>
using namespace std;
class Universal
{
protected:
    long long int i;
    long long int n;
    vector<long long> U_int;
public:
    void setn(long long int);
    void createSetU();
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
class Sets: public Universal
{
protected:
    vector<long long> A_int, B_int;
    vector<bool> A_Bin, B_Bin,U;
public:
    void createSetAB();
    void getSetAB();
    void getBinarySetAB();
    void Union();
    void getUnion();
};
void Sets::createSetAB()
{
    for(i=1; i<=n; i++)
    {
        A_int.push_back(rand()%n);
        A_Bin.push_back((A_int[i-1]%2));
    }
    for(i=1; i<=n; i++)
    {
        B_int.push_back(rand()%n);
        B_Bin.push_back((B_int[i-1])%2);
    }
}
void Sets::getSetAB()
{
    cout<<endl;

    cout<<"The set A=  { ";
    for(i=0; i<n; i++)
    {
        cout<<A_int[i]<<" ";
    }
    cout<<"}"<<endl;

    cout<<"The set B=  { ";
    for(i=0; i<n; i++)
    {
        cout<<B_int[i]<<" ";
    }
    cout<<"}"<<endl<<endl;
}
void Sets::getBinarySetAB()
{
    cout<<"The set A in (0 or 1)=  { ";
    for(i=0; i<n; i++)
    {
        cout<<A_Bin[i]<<" ";
    }
    cout<<"}"<<endl;

    cout<<"The set B in (0 or 1)=  { ";
    for(i=0; i<n; i++)
    {
        cout<<B_Bin[i]<<" ";
    }
    cout<<"}"<<endl;
}
void Sets::Union()
{
    for(i=0;i<n;i++)
    {

        U.push_back(A_Bin[i]|B_Bin[i]);
    }
}
void Sets::getUnion()
{

    cout<<endl<<"Bitwise OR Operation(A Union B) is:{ ";
    for(i=0; i<n; i++)
    {
        cout<<U[i]<<" ";
    }
    cout<<"}"<<endl;
}

int main()
{
    srand(time(NULL));
    clock_t Begin, End;
    long long int n;
    cout<<"Number of Universal set U:";
    cin>>n;
    cout<<endl;
    Sets Set;
    Set.setn(n);
    Set.createSetU();
    cout<<endl;
    Set.createSetAB();
    Set.getSetAB();
    Set.getBinarySetAB();
    cout<<endl;
    Begin=clock();
    Set.Union();
    Set.getUnion();
    cout<<endl;
    End=clock();
    cout<<"Computational Time:"<<fixed<<setprecision(2)<<(((double)End-(double)Begin))*pow(10,6)<<" Nanosecond"<<endl;
    return 0;
}


