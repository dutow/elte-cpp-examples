
cd vendor/boost
call bootstrap.bat --with-toolset=clang
call b2 headers
call b2 install link=static runtime-link=shared threading=multi --prefix=../boost-install --with-filesystem --with-system
