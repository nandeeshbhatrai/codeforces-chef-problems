def solve ():
    temp_list=[]

    for i in arr:
        if len(temp_list)==0:
            s=str(i)
            tmp=[int(i) for i in s]
            tmp.sort()
            tmp_str ="".join(str(i) for i in (tmp))
            tmp=int(tmp_str )
            if str(tmp)==s and i>10:
                for j in s:
                    temp_list.append(int(j))
            else:
                temp_list.append(i)
        else:
            if i<temp_list[-1]:
                print("NO")
                return 
            s=str(i)
            tmp=[int(i) for i in s]
            tmp.sort()
            tmp_str ="".join(str(i) for i in (tmp))
            tmp=int(tmp_str )
            if temp_list[-1] < int(s[0]) and str(tmp) == s and i >= 10:
                for j in s:
                    temp_list.append(int(j))
            else:
                temp_list.append(i)
    for i in range (1,len(temp_list)):
        if temp_list[i]<temp_list[i-1]:
            print("NO")
            return
    print("YES")
    return
for _ in range (int(input())):
    n=int(input())
    arr=list(map(int, input().split()))
    solve()