FROM ubuntu:latest
RUN apt-get -qq -y update && DEBIAN_FRONTEND=noninteractive apt-get -qq -y dist-upgrade && DEBIAN_FRONTEND=noninteractive apt-get -qq -y install autoconf-archive automake build-essential curl gcc git lcov libcurl4-openssl-dev libdmalloc-dev libpthread-stubs0-dev libtest-pod-perl libtool perl pkg-config python-pip valgrind && pip install --upgrade pip && pip install cpp-coveralls
ADD . /root/source
WORKDIR /root
USER root
CMD cd source && (cd c-tap-harness && ./bootstrap) && autoreconf -i && ./configure --enable-valgrind --enable-compiler-warnings=error --with-dmalloc --with-gcov && make distcheck
