#include <bits/stdc++.h>
using namespace std;
class sDES
{
public:
    vector < int > pt;
    vector < int > key;
    vector < int > key1;
    vector < int > key2;
    vector < int > ct;
    sDES()
    {
        key1.resize(6);
        key2.resize(6);
        ct.resize(8);
        cout<<"Enter Plain text (8bits) : ";
        for(int i=0;i<8;i++){
            int temp;
            cin>>temp;
            pt.push_back(temp);
        }
        cout<<endl<<"Enter key (10bits) : ";
        for(int i=0;i<10;i++){
            int temp;
            cin>>temp;
            key.push_back(temp);
        }
    }
    void shift(vector<int>&temp)
    {
        int a=temp[0];
        int i;
        for(i=0; i<temp.size(); i++)
        {
            temp[i]=temp[i+1];
        }
        temp[i-1]=a;
    }
    void keyGeneration()
    {
        key.erase(key.begin()+4);
        key.erase(key.begin()+8);

        vector<int>L(4);
        vector<int>R(4);
        for(int i=0; i<4; i++)
        {
            L[i]=key[i];
            R[i]=key[i+4];
        }
        shift(L);
        shift(R);
        for(int i=0; i<3; i++)
        {
            key1[i]=L[i];
            key1[i+3]=R[i];
        }
        shift(L);
        shift(R);
        for(int i=0; i<3; i++)
        {
            key2[i]=L[i];
            key2[i+3]=R[i];
        }
    }
    void swap(vector<int>&L,vector<int>&R)
    {
        vector<int>temp=L;
        L=R;
        R=temp;
    }

    void encrypt()
    {   vector<int>L;
        vector<int>R;
        for(int i=0; i<4; i++)
        {
            L.push_back(pt[i]);
            R.push_back(pt[i+4]);
        }
        R.push_back(R[0]^R[1]);
        R.push_back(R[2]^R[3]);

        for(int i=0; i<6; i++)
        {
            R[i]=R[i]^key1[i];
        }

        R.erase(R.begin());
        R.erase(R.end()-1);
        reverse(R.begin(),R.end());
        swap(L,R);

        R.push_back(R[0]^R[1]);
        R.push_back(R[2]^R[3]);


        for(int i=0; i<6; i++)
        {
            R[i]=R[i]^key2[i];
        }

        R.erase(R.begin());
        R.erase(R.end()-1);
           reverse(R.begin(),R.end());
        for(int i=0; i<4; i++)
        {
            ct[i]=R[i];
            ct[i+4]=L[i];
        }
        for(int i=0; i<8; i++)
        {
            cout<<ct[i]<<" ";
        }

    }


};
int main()
{
    sDES obj;
    obj.keyGeneration();
   obj.encrypt();
    return 0;
}
    