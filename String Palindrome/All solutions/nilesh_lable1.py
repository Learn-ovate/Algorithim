print('Enter number to be tested: ')
num=raw_input()
length=len(num)
num=int(num)

temp = num
ans=0

while(temp > 0):
        ans+= pow((temp%10),length)        
        temp/=10
if(ans == num):
        print("Armsrtong number!")
else:
        print("Not armstrong number :(")
