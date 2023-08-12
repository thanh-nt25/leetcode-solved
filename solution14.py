class Solution14:
    def longestCommonPrefix(self, strs: list[str])->str:
        preStr = ''
        strs = sorted(strs)
        first = strs[0]
        last = strs[-1]
        
        for i in range(min(len(first), len(last))):
            if (first[i] != last[i]):
                return preStr
            preStr += first[i]

        return preStr