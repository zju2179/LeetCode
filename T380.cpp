#include<iostream>
#include<random>
#include<unordered_map>
using namespace std;

class RandomizedSet {
public:
    static int nums[200010]; //存储集合的数组
    int idx=-1; // 表示数组中[0, idx]是集合元素
    unordered_map<int, int> hashmap; // 值val到数组下标loc的映射
    
    RandomizedSet() {

    }
    
    bool insert(int val) {
        if(hashmap.count(val))
            return false;
        nums[++idx]=val;
        hashmap[val]=idx;
        return true;
    }
    
    bool remove(int val) {
        if(!hashmap.count(val))
            return false;
        int loc = hashmap[val];
        int isDelete = hashmap.erase(val);
        if(isDelete)
        {
            if(loc != idx)
                hashmap[nums[idx]]=loc; //更新最后一个元素的位置到待删除元素的位置，相当于把待删除元素交换到数组尾部进行删除，只要idx--即可实现集合删除最后一个元素
            nums[loc]=nums[idx--];
            return true;
        }
        else
            return false;
    }
    
    int getRandom() {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dist(0,idx);
        int res_idx = dist(gen);
        return nums[res_idx];
    }
};
int RandomizedSet::nums[200010];  
int main()
{
    int val = 1;
    RandomizedSet* obj = new RandomizedSet();
    bool param_1 = obj->insert(val);
    bool param_2 = obj->remove(val);
    int param_3 = obj->getRandom();
    return 0;
}