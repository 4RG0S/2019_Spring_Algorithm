num=int(input())
ar=input()
num_ar=[1,3,6,10,15,21,28,36,45,55]
result=''
temp=0
for i in range(10):
    if num_ar[i]==num:
        num=i+1
for j in range(num):
    result=result+ar[temp]
    temp=temp+j+1
print(result)
