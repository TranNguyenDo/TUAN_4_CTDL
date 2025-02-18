from collections import deque
from typing import List, Union
import sys

def max_sliding_window(num_list: List[int], k: int) -> List[int]:
    """
    Tìm giá trị lớn nhất trong mỗi cửa sổ trượt kích thước k của một mảng số.
    
    Args:
        num_list (List[int]): Danh sách các số nguyên
        k (int): Kích thước cửa sổ trượt
    
    Returns:
        List[int]: Danh sách các giá trị lớn nhất trong mỗi cửa sổ
    
    Raises:
        ValueError: Nếu k <= 0 hoặc k > len(num_list)
        TypeError: Nếu num_list chứa phần tử không phải số
    """
    # Kiểm tra kiểu dữ liệu đầu vào
    if not isinstance(num_list, list):
        raise TypeError("Đầu vào phải là một danh sách")
    if not isinstance(k, int):
        raise TypeError("k phải là số nguyên")
    
    # Kiểm tra đầu vào
    if not num_list or k == 0:
        return []
    if k <= 0:
        raise ValueError("k phải là số dương")
    if k > len(num_list):
        raise ValueError("k không thể lớn hơn độ dài mảng")
    
    # Kiểm tra kiểu dữ liệu của các phần tử trong mảng
    if not all(isinstance(x, (int, float)) for x in num_list):
        raise TypeError("Tất cả các phần tử trong mảng phải là số")
    
    result = []
    dq = deque()
    
    for i in range(len(num_list)):
        # Loại bỏ các phần tử không thuộc cửa sổ hiện tại
        while dq and dq[0] < i - k + 1:
            dq.popleft()
        
        # Loại bỏ các phần tử nhỏ hơn phần tử hiện tại từ cuối deque
        while dq and num_list[dq[-1]] < num_list[i]:
            dq.pop()
        
        dq.append(i)
        
        # Chỉ bắt đầu thêm vào kết quả từ khi cửa sổ đủ k phần tử
        if i >= k - 1:
            result.append(num_list[dq[0]])
    
    return result

def get_input_list() -> List[int]:
    """Nhập và xử lý danh sách số từ người dùng."""
    while True:
        try:
            input_str = input("Nhập danh sách số nguyên, cách nhau bởi dấu cách: ").strip()
            if not input_str:
                raise ValueError("Danh sách không được để trống")
            return [int(x) for x in input_str.split()]
        except ValueError as e:
            print(f"Lỗi nhập liệu: {e}. Vui lòng thử lại.")

def get_window_size(max_size: int) -> int:
    """Nhập và xử lý kích thước cửa sổ từ người dùng."""
    while True:
        try:
            k = int(input("Nhập giá trị k: "))
            if k <= 0:
                raise ValueError("k phải là số dương")
            if k > max_size:
                raise ValueError(f"k không thể lớn hơn {max_size}")
            return k
        except ValueError as e:
            print(f"Lỗi nhập liệu: {e}. Vui lòng thử lại.")

def main():
    """Hàm chính của chương trình."""
    try:
        # Nhập dữ liệu với xử lý lỗi
        num_list = get_input_list()
        k = get_window_size(len(num_list))
        
        # Tính toán và in kết quả
        result = max_sliding_window(num_list, k)
        print("\nKết quả:")
        print(f"Danh sách đầu vào: {num_list}")
        print(f"Kích thước cửa sổ: {k}")
        print(f"Các giá trị lớn nhất: {result}")
        
    except KeyboardInterrupt:
        print("\nChương trình đã bị dừng bởi người dùng.")
        sys.exit(1)
    except Exception as e:
        print(f"Đã xảy ra lỗi không mong muốn: {e}")
        sys.exit(1)

if __name__ == "__main__":
    main()
