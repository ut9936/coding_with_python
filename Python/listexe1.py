

def toCommaList(a) :
    c = a[len(a)-1]
    del a[len(a)-1]
    b = ''
    for i in a :
        b += i+', '
    
    b += 'and ' + c
    return b;

a = ['apples','bananas','tofu','cats']
s = toCommaList(a)
print(s)
