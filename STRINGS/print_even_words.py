def printeven(s):
    s=s.split(" ") # for eg: "My NAME is atul yadav" becomes ['My', 'NAME', 'is', 'atul', 'yadav']
    for i in s:
        if(len(i)%2==0):
            print(i)

s="My NAME is atul yadav"
printeven(s)