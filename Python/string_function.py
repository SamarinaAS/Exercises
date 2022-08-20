#реализовать алгоритм, определяющий, все ли символы в строке встречаются только один раз
#алгоритм в лоб
def is_elements_unic(str):
    for i in range(len(str)):
        for j in range(i+1, len(str)):
            if str[i] == str[j]:
                return False
    return True
#алгоритм с использованием сортировки
def is_elements_unic_sort(str):
    sorted_chars = sorted(str)
    for i in range(len(sorted_chars)-1):
        if sorted_chars[i]==sorted_chars[i+1]: 
            return False
    return True
    
def main():
    str = "hellow"
    if (is_elements_unic_sort(str)):
        print("true")
    else:
        print("false")
main()
