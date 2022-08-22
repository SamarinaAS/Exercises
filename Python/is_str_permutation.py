import numpy as np

#для двух строк напишите метод, определяющий, является одна из них перестановкой другой
def is_str_permutation(str1, str2):
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

def test_is_str_permutation(str1, str2):
    if (is_str_permutation(str1, str2)):
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
