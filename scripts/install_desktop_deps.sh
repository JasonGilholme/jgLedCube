
sudo apt-get -qq update

# Boost
sudo apt-get install libboost1.55-all-dev

# GoogleTest
sudo apt-get install -y libgtest-dev
cd /usr/src/gtest
sudo cmake .
sudo cmake --build .
sudo mv libg* /usr/local/lib/

cd -
