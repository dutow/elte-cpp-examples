
CURR_DIR=`pwd`

# boost
cd vendor/boost
./bootstrap.sh --with-toolset=clang --with-libraries=filesystem,system
./b2 link=static

cd $CURR_DIR
cd vendor/SFML
cmake . -DBUILD_SHARED_LIBS=OFF
cmake --build .

