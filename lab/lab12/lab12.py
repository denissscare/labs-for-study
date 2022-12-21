def find(str, letter):
    arr = [[j for j in i.split(" ")] for i in str.split(".")]
    for i in range(len(arr)):
        for j in range(len(arr[i])):
            if not(letter in arr[i][j]):
                arr[i][j] = ""
    display(arr, str, letter)
    
    
def display(arr, str, letter):
    print ("\nТекст: " + str + "\n")
    print ("Результат: Поиск по букве <<" + letter + ">>\n")
    
    for i in range(len(arr)):
        for j in range(len(arr[i])):
            print(arr[i][j], end = ' ')
        print()
    print("\n")
    
     
def main():
    str = "Иркутск основан как острог в 1661 году на правом берегу Ангары.В 1686 году ему присвоен статус города.С 1764 года – центр Иркутской губернии"
    find(str, "о")
    

if __name__ == '__main__':
    main()