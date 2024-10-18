#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<string>
using namespace std;
int cntOperations(vector<int> nums1, vector<int> nums2, int last1, int last2)
{
    int n = nums1.size(), res = 0;
    for(int i = 0; i <= n - 2; i++)
    {
        if(nums1[i] > last1 || nums2[i] > last2)
        {
            if(nums1[i] > last2 || nums2[i] > last1)
                return n + 1;
            res++;
        }
    }
    return res;
}
int minOperations(vector<int>& nums1, vector<int>& nums2) {
    int res = min(cntOperations(nums1, nums2, nums1.back(), nums2.back()), cntOperations(nums1, nums2, nums2.back(), nums1.back())+1);
    if(res > nums1.size())
        return -1;
    return res;
}
// vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
//     unordered_map<string, vector<int>> hashmap;
//     for(auto item: access_times)
//     {
//         string name = item[0];
//         string time = item[1];
//         hashmap[name].push_back(stoi(time));
//     }
//     vector<string> res;
//     for(auto it: hashmap)
//     {
//         string name = it.first;
//         vector<int> times = it.second;
//         if(times.size() >= 3)
//         {
//             sort(times.begin(), times.end());
//             for(int i = 0; i < times.size(); i++)
//             {
//                 int cnt = 1;
//                 for(int j = i + 1; j < times.size(); j++)
//                 {
//                     if(times[j] - times[i] >= 100)
//                         break;
//                     cnt++;
//                 }
//                 if(cnt >= 3)
//                 {    
//                     res.push_back(name);
//                     break;
//                 }
//             }
//         }
//     }
//     return res;
// }
int main()
{
    vector<int> nums1 = {1,2,7}, nums2 = {4,5,3};
    cout<<minOperations(nums1, nums2)<<endl;
    return 0;
}