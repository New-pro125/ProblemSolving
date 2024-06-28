class Solution:
    def factorize(self,n:int)->list:
        i = 1
        res = []
        while i*i<=n:
            if n%i==0:
                if i!=n//i:
                    res.append(i)
                res.append(n//i)
            i+=1
        return sorted(res)
    def kthFactor(self, n: int, k: int) -> int:
        res = self.factorize(n)
        print(res)
        if len(res)<k:
            return -1
        else:
            return res[k-1]