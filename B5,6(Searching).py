no=int(input("Enter the number of student who were present for the function "))
n=[]
for i in range(no):
  n.append(int(input("Enter the roll no. of student present for the function ")))

#Function for Linear search
def linear():
    print("\n BY LINEAR SEARCH")
    key=int(input("Enter the roll no. to be find "))
    flag=0
    for i in(n):
      if(key==i):
          flag=1
    if(flag==1):
        print("Concern Roll No.",key,"was present for the function")
    else:
        print("Concern Roll No.",key,"Concern Roll No.")
        
#Function for Sentinel search
def sentinel():
    print("\n BY SENTINEL SEARCH")
    key=int(input("Enter the roll no. to be find "))
    n.append(key)
    i=0
    while(n[i]!=key):
        i=i+1
    if(i<no):
        print("Concern Roll No.",key, "was present for the function")
    else:
        print("Concern Roll No.",key,"was absent for the function")
        
#Function for Binary search
def binary():
    print("\n BY BINARY SEARCH")
    key=int(input("Enter the roll no. to be find "))
    n.sort()
    l=0
    h=no-1
    flag=0
    while(l<=h):
       mid=(l+h)//2
       if(key==n[mid]):
          flag=1
          break
       elif(key<n[mid]):
          h=mid-1
       else:
          l=mid+1
    if(flag==1):
       print("Concern Roll No.",key,"was present for the function")
    else:
       print("Concern Roll No.",key,"was absent for the function")
       
#Function for Fibonacci search
def fibonacci():
   print("\n BY FIBONACCI SERACH")
   key=int(input("Enter the roll no. to be find "))
   fib2=0
   fib1=1
   fib=fib1+fib2
   while (fib<no):
      fib2=fib1
      fib1=fib
      fib=fib1+fib2
   offset=0
   flag=0
   while(fib>1):
      i=min(offset+fib2,no)
      if(n[i]==key):
          flag=1
          break
      elif(n[i]>key):
          fib=fib2
          fib1=fib1-fib2
          fib2=fib-fib1
      else:
          fib=fib1
          fib1=fib2
          fib2=fib-fib1
          offset=i
   if(flag==1):
         print("Concern Roll No.",key,"was present for the function")
   else:
         print("Concern Roll No.",key,"was absent for the function")
         
linear()
sentinel()
binary()
fibonacci()
