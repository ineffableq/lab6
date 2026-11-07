#include <stdio.h>

// Прототипи функцій для 5 завдань
void task1();
void task2();
void task3();
void task4();
void task5();

int main() {
    int choice;

    do {
        printf("\n===================================================\n");
        printf("       ЛАБОРАТОРНА РОБОТА №6: ДВОВИМІРНІ МАСИВИ     \n");
        printf("===================================================\n");
        printf("1. Завдання №915 (Стовпець з мін. середнім арифметичним)\n");
        printf("2. Завдання №929 (Розділення матриці на два 1D масиви)\n");
        printf("3. Завдання №955 (Сума/добуток обраних елементів)\n");
        printf("4. Завдання №999 (Максимум серед мінімумів рядків)\n");
        printf("5. Завдання №950 (Перестановка чвертей квадратної матриці)\n");
        printf("0. Вихід\n");
        printf("---------------------------------------------------\n");
        printf("Виберіть номер завдання (0-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: task1(); break;
            case 2: task2(); break;
            case 3: task3(); break;
            case 4: task4(); break;
            case 5: task5(); break;
            case 0: printf("Вихід з програми...\n"); break;
            default: printf("Некоректний вибір! Спробуйте ще раз.\n");
        }
    } while (choice != 0);

    return 0;
}

// -------------------------------------------------------------------
// Завдання 1 (№915): Стовпець з мінімальним середнім арифметичним
// -------------------------------------------------------------------
void task1() {
    printf("\n--- Завдання №915 ---\n");
    int rows, cols;

    printf("Введіть кількість рядків: ");
    scanf("%d", &rows);
    printf("Введіть кількість стовпців: ");
    scanf("%d", &cols);

    double matrix[50][50];
    printf("Введіть елементи дійсного масиву (%dx%d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }

    int min_col_index = 0;
    double min_avg;

    // Перший стовпець приймаємо за початковий мінімум
    double sum0 = 0.0;
    for (int i = 0; i < rows; i++) {
        sum0 += matrix[i][0];
    }
    min_avg = sum0 / rows;

    // Шукаємо серед решти стовпців
    for (int j = 1; j < cols; j++) {
        double current_sum = 0.0;
        for (int i = 0; i < rows; i++) {
            current_sum += matrix[i][j];
        }
        double current_avg = current_sum / rows;

        if (current_avg < min_avg) {
            min_avg = current_avg;
            min_col_index = j;
        }
    }

    printf("\nМінімальне середнє арифметичне стовпця: %.4f\n", min_avg);
    printf("Номер стовпця з мінімальним середнім: %d (індекс в C: %d)\n", min_col_index + 1, min_col_index);
}

// -------------------------------------------------------------------
// Завдання 2 (№929): Розділення 2D масиву на два 1D масиви
// -------------------------------------------------------------------
void task2() {
    printf("\n--- Завдання №929 ---\n");
    int rows, cols;

    printf("Введіть кількість рядків: ");
    scanf("%d", &rows);
    printf("Введіть кількість стовпців: ");
    scanf("%d", &cols);

    int matrix[50][50];
    int pos_arr[2500]; // для додатних та 0
    int neg_arr[2500]; // для від'ємних
    int pos_count = 0;
    int neg_count = 0;

    printf("Введіть %d цілих елементів матриці (%dx%d):\n", rows * cols, rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
            if (matrix[i][j] >= 0) {
                pos_arr[pos_count] = matrix[i][j];
                pos_count++;
            } else {
                neg_arr[neg_count] = matrix[i][j];
                neg_count++;
            }
        }
    }

    printf("\n1. Масив позитивних та нульових елементів (%d шт.):\n", pos_count);
    for (int i = 0; i < pos_count; i++) {
        printf("%d ", pos_arr[i]);
    }

    printf("\n\n2. Масив негативних елементів (%d шт.):\n", neg_count);
    for (int i = 0; i < neg_count; i++) {
        printf("%d ", neg_arr[i]);
    }
    printf("\n");
}

// -------------------------------------------------------------------
// Завдання 3 (№955): Обчислення суми елементів 3-го стовпця та добутку 2-го рядка
// -------------------------------------------------------------------
void task3() {
    printf("\n--- Завдання №955 ---\n");
    int rows, cols;

    printf("Введіть кількість рядків (мінімум 2): ");
    scanf("%d", &rows);
    printf("Введіть кількість стовпців (мінімум 3): ");
    scanf("%d", &cols);

    if (rows < 2 || cols < 3) {
        printf("Помилка: Матриця повинна мати принаймні 2 рядки та 3 стовпці!\n");
        return;
    }

    double matrix[50][50];
    printf("Введіть елементи матриці (%dx%d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }

    // Третій стовпець має індекс j = 2
    // Другий рядок має індекс i = 1
    int r1, r2;
    printf("\nВведіть номери двох рядків (від 0 до %d) для додавання їх елементів з 3-го стовпця: ", rows - 1);
    scanf("%d %d", &r1, &r2);

    double sum = matrix[r1][2] + matrix[r2][2];
    printf("а) Сума matrix[%d][2] (%.2f) + matrix[%d][2] (%.2f) = %.2f\n", r1, matrix[r1][2], r2, matrix[r2][2], sum);

    int c1, c2;
    printf("\nВведіть номери двох стовпців (від 0 до %d) для множення їх елементів з 2-го рядка: ", cols - 1);
    scanf("%d %d", &c1, &c2);

    double prod = matrix[1][c1] * matrix[1][c2];
    printf("б) Добуток matrix[1][%d] (%.2f) * matrix[1][%d] (%.2f) = %.2f\n", c1, matrix[1][c1], c2, matrix[1][c2], prod);
}

// -------------------------------------------------------------------
// Завдання 4 (№999): Знайти найбільший серед найменших елементів рядків
// -------------------------------------------------------------------
void task4() {
    printf("\n--- Завдання №999 ---\n");
    int rows, cols;

    printf("Введіть кількість рядків: ");
    scanf("%d", &rows);
    printf("Введіть кількість стовпців: ");
    scanf("%d", &cols);

    double matrix[50][50];
    printf("Введіть елементи матриці з різними значеннями (%dx%d):\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%lf", &matrix[i][j]);
        }
    }

    int result_row = 0;
    int result_col = 0;
    double max_of_mins;

    for (int i = 0; i < rows; i++) {
        // Знаходимо найменший елемент у поточному рядку i
        int min_col = 0;
        for (int j = 1; j < cols; j++) {
            if (matrix[i][j] < matrix[i][min_col]) {
                min_col = j;
            }
        }

        double current_min = matrix[i][min_col];

        // Порівнюємо найменший елемент з поточним максимумом
        if (i == 0 || current_min > max_of_mins) {
            max_of_mins = current_min;
            result_row = i;
            result_col = min_col;
        }
    }

    printf("\nЗнайдене значення (максимум з мінімумів): %.4f\n", max_of_mins);
    printf("Індекси елемента: рядок %d, стовпець %d (починаючи з 0)\n", result_row, result_col);
}

// -------------------------------------------------------------------
// Завдання 5 (№950): Перестановка чвертей квадратної матриці
// -------------------------------------------------------------------
void task5() {
    printf("\n--- Завдання №950 ---\n");
    int n;

    printf("Введіть розмір квадратної матриці n (n x n): ");
    scanf("%d", &n);

    int matrix[50][50];
    printf("Введіть елементи матриці %dx%d:\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // а) Обмін місцями верхньої та нижньої чвертей
    // Умови для верхньої чверті: i < j та i + j < n - 1
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i < j && (i + j) < (n - 1)) {
                int opposite_i = n - 1 - i; // симетричний рядок у нижній чверті
                int temp = matrix[i][j];
                matrix[i][j] = matrix[opposite_i][j];
                matrix[opposite_i][j] = temp;
            }
        }
    }

    // б) Обмін місцями правої та лівої чвертей
    // Умови для лівої чверті: i > j та i + j < n - 1
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i > j && (i + j) < (n - 1)) {
                int opposite_j = n - 1 - j; // симетричний стовпець у правій чверті
                int temp = matrix[i][j];
                matrix[i][j] = matrix[i][opposite_j];
                matrix[i][opposite_j] = temp;
            }
        }
    }

    printf("\nМатриця після обміну чвертей:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d ", matrix[i][j]);
        }
        printf("\n");
    }
}