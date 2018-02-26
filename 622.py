TC = int(input())

for i in range(TC):
    try:
        
        expr = input()
        
        if expr.strip().startswith("+") or expr.strip().startswith("-"):
            print('ERROR')
        elif expr.find('(-') >= 0 or expr.find('(+') >= 0:
            print('ERROR')
        else:
            ans = eval(expr)
            print(ans)
    except:
        print('ERROR')