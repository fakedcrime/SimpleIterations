import numpy as np
import matplotlib.pyplot as plt
import os
from matplotlib import cm
from matplotlib.ticker import FormatStrFormatter
from mpl_toolkits.mplot3d import Axes3D

# Настройка стиля графиков
plt.style.use('seaborn-v0_8')
plt.rcParams['font.family'] = 'DejaVu Sans'
plt.rcParams['axes.labelsize'] = 12
plt.rcParams['axes.titlesize'] = 14

def read_table(filename: str):
    """Чтение данных из файла с автоматическим определением типа задачи"""
    if not os.path.exists(filename):
        raise FileNotFoundError(f"Файл {filename} не найден")

    with open(filename, 'r') as f:
        lines = [line.strip() for line in f if line.strip()]

    # Определяем тип задачи по первой строке
    if not lines:
        raise ValueError("Файл пуст")
    
    task_type = None
    if lines[0].startswith("TEST"):
        task_type = "test"
    elif lines[0].startswith("MAIN"):
        task_type = "main"
    else:
        raise ValueError("Неизвестный тип задачи в файле")

    # Пропускаем строку с типом задачи и заголовки
    data_lines = lines[2:]  # Пропускаем TEST/MAIN и строку с заголовками

    # Загружаем данные как массив numpy
    try:
        data = np.genfromtxt(data_lines)
    except Exception as e:
        raise ValueError(f"Ошибка чтения данных: {str(e)}")

    # Определяем размеры сетки по уникальным значениям X и Y
    x_vals = np.unique(data[:, 0])
    y_vals = np.unique(data[:, 1])
    Nx, Ny = len(x_vals), len(y_vals)

    # Формируем координатные сетки
    X = data[:, 0].reshape(Nx, Ny)
    Y = data[:, 1].reshape(Nx, Ny)

    # Обрабатываем данные в зависимости от типа задачи
    if task_type == "test":
        Z_num = data[:, 2].reshape(Nx, Ny)  # Numerical
        Z_ref = data[:, 3].reshape(Nx, Ny)  # Exact
        Z_err = data[:, 4].reshape(Nx, Ny)  # Difference
        return "test", X, Y, Z_num, Z_ref, Z_err
    elif task_type == "main":
        Z_num = data[:, 2].reshape(Nx, Ny)  # Numerical
        Z_ref = data[:, 3].reshape(Nx, Ny)  # HalfStep
        Z_err = data[:, 4].reshape(Nx, Ny)  # Difference
        return "main", X, Y, Z_num, Z_ref, Z_err

def plot_surfaces(kind, X, Y, Z_num, Z_ref, Z_err):
    """Визуализация результатов"""
    if kind == "test":
        titles = ["Численное решение", "Точное решение", "Погрешность"]
        data = [Z_num, Z_ref, Z_err]
        cmaps = [cm.coolwarm, cm.viridis, cm.plasma]
    else:  # main
        titles = ["Численное решение", "Решение (половинный шаг)", "Разность"]
        data = [Z_num, Z_ref, Z_err]
        cmaps = [cm.coolwarm, cm.coolwarm, cm.plasma]

    fig = plt.figure(figsize=(18, 5), dpi=100)
    
    for i, (title, z_data, cmap) in enumerate(zip(titles, data, cmaps), 1):
        ax = fig.add_subplot(1, 3, i, projection='3d')
        surf = ax.plot_surface(X, Y, z_data, cmap=cmap,
                             rstride=1, cstride=1,
                             linewidth=0.1, edgecolor='black',
                             alpha=0.95)
        
        ax.set_title(title, pad=15)
        ax.set_xlabel('Ось X', labelpad=10)
        ax.set_ylabel('Ось Y', labelpad=10)
        ax.zaxis.set_major_formatter(FormatStrFormatter('%.02f'))
        fig.colorbar(surf, ax=ax, shrink=0.5, aspect=10, pad=0.1)

    plt.tight_layout()
    plt.show()

def main():
    try:
        kind, X, Y, Znum, Zref, Zerr = read_table("table_output.txt")
        plot_surfaces(kind, X, Y, Znum, Zref, Zerr)
    except Exception as e:
        print(f"\nОшибка: {str(e)}")

if __name__ == "__main__":
    main()