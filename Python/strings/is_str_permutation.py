import numpy as np

#для двух строк напишите метод, определяющий, является одна из строк перестановкой другой
#с помощью вспомогательного массива-счетчика
def is_str_permutation_arr(str1, str2):
    array = np.full(256, 0, int)
    if len(str1) != len(str2):
        return False
    for i in range(len(str1)):
        array[ord(str1[i])] +=1
    for i in range(len(str2)):
        array[ord(str2[i])] -=1
    for elem in array:
        if (elem!=0):
            return False
    return True
    
#с помощью сортировки
def is_str_permutation_sort(str1, str2):
    array = np.full(256, 0, int)
    if len(str1) != len(str2):
        return False
    sorted_chars1 = sorted(str1)
    sorted_chars2 = sorted(str2)
    if sorted_chars1 == sorted_chars2:
        return True
    else:
        return False

def test_is_str_permutation(str1, str2):
    print("С помощью вспомогательного массива")
    if (is_str_permutation_arr(str1, str2)):
        print(str1, str2, ": true")
    else:
        print(str1, str2, ": false")
    print("С помощью сортировки")
    if (is_str_permutation_sort(str1, str2)):
        print(str1, str2, ": true")
    else:
        print(str1, str2, ": false")
        
def main():
    print("Метод, определяющий, является одна из них перестановкой другой:")
    str1 = "abi"
    str2 = "bia"
    test_is_str_permutation(str1, str2)
    str1 = "abl"
    str2 = "bia"
    test_is_str_permutation(str1, str2)
    str1 = "ab"
    str2 = "bia"
    test_is_str_permutation(str1, str2)
main()
