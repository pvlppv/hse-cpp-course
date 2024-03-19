#include <cmath>

class Complex
{
private:
    double re;
    double im;

public:
    Complex(double r = 0.0, double i = 0.0) : re(r), im(i) {}

    double Re() const
    {
        return re;
    }
    double Im() const
    {
        return im;
    }

    Complex operator+(const Complex& other) const
    {
        return Complex(re + other.re, im + other.im);
    }

    Complex operator-(const Complex& other) const
    {
        return Complex(re - other.re, im - other.im);
    }

    Complex operator*(const Complex& other) const
    {
        return Complex(re * other.re - im * other.im,
                       re * other.im + im * other.re);
    }

    Complex operator/(const Complex& other) const
    {
        double denominator = other.re * other.re + other.im * other.im;
        return Complex((re * other.re + im * other.im) / denominator,
                       (im * other.re - re * other.im) / denominator);
    }

    Complex operator+() const
    {
        return *this;
    }

    Complex operator-() const
    {
        return Complex(-re, -im);
    }

    double abs() const
    {
        return std::sqrt(re * re + im * im);
    }

    bool operator==(const Complex& other) const
    {
        return re == other.re && im == other.im;
    }

    bool operator!=(const Complex& other) const
    {
        return (re != other.re) || (im != other.im);
    }
};

Complex operator+(double n, const Complex& other)
{
    return other + n;
}

Complex operator-(double n, const Complex& other)
{
    return -other + n;
}

Complex operator*(double n, const Complex& other)
{
    return other * n;
}

Complex operator/(double n, const Complex& other)
{
    Complex nerator = Complex(n);
    Complex denominator = other;
    return nerator / denominator;
}

double abs(const Complex& other)
{
    return std::sqrt(other.Re() * other.Re() + other.Im() * other.Im());
}
