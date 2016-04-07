'''Name : Ashish Musani
   github Username : ashishmusani
'''

print "Enter the number : "
N = input()
n = N
ans=0

while n>0:
    ans += (n%10)**3
    n = n/10

if ans == N:
    print "Yes"
else:
    print "No"
