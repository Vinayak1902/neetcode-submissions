class Solution:

    def encode(self, strs: List[str]) -> str:
        res = ""
        for s in strs:
            res += str(len(s))
            res += '#'
            res +=s
        return res

    def decode(self, s: str) -> List[str]:
        res = []
        n = len(s)
        i,j = 0,0
        while j!=n:
            while s[j] != '#':
                j += 1
            num = s[i:j]
            num = int(num)
            j += 1
            i = j
            j += num
            temp = s[i:j]
            res.append(temp)
            i = j
        return res
        