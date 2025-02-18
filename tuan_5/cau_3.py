from collections import Counter

def word_count(file_path):
    with open(file_path, 'r', encoding='utf-8') as file:
        text = file.read()
    
    # Tách từ theo khoảng trắng
    words = text.lower().split()
    
    # Đếm số lần xuất hiện của từng từ
    word_freq = Counter(words)
    
    return dict(word_freq)

# Ví dụ sử dụng
file_path = 'P1_data.txt'  # Thay bằng đường dẫn thực tế
word_counts = word_count(file_path)
print(word_counts)
