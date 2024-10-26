n = int (input())
_ = 1 

while _ <=n : 
    count1 = 0
    count3 = 0 
    count5 = 0 
    count7 = 0 
    a = str(input())
    b = str (input ())
    for i in a :
        if i == "1":
            count1 = count1+1 

        if i == "3":
            count3 = count3+1

        if i == "5":
            count5 = count5+1


        if i == "7":
            count7 = count7+1


    for i in b :
        if i == "1":
            count1 = count1-1 

        if i == "3":
            count3 = count3-1

        if i == "5":
            count5 = count5-1


        if i == "7":
            count7 = count7-1

    _ = _+1

    print (count1*1+count3*4+count5*6+count7*9)
