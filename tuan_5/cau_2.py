def count_letters(word):
    letter_count = {}
    # Chuyển từ về chữ thường để không phân biệt hoa thường
    word = word.lower()
    
    # Đếm số lần xuất hiện của mỗi chữ cái
    for char in word:
        if char in letter_count:
            letter_count[char] += 1
        else:
            letter_count[char] = 1
            
    return letter_count

# Test function
if __name__ == "__main__":
    test_word = input("Nhập một từ: ")
    result = count_letters(test_word)
    print(result)
