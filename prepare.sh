
echo "Preparing..."
echo "Downloading ncurses 6.2"
wget https://ftp.gnu.org/pub/gnu/ncurses/ncurses-6.2.tar.gz
tar -zxf ncurses-6.2.tar.gz
cd ncurses-6.2
mkdir install
./configure --prefix=`realpath ./install`
make
make install
