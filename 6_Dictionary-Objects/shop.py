assortiment = { 
    'key': {
        'milk':{
            'sour cream':{
                'cost':45,
                'amount':10}, 
            'milk':{
                "cost":67,
                'amount':16}, 
            'cheese':{
                'cost':89,
                'amount':5}},
        'drinks':{
            'water':{
                'cost':21,
                'amount':20},
            'juices':{
                'cost':47,
                'amount':25},
            'soda':{
                'cost':30,
                'amount':5}},
        "bakery":{
            "bread":{
                "cost":12,
                "amount":2},
            "cinamon rolls":{
                "cost":32,
                "amount":6},
            "cherry buns":{
                "cost":26,
                "amount":0}}
}}
orderBuy = {}
where = []
wallet = 506
step = 0
print("\n"*50)
while step < 5:
    if step == 0:
        print(assortiment['key'].keys())
        where.append(input("        в какой раздел отправится? "))
        step = 1
    elif step == 1:
        print("\n"*2)
        print(assortiment['key'][where[0]].keys())
        where.append(input("        какой продукт взять? "))
        step = 2
    elif step == 2:
        print("\n"*1)
        print(assortiment['key'][where[0]][where[1]])
        print('        ваши деньги: ',wallet)
        where.append(input("        какое количество взять? "))
        if int(where[-1]) < assortiment['key'][where[0]][where[1]]['amount']:
            if wallet > assortiment['key'][where[0]][where[1]]['cost'] * int(where[-1]):
                step = 3
            else:
                print("\n")
                print("/////////////////у вас не хватает денег!")
        else:
            print("\n")
            print("/////////////////вы берете больше чем есть в магазине! ")
    elif step == 3:
        print("\n"*5)
        print("     хотите взять что то еще? ")
        where.append(input("        yes/no:  "))
        step = 4
        if where[-1] == 'yes':
            step = 0
        if where[-1] == 'no':
            step = 4   
        assortiment['key'][where[0]][where[1]]['amount'] = assortiment['key'][where[0]][where[1]]['amount'] - int(where[-2])
        orderBuy[where[1]] = int(where[- 2])
        wallet = wallet - assortiment['key'][where[0]][where[1]]['cost'] * int(where[-2])
        where = []
    elif step == 4:
        print("\n"*5)
        print("        хотите посмотреть свою корзину? ")
        where.append(input("        yes/no:  "))
        if where[-1] == 'yes':
            print(orderBuy)
        step = 5