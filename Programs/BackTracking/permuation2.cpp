
/*
   Given a collection of numbers , nums , that might contain duplicates
   return all possible unique permutations in any order.
 */
#include<bits/stdc++.h>
using namespace std;
void helper(vector<int> a, vector<vector<int> > &ans, int idx){
    if(idx == a.size()){
        ans.push_back(a);
        return;
    }
    for(int i=idx;i<a.size();i++){
        if(i != idx and a[i] == a[idx]){
            continue;
        }
        swap(a[i],a[idx]);
        helper(a,ans,idx+1);
    }

 }
vector< vector<int> > permute(vector<int> nums)
{

    sort(nums.begin(),nums.end());
    vector<vector<int> > ans;
    helper(nums,ans,0);
    return ans;
}
int main()
{
    int n;cin>>n;
    vector<int> a(n);
    for(int i=0;i<a.size();i++){
        cin>>a[i];
    }
    vector<vector<int> > res = permute(a);
    for(int v=0;v<res.size();v++){
        for(int i=0;i<res[0].size();i++){
            cout<<res[v][i]<<" ";
        }
        cout<<"\n";
    }

}
