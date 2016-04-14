
CURR_DIR=`pwd`

# boost
cd vendor/boost
./bootstrap.sh --with-toolset=clang
./b2 headers
./b2 install link=static runtime-link=shared threading=multi --prefix=../boost-install --with-filesystem --with-system

cd "$CURR_DIR"
