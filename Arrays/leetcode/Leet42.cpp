#include<iostream>
#include<vector>
using namespace std;
int main(){
        /*class Solution {
public:
    int trap(vector<int>& height) {
        int m=height[0],c=0,q=height.size();
        vector<int> v1(q);
        vector<int> v2(q);
        v1[0]=-1,v2[q-1]=-1;
        for(int i=1; i<q; i++){
            if(m<height[i])m=height[i];
            v1[i]=m;
        }
        m=height[q-1];
        for(int i=q-2; i>=0; i--){
            if(m<height[i]) m=height[i];
            v2[i]=m;
        }
        vector<int> v3(q);
        for(int i=0;i<q;i++){
            v3[i]=min(v1[i],v2[i]);
        }
        for(int i=1;i<q-1;i++){
            if(height[i]<v3[i]){
                c=c + v3[i]-height[i];
            }
        }
    return c;
    }
};*/




/*class Solution {
public:
    int trap(vector<int>& height) {
        int m=height[0],c=0,q=height.size();
        vector<int> v1(q);
        vector<int> v2(q);
        v1[0]=-1,v2[q-1]=-1;
        for(int i=1; i<q; i++){
            if(m<height[i])m=height[i];
            v1[i]=m;
        }
        m=height[q-1];
        for(int i=q-2; i>=0; i--){
            if(m<height[i]) m=height[i];
            v2[i]=m;
        }
        for(int i=0;i<q;i++){
            v1[i]=min(v1[i],v2[i]);
        }
        for(int i=1;i<q-1;i++){
            if(height[i]<v1[i]){
                c=c + v1[i]-height[i];
            }
        }
    return c;
    }
};*/




/*class Solution {
public:
    int trap(vector<int>& height) {
        int m=height[0],c=0,q=height.size();
        vector<int> v1(q);
        v1[0]=-1;
        for(int i=1; i<q; i++){
            if(m<height[i])m=height[i];
            v1[i]=m;
        }
        m=height[q-1];
        for(int i=q-2; i>=0; i--){
            if(m < v1[i]) v1[i]=m;
            if(m<height[i]) m=height[i];
        }
        for(int i=1;i<q-1;i++){
            if(height[i]<v1[i]){
                c=c + v1[i]-height[i];
            }
        }
    return c;
    }
};*/
}