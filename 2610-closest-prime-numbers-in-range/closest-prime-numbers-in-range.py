class Solution:
    def closestPrimes(self, left: int, right: int) -> List[int]:
        primes = [1] * (right + 1)
        primes[0],primes[1] = 0,0
        for i in range(2,int(math.sqrt(right)+1)):
            if primes[i]:
                for j in range(i*i,right+1,i):
                    primes[j] = 0
        """
            Debugging Part:
                # for i,prime in enumerate(primes):
                #     print(f"{i} -> {'Prime' if prime else 'not Prime'}")
        """
        
        res = []
        for i in range(left,right+1):
            if primes[i]:
                res.append(i)
        min_diff,min_index = 1e9,-1
        for i in range(len(res)-1):
            if min_diff > (res[i+1]-res[i]):
                min_diff = (res[i+1]-res[i])
                min_index = i
        if min_index !=-1:
            return [res[min_index],res[min_index+1]] 
        return [-1,-1]
