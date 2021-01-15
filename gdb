warning: Cannot parse .gnu_debugdata section; LZMA support was disabled at compile time


wget http://ftp.gnu.org/gnu/gdb/gdb-9.2.tar.gz

deps
lzma  source git clone https://git.tukaani.org/xz.git
我直接使用了rpm包
wget http://mirror.centos.org/centos/7/os/x86_64/Packages/xz-devel-5.2.2-1.el7.x86_64.rpm
rpm2cpio *.rpm | cpio -div
設置PKG_CONFIG_PATH不起作用

export CPATH=/var/fpwork/pechen/tools/usr/include
export LIBRARY_PATH=/var/fpwork/pechen/tools/usr/lib64:$LIBRARY_PATH

mkdir build
cd build
../configure --with-lzma --prefix=`pwd`/output
make
make install
