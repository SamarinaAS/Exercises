#реализовать алгоритм, определяющий, все ли символы в строке встречаются только один раз
import numpy as np
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
#с использованием вспомогательного массива, допустим, что речь идет о расширенной кодировке ascii
def is_elements_unic_arr(str):
    array = np.full(256, False, bool)
    if len(array)>256:
        return false
    for i in range(len(str)):
        if ord(str[i]) > 255:
            print("Кодировка не ASCII")
            return False
            #вывести как ошибку?
        elif array[ord(str[i])]:
            return False
        else:
            array[ord(str[i])] = True
    return True


def main():
    str = "abignhfme"
    if (is_elements_unic_arr(str)):
        print("true")
    else:
        print("false")
main()
