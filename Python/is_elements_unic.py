#реализовать алгоритм, определяющий, все ли символы в строке встречаются только один раз
import numpy as np
#алгоритм в лоб
def is_elements_unic(string):
    for i in range(len(string)):
        for j in range(i+1, len(string)):
            if string[i] == string[j]:
                return False
    return True
#алгоритм с использованием сортировки
def is_elements_unic_sort(string):
    sorted_chars = sorted(string)
    for i in range(len(sorted_chars)-1):
        if sorted_chars[i]==sorted_chars[i+1]: 
            return False
    return True

#с использованием вспомогательного массива, допустим, что речь идет о расширенной кодировке ascii
#Поскольку в python кодировка в формате юникода, этот вариант, возможно, некорректен
#def is_elements_unic_arr(string):
#    array = np.full(256, False, bool)
#    if len(array)>256:
#        return False
#    for i in range(len(string)):
#        if ord(string[i]) > 255:
#            print("Кодировка не ASCII:", string[i], ord(string[i]))
#            return False
#            #вывести как ошибку?
#        elif array[ord(string[i])]:
#            return False
#        else:
#            array[ord(string[i])] = True
#    return True
    
def test_is_elem_unic(string):
    print ("Алгоритм в лоб:")
    if is_elements_unic(string):
        print(string, ": true")
    else:
        print(string, ": false")
    print("С помощью сортировки:")
    if is_elements_unic_sort(string):
        print(string, ": true")
    else:
        print(string, ": false")
    #print("С помощью вспомогательного массива:")
    #if is_elements_unic_arr(string):
    #    print(string, ": true")
    #else:
    #    print(string, ": false")

def main():
    print("Алгоритм, определяющий, все ли символы в строке встречаются только один раз:")
    string = "abignhfme"    
    test_is_elem_unic(string)
    string = "abignhfmeе"    
    test_is_elem_unic(string)
    array = np.full(257, 'a', str)
    print("проверка на 257 символов")
    string = ''.join(array)    
    test_is_elem_unic(string)
    str1 = "abi"
    str2 = "bia"
main()


