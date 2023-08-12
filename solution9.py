class Solution9:
    def isPalindrome(self, x: int)->bool:
        str_convert = str(x)
        length = len(str_convert)
        stack = []
        if (length % 2 == 1): 
            mid = length // 2
            str_convert = str_convert[:mid] + str_convert[mid+1:]
            length = length - 1
            print('if')

        mid = length//2 - 1 # mid index
        for i in range(length):
            if(i > mid and stack != [] and str_convert[i] == stack[-1]):
                stack.pop()
                continue
            stack.append(str_convert[i])
            print(stack)

        if (stack == []):
            return True
        else:
            return False

class Solution9: #2
    def isPalindrome(self, x: int)->bool:
        rever = 0
        temp = x
        while(temp != 0):
            rever = rever * 10 + temp % 10
            temp //= 10
        return rever == x