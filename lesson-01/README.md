1. ora
======


Az ora anyaga
---

 * Az ora peldait, extrakat tartalmazo git repository bemutatasa, hogyan gyakorolj
 * Mi az a C/C++, hogyan lehet leforditani egy programot, a forditas lepesei, gcc/clang fontosabb kapcsoloi
 * Egyszeru peldaprogramok (hello vilag, tobb forditasi egysegbol allo program)
 * Debugolas


Peldak
---

 * `1-hello-world`: Nagyon egyszeru pelda, mi az a C++.
 * `2-hello-world-c`: Ugyanaz a peldaprogram, C stilusban megvalositva. Ugyanugy fordul C++ programkent is.
 * `3-sum-with-a-library`: Kiszamolja egy intervallumban a hettel oszthato szamok osszeget, es kozben bemutatja a tobb reszegysegben fordulo programokat is.


Extra
---

### `t-sample-tests`

Pelda automatikus tesztekre.

Egyben egy kis opcionalis hazifeladat is, mivel par teszt hibat jelez.


### `g-hello-world`

Grafikus hello vilag, forog is.

Lehet rajta sok kiserletet vegezni, pl. (a zarojeles szam a nehezsege, 1-3):

 * (1) ne forogjon, hanem mindig 45 fokos szogben jelenitse meg a feliratot
 * (1) a bin konyvtarbol allva lehessen elinditani a programot, ne egyel kivulrol
 * (2) A kozeppontja korul forogjon a szoveg
 * (3) Mozogjon a felirat balra-jobbra, a kepernyon belul

### `g-pong`

A "pong" jatek egyszeru megvalositasa.

 * (1) A jatek ne tartalmazzon rejtett falakat
 * (1) A labda ne sulyledjen bele az utobe
 * (1) A jatek elforgatasa 90 fokkal
 * (2) A labda folyamatosan gyorsuljon
 * (2) Pontszamitas es kijelzes (segitseg: `std::to\_string`)
 * (3) "Korkoros", egyjatekos pong (az uto egy korvonalon mozog, a cel a labda benntartasa)
