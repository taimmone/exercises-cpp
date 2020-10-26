#ifndef LUOKAT_H
#define LUOKAT_H

namespace otecpp_luokat
{
struct A {
  A(int i);
  virtual ~A();
private:
  int i_;
};

struct B : A {
  B(int i);
  virtual ~B();
private:
  int i_;
};

struct C : A {
  C(int i);
  virtual ~C();
private:
  int i_;
};

struct D : A {
  D(int i);
  virtual ~D();
private:
  int i_;
};

struct B2 : virtual A {
 B2(int i);
 virtual ~B2();
private:
  int i_;
};
struct C2 : virtual A {
  C2(int i);
  virtual ~C2();
private:
  int i_;
};
struct D2 : virtual A {
  D2(int i);
  virtual ~D2();
private:
  int i_;
};

struct E : B, C, D {
  E(int i);
  virtual ~E();
private:
  int i_;
};

struct E2 : B2, C2, D2 {
  E2(int i);
  virtual ~E2();
private:
  int i_;
};

struct F : E, E2 {
  F(int i);
  ~F();
private:
  int i_;
};

} // namespace otecpp_luokat

#endif //LUOKAT_H
