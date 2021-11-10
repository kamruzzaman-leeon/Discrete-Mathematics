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
        BeginL=clock();
        S.LinearSearch();
        EndL=clock();

        cout<<"Computational Time for Linear Search in nanosecond is=  "<<fixed<<setprecision(2)<<(((double)EndL-(double)BeginL))*pow(10,6)<<" ns"<<endl<<endl;

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


void Set::LinearSearch()
{
    cout<<endl<<"Created Linear Searching Value is: "<<Search<<endl<<endl;
    i=0;
    while(i<n && A[i]!=Search)
    {
        i++;
    }
    if(i<n)
    {
        cout<<"The value has been found in "<<i+1<<" th Position"<<endl<<endl<<endl<<endl;
    }
    else
    {
        cout<<"The value was not found!!!!!!!"<<endl<<endl<<endl<<endl;
    }
}

