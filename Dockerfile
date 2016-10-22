FROM ubuntu:latest
RUN apt-get -q -y update && DEBIAN_FRONTEND=noninteractive apt-get -q -y dist-upgrade && DEBIAN_FRONTEND=noninteractive apt-get -q -y install autoconf-archive automake build-essential curl gcc git lcov libcurl4-openssl-dev libdmalloc-dev libpthread-stubs0-dev libtest-pod-perl libtool perl pkg-config python-pip valgrind && pip install --upgrade pip && pip install cpp-coveralls
ADD . /root/source
WORKDIR /root
USER root
CMD cd source && (cd c-tap-harness && ./bootstrap) && autoreconf -i && ./configure --enable-valgrind --enable-compiler-warnings=error --with-dmalloc --with-gcov && make distcheck
