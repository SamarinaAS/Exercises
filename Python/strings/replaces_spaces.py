#Напишите метод, заменяющий все пробелы в строке символами %20. Можно считать, что длина строки позволяет сохранить дополнительные символы, а фактическая длина строки известна заранее

#def replaces_spaces(str):
#    count_spaces = 0
#    for elem in str:
#        if elem == ' ':
#            count_spaces+=1;
#    for 
        
def main():
    print("Алгоритм, определяющий, все ли символы в строке встречаются только один раз, алгоритм в лоб:")
    string = "abignhfme"    
    test_is_elem_unic(string)
    string = "abignhfmeе"    
    test_is_elem_unic(string)
    array = np.full(257, 'a', char)
    string = ''.join(array)    
    test_is_elem_unic(string)
    str1 = "abi"
    str2 = "bia"
    print("Метод, определяющий, является одна из них перестановкой другой:")
    test_is_str_permutation(str1, str2)
    str1 = "abl"
    str2 = "bia"
    test_is_str_permutation(str1, str2)
    str1 = "ab"
    str2 = "bia"
    test_is_str_permutation(str1, str2)
main()
