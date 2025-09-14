class student:
      def kadane(self,nums:list[int])->int:
            current_sum=nums[0]
            over_sum=nums[0]
            for i in range(1,len(nums)):
                  if current_sum+nums[i]>nums[i]:
                        current_sum=current_sum+nums[i]
                        if current_sum>over_sum:
                              over_sum=current_sum
                  else:
                        current_sum=nums[i]
                        over_sum=max(current_sum,over_sum)
            return over_sum
nums=[4,3,-2,6,-14,7-1,4,5,7,-10,2]
s=student()
result=s.kadane(nums)
print(result)