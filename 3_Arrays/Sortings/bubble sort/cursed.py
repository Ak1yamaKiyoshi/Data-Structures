(r:=range)and(l:=len)and(p:=print)and((
# Define your array to sort 
a:=[7,5,3,4,5]
)and([[(temp:=a[j],a.__setitem__(j, a[j+1]),a.__setitem__(j+1,temp))for j in r(l(a)-1)if a[j]>a[j+1]]for i in r(l(a))])and(p(a)))
