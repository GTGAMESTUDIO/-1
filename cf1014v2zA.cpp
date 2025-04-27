
// Online C++ Compiler - Build, Compile and Run your C++ programs online in your favorite browser

#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;



int main()
{
    int a,b,c,x,m,n;
    
    cin >> a;
    for (int i=0; i<a;++i){
        cin >> b;
        //cout<<'d';
        vector<int> vec;
        for (int r=0;r<b;++r){
            cin >>c;
            vec.push_back(c);
        }
        //cout<<'r';
        sort(vec.begin(),vec.end());
        
        //cout << vec[-1]<<" "<<vec[0]<<"\n";
        m=vec[b-1];
        n=vec[0];
        x=m-2*n;
        cout << vec[0] + x<<'\n';
        vec.clear();
        
        
    }
}
