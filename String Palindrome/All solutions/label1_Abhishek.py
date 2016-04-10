sum=0
print("Armstrong number program")
print("Enter the number to check armstrong : ")
n=int(raw_input())
temp=n
while(n>0):
	rem=n%10
	sum=sum+(rem*rem*rem)
	n=n/10
if(sum==temp):
	print("YES")
else:
	print("NO")
