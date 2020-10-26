#ifndef AJONEUVOT_H
#define AJONEUVOT_H

#include <string>
#include <ostream>

namespace otecpp_ajoneuvot
{
class Ajoneuvo {
  unsigned hinta_;
  std::string merkki_;
  std::string malli_;
  unsigned vuosi_;

protected:
  Ajoneuvo(unsigned hinta, std::string const &merkki, std::string const &malli, unsigned vuosi);
public:
  virtual ~Ajoneuvo();
  virtual void tulosta(std::ostream &virta);

  friend std::ostream &operator<<(std::ostream &os, Ajoneuvo const &ajoneuvo);
};

class Auto : public Ajoneuvo {
  unsigned lukema_;
  std::string vaihteisto_;

public:
  Auto(unsigned hinta,
       std::string const &merkki,
       std::string const &malli,
       unsigned vuosi,
       unsigned lukema,
       std::string const &vaihteisto);
  ~Auto();
  void tulosta(std::ostream &virta);

  friend std::ostream &operator<<(std::ostream &os, Auto const &an_auto);
};

class Vene : public Ajoneuvo {
  std::string tyyppi_;
  unsigned tunnit_;

public:
  Vene(unsigned int hinta,
       std::string const &merkki,
       std::string const &malli,
       unsigned int vuosi,
       std::string const &tyyppi,
       unsigned int tunnit);
  ~Vene();
  void tulosta(std::ostream &virta);

  friend std::ostream &operator<<(std::ostream &os, Vene const &vene);
};
} // namespace otecpp_ajoneuvot

#endif //AJONEUVOT_H
