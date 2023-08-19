# 打印圣诞树
def triangle(n):  # 打印三角形
    for i in range(n):
        print(' ' * (n - 1 - i), end="")
        print('*' * (2 * i + 1))

def square():  # 打印正方形
    for i in range(4):
        print(' ' * 3 + '*' * 3)


triangle(5)
square()

