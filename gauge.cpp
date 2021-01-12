#include "gauge.h"

SU2_mat::SU2_mat() {}

SU2_mat::SU2_mat(double _c0, double _c1, double _c2, double _c3)
{
    c0 = _c0;
    c1 = _c1;
    c2 = _c2;
    c3 = _c3;
}

SU2_mat SU2_mat::operator+(SU2_mat const &obj)
{
    return SU2_mat(c0 + obj.c0, c1 + obj.c1, c2 + obj.c2, c3 + obj.c3);
}

void SU2_mat::operator+=(SU2_mat const &obj)
{
    *this = *this + obj;
}

SU2_mat SU2_mat::operator-(SU2_mat const &obj)
{
    return SU2_mat(c0 - obj.c0, c1 - obj.c1, c2 - obj.c2, c3 - obj.c3);
}

void SU2_mat::operator-=(SU2_mat const &obj)
{
    *this = *this - obj;
}

SU2_mat SU2_mat::operator*(SU2_mat const &obj)
{
    double res_c0, res_c1, res_c2, res_c3;
    res_c0 = c0 * obj.c0 - c1 * obj.c1 - c2 * obj.c2 - c3 * obj.c3;
    res_c1 = c0 * obj.c1 + c1 * obj.c1 - c2 * obj.c3 + c3 * obj.c2;
    res_c2 = c0 * obj.c2 + c1 * obj.c3 + c2 * obj.c0 - c3 * obj.c1;
    res_c3 = c0 * obj.c3 - c1 * obj.c2 + c2 * obj.c1 + c3 * obj.c0;
    return SU2_mat(res_c0, res_c1, res_c2, res_c3);
}

void SU2_mat::operator*=(SU2_mat const &obj)
{
    *this = *this * obj;
}

void SU2_mat::operator=(SU2_mat const &obj)
{
    c0 = obj.c0;
    c1 = obj.c1;
    c2 = obj.c2;
    c3 = obj.c3;
}

SU2_mat SU2_mat::dag()
{
    return SU2_mat(c0, -c1, -c2, -c3);
}

double SU2_mat::trace()
{
    return 2 * c0;
}

void SU2_mat::mk_dble_array_sun(double u[4])
{
    c0 = u[0];
    c1 = u[1];
    c2 = u[3];
    c3 = u[4];
}

SU2_mat operator*(SU2_mat const &obj, double const &i)
{
    return SU2_mat(obj.c0 * i, obj.c1 * i, obj.c2 * i, obj.c3 * i);
}

SU2_mat operator*(double const &i, SU2_mat const &obj)
{
    return i * obj;
}

SU2_mat operator/(SU2_mat const &obj, double const &i)
{
    return SU2_mat(obj.c0 / i, obj.c1 / i, obj.c2 / i, obj.c3 / i);
}
