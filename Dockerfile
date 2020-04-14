FROM amazonlinux:latest

COPY main.cpp ./etc/cpp/
COPY controlsum.cpp ./etc/cpp/
COPY Makefile ./etc/cpp/

RUN apt update
RUN apt install g++ gcc nano binutils mingw-w64 -y

WORKDIR ./etc/cpp/

CMD make

MAINTAINER Alexey Semenkov <sealekssaa@gmail.com>