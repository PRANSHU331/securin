#include<bits/stdc++.h>
using namespace std;


void print(vector<int> die_a,vector<int> die_b)
{
    int n=die_a.size();
    for(int i=0;i<n;i++)
    {
        cout<<die_a[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<die_b[i]<<" ";
    }
    cout<<endl;
}
int find(vector<int> die,vector<int> sum,vector<int> &die_b)
{
    int s=1;
    int i=1;
    
    while(i<=8)
    {
        int next=i+s;
        if(sum[next]>0)
        {
            for(int k=0;k<die.size();k++)
            {
                int temp=i+die[k];
                sum[temp]=sum[temp]-1;
            }
            die_b.push_back(i);
        }
        i++;
    }
    
    for(int i=2;i<sum.size();i++)
    {
        if(sum[i]!=0)
        return 0;
    }
    return 1;
}
void undoom_dice(vector<int> &die_a,vector<int> &die_b)
{
    int n=die_a.size();
    
    vector<int> new_die_a={1,2,3,4};
    vector<int> new_die_b;
    vector<int> sum={0,0,1,2,3,4,5,6,5,4, 3, 2, 1};
                    //   2 3 4 5 6 7 8 9 10 11 12
    
    // case 1 =(2 2)
    new_die_a.push_back(2);
    new_die_a.push_back(2);
    
    int f1=find(new_die_a,sum,new_die_b);
    if(f1==1)
    {
        die_a=new_die_a;
        die_b=new_die_b;
        return;
    }
    new_die_b.clear();
    // cse 2 = (2,3)
    new_die_a[5]=3;
    int f2=find(new_die_a,sum,new_die_b);
    if(f2==1)
    {
        die_a=new_die_a;
        die_b=new_die_b;
        return;
    }
    new_die_b.clear();
    
    // case 3 = (3,3)
    new_die_a[4]=4;
    int f3=find(new_die_a,sum,new_die_b);
    
    if(f3==1)
    {
        die_a=new_die_a;
        die_b=new_die_b;
        return;
    }
    
}
int main()
{
    vector<int> die_a={1,2,3,4,5,6};
    vector<int> die_b={1,2,3,4,5,6};
    
    int n=die_a.size();
    undoom_dice(die_a,die_b);
    
    print(die_a,die_b);
    return 0;
}