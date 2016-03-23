# Python Program to Check Whether Given Number is Armstrong or Not
# Created By Himanshu Patel 

def arm(p):
	tmp=p
	r=0
	summ=0
	while(tmp>0):
		r=int(tmp) % 10
		tmp=int(tmp)/10
		summ=summ+(r*r*r)
		
	
	if int(summ) == int(p):
		print "This is Armstrong Number"
	else:
		print "This is Not Armstrong Number"
	
	return

n=raw_input("Enter the number:")
arm(n)

