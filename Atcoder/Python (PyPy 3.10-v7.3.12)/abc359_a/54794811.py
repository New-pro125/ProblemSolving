n = int(input())
people = [int(i) for i in input().split()]
res = 0 
for i in range(len(people)-2):
    if people[i]==people[i+2]:
        res+=1
print(res)