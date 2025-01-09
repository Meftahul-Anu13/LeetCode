#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {

        float height=h/2;
        float width =w/2;
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        int diffV =0;
        int diffH=0;
        for(int i=verticalCuts.size()-1;i>=0;i--)
        {
            diffV=max(diffV,(verticalCuts[i]-verticalCuts[i-1]));
            cout<<diffV<<endl;
        }
        for(int i=horizontalCuts.size()-1;i>=0;i--)
        {
            diffH=max(diffH,(horizontalCuts[i]-horizontalCuts[i-1]));
            cout<<diffH<<endl;
        }
        if(verticalCuts.size()>0)
        {
            diffV=max(diffV,verticalCuts[0]);
            diffV=max(diffV,w-verticalCuts[verticalCuts.size()-1]);
        }
        if(horizontalCuts.size()>0)
        {
            diffH=max(diffH,horizontalCuts[0]);
            diffH=max(diffH,h-horizontalCuts[horizontalCuts.size()-1]);
        }
        
        return (1LL * diffH * diffV) % (1000000007);
    }
};

