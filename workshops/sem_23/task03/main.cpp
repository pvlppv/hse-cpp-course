/*
Реализуйте систему обработки заказов, которая проверяет 
корректность введенного количества товаров и их стоимости. 
Если количество товаров отрицательное или стоимость товара 
ниже допустимого предела, система должна генерировать исключения.

Требования к реализации:
Определение класса исключения: Создайте класс исключения 
OrderException, который наследуется от std::exception. 
Класс должен содержать два поля: сообщение об ошибке и код ошибки.
 Реализуйте конструктор, принимающий эти параметры, и методы для их 
 извлечения.

Функция обработки заказа: Реализуйте функцию processOrder, 
которая принимает количество товаров и их стоимость как аргументы. 
Функция должна проверять, что количество товаров не отрицательно 
 что стоимость товара не ниже минимально допустимой. В случае
  обнаружения ошибки, функция должна генерировать исключение 
  OrderException с соответствующим сообщением об ошибке и кодом ошибки.

Обработка исключений: В функции main, вызовите processOrder с
 различными параметрами для демонстрации работы системы. 
 Используйте блоки try-catch для обработки исключений, 
 генерируемых функцией processOrder. При перехвате исключения, 
  выводите информацию об ошибке и код ошибки.
*/

#include <iostream>
#include <exception>
#include <string>


class OrderException : public std::runtime_error {
  int error_code;

public:
  OrderException(const std::string& message, int error_code) : runtime_error(message), error_code(error_code) {}
  int getErrorCode() const { return error_code; }
};

void processOrder(int count, double price) {
  if (count <= 0 || price < 0) {
    throw OrderException("Invalid order", -1);
  }
  std::cout << "Order processed!!!" << std::endl;
}

int main() {
  try {
    processOrder(-99, 12.0);
  } catch (const OrderException& e) {
    std::cout << "исключение:: " << e.what() << "\nкод ошибки: " << e.getErrorCode() << std::endl;
  }

  try {
    processOrder(10, -5.0);
  } catch (const OrderException& e) {
    std::cout << "исключение: " << e.what() << "\nкод ошибки: " << e.getErrorCode() << std::endl;
  }
  return 0;
}
