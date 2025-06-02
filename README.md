#include <iostream>
#include <cmath>
#include <stdexcept>

class ComplexNumber {
private:
    double real; // Дійсна частина
    double imag; // Уявна частина

public:
    // Конструктор
    ComplexNumber(double real_part, double imag_part) : real(real_part), imag(imag_part) {
        if (!std::isfinite(real_part) || !std::isfinite(imag_part)) {
            throw std::invalid_argument("Real and imaginary parts must be finite numbers");
        }
    }

    // Метод для отримання дійсної частини
    double getReal() const {
        return real;
    }

    // Метод для отримання уявної частини
    double getImag() const {
        return imag;
    }

    // Метод для обчислення модуля суми двох комплексних чисел
    static double modulusOfSum(const ComplexNumber& num1, const ComplexNumber& num2) {
        double sum_real = num1.real + num2.real;
        double sum_imag = num1.imag + num2.imag;
        return std::sqrt(sum_real * sum_real + sum_imag * sum_imag);
    }

    // Метод для виведення комплексного числа у зрозумілому форматі
    void print() const {
        if (imag >= 0) {
            std::cout << real << " + " << imag << "i";
        } else {
            std::cout << real << " - " << std::abs(imag) << "i";
        }
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
        double modulus = ComplexNumber::modulusOfSum(num1, num2);
        std::cout << "Модуль суми: " << modulus << std::endl;
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Помилка: " << e.what() << std::endl;
    }

    return 0;
}
