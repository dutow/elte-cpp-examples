elte-cpp-examples
=====

Ez a repository az ELTE IK programtervezo informatikus Bsc C++ programozas gyakorlatahoz tartalmaz peldakat.

Az egyes orak anyagai a lesson-XX konyvtarakban talalhatoak. Mindegyik konyvtarban talalhato egy ujabb README, ami az adott ora tomor vazlatat tartalmazza.

Ennek az anyagnak NEM az a celja, hogy teljesen onalloan is megtanuld az anyagot, hanem az, hogy az orakra bejarok kapjanak egy plusz segitseget a C++/programozas megerteseben, elsajatitasaban.

Ennek megfeleloen reszletes magyarazatokat nem tartalmaz, ugyanakkor aki csak 1-1 orarol hianyzik, kedvenc internetes keresoje segitsegevel a peldaprogramok alapjan viszonylag konnyen tud boldogulni.


Elokeszites
-----

Az anyag nagy resze C++-ban keszult programokbol all. 

Az oran bemutatottak nagy resze siman onmagaban, kezzel is fordithato, igy eleg odanavigalnod az adott konyvtarba, es kiadni az azt fordito parancsot (felteve, hogy van egy C++ fordito a gepeden). 

Peldaul:

```bash
cd lesson-01/1-hello-world
g++ main.cpp -o hello-vilag
./hello-vilag
```

Emellett azonban tartalmaz extra peldakat, amikhez kulso konyvtarak is kellenek - amennyiben szeretned azokat hasznalni, ahhoz elobb be kell szerezned oket. Ehhez is vannak scriptek, amik vegrehajtjak.


### Szukseges szoftverek

#### Ubuntu

Futtasd az `ubuntu_dependencies.sh` shell scriptet (nyugodtan nezd meg a tartalmat, csak `apt-get install` hivasokat tartalmaz), ez fel fog tenni neked minden szukseges csomagot: clang (fordito), cmake (segit leforditani mindent egyszerre), git (a letolteshez, frissiteshez), illetve a kulso konyvtarak altal igenyelt fuggosegek. 

A fajlban vannak kommentek, mi miert kell.

#### Windows

 * Szukseged lesz egy git kliensre. A SourceTree, valamint a GitExtensions is nagyon jo.
 * Szukseged lesz egy forditora is. Legegyszerubb a Visual Studio Community feltetele (vagy dreamspark-rol Professional), de a clang telepitese sem *sokkal* bonyolultabb
 * Szukseged lesz a CMake-re is, amennyiben szeretned az extra peldakat is futtatni.


### Fejlesztokornyezet

Ugyan egy paranccsor es egy szovegszerkeszto is elegendo (es javaslom, hasznald ugy is a peldakat, nem art a tapasztalat!), egy jo fejlesztoi kornyezet igen sokat segit, foleg hibakereseskor.

Ime par lehetoseg:

 * Visual Studio (Windows alatt, valoszinuleg fel is tetted az elozo lepes kereteben)
 * Clion (platformfuggetlen, diakoknak regisztracio utan ingyenes, jol egybeepul a CMake-el)
 * KDevelop (linux)
 * Eclipse CDT (platformguggetlen)


### A peldak beszerzese

Miutan a fuggosegeket feltetted, le tudod szedni ezt a git repository-t a sajat gepedre. Ez parancssorban a kovetkezo parancs:

```bash
git clone --recursive https://github.com/dutow/elte-cpp-examples.git
```

Amennyiben egy grafikus eszkozt hasznalsz, eleg lesz az URL-t megadni.

A rekurziv opcio csak akkor szukseges, ha az extrakat is szeretned. Amennyiben igen, nyugodtan menny el kavezni az elinditasa utan.


### Opcionalis: forditsd le a kulso konyvtarakat

Amennyiben szeretned az extrakat, szukseged van a boost (altalanos C++ osztalyok/fuggvenyek gyujtemenye) egy reszere, valamint az SFML nevu grafikus csomagra. Ezeket a pltaformodtol fuggoen a `boostrap.sh`, vagy `bootstrap.bat` futtatasaval tudod leforditani.

Csak egyszer kell megtenned.


### Opcionalis: forditsd le a peldakat (csak amennyiben az extrakat is szeretened)

Amennyiben olyan fejlesztoi kornyezetet hasznalsz, ami tamogatja a CMake-t, a legegyszerubb, ha megnyitod a projekt konyvtarat benne, majd megnyomod a forditas gombot.

Amennyiben Visual Studio-t / Eclipse-t hasznalsz, a CMake tud generalni neked projekt fajlokat, peldaul:

```bash
cmake .. -G "Visual Studio 10 Win64"
```

Amennyiben parancssorbol szeretnel forditani:

```bash
cmake .
cmake --build .
```

A generalast minden esetben csak egyszer kell megtenned, utana a valtozasokat automatikusan eszre fogja venni - azaz peldaul paranccsorbol a kesobbiekben elegendo a masodik parancsot tobbszor kiadnod.


Frissites
---

A felev kozben a repository tartalma frissulni fog. Hogy mindig megkapjad a legfrissebb valtoztatasokat, frissitened kell a lokalis masolatodat. Ez parancssorbol:

```bash
git pull
```

Majd forditsd ujra a peldakat.


Hogyan piszkalj bele
---

Amennyiben csak lokalisan szeretnel modositasokat vegezni, ez igy teljesen jo is - modosits a fajlokon, forditsd le oket, probalkozz.

Amennyiben szeretned masokkal is megosztani a megoldasaidat, vagy nekem interneten at kerdest feltenni egy a peldakkal kapcsolatos problemaddal:

* Regisztralj Githubra
* Nyomd meg a Fork gombot, maris van egy peldanyod, amit szabadon modosithatsz!
* Olvass a gitrol (commit es push fog leginkabb erdekelni)


Kerdesed van?
---

Amennyiben kerdesed, problemad van:

 * A github egy kivalo eszkoz erre. Fork, modosit, feltesz, emailt ir.
 * Amennyiben jarsz az oramra, elotte vagy utana nyugodtan kerdezz.
 * Az anyag fo celja a folyamatos tanulas segitese. Lehetoleg probalj maximum harom het elmaradassal kerdezni!


Hasznos linkek
---

 * [Online C++ Reference](http://en.cppreference.com/w/)
 * [C++ FAQ](https://isocpp.org/faq)
 * [C++ Core Guidelines](https://github.com/isocpp/CppCoreGuidelines)
 * [Awesome C++](https://github.com/fffaraz/awesome-cpp) - A curated list of awesome C/C++ frameworks, libraries, resources, and shiny things
