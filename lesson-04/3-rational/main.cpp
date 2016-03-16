
#include <iostream>

class rational {
public:

    rational(int p, int q)
            : p(p)
            , q(q)
    {
    }

    rational operator*(rational const& other) const {
      return rational(p*other.p, q*other.q);
    }

    rational operator*(int other) const {
      return rational(p*other, q);
    }

    rational& operator*=(rational const& other) {
      p *= other.p;
      q *= other.q;
      return *this;
    }

    explicit operator bool() const { // c++11
      return q != 0;
    }

    operator void*() const { // before C++11
      return q == 0 ? NULL /* nullptr */ : reinterpret_cast<void*>(1);
    }

    int getP() const { return p; }
    int getQ() const { return q; }

private:
    int p,q;
};

rational operator*(int other, rational const& rat) {
  return rational(rat.getP()*other, rat.getQ());
}

std::ostream& operator <<(std::ostream& out, rational const& rr)
{
  out << rr.getP() << "/" << rr.getQ();
  return out;
}

int main(int argc, char** argv)
{
  //rational r;
  const rational r1p3(1,3);
  rational r1p4(1,4);
  const rational r1p5(1,5);
  const rational r1p12 = r1p3 * r1p4;

  std::cout << r1p3 << std::endl;
  std::cout << r1p4 << std::endl;
  std::cout << r1p5 << std::endl;
  std::cout << r1p12 << std::endl;

  rational r1 = r1p3;
  r1 *= r1p4 *= r1p5;
  std::cout << r1 << std::endl;
  std::cout << r1p4 << std::endl;
  std::cout << r1p5 << std::endl;

  return 0;
}
