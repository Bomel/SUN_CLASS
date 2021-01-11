#ifndef GAUGE_H
#define GAUGE_H

class SU2_mat
{
public:
    double c0, c1, c2, c3;
    SU2_mat(double c0, double c1, double c2, double c3);

    SU2_mat operator+(SU2_mat const &obj);
    SU2_mat operator+=(SU2_mat const &obj);
    SU2_mat operator-(SU2_mat const &obj);
    SU2_mat operator-=(SU2_mat const &obj);
    SU2_mat operator*(SU2_mat const &obj);
    SU2_mat operator*=(SU2_mat const &obj);

    SU2_mat dag();

    double trace();

    void mk_dble_array_sun(double u[4]);
};

SU2_mat operator*(SU2_mat const &obj, double const &i);
SU2_mat operator*(double const &i, SU2_mat const &obj);
SU2_mat operator*=(SU2_mat const &obj, double const &i);

SU2_mat operator/(SU2_mat const &obj, double const &i);
SU2_mat operator/=(SU2_mat const &obj, double const &i);

#endif