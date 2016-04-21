
#include <map>
#include <unordered_map>
#include <iostream>
#include <algorithm>

template<typename K1, typename K2>
class bimap {
public:
    // std::map<K1,K2>::const_iterator
    typedef std::map<K1,K2> map_type;
    typedef typename map_type::const_iterator iterator;

    bimap(){}

    // IT-nek kell hogy legyen first es second adattagja
    template<typename IT>
    bimap(IT begin, IT end)
    {
        for(auto it = begin; it!=end;++it)
        {
            insertOrReplace(it->first, it->second);
        }
    }

    void insertOrKeep(K1 const& k1, K2 const& k2) {
        auto it = find_by_k2(k2);
        if(it != data.end() || data.find(k1) != data.end()) return;
        data[k1] = k2;
    }

    void insertOrReplace(K1 const& k1, K2 const& k2) {
        auto it = find_by_k2(k2);
        if(it != data.end())
            data.erase(it);
        data[k1] = k2;
    }

    K2 const& operator[] (K1 const& k1) const {
        return data.at(k1);
    }

    K1 const& operator() (K2 const& k2) const {
        auto it = find_by_k2(k2);
        if(it == data.end())
            throw std::out_of_range("ertelmes hibauzenet");

        return it->first;
    }

    iterator begin() const {
        return data.begin();
    }

    iterator end() const {
        return data.end();
    }
private:
    std::map<K1, K2> data;

    iterator find_by_k2(K2 const& k2) const
    {
        return std::find_if(
                data.begin(),
                data.end(),
                [k2](std::pair<K1,K2> const& p) { return p.second == k2; }
        );
    }
};


int main(int argc, char** argv)
{
    bimap<int, char> bm;

    bm.insertOrKeep(5, 'c');
    bm.insertOrKeep(3, 'b');

    bm.insertOrKeep(5, 'd');
    bm.insertOrReplace(4, 'b');

    std::cout << bm[4] << std::endl;
    std::cout << bm('b') << std::endl;

    try {
        std::cout << bm('f') << std::endl;
    } catch(...) {

    }

    // for(bimap::iterator it = bm.begin(); it != bm.end(); ++it) {
    for(auto const& p: bm)
    {
        std::cout << "<" << p.first << ", " << p.second << ">" << std::endl;
    }

    std::unordered_map<int, char> m;
    m[5] = 'c';
    m[4] = 'b';
    m[2] = 'c';

    bimap<int, char> b2(m.begin(), m.end());

    for(auto const& p: b2)
    {
        std::cout << "<" << p.first << ", " << p.second << ">" << std::endl;
    }

    std::vector<std::pair<int, char>> v;
    v.push_back(std::pair<int,char>(3, 'a'));
    v.push_back(std::pair<int,char>(5, 'c'));
    v.push_back(std::pair<int,char>(9, 'b'));

    bimap<int, char> b3(v.begin(), v.end());

    return 0;
}
