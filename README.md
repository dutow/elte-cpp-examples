elte-cpp-examples
=====

Ez a repository az ELTE IK programtervezo informatikus Bsc C++ programozas gyakorlatahoz tartalmaz peldakat.

Az egyes orak anyagai a lesson\_X konyvtarakban talalhatoak. Mindegyik konyvtarban talalhato egy ujabb README, ami az adott ora tomor vazlatat tartalmazza.


Elokeszites
---

Az anyag nagy resze C++-ban keszult programokbol all. 

Az oran bemutatottak nagy resze siman onmagaban, kezzel is fordithato, igy eleg odanavigalnod az adott konyvtarba, es kiadni az azt fordito parancsot. 
Ezekhez elegendo az 1-3 lepesek vegrehajtasa, a rekurziv opciot a harmadikbol mar ki is hagyhatod.

Amennyiben azonban az erdekesebb (grafikus, automatikus teszteket futtato, extra dolgokat is bemutato) reszeket is szeretned hasznalni, ahhoz szukseg van kulso konyvtarakra is, anelkul nem fognak fordulni. Ezek a peldak *teljesen* opcionalisak,
segithetnek a tanulasban / es talan fenntartani az erdeklodesedet, de nem kepezik a mindenkeppen szukseges tananyag reszet.

1. Szukseged lesz C++ forditora, git kliensre, valamint CMake-re. 
   Linuxon: apt-get install git clang cmake build-essential libbz2-dev
   Windowson: manualisan letolthetoek es telepithetoek. Git kliensnek a SourceTree kivalo, ha GUI-t szeretnel.
2. A tanulast igencsak megkonnyiti egy *jo* fejleszoi kornyezet. A hangsuly a jon van.
   Ajanlom: https://www.jetbrains.com/clion/ (diakoknak ingyenes)  
   Windowson a Visual Studio Community is tokeletes (akkor clang sem kell, fordito is van benne)
3. Klonozd rekurzivan a projektet:
   git clone --recursive ...
   (ez nemi idot fog igenyelni, igyal egy kavet)
4. Fordits le a fuggosegeket (ez nemi idot fog igenyelni, igyal egy kavet)
   ./bootstrap.sh (vagy .bat, ha ragaszkodsz a Windowshoz)
5. Nyisd meg a projektet az IDE-dben. Clionnal ez egyszeruen a konyvtar kivalasztasat jelenti, Visual Studiohoz pedig:
   cmake .
   Majd a keletkezett .sln fajl megnyitasa.
6. Forditsd es futtasd!


Hogyan hasznald
---

A projekt orakra van bontva, azon belul is altalaban talaltok:

* Mindenfele peldat, amit vagy megmutatok oran, vagy extra
* Egy grafikus peldat (extra, otthonra, jatszani vele)
* Egy GTest-es peldat, amiben opcionalis hazifeladatokat talaltok

h3. Parancssor

cmake .
cmake --build

Ezzel leforditottal mindent, es a binaris fajlok a bin konyvtarba masolodtak, onnan tudod futtatni oket.

h3. Clion

h3. Visual Studio


Hazik megoldasa
---
TODO


Ha szeretned te is verziokovetni
---

* Regisztralj Githubra
* Nyomd meg a Fork gombot, maris van egy peldanyod, amit szabadon modosithatsz!
* Olvass a gitrol


Kerdesed van?
---

Amennyiben kerdesed van, annak kivalo helye az ora. (Kiveve, amennyiben kulsos vagy es csak idetevedtel, akkor irj emailt!)

* Kerdeseket gyakorlat elott vagy utan tudsz feltenni
* Az elozo harom ora anyagaval kapcsolatban

Elerhetoseg
---

 * E-mail: zsolt.parragi@cancellar.hu

