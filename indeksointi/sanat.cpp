#include "sanat.h"
#include <iostream>
#include <sstream>

typedef std::multimap<std::string, unsigned int>::iterator MultiIt;
namespace otecpp_sanat
{
std::multimap<std::string, unsigned int>
rivit(std::istream &syote) {
  std::multimap<std::string, unsigned int> rivit;
  std::string rivi;
  for (unsigned i = 1; std::getline(syote, rivi); ++i) {
    std::istringstream iss(rivi);
    for (std::string sana; std::getline(iss, sana, ' ');) {
      rivit.insert(make_pair(sana, i));
    }
  }
  return rivit;
}
std::multimap<std::string, unsigned int>
tasmaavatRivit(std::istream &syote, std::set<std::string> const &sanat) {
  std::multimap<std::string, unsigned int> rivit;
  std::string rivi;
  for (unsigned i = 1; std::getline(syote, rivi); ++i) {
    std::istringstream iss(rivi);
    for (std::string sana; std::getline(iss, sana, ' ');) {
      bool tasmaa = false;
      for (std::set<std::string>::const_iterator it = sanat.begin(); it!=sanat.end(); ++it) {
        if (sana==*it) {
          tasmaa = true;
          break;
        }
      }
      if (tasmaa) {
        rivit.insert(make_pair(sana, i));
      }
    }
  }
  return rivit;
}
std::map<std::string, unsigned int>
sanaLkmt(std::istream &syote) {
  std::map<std::string, unsigned int> lkmt;
  for (std::string rivi; std::getline(syote, rivi);) {
    std::istringstream iss(rivi);
    for (std::string sana; std::getline(iss, sana, ' ');) {
       lkmt[sana] += 1;
    }
  }
  return lkmt;
}
std::map<std::string, std::vector<unsigned int> >
rivitTaulukkoon(std::multimap<std::string, unsigned int> const &rivimm) {
  std::map<std::string, std::vector<unsigned int> > riviMap;
  for (std::multimap<std::string, unsigned int>::const_iterator it = rivimm.begin(); it != rivimm.end(); ++it) {
    riviMap[it->first].push_back(it->second);
  }
  return riviMap;
}
} // namespace otecpp_sanat