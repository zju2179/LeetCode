def threeSum(nums: list[int]) -> list[list[int]]:
    n = len(nums)
    if n < 3 or not nums:   # 数组长度小于3或者数组为null
        return []
    nums.sort()
    res = []
    for i in range(n):
        if nums[i] > 0:
            return res
        if i > 0 and nums[i] == nums[i - 1]:
            continue
        l = i + 1
        r = n - 1
        while(l < r):
            if nums[i] + nums[l] + nums[r] == 0:
                res.append([nums[i], nums[l], nums[r]])
                while(l < r and nums[l] == nums[l+1]):
                    l += 1
                while l < r and nums[r] == nums[r-1]:
                    r -= 1
                l += 1
                r -= 1
            elif nums[i] + nums[l] + nums[r] > 0:
                r -= 1
            else:
                l += 1
    return res

nums = [-1,0,1,2,-1,-4]
print(threeSum(nums))