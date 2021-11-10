#include<iostream>
#include<vector>
#include<ctime>
#include<algorithm>
#include<cmath>
#include<iomanip>

using namespace std;

class Set
{
protected:
    long long int n,i,j,temp,Search;
    vector<long long int> A;
public:
    void setN(long long int);
    void createSet();
    void getSet();
    void Sorting();
    void LinearSearch();
    void BinarySearch();
};


int main()
{
    srand(time(NULL));
    clock_t BeginL, EndL, BeginB, EndB;

    while(1)
    {
        long long int x;
        cout<<"Input the value of n: ";
        cin>>x;
        cout<<endl<<endl;

        Set S;
        S.setN(x);
        S.createSet();
        cout<<endl<<endl;
        S.getSet();
        BeginB=clock();
        S.BinarySearch();
        EndB=clock();

        cout<<"Computational Time for Binary Search in nanosecond is=  "<<fixed<<setprecision(2)<<(((double)EndB-(double)BeginB))*pow(10,6)<<" ns"<<endl<<endl;
    }
}





void Set::setN(long long int N)
{
    n=N;
}


void Set::createSet()
{
    Search=(rand()*rand());
    for(i=0;i<n;i++)
    {
        temp=(rand()*rand());
        int c=0;
        do
        {
            c=0;
            if(count(A.begin(),A.end(),temp))
            {
                temp=(rand()*rand());
                c=1;
            }
        }while(c==1);
        A.push_back(temp);
    }
}


void Set::getSet()
{
    cout<<"The set is=  { ";
    for(i=0; i<n; i++)
    {
        cout<<A[i];
        if(i!=n-1)
        {
            cout<<", ";
        }
    }
    cout<<" }"<<endl<<endl<<endl;
}


void Set::Sorting()
{
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(A[i]>A[j])
            {
                temp=A[i];
                A[i]=A[j];
                A[j]=temp;
            }
        }
    }
}


void Set::BinarySearch()
{
    cout<<"Created Binary Searching Value is: "<<Search<<endl<<endl;
    i=0;
    j=n;
    while(i<j)
    {
        temp=floor((i+j)/2);
        if(Search>A[temp])
        {
            i=temp+1;
        }
        else
        {
            j=temp;
        }
    }
    if(Search==A[i])
    {
        cout<<"The value has been found in "<<i+1<<" th Position"<<endl<<endl<<endl<<endl;
    }
    else
    {
        cout<<"The value was not found!!!!!!!"<<endl<<endl<<endl<<endl;
    }
}




