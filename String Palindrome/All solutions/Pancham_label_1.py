n1=0 
print("Program to check if a number is an Armstrong number.") 
print("")
print("Enter a number: ") //Prompt to enter a number
n=int(raw_input()) //Taking input as an integer data type
x=n //Assigning the value of the number taken from the user to 'x'
while(n!=0): //Checking if the number is not 0
	rem=n%10
	n1=n1+(rem*rem*rem) //Splitting and cubing the number.
	n=n/10
if(n1==x): //Checking if the cube is equal to x
	print("RESULT: Yes, " +str(x)+ " is an Armstrong number.")
else:
	print("RESULT: No, " +str(x)+ " is not an Armstrong number." )
	
