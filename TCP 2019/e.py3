str1=input()
str2=input()

n=float(str1.split(" ")[0])
m=float(str1.split(" ")[1])

x=float(str2.split(" ")[0])
y=float(str2.split(" ")[1])

p1= (x/n)*100
p2= (y/m)*100
o1= ((p1+p2)/2)

sum1 = n+m
sum2 = x+y
o2 = (sum2/sum1)*100

o1=round(o1,10)
o2=round(o2,10)


if o2==o1:
	print("C")
elif o1>o2:
	print("A")
elif o2>o1:
	print("B")