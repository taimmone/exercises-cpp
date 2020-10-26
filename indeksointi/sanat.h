#ifndef SANAT_H
#define SANAT_H

#include <istream>
#include <map>
#include <set>
#include <string>
#include <vector>

namespace otecpp_sanat
{
std::multimap<std::string, unsigned>
rivit(std::istream &syote);
std::multimap<std::string, unsigned>
tasmaavatRivit(std::istream &syote, const std::set<std::string>& sanat);
std::map<std::string, unsigned>
sanaLkmt(std::istream &syote);
std::map<std::string, std::vector<unsigned> >
rivitTaulukkoon(std::multimap<std::string, unsigned> const &rivimm);

} // namespace otecpp_sanat

#endif //SANAT_H
