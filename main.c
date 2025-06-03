#include <iostream>
#include <cmath>
#include <stdexcept>

class ComplexNumber {
private:
    double real; // Дійсна частина
    double imaginary; // Уявна частина

public:
    // Конструктор з перевіркою вхідних даних
    ComplexNumber(double realPart, double imaginaryPart) {
        if (!std::isfinite(realPart) || !std::isfinite(imaginaryPart)) {
            throw std::invalid_argument("Real and imaginary parts must be finite numbers");
        }
        real = realPart;
        imaginary = imaginaryPart;
    }

    // Гетери для отримання частин числа
    double getReal() const { return real; }
    double getImaginary() const { return imaginary; }

    // Метод для обчислення модуля числа
    double modulus() const {
        return std::sqrt(real * real + imaginary * imaginary);
    }

    // Метод для додавання комплексних чисел
    ComplexNumber add(const ComplexNumber& other) const {
        return ComplexNumber(real + other.real, imaginary + other.imaginary);
    }

    // Метод для виведення числа на екран
    void print() const {
        if (imaginary >= 0) {
            std::cout << real << " + " << imaginary << "i";
        } else {
            std::cout << real << " - " << -imaginary << "i";
        }
    }
};

class ComplexCalculator {
public:
    // Метод для обчислення модуля суми двох комплексних чисел
    static double modulusOfSum(const ComplexNumber& num1, const ComplexNumber& num2) {
        ComplexNumber sum = num1.add(num2);
        return sum.modulus();
    }
};

int main() {
    try {
        // Створення двох комплексних чисел: 1 + 3i та -1 + 2i
        ComplexNumber num1(1.0, 3.0);
        ComplexNumber num2(-1.0, 2.0);

        // Виведення чисел
        std::cout << "Перше число: ";
        num1.print();
        std::cout << std::endl;

        std::cout << "Друге число: ";
        num2.print();
        std::cout << std::endl;

        // Обчислення та виведення модуля суми
        double modulus = ComplexCalculator::modulusOfSum(num1, num2);
        std::cout << "Модуль суми: " << modulus << std::endl;
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Помилка: " << e.what() << std::endl;
    }

    return 0;
}
