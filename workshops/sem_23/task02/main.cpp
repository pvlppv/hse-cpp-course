#include <iostream>
#include <vector>
#include <stdexcept>
#include <new>
#include <typeinfo>
#include <cstring>
#include <memory>
#include <cmath>

/*
Написать код для 10 исключений (См. пример)
 * */


int main() {
    try {
        std::vector<int> v(5);

        throw std::out_of_range("Index out of range");

        std::cout << v.at(10);
    } catch (const std::out_of_range& e) {
        std::cout << "Exception: out_of_range " << e.what() << '\n';
    } catch (const std::bad_alloc& e) {
        std::cout << "Exception: bad_alloc " << e.what() << '\n';
    } catch (const std::logic_error& e) {
        std::cout << "Exception: logic_error " << e.what() << '\n';
    } catch (const std::runtime_error& e) {
        std::cout << "Exception: runtime_error " << e.what() << '\n';
    } catch (const std::invalid_argument& e) {
        std::cout << "Exception: invalid_argument " << e.what() << '\n';
    } catch (const std::length_error& e) {
        std::cout << "Exception: length_error " << e.what() << '\n';
    } catch (const std::bad_cast& e) {
        std::cout << "Exception: bad_cast " << e.what() << '\n';
    } catch (const std::overflow_error& e) {
        std::cout << "Exception: overflow_error " << e.what() << '\n';
    } catch (const std::underflow_error& e) {
        std::cout << "Exception: underflow_error " << e.what() << '\n';
    } catch (const std::domain_error& e) {
        std::cout << "Exception: domain_error " << e.what() << '\n';
    } catch (const std::exception& e) {
        std::cout << "Exception: unknown " << e.what() << '\n';
    } catch (...) {
        std::cout << "Unknown exception\n";
    }

    return 0;
}


