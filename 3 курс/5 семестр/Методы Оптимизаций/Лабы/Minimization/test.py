from sympy import *
import numpy as np
from sympy.parsing.sympy_parser import standard_transformations, implicit_multiplication_application

x1, x2 = var('x_1 x_2')
ITERATIONS = 50


def upper_index(base: str, index: int) -> str:
    match index:
        case 1:
            return f"{base}¹"
        case 2 | 3:
            return f"{base}{chr(ord('²') + index - 2)}"
        case __:
            return f"{base}{chr(ord('⁰') + index)}"


filename = "expr.txt"
with open(filename, "rt") as file:
    expression = file.readline()
    transformations = (standard_transformations + (implicit_multiplication_application,))
    function: Expr = parse_expr(expression, transformations=transformations)  # ƒ(x)
    x_0 = list(map(float, file.readline().split()))  # начальная точка <print(f'𝒙⁰ = {x_0}')>
    delta = list((map(float, file.readline().split())))   # вектор приращения (величина шага) Δ <print(f"Δ⁰ = {delta}")>
    alpha = float(file.readline())  # коэффициент сжатия (𝛂 > 1) <print(f"𝛂 = {alpha}")>
    eps_x = float(file.readline())  # точность по аргументу x (εₓ) <print(f"εₓ = {eps_x}")>
    eps_y = float(file.readline())  # точность по функции y (εᵧ) <print(f"εᵧ = {eps_y}")>


n = 2
e_i = np.eye(n)  # единичная матрица 𝐞
x_approx_0, x_approx_1 = x_0.copy(), x_0.copy()

for k in range(ITERATIONS):
    x_approx_1 = x_approx_0.copy()
    print(f"\n\t\t\tИТЕРАЦИЯ: k = {k}")
    print(f"{upper_index('x̅', k)} = {x_approx_1}")  # приближение x̅ᶦ (x̅⁰ = 𝒙⁰)
    print(f"ƒ({upper_index('x̅', k)}) = {function.subs({x1: x_approx_1[0], x2: x_approx_1[1]})}")
    x_p = np.array(x_approx_1)  # исходная точка - (𝒙ᵨ⁰ = x̅ᵏ)
    print("\n\t\tИССЛЕДУЮЩИЙ ПОИСК")
    # - для каждой координаты предыдущей (исходной) точки 𝒙ᵨᶦ⁻¹
    for i in range(n):
        print(f"{upper_index('𝒙ᵨ', i)} = {x_p}")
        f_x_p = function.subs({x1: x_p[0], x2: x_p[1]})
        print(f"ƒ({upper_index('𝒙ᵨ', i)}) = {f_x_p}")
        # x_i - 𝒙ᶦ - пробная точка
        # выполнить шаг в сторону приращения Δᵢᵏ
        x_i = x_p + delta * e_i[i]  # 𝒙ᶦ = 𝒙ᵨᶦ⁻¹ + Δᵢᵏ * 𝐞ᵢ
        print(f"Пробная точка №{i+1}: {upper_index('𝒙', i+1)} = {x_i}")
        f_x_i = function.subs({x1: x_i[0], x2: x_i[1]})
        if f_x_i < f_x_p:  # если в пробной значение ЦФ меньше, чем в исходной
            print(f"ƒ({upper_index('𝒙', i + 1)}) = {f_x_i}\t < \tƒ({upper_index('𝒙', i)}ᵨ) = {f_x_p}")
            # то шаг поиска удачный => 𝒙ᵨᶦ = 𝒙ᶦ
            x_p = x_i.copy()  # новой исходной точкой становится пробная
            print(f"Шаг поиска удачный: {upper_index('𝒙ᵨ', i+1)} = {x_p}")
        else:  # из исходной точки делается шаг в противоположном направлении
            print(f"ƒ({upper_index('𝒙', i + 1)}) = {f_x_i}\t >= \tƒ({upper_index('𝒙', i)}ᵨ) = {f_x_p}")
            # делаем шаг в обратном направлении
            x_i = x_p - delta * e_i[i]  # 𝒙ᶦ = 𝒙ᵨᶦ⁻¹ - Δᵢᵏ * 𝐞ᵢ
            print(f"Шаг в обратном направлении: {upper_index('𝒙', i+1)} = {x_i}")
            print(f"Исходная точка: {upper_index('𝒙ᵨ', i+1)} = {x_p}")


    # Шаг №5 - Поиск по образцу
    print("\n\t\tПОИСК ПО ОБРАЗЦУ")
    print(f"{upper_index('Δ', k+1)} = {delta}")
    # x_b - базовая точка = > 𝒙ᵦᵏ = 𝒙ᵨⁿ
    x_b = x_p.copy()
    print(f"Базовая точка: {upper_index('𝒙ᵦ', k)} = {x_b}")
    f_x_b = function.subs({x1: x_b[0], x2: x_b[1]})
    j = 1
    while True:
        # x_o - точка по образцу - шаг из полученной базовой точки вдоль прямой,
        # соединяющей эту точку с предыдущей базовой точкой
        x_o = x_p + j * (x_p - x_approx_1)
        print(f"j = {j}: Точка по образцу: {upper_index('𝒙ₒ', k)} = {x_o}")
        f_x_o = function.subs({x1: x_o[0], x2: x_o[1]})
        if f_x_o >= f_x_b:
            print(f"ƒ({upper_index('𝒙ₒ', k)}) = {f_x_o}\t >= \tƒ({upper_index('𝒙ᵦ', k)}ᵨ) = {f_x_b}")
            j -= 1
            x_o = x_b.copy()
            f_x_o = f_x_b
            print(f"При j = {j}, Поиск по образцу был удачным: {upper_index('𝒙ₒ', k)} = {x_o}")
            break
        else:
            print(f"ƒ({upper_index('𝒙ₒ', k)}) = {f_x_o}\t < \tƒ({upper_index('𝒙ᵦ', k)}) = {f_x_b}")
            print(f"Поиск по образцу удачный: {upper_index('𝒙ₒ', k)} = {x_o}")
            x_b = x_o.copy()
            f_x_b = f_x_o
            j += 1

    x_0 = x_o.copy()
    print(f"\n\t\t\tНовое приближение: {upper_index('x̅', k+1)} = {x_o}")
    diff_x = np.sqrt(sum(pow(coord, 2) for coord in delta))
    diff_y = abs(f_x_o - f_x_p)  # |ƒ(x̅¹) - ƒ(x̅⁰)|
    print(f"|{upper_index('Δ', k+1)}| = {diff_x}",
              f"εₓ = {eps_x}",
              f"|ƒ({upper_index('x̅', k+1)}) - ƒ({upper_index('x̅', k)})| = {diff_y}",
              f"εᵧ = {eps_y}",
              f"ƒ({upper_index('x̅', k+1)}) = {f_x_o}",
              f"ƒ({upper_index('x̅', k)}) = {f_x_p}", sep='\n')
    if diff_x <= eps_x and diff_y <= eps_y:
        break

